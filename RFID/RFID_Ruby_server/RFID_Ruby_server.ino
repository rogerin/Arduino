#include <SPI.h>
#include <RFID.h>

RFID rfid(10,5); 

void setup()
{ 
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  SPI.begin(); 
  rfid.init();
  
}

void loop()
{
    if (rfid.isCard()) {
      
          //Serial.println("IS CARD");
          
          if (rfid.readCardSerial()) {
                        
                        //Serial.println(" ");
                        //Serial.println("El numero de serie de la tarjeta es  : ");
                        //Serial.print("#");
			Serial.print(rfid.serNum[0],DEC);
                        //Serial.print(" , ");
			Serial.print(rfid.serNum[1],DEC);
                        //Serial.print(" , ");
			Serial.print(rfid.serNum[2],DEC);
                        //Serial.print(" , ");
			Serial.print(rfid.serNum[3],DEC);
                        //Serial.print(" , ");
			Serial.print(rfid.serNum[4],DEC);
                        Serial.println(" ");
                        digitalWrite(2, 1);
                        delay(100);
                        digitalWrite(2, 0);
                        delay(500);
                       
            
          }
          
    }
    
    rfid.halt();
}
