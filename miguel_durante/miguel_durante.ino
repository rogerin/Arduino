#include <Bounce.h>


int MILIS_ESPERA = 400; // aumenta para os testes ate chegar em um valor correto.

int statusRele[] = {LOW,LOW};
int RELES[] = {7,8};
int botoes[] = {2,3};

int repeticao = 0;
boolean start = false;

unsigned long startTimer = 0;
unsigned long endTimer;

unsigned long  present; 




Bounce botao_radio = Bounce (botoes[0], MILIS_ESPERA);
Bounce botao_fixo = Bounce (botoes[1], MILIS_ESPERA);



int status_radio = 0;
int status_fixo  = 0;

long previousMillis = 0;        // will store last time LED was updated
long previousMillis2 = 0;        // will store last time LED was updated

long interval = 1000;           // interval at which to blink (milliseconds)
long intervalParte1 = 12000;

void setup(){
  Serial.begin(9600);
  Serial.println("Iniciando...");
  Serial.println("Configurando RELES...");
  
  pinMode(RELES[0],OUTPUT);
  pinMode(RELES[1],OUTPUT);
  
  Serial.println("Configurando BOTOES...");
  pinMode(botoes[0],INPUT);
  pinMode(botoes[1],INPUT);
  
  Serial.println("PULL-UP Interno nos botoes.");
  digitalWrite(botoes[0], HIGH);
  digitalWrite(botoes[1], HIGH);
  
  Serial.println("Iniciado!");
  
}


void loop (){

  if ( botao_radio.update() ) {
    if ( botao_radio.read() == 1) {
      if ( status_radio == 0 ) {
        status_radio = 1;
      }
    }
  }
  
  if ( botao_fixo.update() ) {
    if ( botao_fixo.read() == 1) {
       status_fixo = 1;
    }
  }
  
  unsigned long currentMillis = millis();
  
 if(status_fixo == 1) {
   statusRele[1] = HIGH;
   digitalWrite(RELES[1], statusRele[1]);

  if ( start) {
    previousMillis = 0;
  } else {
    if(currentMillis - previousMillis > interval) {

      previousMillis = currentMillis;  
  

      if (statusRele[0] == LOW){ 
        statusRele[0] = HIGH;
        Serial.println("LIGA RELE1.");
        repeticao = repeticao + 1;
      }
      else {
        statusRele[0] = LOW;
         Serial.println("DESLIGA RELE1.");
        repeticao = repeticao + 1;
      }
      
      if(repeticao == 10) {
        start = true;
      }

      digitalWrite(RELES[0], statusRele[0]);
    }    
  }
  
   Serial.print("Numero de LOOP: ");
   Serial.print(repeticao);
   Serial.println();

  if (currentMillis - previousMillis2 > 1200){
    previousMillis2 = currentMillis;
    

  } else {
     statusRele[0] = LOW;
    statusRele[1] = LOW;
    digitalWrite(RELES[0], statusRele[0]);
    digitalWrite(RELES[1], statusRele[1]);
    Serial.println("DEsliga rele.");
    status_fixo = 0;
  }
 }
 
   
 
 }
