// Display Brightnesscontrol with button debounce
void brightnessControll(int reading)
{
  if (reading != lastButtonState)
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState)
    {
      buttonState = reading;

      // only toggle the LED if the new button state is LOW
      if (buttonState == LOW)
      {
        brightnessState++;
        if (brightnessState > 3)
        {
          brightnessState = 0;
        }
      }
    }
  }

  switch (brightnessState)
  {
  case 0: // brightness state 1
    analogWrite(brightness_pin, brState1);
    break;
  case 1: // brightness state 2
    analogWrite(brightness_pin, brState2);
    break;
  case 2: // brightness state 3
    analogWrite(brightness_pin, brState3);
    break;
  case 3: // brightness state 4
    analogWrite(brightness_pin, brState4);
    break;
  }
  lastButtonState = reading;
}