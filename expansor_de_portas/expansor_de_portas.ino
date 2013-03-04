#include <Wire.h>

#define expansor1 0x38
#define expansor2 0x39

byte inicio = B11111111;

int tempo = 350;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  
   Wire.beginTransmission(expansor1);
    Wire.write(inicio);
  Wire.endTransmission(expansor1);
  delay(40); 
   Wire.beginTransmission(expansor2);
    Wire.write(inicio);
  Wire.endTransmission(expansor2);
  delay(40);   
}

void loop()
{     
 
 for (int i = 0; i<8 ; i++){
   invertePino(i, expansor1); delay(500); 
 }
 
 for (int i = 0; i<8 ; i++){
   invertePino(i, expansor1); delay(500); 
 }
 
 for (int i = 0; i<8 ; i++){
   invertePino(i, expansor2); delay(500); 
 }
 
 for (int i = 0; i<8 ; i++){
   invertePino(i, expansor2); delay(500); 
 }
  
}

void invertePino(int pinN, byte endereco){ 
  inicio = inicio ^ (1 << pinN); 
  Wire.beginTransmission(endereco);
    Wire.write(inicio);
  Wire.endTransmission(endereco);
  delay(40); 
}
