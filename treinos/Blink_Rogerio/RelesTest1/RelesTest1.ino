
byte BOTAO1 = 0;
byte BOTAO2 = 0;
byte BOTAO3 = 0;

byte RELE1 = 0;
byte RELE2 = 0;
byte RELE3 = 0;

byte porta_b1 = 22;
byte porta_b2 = 23;
byte porta_b3 = 24;

byte porta_r1 = 25;
byte porta_r2 = 26;
byte porta_r3 = 27;



void setup() {                
  // initialize the digital pin as an output.
  pinMode(porta_b1, INPUT);
  pinMode(porta_b2, INPUT);
  pinMode(porta_b3, INPUT);
  
  digitalWrite(porta_b1, 1);
  digitalWrite(porta_b2, 1);
  digitalWrite(porta_b3, 1);
  
  pinMode(porta_r1, OUTPUT);
  pinMode(porta_r2, OUTPUT);
  pinMode(porta_r3, OUTPUT);
  
  digitalWrite(porta_r1, 0);
  digitalWrite(porta_r2, 0);
  digitalWrite(porta_r3, 0);  
}

void loop() {
 BOTAO1 = digitalRead(porta_b1);
 BOTAO2 = digitalRead(porta_b2);
 BOTAO3 = digitalRead(porta_b3);
 
 
 if(BOTAO1 == 0){
  RELE1 = !RELE1;
 digitalWrite(porta_r1, RELE1);
  delay(100); 
 }
 
 if(BOTAO2 == 0){
  RELE2 = !RELE2;
 digitalWrite(porta_r2, RELE2);
  delay(100); 
 }
 
 if(BOTAO3 == 0){
  RELE3 = !RELE3;
 digitalWrite(porta_r3, RELE3);
  delay(100); 
 }
 
 delay(200);
  
}
