#ifndef DECLARATIONS
#define DECLARATIONS

#define DEBUG
#define backLight GPIO_NUM_5
#define batteryPin 33
#define leftPin  14
#define rightPin 13
#define I2C_SDA  21
#define I2C_SCL  22

#include <TFT_eSPI.h>
#include <SPI.h>
#include <ESP32Time.h>
#include <Wire.h>
#include <DFRobot_SHT20.h>
//#include <WiFi.h>
#include <BluetoothSerial.h>
#include "BL.h"
#include "esp_sleep.h"
#include "soc/rtc.h"
#include "driver/adc.h"
#include <esp_wifi.h>
#include <esp_bt.h>
#include <esp_bt_main.h>

TFT_eSPI tft = TFT_eSPI();
BluetoothSerial SerialBT;
ESP32Time rtc;
DFRobot_SHT20 sht;

//RTC_DATA_ATTR int bootCount = 0;
RTC_DATA_ATTR bool timeseted = false;
int ho, mi;
int tim[6];
float percent;
float batvalue;
const long interval = 2000;
unsigned long previous = 0;
String val;
String mistring, hostring;
boolean conected = false;
float temp, humi;

#endif
