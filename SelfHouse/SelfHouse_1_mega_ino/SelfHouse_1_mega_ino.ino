#include <IRremote.h>
#include <Bounce.h>
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

#define BUTTON1 22
#define BUTTON2 24
#define BUTTON3 26
#define BUTTON4 28
#define BUTTON5 30
#define BUTTON6 32
#define BUTTON7 34
#define BUTTON8 36
#define BUTTON9 38
#define BUTTON10 40
#define BUTTON11 42
#define BUTTON12 44
#define BUTTON13 46
#define BUTTON14 48
#define BUTTON15 50
#define BUTTON16 52

int RELE1 = HIGH;
int RELE2 = HIGH;
int RELE3 = HIGH;
int RELE4 = HIGH;
int RELE5 = HIGH;
int RELE6 = HIGH;
int RELE7 = HIGH;
int RELE8 = HIGH;
int RELE9 = HIGH;
int RELE10 = HIGH;
int RELE11 = HIGH;
int RELE12 = HIGH;
int RELE13 = HIGH;
int RELE14 = HIGH;
int RELE15 = HIGH;
int RELE16 = HIGH;
int RELE17 = HIGH;
int RELE18 = HIGH;
int RELE19 = HIGH;
int RELE20 = HIGH;

// Configurando delay`s
int delay_botoes = 50;
int delay_programa = 100;

Bounce bon1 = Bounce( BUTTON1, 10 ); 
Bounce bon2 = Bounce( BUTTON2, 10 ); 
Bounce bon3 = Bounce( BUTTON3, 10 );
Bounce bon4 = Bounce( BUTTON4, 10 );
Bounce bon5 = Bounce( BUTTON5, 10 );
Bounce bon6 = Bounce( BUTTON6, 10 );
Bounce bon7 = Bounce( BUTTON7, 10 );
Bounce bon8 = Bounce( BUTTON8, 10 );
Bounce bon9 = Bounce( BUTTON9, 10 );
Bounce bon10 = Bounce( BUTTON10, 10 );
Bounce bon11 = Bounce( BUTTON11, 10 );
Bounce bon12 = Bounce( BUTTON12, 10 );
Bounce bon13 = Bounce( BUTTON13, 10 );
Bounce bon14 = Bounce( BUTTON14, 10 );
Bounce bon15 = Bounce( BUTTON15, 10 );
Bounce bon16 = Bounce( BUTTON16, 10 );


void setup()
{
    Serial.begin(9600);
    servidor.begin(9600);
        pinMode(13, OUTPUT);
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(BUTTON3, INPUT);
    pinMode(BUTTON4, INPUT);
    pinMode(BUTTON5, INPUT);
    pinMode(BUTTON6, INPUT);
    pinMode(BUTTON7, INPUT);
    pinMode(BUTTON8, INPUT);
    pinMode(BUTTON9, INPUT);
    pinMode(BUTTON10, INPUT);
    pinMode(BUTTON11, INPUT);
    pinMode(BUTTON12, INPUT);
    pinMode(BUTTON13, INPUT);
    pinMode(BUTTON14, INPUT);
    pinMode(BUTTON15, INPUT);
    pinMode(BUTTON16, INPUT);
    digitalWrite(BUTTON1, HIGH);
    digitalWrite(BUTTON2, HIGH);
    digitalWrite(BUTTON3, HIGH);
    digitalWrite(BUTTON4, HIGH);
    digitalWrite(BUTTON5, HIGH);
    digitalWrite(BUTTON6, HIGH);
    digitalWrite(BUTTON7, HIGH);
    digitalWrite(BUTTON8, HIGH);
    digitalWrite(BUTTON9, HIGH);
    digitalWrite(BUTTON10, HIGH);
    digitalWrite(BUTTON11, HIGH);
    digitalWrite(BUTTON12, HIGH);
    digitalWrite(BUTTON13, HIGH);
    digitalWrite(BUTTON14, HIGH);
    digitalWrite(BUTTON15, HIGH);
    digitalWrite(BUTTON16, HIGH);
    pinMode(9, OUTPUT);
    delay(40);
}

void loop()
{
  if ( bon1.update() ) {
     if ( bon1.read() == HIGH) {
       if ( RELE1 == LOW ) {
         RELE1 = HIGH;
         Serial.println("RELE1 ATIVADO");
       } else {
         RELE1 = LOW;
         Serial.println("RELE1 DESATIVADO");
       }
       digitalWrite(LUZ1, RELE1);
     }
   }  
   if ( bon2.update() ) {
     if ( bon2.read() == HIGH) {
       if ( RELE2 == LOW ) {
         RELE2 = HIGH;
          Serial.println("RELE2 ATIVADO");
       } else {
         RELE2 = LOW;
         Serial.println("RELE2 DESATIVADO");
       }
       digitalWrite(LUZ2,RELE2);
     }
   }
   
   if ( bon3.update() ) {
     if ( bon3.read() == HIGH) {
       if ( RELE3 == LOW ) {
         RELE3 = HIGH;
          Serial.println("RELE3 ATIVADO");
       } else {
         RELE3 = LOW;
         Serial.println("RELE3 DESATIVADO");
       }
       digitalWrite(LUZ3,RELE3);
     }
   }
   
   if ( bon4.update() ) {
     if ( bon4.read() == HIGH) {
       if ( RELE4 == LOW ) {
         RELE4 = HIGH;
          Serial.println("RELE4 ATIVADO");
       } else {
         RELE4 = LOW;
         Serial.println("RELE4 DESATIVADO");
       }
       digitalWrite(LUZ4,RELE4);
     }
   }
   
   if ( bon5.update() ) {
     if ( bon5.read() == HIGH) {
       if ( RELE5 == LOW ) {
         RELE5 = HIGH;
          Serial.println("RELE5 ATIVADO");
       } else {
         RELE5 = LOW;
         Serial.println("RELE5 DESATIVADO");
       }
       digitalWrite(LUZ5,RELE5);
     }
   }
   
   if ( bon6.update() ) {
     if ( bon6.read() == HIGH) {
       if ( RELE6 == LOW ) {
         RELE6 = HIGH;
          Serial.println("RELE6 ATIVADO");
       } else {
         RELE6 = LOW;
         Serial.println("RELE6 DESATIVADO");
       }
       digitalWrite(LUZ6,RELE6);
     }
   }
   
   if ( bon7.update() ) {
     if ( bon7.read() == HIGH) {
       if ( RELE7 == LOW ) {
         RELE7 = HIGH;
          Serial.println("RELE7 ATIVADO");
       } else {
         RELE7 = LOW;
         Serial.println("RELE7 DESATIVADO");
       }
       digitalWrite(LUZ7,RELE7);
     }
   }
   
   if ( bon8.update() ) {
     if ( bon8.read() == HIGH) {
       if ( RELE8 == LOW ) {
         RELE8 = HIGH;
          Serial.println("RELE8 ATIVADO");
       } else {
         RELE8 = LOW;
         Serial.println("RELE8 DESATIVADO");
       }
       digitalWrite(LUZ8,RELE8);
     }
   }
   
   if ( bon9.update() ) {
     if ( bon9.read() == HIGH) {
       if ( RELE9 == LOW ) {
         RELE9 = HIGH;
          Serial.println("RELE9 ATIVADO");
       } else {
         RELE9 = LOW;
         Serial.println("RELE9 DESATIVADO");
       }
       digitalWrite(LUZ9,RELE9);
     }
   }
   
   if ( bon10.update() ) {
     if ( bon10.read() == HIGH) {
       if ( RELE10 == LOW ) {
         RELE10 = HIGH;
          Serial.println("RELE10 ATIVADO");
       } else {
         RELE10 = LOW;
         Serial.println("RELE10 DESATIVADO");
       }
       digitalWrite(LUZ10,RELE10);
     }
   }
   
   if ( bon11.update() ) {
     if ( bon11.read() == HIGH) {
       if ( RELE11 == LOW ) {
         RELE11 = HIGH;
          Serial.println("RELE11 ATIVADO");
       } else {
         RELE11 = LOW;
         Serial.println("RELE11 DESATIVADO");
       }
       digitalWrite(LUZ11,RELE11);
     }
   }
   
   if ( bon12.update() ) {
     if ( bon12.read() == HIGH) {
       if ( RELE12 == LOW ) {
         RELE12 = HIGH;
          Serial.println("RELE12 ATIVADO");
       } else {
         RELE12 = LOW;
         Serial.println("RELE12 DESATIVADO");
       }
       digitalWrite(LUZ12,RELE12);
     }
   }
   
   if ( bon13.update() ) {
     if ( bon13.read() == HIGH) {
       if ( RELE13 == LOW ) {
         RELE13 = HIGH;
          Serial.println("RELE13 ATIVADO");
       } else {
         RELE13 = LOW;
         Serial.println("RELE13 DESATIVADO");
       }
       digitalWrite(LUZ13,RELE13);
     }
   }
   
   if ( bon14.update() ) {
     if ( bon14.read() == HIGH) {
       if ( RELE14 == LOW ) {
         RELE14 = HIGH;
          Serial.println("RELE14 ATIVADO");
       } else {
         RELE14 = LOW;
         Serial.println("RELE14 DESATIVADO");
       }
       digitalWrite(LUZ14,RELE14);
     }
   }
   
   if ( bon15.update() ) {
     if ( bon15.read() == HIGH) {
       if ( RELE15 == LOW ) {
         RELE15 = HIGH;
          Serial.println("RELE15 ATIVADO");
       } else {
         RELE15 = LOW;
         Serial.println("RELE15 DESATIVADO");
       }
       digitalWrite(LUZ15,RELE15);
     }
   }
   
   if ( bon16.update() ) {
     if ( bon16.read() == HIGH) {
       if ( RELE16 == LOW ) {
         RELE16 = HIGH;
          Serial.println("RELE16 ATIVADO");
       } else {
         RELE16 = LOW;
         Serial.println("RELE16 DESATIVADO");
       }
       digitalWrite(LUZ16,RELE16);
     }
   }

  // Retorno dos dados do servidor
  String linha = "";
  servidor.listen();
  if (servidor.available() > 0) {
    char acao = servidor.read();
    
    Serial.println(acao);
    
    if(acao == 'a') {
      digitalWrite(13,1);
      Serial.println("Acao 001 recebida.");
    }
    else if (acao =='b') {
      digitalWrite(13,0);
      Serial.println("Acao 001 recebida.");
    }
    
  }
}
