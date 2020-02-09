/* Timestamp functions using a DS1307 RTC connected via I2C and Wire lib
**
** Useful for file name
**		` SD.open(time.timestamp()+".log", FILE_WRITE) `
**
**
** Created: 2015-06-01 by AxelTB
** Last Edit:
*/

// Connections: 
// SCL to D22
// SDA to D21
// VCC to 3V3
// GND to GND

#include "RTClib.h"

RTC_DS1307 rtc;

// If the time is incorrect:  Upload with Need2SetTime = true first. Then upload with Need2SetTime = false
// If the time is correct:    Upload with Need2SetTime = false
bool Need2SetTime = false;

void setup() {
  Serial.begin(57600);
  rtc.begin();
  
  if (! rtc.isrunning())
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
  if (Need2SetTime)
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  

}

void loop() {
if (rtc.isrunning()) {
    DateTime time = rtc.now();

    //Full Timestamp
    //Serial.println(String("DateTime::TIMESTAMP_FULL:\t")+time.timestamp(DateTime::TIMESTAMP_FULL));

    //Date Only
    Serial.println(String("DateTime::TIMESTAMP_DATE:\t")+time.timestamp(DateTime::TIMESTAMP_DATE));

    //Full Timestamp
    Serial.println(String("DateTime::TIMESTAMP_TIME:\t")+time.timestamp(DateTime::TIMESTAMP_TIME));

    Serial.println("\n");

    //Delay 1s
    delay(1000);
    }
}