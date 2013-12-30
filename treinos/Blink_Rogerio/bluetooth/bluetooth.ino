byte BOTAO1 = 0;
byte BOTAO2 = 0;
byte BOTAO3 = 0;

byte RELE1 = 1;
byte RELE2 = 1;
byte RELE3 = 2;

byte porta_b1 = 22;
byte porta_b2 = 23;
byte porta_b3 = 24;

byte porta_r1 = 25;
byte porta_r2 = 26;
byte porta_r3 = 27;

void setup(){
  pinMode(porta_b1, INPUT);
  pinMode(porta_b2, INPUT);
  pinMode(porta_b3, INPUT);
  
  digitalWrite(porta_b1, 0);
  digitalWrite(porta_b2, 0);
  digitalWrite(porta_b3, 0);
  
  pinMode(porta_r1, OUTPUT);
  pinMode(porta_r2, OUTPUT);
  pinMode(porta_r3, OUTPUT);
  
  digitalWrite(porta_r1, 1);
  digitalWrite(porta_r2, 1);
  digitalWrite(porta_r3, 1);  
  Serial.begin(9600);
}

void loop(){
 
 BOTAO1 = digitalRead(porta_b1);
 BOTAO2 = digitalRead(porta_b2);
 BOTAO3 = digitalRead(porta_b3);
 
 char c = Serial.read();
  if(c == '1'){
   RELE1 = !RELE1;
   digitalWrite(porta_r1, RELE1);
  delay(100); 
  }
 
  if(c == '2'){
     RELE2 = !RELE2;
 digitalWrite(porta_r2, RELE2);
 delay(100); 
  }
  if(c == '3'){
     RELE3 = !RELE3;
 digitalWrite(porta_r3, RELE3);
  delay(100); 
  }
 
 
 delay(200);
}
