//initializing important stuff
  lcd.init();
  //lcd.backlight(); //use for fixed brightness
  analogWrite(brightness_pin, brightness); //use for ajdustable brightness
  
  dht.begin();

  pinMode(buttonPin, INPUT_PULLUP);