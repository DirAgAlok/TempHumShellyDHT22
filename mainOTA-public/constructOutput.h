//from Shelly HT
shellyTemp = splitString(convertData(payload), parser, 0);
shellyHum = splitString(convertData(payload), parser, 1);
shellyTime = splitString(convertData(payload), parser, 2);
shellyOutput = "OUT:" + shellyTemp + degCent + shellyHum + "%";

//from DHT22
dhtTemp = splitString(dhtTempHumi(), parser, 0);
dhtHum = splitString(dhtTempHumi(), parser, 1);
if (dhtError == 0)
{
  dhtOutput = "IN: " + dhtTemp + degCent + dhtHum + "%";
}
else
{
  dhtOutput = dhtTempHumi();
}