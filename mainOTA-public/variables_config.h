// lcd brightness control
const int brightness_pin = 33; // brightness conrol pin
const int buttonPin = 27;      // button pin to toggle brightness
int brightnessState = 1;
int buttonState;
int lastButtonState = HIGH;
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers
int brState1 = 0;
int brState2 = 50;
int brState3 = 170;
int brState4 = 255;
int brightness = brState2; // starting Brightness 0-255, can be changed with button press
int reading;

unsigned long shellyFirstDelay = 60000; //timedelay for first shelly update
unsigned long bootDelay = 10000; //timedelay between showing IP and day/time
unsigned long startupConnectTime = 20000;
unsigned long lastTime = 0;
unsigned long newUpdate = 600000;

// payload for shelly
String payload = "{}";

// char for splitting Strings
char parser = '_';

// display values
String ntpDate = "";
String ntpTime = "";
String ntpTimeSubStr = "";
String dhtTemp = "";
String dhtHum = "";
String dhtOutput = "";
String shellyTime = "";
String shellyTemp = "";
String shellyHum = "";
String shellyOutput = "";
String degCent = "\337C ";
int dhtError = 0;
String ip = "";

// startup check variable
int chkstart = 0;