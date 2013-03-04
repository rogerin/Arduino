#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX

void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
 
  Serial.println("Iniciado!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

  
  pinMode(13,OUTPUT);
}

void loop() // run over and over
{
  mySerial.listen();
  if (mySerial.available() > 0) {
    char acao = (char)mySerial.read();
    Serial.println(acao);    
  
    if(acao == '1') {
      digitalWrite(13,1);
      Serial.println("Acao 1 chamada");
    }
    if(acao == '2') {
      digitalWrite(13,0);
      Serial.println("Acao 2 chamada");
    }
    
  }

}
