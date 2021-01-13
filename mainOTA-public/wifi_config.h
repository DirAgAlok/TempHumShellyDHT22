//WiFi credentials
const char *host = "ShellyDisplay";
const char *ssid = "YOUR_WIFI_SSID";
const char *password = "YOUR_WIFI_PASSWORD";
IPAddress staticIP(10, 0, 0, 33);
IPAddress gateway(10, 0, 0, 138);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(10, 0, 0, 63);

//OTA Credentials
String login = "admin";
String pw = "admin";