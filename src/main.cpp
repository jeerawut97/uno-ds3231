#include <Arduino.h>
#include "Wire.h"
#include "SPI.h"
#include "RTClib.h"

RTC_DS3231 RTC;

void setup () {
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));
}

void loop () {

  DateTime now = RTC.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);

  Serial.println();
  Serial.print("Tempeature = ");
  Serial.print(RTC.getTemperature());
  Serial.println(" C");
  delay(1000);
}
