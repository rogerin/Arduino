#include <IRremote.h>
IRsend irsend;

byte BOTAO1 = 0;
byte BOTAO2 = 0;
byte BOTAO3 = 0;
byte BOTAO4 = 0;
byte BOTAO5 = 0;
byte BOTAO6 = 0;

byte RELE1 = 0;
byte RELE2 = 0;
byte RELE3 = 0;
byte RELE4 = 0;
byte RELE5 = 0;
byte RELE6 = 0;


// Arduino UNO
/*
byte porta_botao1 = 6;
byte porta_botao2 = 5;
byte porta_botao3 = 4;
byte porta_botao4 = 3;


byte porta_rele1 = 12;
byte porta_rele2 = 11;
byte porta_rele3 = 10;
byte porta_rele4 = 8;
*/



// Arduino MEGA

byte porta_botao1 = 53;
byte porta_botao2 = 52;
byte porta_botao3 = 51;
byte porta_botao4 = 50;
byte porta_botao5 = 49;
byte porta_botao6 = 50;


byte porta_rele1 = 22;
byte porta_rele2 = 23;
byte porta_rele3 = 24;
byte porta_rele4 = 25;
byte porta_rele5 = 26;
byte porta_rele6 = 27;



// Configurando delay`s
int delay_botoes = 50;
int delay_programa = 100;



void setup()

{
  Serial.begin(9600);
  Serial.println("Configurando Botões");
  // CONFIGURANDO BOTOES
  pinMode(porta_botao1, INPUT);
  pinMode(porta_botao2, INPUT);
  pinMode(porta_botao3, INPUT);
  pinMode(porta_botao4, INPUT);
  pinMode(porta_botao5, INPUT);
  pinMode(porta_botao6, INPUT);
  
  
  
  Serial.println("Ativando Botões");
  // ATIVANDO BOTOES
  digitalWrite(porta_botao1, 1);
  digitalWrite(porta_botao2, 1);
  digitalWrite(porta_botao3, 1);
  digitalWrite(porta_botao4, 1);
  digitalWrite(porta_botao5, 1);
  digitalWrite(porta_botao6, 1);
  
  
  
  Serial.println("Configurando RELÉS");
  // CONFIGURANDO RELÉS
  pinMode(porta_rele1, OUTPUT);
  pinMode(porta_rele2, OUTPUT);
  pinMode(porta_rele3, OUTPUT);
  pinMode(porta_rele4, OUTPUT);
  pinMode(porta_rele5, OUTPUT);
  pinMode(porta_rele6, OUTPUT);
  
  Serial.println("Configurando Estado inicial dos Relés");
  // ESTADO INICIAL DOS RELÉS
  digitalWrite(porta_rele1, RELE1);
  digitalWrite(porta_rele2, RELE2);
  digitalWrite(porta_rele3, RELE3);
  digitalWrite(porta_rele4, RELE4);
  digitalWrite(porta_rele5, RELE5);
  digitalWrite(porta_rele6, RELE6);

  Serial.println("Configurando infravermelho...");
  pinMode(9, OUTPUT);
  
  Serial.println("Iniciando Programa...");
}

void loop()
{
  BOTAO1 = digitalRead(porta_botao1);
  BOTAO2 = digitalRead(porta_botao2);
  BOTAO3 = digitalRead(porta_botao3);
  BOTAO4 = digitalRead(porta_botao4);
  BOTAO5 = digitalRead(porta_botao5);
  BOTAO6 = digitalRead(porta_botao6);
  
  
   
  if(BOTAO1 == 0){
    Serial.println("Botao 1 pressionado");
    RELE1 = !RELE1;
    digitalWrite(porta_rele1, RELE1);
    delay(delay_botoes); 
  }
   
  if(BOTAO2 == 0){
    Serial.println("Botao 2 pressionado");
    RELE2 = !RELE2;
    digitalWrite(porta_rele2, RELE2);
    delay(delay_botoes); 
  }
   
  if(BOTAO3 == 0){
    Serial.println("Botao 3 pressionado");
    RELE3 = !RELE3;
    digitalWrite(porta_rele3, RELE3);
    delay(delay_botoes); 
  }
  if(BOTAO4 == 0){
    Serial.println("Botao 4 pressionado");
    RELE4 = !RELE4;
    digitalWrite(porta_rele4, RELE4);
    delay(delay_botoes); 
  }
  if(BOTAO5 == 0){
    Serial.println("Botao 5 pressionado");
    RELE5 = !RELE5;
    digitalWrite(porta_rele5, RELE5);
    delay(delay_botoes); 
  }
  if(BOTAO6 == 0){
    Serial.println("Botao 6 pressionado");
    RELE6 = !RELE6;
    digitalWrite(porta_rele6, RELE6);
    delay(delay_botoes); 
  }
  
  // recebe dados da serial
  if(Serial.available())
  {
    char c = Serial.read();
    // a = DESLIGA RELE1
    if(c == 'a'){
      Serial.println("Desligando rele 1");
      RELE1 = 1;
      digitalWrite(porta_rele1, RELE1);
      delay(delay_botoes); 
    }
    
    // A = LIGA RELE1
    else if(c == 'A')
    {
      Serial.println("Ligando rele 1");
      RELE1 = 0;
      digitalWrite(porta_rele1, RELE1);
      delay(delay_botoes); 
    }
    
    // b = DESLIGA RELE2
    else if(c == 'b')
    {
      Serial.println("Desligando rele 2");
      RELE2 = 1;
      digitalWrite(porta_rele2, RELE2);
      delay(delay_botoes); 
    }
    // B = LIGA RELE2
    else if(c == 'B')
    {
      Serial.println("Ligando rele 2");
      RELE2 = 0;
      digitalWrite(porta_rele2, RELE2);
      delay(delay_botoes); 
    }
    // c = DESLIGA RELE3
    else if(c == 'c')
    {
      Serial.println("Desligando rele 3");
      RELE3 = 1;
      digitalWrite(porta_rele3, RELE3);
      delay(delay_botoes); 
    }
    // C = LIGA RELE3
    else if(c == 'C')
    {
      Serial.println("Ligando rele 3");
      RELE3 = 0;
      digitalWrite(porta_rele3, RELE3);
      delay(delay_botoes); 
    }
    // e = DESLIGA RELE4
    else if(c == 'e')
    {
      Serial.println("Desligando rele 4");
      RELE4 = 1;
      digitalWrite(porta_rele4, RELE4);
      delay(delay_botoes); 
    }
    // C = LIGA RELE4
    else if(c == 'E')
    {
      Serial.println("Ligando rele 4");
      RELE4 = 0;
      digitalWrite(porta_rele4, RELE4);
      delay(delay_botoes); 
    }
    // f = DESLIGA RELE5
    else if(c == 'f')
    {
      Serial.println("Desligando rele 5");
      RELE5 = 1;
      digitalWrite(porta_rele5, RELE5);
      delay(delay_botoes); 
    }
    // F = LIGA RELE5
    else if(c == 'F')
    {
      Serial.println("Ligando rele 5");
      RELE5 = 0;
      digitalWrite(porta_rele5, RELE5);
      delay(delay_botoes); 
    }
    
    // g = DESLIGA RELE6
    else if(c == 'g')
    {
      Serial.println("Desligando rele 6");
      RELE6 = 1;
      digitalWrite(porta_rele6, RELE6);
      delay(delay_botoes); 
    }
    // G = LIGA RELE6
    else if(c == 'G')
    {
      Serial.println("Ligando rele 6");
      RELE6 = 0;
      digitalWrite(porta_rele6, RELE6);
      delay(delay_botoes); 
    }
    
    // H = DESLIGA Cena
    else if(c == 'H')
    {
      Serial.println("Cena 1 desliga");
      RELE6 = 1;
      digitalWrite(porta_rele6, RELE6);
      
      RELE4 = 1;
      digitalWrite(porta_rele4, RELE4);
      
      delay(delay_botoes); 
    }
    // f = LIGA RELE6
    else if(c == 'h')
    {
      Serial.println("Cena 1 liga");
      RELE6 = 0;
      digitalWrite(porta_rele6, RELE6);
      
      RELE4 = 0;
      digitalWrite(porta_rele4, RELE4);
      
      delay(delay_botoes); 
    }
    
    // I = DESLIGA Cena
    else if(c == 'I')
    {
      Serial.println("Cena 2 desliga");
      RELE2 = 1;
      digitalWrite(porta_rele2, RELE2);
      
      RELE3 = 1;
      digitalWrite(porta_rele3, RELE3);
      
      delay(delay_botoes); 
    }
    // f = LIGA RELE6
    else if(c == 'i')
    {
      Serial.println("Cena 2 liga");
      RELE2 = 0;
      digitalWrite(porta_rele2, RELE2);
      
      RELE3 = 0;
      digitalWrite(porta_rele3, RELE3);
      
      delay(delay_botoes); 
    }
    
    
    // T = DESLIGA Tudo
    else if(c == 'T')
    {
      Serial.println("desliga tudo");
      
      RELE1 = 1;
      RELE2 = 1;
      RELE3 = 1;
      RELE4 = 1;
      RELE5 = 1;
      RELE6 = 1;
      
      digitalWrite(porta_rele1, RELE1);
      digitalWrite(porta_rele2, RELE2);
      digitalWrite(porta_rele3, RELE3);
      digitalWrite(porta_rele4, RELE4);
      digitalWrite(porta_rele5, RELE5);
      digitalWrite(porta_rele6, RELE6);
      
      delay(delay_botoes); 
    }
    // t = LIGA tudo
    else if(c == 't')
    {
      Serial.println("Cena 1 liga");
      
      RELE1 = 0;
      RELE2 = 0;
      RELE3 = 0;
      RELE4 = 0;
      RELE5 = 0;
      RELE6 = 0;
      
      digitalWrite(porta_rele1, RELE1);
      digitalWrite(porta_rele2, RELE2);
      digitalWrite(porta_rele3, RELE3);
      digitalWrite(porta_rele4, RELE4);
      digitalWrite(porta_rele5, RELE5);
      digitalWrite(porta_rele6, RELE6);
      
      
      delay(delay_botoes); 
    }
    
   
    
    // l = Codigo de On/Off da TV
    else if(c == 'l') {
      Serial.println("Liga TV");
      for (int i = 0; i < 1; i++) {
        irsend.sendNEC(0x8076807F, 32); 
        delay(100);
      }  
    }
    
    // V = envia codigo aumenta volume da tv
    else if (c == 'U') {
     Serial.println("Volume ++");
     for (int i = 0; i < 1; i++) {
      irsend.sendNEC(0x80767887, 32); 
      delay(100);
      }
    }
  
    // v = envia codigo baixa volume da tv
     else if(c == 'u'){
      Serial.println("Volume --");
      for (int i = 0; i < 1; i++) {
        irsend.sendNEC(0x8076F807, 32); 
        delay(100);
      }
    }
  
    // V = envia codigo muda de canal para mais tv
    else if(c == 'M'){
      Serial.println("Canal ++");
      for (int i = 0; i < 1; i++) {
        irsend.sendNEC(0x807620DF, 32); 
        delay(100);
      }
    }
    
    // V = envia codigo muda de canal para menos tv
     else if(c == 'm'){
      Serial.println("Canal --");
      for (int i = 0; i < 1; i++) {
        irsend.sendNEC(0x8076A05F, 32); 
        delay(100);
      }
    }
  }
    delay(delay_programa);
}
