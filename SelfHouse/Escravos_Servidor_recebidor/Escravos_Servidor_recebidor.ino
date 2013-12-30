#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX


#define LUZ1 22
#define BUTTON2 23
#define BUTTON3 24
#define BUTTON4 25
#define BUTTON5 26
#define BUTTON6 27
#define BUTTON7 28
#define BUTTON8 29
#define BUTTON9 30
#define BUTTON10 31
#define BUTTON11 32
#define BUTTON12 33
#define BUTTON13 34
#define BUTTON14 35
#define BUTTON15 36
#define BUTTON16 37

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
    if(acao == '3') {
      digitalWrite(13,0);
      Serial.println("Acao 2 chamada");
    }
    if(acao == '4') {
      digitalWrite(13,0);
      Serial.println("Acao 2 chamada");
    }
    if(acao == '5') {
      digitalWrite(13,0);
      Serial.println("Acao 2 chamada");
    }
    
    if(acao == '6') {
      digitalWrite(13,0);
      Serial.println("Acao 2 chamada");
    }
    if(acao == '7') {
      digitalWrite(13,0);
      Serial.println("Acao 2 chamada");
    }
    if(acao == '8') {
      digitalWrite(13,0);
      Serial.println("Acao 2 chamada");
    }
    
    if(acao == '9') {
      digitalWrite(13,0);
      Serial.println("Acao 2 chamada");
    }
  }

}
