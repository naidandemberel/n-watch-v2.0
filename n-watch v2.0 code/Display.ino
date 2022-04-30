void initLCD()
{
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH);
  tft.init();
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);
}

void displayBLconnect()
{
  tft.setSwapBytes(true);
  tft.pushImage(50, 20, 140, 140, BL);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 175);
  tft.print("Please connect with");
  tft.setCursor(0, 200);
  tft.print("your phone");
}

void mainDisplay()
{
  unsigned long currentTime = millis();
  if (currentTime - previous >= interval)
  {
    temp = sht.readTemperature();
    humi = sht.readHumidity();
    previous = currentTime;
    battery();
  }
  mi = rtc.getMinute();
  ho = rtc.getHour(true);
  if (mi < 10) {
    mistring = "0" + String(mi);
  }
  else {
    mistring = String(mi);
  }
  if (ho < 10) {
    hostring = "0" + String(ho);
  }
  else {
    hostring = String(ho);
  }
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextFont(7);
  tft.setTextSize(1);
  tft.setCursor(45, 80);
  tft.print(hostring + ":" + mistring);

  tft.setTextFont(1);
  tft.setTextSize(2);
  tft.setCursor(30, 180);
  tft.print(rtc.getDate());

  tft.setCursor(10, 10);
  tft.print(temp, 1);
  tft.setCursor(60, 10);
  tft.print("C");

  tft.setCursor(10, 30);
  tft.print(humi, 1);
  tft.setCursor(60, 30);
  tft.print("%");
  
  tft.setCursor(175, 10);
  tft.print(String(percent,0)+"%");
  tft.setCursor(175, 30);
  tft.print(String(batvalue,2)+"V");
}
