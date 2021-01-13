String dhtTempHumi()
{
    String result;
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t))
    {
        result = ("Sensor Error");
        dhtError = 1;
        return result;
    }

    String _parser = String(parser);
    String _dhtTemp = String(t, 1);
    String _dhtHum = String(h, 1);
    dhtError = 0;

    result = _dhtTemp + _parser + _dhtHum;
    return result;
}