// Connecting to WIFI and posting to server
String postRequest(const char *serverName, const String auth_key, const String id)
{
  //Check WiFi connection status
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;

    // Your Domain name with URL path or IP address with path
    http.begin(serverName);

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    // Data to send with HTTP POST
    String httpRequestData = "auth_key=" + auth_key + "&id=" + id;
    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);

    payload = "{}";

    if (httpResponseCode > 0)
    {
      payload = http.getString();
    }

    // Free resources
    http.end();
  }
  else
  {
    payload = ("  Disconnected  ");
  }
  lcd.clear();
  return payload;
}