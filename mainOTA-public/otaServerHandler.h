  /*return index page which is stored in uploadBin */
  server.on("/", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", loginIndex);
  });
  server.on("/uploadBin", HTTP_GET, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/html", uploadBin);
  });
  /*handling uploading firmware file */
  server.on("/update", HTTP_POST, []() {
    server.sendHeader("Connection", "close");
    server.send(200, "text/plain", (Update.hasError()) ? "FAIL" : "OK");
    ESP.restart();
  });
  server.begin();