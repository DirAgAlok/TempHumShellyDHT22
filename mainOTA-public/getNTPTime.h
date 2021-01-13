// change between german and english days here and in getNTPTime()
char daysOfTheWeek[7][12] = {"So", "Mo", "Di", "Mi", "Do", "Fr", "Sa"}; //german
//char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; //english

const long utcOffsetInSeconds = 3600; //UTC offset of your Timezone (ask google)
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

String getNTPTime(char parser)
{
    timeClient.update();
    unsigned long epochTime = timeClient.getEpochTime();
    struct tm *ptm = gmtime((time_t *)&epochTime);
    int monthDay = ptm->tm_mday;
    int currentMonth = ptm->tm_mon + 1;
    int currentYear = ptm->tm_year + 1900;

    String _parser = String(parser);
    String time = String(timeClient.getHours()) + ":" + String(timeClient.getMinutes());
    String doW = String(daysOfTheWeek[timeClient.getDay()]);
    String currYear = String(currentYear);
    String date = doW + " " + String(monthDay) + "." + String(currentMonth) + "." + String(currentYear);
    String fTime = timeClient.getFormattedTime();
    String result = fTime + _parser + date + _parser + time;
    return result;
}