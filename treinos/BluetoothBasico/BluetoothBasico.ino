#include <IRremote.h>
IRsend irsend;
// UNO
/*
  pinMode(porta_b1, INPUT);
  pinMode(porta_b2, INPUT);
  pinMode(porta_b3, INPUT);
  
  digitalWrite(porta_b1, 1);
  digitalWrite(porta_b2, 1);
  digitalWrite(porta_b3, 1);
  BOTAO1 = digitalRead(porta_b1);
  BOTAO2 = digitalRead(porta_b2);
  BOTAO3 = digitalRead(porta_b3);
   

*/

// Arduino MEGA
const int pinBotao1 = 22;
const int pinLuz1 = 23;
int btStado1 = 0;

const int pinBotao2 = 24;
const int pinLuz2 = 25;
int btStado2 = 0;

const int pinBotao3 = 26;
const int pinLuz3 = 27;
int btStado3 = 0;

const int pinBotao4 = 28;
const int pinLuz4 = 29;
int btStado4 = 0;


// Arduino MEGA
/*
const int portaVentilador = 34;
const int portaLuz1 = 35;
const int portaLuz2 = 36;
const int portaLuz3 = 37;
*/ 

void setup()
{
  Serial.begin(9600);
  pinMode(pinLuz1, OUTPUT);
  pinMode(pinLuz2, OUTPUT);
  pinMode(pinLuz3, OUTPUT);
  pinMode(pinLuz4, OUTPUT);
  
  pinMode(pinBotao1, INPUT);
  pinMode(pinBotao2, INPUT);
  pinMode(pinBotao3, INPUT);
  pinMode(pinBotao4, INPUT);
  
  pinMode(9, OUTPUT);
  
  
  
}
void loop() 
{
  btStado4 = digitalRead(pinBotao4);
       
       if(btStado4 == HIGH) {
         digitalWrite(pinLuz4, HIGH);
       } else {
         digitalWrite(pinLuz4, LOW);
       } 
       
  // Verifica se chega algo na serial.
  if(Serial.available())
  {
    // recebe dados da serial
    char c = Serial.read();
    
    // t = DESLIGA TUDO
    if(c == 't'){
       
    }
    
    
    // T = LIGA tudo
    else if(c == 'T')
    {
    } 
    else if(c == '1')
    {
        
    } 
    else if (c == '0'){
      digitalWrite(pinLuz4, 0);
    } 
    // luz 1 acoes
    else if (c == 'A'){
    } 
    else if (c == 'a'){
    }
    /// luz 1
    
    // luz 2
     
    else if (c == 'B'){
    } 
    else if (c == 'b'){
    }
    // luz 2
    
    // luz 3 
    else if (c == 'D'){
    } 
    else if (c == 'd'){
    }
    // luz 3
    
    // l = Codigo de On/Off da TV
    else if(c == 'l') {
      Serial.println("Liga TV");
      for (int i = 0; i < 1; i++) {
        irsend.sendNEC(0x8076807F, 32); 
        delay(100);
      }  
    }
    
    // V = envia codigo aumenta volume da tv
    else if (c == 'V') {
     Serial.println("Volume ++");
     for (int i = 0; i < 1; i++) {
      irsend.sendNEC(0x80767887, 32); 
      delay(100);
      }
    }
  
    // v = envia codigo baixa volume da tv
     else if(c == 'v'){
      Serial.println("Volume --");
      for (int i = 0; i < 1; i++) {
        irsend.sendNEC(0x8076F807, 32); 
        delay(100);
      }
    }
  
    // V = envia codigo muda de canal para mais tv
    else if(c == 'C'){
      Serial.println("Canal ++");
      for (int i = 0; i < 1; i++) {
        irsend.sendNEC(0x807620DF, 32); 
        delay(100);
      }
    }
    
    
    // V = envia codigo muda de canal para menos tv
     else if(c == 'c'){
      Serial.println("Canal --");
      for (int i = 0; i < 1; i++) {
        irsend.sendNEC(0x8076A05F, 32); 
        delay(100);
      }
    }
  }
}
