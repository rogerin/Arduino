#include <EEPROM.h>
#include <SD.h>

File arquivo;
byte inicio_ok;

void setup()
{
  Serial.begin(9600);
   while (!Serial) {
    ; 
  }
  Serial.print("Initializing SD card...");
   pinMode(10, OUTPUT);
   
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop()
{
}
