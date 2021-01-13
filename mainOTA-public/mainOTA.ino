/*
 * Code by Andreas Pichler / DirAgAlok
 * 
 * https://diragalok.at
 * info@diragalok.at
 */

// Including libraries
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h> // !!Max Version 6.16.1!! if you have problems compiling downgrade the librarie
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <analogWrite.h>
#include "DHT.h"
#include <WiFiClient.h>
#include <WebServer.h>
#include <Update.h>


// Including internal files
#include "wifi_config.h"
#include "shelly_config.h"
#include "getNTPTime.h"
#include "splitString.h"
#include "dhtTempHumi_config.h"
#include "variables_config.h"

// Initialize I2C Display
LiquidCrystal_I2C lcd(0x27, 20, 4);

WebServer server(80);
#include "otaWebServer.h"

void setup(void)
{
  /*
  just for testing
  if Serial print is used I2C Displays show strange behavior
  */
  //Serial.begin(115200);

#include "init_setup.h"
#include "startup.h"
#include "otaServerHandler.h"
}

// Including internal functions
#include "dhtTempHumi.h"
#include "brightness.h"
#include "convertData.h"
#include "postRequest.h"

void loop()
{
  server.handleClient();

  //get current time and day
  ntpTime = splitString(getNTPTime(parser), parser, 0);
  ntpDate = splitString(getNTPTime(parser), parser, 1);
  ntpTimeSubStr = splitString(getNTPTime(parser), parser, 2);

  // checking for first start and getting Values
  if (chkstart == 0)
  {
    if (millis() > shellyFirstDelay)
    {
#include "getValues.h"
      chkstart = 1;
    }
  }
  else if((millis() - lastTime) > newUpdate)
  {
    lastTime = millis();
    lcd.clear();
#include "getValues.h"
  }
  

  //printing to LCD
  lcd.setCursor(2, 0);
  lcd.print(shellyOutput);
  lcd.setCursor(2, 1);
  lcd.print(dhtOutput);
  lcd.setCursor(6, 2);
  lcd.print(ntpTime);
  lcd.setCursor(3, 3);
  lcd.print(ntpDate);

  //control display brightness
  reading = digitalRead(buttonPin);
  brightnessControll(reading);
}
