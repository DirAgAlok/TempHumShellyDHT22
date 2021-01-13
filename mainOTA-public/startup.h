//LCD Display Output
lcd.setCursor(5, 0);
lcd.print("Shelly H&T");
lcd.setCursor(8, 1);
lcd.print("DHT22");
lcd.setCursor(4, 2);
lcd.print("by DirAgAlok");

WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
  delay(500);
  lcd.setCursor(5, 3);
  lcd.print("Connecting");
  if (millis() > startupConnectTime)
  {
    lcd.setCursor(0, 3);
    lcd.print("                    ");
    lcd.setCursor(6, 3);
    lcd.print("No  WiFi");
    delay(5000);
    lcd.setCursor(4, 3);
    lcd.print("RECONNECTING");
    WiFi.reconnect();
    ip = WiFi.localIP().toString();
    if (WiFi.status() == WL_CONNECTED)
    {
      lcd.setCursor(0, 3);
      lcd.print("                    ");
      lcd.setCursor(4, 3);
      lcd.print("IP:" + ip);
    }
    delay(2000);
    break;
  }
}

ip = WiFi.localIP().toString();
if (WiFi.status() == WL_CONNECTED)
{
  lcd.setCursor(4, 3);
  lcd.print("IP:" + ip);
}

delay(bootDelay);
lcd.clear();
lcd.setCursor(4, 0);
lcd.print("GETTING DATA");
lcd.setCursor(4, 1);
lcd.print("PLEASE  WAIT");

//starting the NTP CLient
timeClient.begin();