/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  char c = Serial.read();
  
  if(c == 'l'){
    for (int i = 0; i < 1; i++) {
      irsend.sendNEC(0x8076807F, 32); 
      delay(100);
    }  
  }
  
   if(c == 'V'){
    for (int i = 0; i < 1; i++) {
      irsend.sendNEC(0x80767887, 32); 
      delay(100);
    }
  }
  
  if(c == 'v'){
    for (int i = 0; i < 1; i++) {
      irsend.sendNEC(0x8076F807, 32); 
      delay(100);
    }
  }
  
  if(c == 'C'){
    for (int i = 0; i < 1; i++) {
      irsend.sendNEC(0x807620DF, 32); 
      delay(100);
    }
  }
  if(c == 'c'){
    for (int i = 0; i < 1; i++) {
      irsend.sendNEC(0x8076A05F, 32); 
      delay(100);
    }
  }
  
  
}

