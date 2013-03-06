#include <IRremote.h>
#include <SoftwareSerial.h>

SoftwareSerial servidor(10, 11); // RX, TX

IRsend irsend;

#define LUZ1 23
#define LUZ2 25
#define LUZ3 27
#define LUZ4 28
#define LUZ5 31
#define LUZ6 33
#define LUZ7 35
#define LUZ8 37
#define LUZ9 39
#define LUZ10 41
#define LUZ11 43
#define LUZ12 45
#define LUZ13 47
#define LUZ14 49
#define LUZ15 51
#define LUZ16 53

// Configurando delay`s
int delay_botoes = 50;
int delay_programa = 100;



void setup()
{
    Serial.begin(9600);
    servidor.begin(9600);
    
    pinMode(LUZ1, OUTPUT);
    pinMode(LUZ2, OUTPUT);
    pinMode(LUZ3, OUTPUT);
    pinMode(LUZ4, OUTPUT);
    pinMode(LUZ5, OUTPUT);
    pinMode(LUZ6, OUTPUT);
    pinMode(LUZ7, OUTPUT);
    pinMode(LUZ8, OUTPUT);
    pinMode(LUZ9, OUTPUT);
    pinMode(LUZ10, OUTPUT);
    pinMode(LUZ11, OUTPUT);
    pinMode(LUZ12, OUTPUT);
    pinMode(LUZ13, OUTPUT);
    pinMode(LUZ14, OUTPUT);
    pinMode(LUZ15, OUTPUT);
    pinMode(LUZ16, OUTPUT);
    
    digitalWrite(LUZ1, 1);
    digitalWrite(LUZ2, 1);
    digitalWrite(LUZ3, 1);
    digitalWrite(LUZ4, 1);
    digitalWrite(LUZ5, 1);
    digitalWrite(LUZ6, 1);
    digitalWrite(LUZ7, 1);
    digitalWrite(LUZ8, 1);
    digitalWrite(LUZ9, 1);
    digitalWrite(LUZ10, 1);
    digitalWrite(LUZ11, 1);
    digitalWrite(LUZ12, 1);
    digitalWrite(LUZ13, 1);
    digitalWrite(LUZ14, 1);
    digitalWrite(LUZ15, 1);
    digitalWrite(LUZ16, 1);
    
    pinMode(9, OUTPUT);
    delay(40);
}

void loop()
{
  
  // Retorno dos dados do servidor
  String linha = "";
  servidor.listen();
  if (servidor.available() > 0) {
    char acao = servidor.read();
    
    Serial.println(acao);
    
    if(acao == 'a') {
      digitalWrite(LUZ1,0);
      Serial.println("LIGA LUZ1");
    }
    else if (acao =='b') {
      digitalWrite(LUZ1,1);
    }
    else if (acao =='c') {
      digitalWrite(LUZ2,0);
    }
     else if (acao =='d') {
      digitalWrite(LUZ2,1);
    }
     else if (acao =='e') {
      digitalWrite(LUZ3,0);
    }
     else if (acao =='f') {
      digitalWrite(LUZ3,1);
    }
    
    else {}
   
   
   
    
   
    
    
    
  }
}
