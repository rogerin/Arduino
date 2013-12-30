#include <Wire.h>

#define expansor1 0x38
#define expansor2 0x39
byte inicio = 0b11111111;
byte inicio2 = 0b11111111;

void setup()
{
  Wire.begin();
  Serial.begin(9600);

}

void loop()
{     

  for (int i = 0; i < 8; i++) {
    I2C_IO_Write22(i, expansor2, 1);
    delay(100);
  }
  
  for (int i = 0; i < 8; i++) {
    I2C_IO_Write(i, expansor1, 1);
    delay(100);
  }
  
  for (int i = 0; i < 8; i++) {
    I2C_IO_Write22(i, expansor2, 0);
    delay(100);
  }
  
  for (int i = 0; i < 8; i++) {
    I2C_IO_Write(i, expansor1, 0);
    delay(100);
  }
  
  
  
  
  
  
  /*
 I2C_IO_Write22(0, expansor2, 0);
 delay(50);
 I2C_IO_Write22(1, expansor2, 0);
 delay(50);
 I2C_IO_Write22(2, expansor2, 0);
 delay(50);
 I2C_IO_Write22(3, expansor2, 0);
 delay(50);
 I2C_IO_Write22(4, expansor2, 0);
 delay(50);
 I2C_IO_Write22(5, expansor2, 0);
 delay(50);
 I2C_IO_Write22(6, expansor2, 0);
 delay(50);
 I2C_IO_Write22(7, expansor2, 0);
 
 
 I2C_IO_Write22(0, expansor2, 1);
 delay(50);
 I2C_IO_Write22(1, expansor2, 1);
 delay(50);
 I2C_IO_Write22(2, expansor2, 1);
 delay(50);
 I2C_IO_Write22(3, expansor2, 1);
 delay(50);
 I2C_IO_Write22(4, expansor2, 1);
 delay(50);
 I2C_IO_Write22(5, expansor2, 1);
 delay(50);
 I2C_IO_Write22(6, expansor2, 1);
 delay(50);
 I2C_IO_Write22(7, expansor2, 1);
 delay(50);
 
 
 I2C_IO_Write22(0, expansor2, 0);
 delay(50);
 I2C_IO_Write22(1, expansor2, 0);
 delay(50);
 I2C_IO_Write22(2, expansor2, 0);
 delay(50);
 I2C_IO_Write22(3, expansor2, 0);
 delay(50);
 I2C_IO_Write22(4, expansor2, 0);
 delay(50);
 I2C_IO_Write22(5, expansor2, 0);
 delay(50);
 I2C_IO_Write22(6, expansor2, 0);
 delay(50);
 I2C_IO_Write22(7, expansor2, 0);
 delay(50);
 
 
 I2C_IO_Write22(0, expansor2, 1);
 delay(50);
 I2C_IO_Write22(1, expansor2, 1);
 delay(50);
 I2C_IO_Write22(2, expansor2, 1);
 delay(50);
 I2C_IO_Write22(3, expansor2, 1);
 delay(50);
 I2C_IO_Write22(4, expansor2, 1);
 delay(50);
 I2C_IO_Write22(5, expansor2, 1);
 delay(50);
 I2C_IO_Write22(6, expansor2, 1);
 delay(50);
 I2C_IO_Write22(7, expansor2, 1);
 delay(50);
 
 
 

 I2C_IO_Write(0, expansor1, 0);
 Serial.println("Pin: 0 | Expansor: 1 | 0");
 delay(1000);
 I2C_IO_Write(1, expansor1, 0);
 Serial.println("Pin: 1 | Expansor: 1 | 0");
 delay(1000);
 I2C_IO_Write(2, expansor1, 0);
 Serial.println("Pin: 2 | Expansor: 1 | 0");
 delay(1000);
 I2C_IO_Write(3, expansor1, 0);
 Serial.println("Pin: 3 | Expansor: 1 | 0");
 delay(1000);
 I2C_IO_Write(4, expansor1, 0);
 Serial.println("Pin: 4 | Expansor: 1 | 0");
 delay(1000);
 I2C_IO_Write(5, expansor1, 0);
 Serial.println("Pin: 5 | Expansor: 1 | 0");
 delay(1000);
 I2C_IO_Write(6, expansor1, 0);
 Serial.println("Pin: 6 | Expansor: 1 | 0");
 delay(1000);
 I2C_IO_Write(7, expansor1, 0);
 Serial.println("Pin: 7 | Expansor: 1 | 0");
 delay(5000);
 
 I2C_IO_Write(0, expansor1, 1);
 Serial.println("Pin: 0 | Expansor: 1 | 1");
 delay(1000);
 I2C_IO_Write(1, expansor1, 1);
 Serial.println("Pin: 1 | Expansor: 1 | 1");
 delay(1000);
 I2C_IO_Write(2, expansor1, 1);
 Serial.println("Pin: 2 | Expansor: 1 | 1");
 delay(1000);
 I2C_IO_Write(3, expansor1, 1);
 Serial.println("Pin: 3 | Expansor: 1 | 1");
 delay(1000);
 I2C_IO_Write(4, expansor1, 1);
 Serial.println("Pin: 4 | Expansor: 1 | 1");
 delay(1000);
 I2C_IO_Write(5, expansor1, 1);
 Serial.println("Pin: 5 | Expansor: 1 | 1");
 delay(1000);
 I2C_IO_Write(6, expansor1, 1);
 Serial.println("Pin: 6 | Expansor: 1 | 1");
 delay(1000);
 I2C_IO_Write(7, expansor1, 1);
 Serial.println("Pin: 7 | Expansor: 1 | 1");
 delay(5000);
*/ 
 
 
 
}

void invertePino(int pinN, byte endereco){ 
  inicio = inicio ^ (1 << pinN); 
  Wire.beginTransmission(endereco);
    Wire.write(inicio);
  Wire.endTransmission(endereco);
  delay(40); 
}



void I2C_IO_Write(int pinN, byte endereco,int status){
  int aux = 0;
  aux = 1 << pinN;
  if(status == LOW){
  inicio &= ~ aux;     //(LOW)
  }
  if (status == HIGH){
  inicio |= aux;          //(HIGH)
  }
  inicio = inicio ^ (1 << pinN);
  Wire.beginTransmission(endereco);
    Wire.write(inicio);
  Wire.endTransmission(endereco);
  delay(40);
}


void I2C_IO_Write22(int pinN, byte endereco,int status){
  int aux = 0;
  aux = 1 << pinN;
  if(status == LOW){
  inicio2 &= ~ aux;     //(LOW)
  }
  if (status == HIGH){
  inicio2 |= aux;          //(HIGH)
  }
  inicio2 = inicio2 ^ (1 << pinN);
  Wire.beginTransmission(endereco);
    Wire.write(inicio2);
  Wire.endTransmission(endereco);
  delay(40);
}


void I2C_IO_Write2(int pinN, byte endereco,int status){ 
    inicio = inicio ^ (1 << pinN);
    inicio = (status == HIGH) ? (inicio | (1 << pinN)) :(inicio & ~(1 << pinN));
    delay(40); 
}
