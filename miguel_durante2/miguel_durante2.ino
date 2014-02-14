#include <Bounce.h>

int RELES[] = {7,8};
int botoes[] = {2,3};
int status_radio = 0;
int status_fixo  = 0;

int delay_min = 4000;
int delay_max = 92000;

int MILIS_ESPERA = 800; // !IMPORTANTE: aqui é o tempo em millis segundo do sistema debounce.

Bounce botao_radio = Bounce (botoes[0], MILIS_ESPERA);
Bounce botao_fixo = Bounce (botoes[1], MILIS_ESPERA);

void setup() {
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


void loop() {
   if ( botao_radio.update() ) {
    if ( botao_radio.read() == 1) {
      Serial.println("RADIO HIGH");
      if ( status_radio == 0 ) {
        status_radio = 1;
      }
    } else {
      Serial.println("RADIO LOW");
    }
  }

  if ( botao_fixo.update() ) {
    if ( botao_fixo.read() == 1) {
       Serial.println("FIXO HIGH");
       status_fixo = 1;
    } else {
       Serial.println("FIXO LOW");
    }
  }
  
  if(status_fixo == 1) {
    digitalWrite(RELES[1],HIGH);
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);
    delay(delay_min);
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);
    delay(delay_min);
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);
    delay(delay_min);
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);
    delay(delay_max);
    digitalWrite(RELES[1],LOW);    
    status_fixo = 0;
  }
  
  if(status_radio == 1) {
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);
    delay(delay_min);
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);
    delay(delay_min);
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);
    delay(delay_min);
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);
    delay(delay_min);
    digitalWrite(RELES[0],HIGH);
    delay(delay_min);
    digitalWrite(RELES[0],LOW);   
    status_radio = 0;
  }
  
}
