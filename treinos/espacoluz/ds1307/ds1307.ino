// Date and time functions using a DS1307 RTC connected via I2C and Wire lib

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;

byte BOTAO1 = 0;
int porta_botao1 = 7;
byte RELE1 = 0;

void setup () {
    Serial.begin(9600);
    Wire.begin();
    RTC.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  
  pinMode(13, OUTPUT);
  digitalWrite(13,0);
  pinMode(8, OUTPUT);
  digitalWrite(8,0);
  
  pinMode(porta_botao1, INPUT);
  digitalWrite(porta_botao1, 1);
  
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
    
    if(now.second() == 1) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
    if(now.second() == 3) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }
    if(now.second() == 6) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
    if(now.second() == 9) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }
    if(now.second() == 12) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
      if(now.second() == 17) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }
    if(now.second() == 20) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
      if(now.second() == 23) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }if(now.second() == 26) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
      if(now.second() == 29) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }
    
    if(now.second() == 32) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
      if(now.second() == 35) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }
    
    if(now.second() == 38) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
      if(now.second() == 41) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }
    
    if(now.second() == 43) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
      if(now.second() == 46) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }
    if(now.second() == 49) {
    digitalWrite(13, 1);
    digitalWrite(8,1);
    }
      if(now.second() == 51) {
    digitalWrite(13, 0);
    digitalWrite(8,0);
    }



  BOTAO1 = digitalRead(7);
  if(BOTAO1 == 0){
    Serial.println("Botao 1 pressionado");
    RELE1 = !RELE1;
    digitalWrite(8, RELE1);
    delay(200); 
  }
 
}
