#include "Declarations.h"

void setup()
{
  setCpuFrequencyMhz(80); // setting CPU frequency to 80MHz to reduce power consumption
  rtc_clk_slow_freq_set(RTC_SLOW_FREQ_8MD256);// setting rtc slow frequency(more accurate in sleep modes)
  //use arduino-esp32 version 2.0.0 (2.0.2 won't work)

#ifdef DEBUG
  Serial.begin(115200);
  Serial.println("n-watch v2.0");
#endif
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  
  Wire.begin(I2C_SDA, I2C_SCL);
  
  initLCD();
  initBL();
  
  delay(100);
}

void sleep()
{
  digitalWrite(backLight, LOW);

  tft.writecommand(0x10);
  delay(5);// Sleep

  //gpio_deep_sleep_hold_en();
 
  if (timeseted == true)
  {
    esp_wifi_stop();
    btStop();
    esp_bt_controller_disable();
    esp_bluedroid_disable();
  }
  
  //adc_power_off();
  //WiFi.mode(WIFI_OFF);
  
  esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, 1);
  Serial.println("Sleping");
  Serial.flush();
  esp_light_sleep_start();
  //esp_deep_sleep_start();
}

void onWakeup()
{
  //gpio_deep_sleep_hold_dis();
  digitalWrite(backLight, HIGH);
  tft.writecommand(0x11);
  delay(120);
  tft.fillScreen(TFT_BLACK);
}

boolean wakeupCheck()
{
  if(digitalRead(rightPin) == 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void battery()
{
  batvalue = analogRead(batteryPin)*(6.6/4096);
  percent = (batvalue-2.2)/1.55*100;
}

void loop()
{
  if (wakeupCheck())
  {
    if (timeseted == true)
    {
      mainDisplay();
      Serial.println(batvalue);
    }
    else
    {
      if (SerialBT.available() > 0)
      {
        setRTC();
      }
      displayBLconnect();
    }
  }
  else
  {
    sleep();

    onWakeup();
  }
}
