#include <Wire.h>

#define expansor1 0x38


void setup(){
  Wire.begin();
  Wire.beginTransmission(expansor1);
  Wire.write(B00000000);
  Wire.endTransmission();
}

void loop() {
  Wire.begin();
  Wire.beginTransmission(expansor1);
  Wire.write(B00001000);
  Wire.endTransmission();
  delay(500);
  
  Wire.begin();
  Wire.beginTransmission(expansor1);
  Wire.write(B00000100);
  Wire.endTransmission();
  delay(500);
  
  
  
}

