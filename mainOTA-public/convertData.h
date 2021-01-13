// converting data
String convertData(String payload)
{
  String result;
  // converting payload string to const char
  const char *json = payload.c_str();

  // converting json to useable variables
  StaticJsonDocument<0> filter;
  filter.set(true);

  DynamicJsonDocument doc(1536);
  deserializeJson(doc, json, DeserializationOption::Filter(filter));

  JsonObject data_device_status = doc["data"]["device_status"];
  const char *data_device_status_time = data_device_status["time"];

  JsonObject data_device_status_tmp = data_device_status["tmp"];
  float data_device_status_tmp_value = data_device_status_tmp["value"];

  float data_device_status_hum_value = data_device_status["hum"]["value"];

  // converting chars to string for further use
  String _shellyTemp = String(data_device_status_tmp_value, 1);
  String _shellyHum = String(data_device_status_hum_value, 1);
  String _shellyTime = String(data_device_status_time);

  // generating return value
  //result = "Out:" + _shellyTemp + "\337C " + _shellyHum + "%";
  result = _shellyTemp + String(parser) + _shellyHum + String(parser) + _shellyTime;
  return result;
}