#include <OneWire.h>
#include<Servo.h>

#include <Wire.h>
#include "RTClib.h"
const int buzzer = 13;
int LedA= 12;
int LedB= 11;
int LedC= 10;
int LedD= 9;


RTC_DS1307 rtc;



void setup () {
  Serial.begin(57600);
#ifdef AVR
  Wire.begin();
#else
  Wire.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2015, 2, 4, 21, 3, 0));
     pinMode(buzzer, OUTPUT);
     pinMode(LED_BUILTIN, OUTPUT);
     ServoA.attach(12);
     ServoB.attach(11);
     ServoC.attach(10);
     ServoD.attach(9);
  }
  
  rtc.adjust(DateTime(2017, 6, 27, 7, 47, 0));
}

void loop () {
    DateTime now = rtc.now();
    
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
    
    Serial.println();
    delay(3000);

      if(now.hour() ==8 && now.minute() == 00)
      {
        tone(buzzer,HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(LedA,HIGH));
        Serial.print("Time to take medicine A");
        }
      
      if (now.hour() ==2 && now.minute() == 30)
      {
        tone(buzzer,HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(LedB,HIGH);
        digitalWrite(LedD,HIGH); 
        Serial.print("Time to take medicine B and D");
      }
      
      if  (now.hour() ==8 && now.minute() == 00)
      {
        tone(buzzer,HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(LedC,HIGH));
        Serial.print("Time to take medicine C"); 
      }
      
}
      

