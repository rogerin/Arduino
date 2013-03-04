#include <SPI.h>
#include <RFID.h>

RFID rfid(10,5); 

void setup()
{ 
  Serial.begin(9600);
  Serial.println("iniciando");
  SPI.begin(); 
  rfid.init();
  
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  
}

void loop()
{
    if (rfid.isCard()) {
      
          Serial.println("IS CARD");
          
          if (rfid.readCardSerial()) {
            
                        Serial.println(" ");
                        Serial.println("Numero  : ");
			Serial.print(rfid.serNum[0],DEC);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[1],DEC);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[2],DEC);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[3],DEC);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[4],DEC);
                        Serial.println(" ");
                        digitalWrite(2,1);
                        delay(150);
                        digitalWrite(2,0);
                        delay(1000);  
          }
          
    }
    
    rfid.halt();
}
