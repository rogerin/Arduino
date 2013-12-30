//Mux control pins
int s00 = 5;
int s01 = 6;
int s02 = 7;
int s10 = 8;
int s11 = 9;
int s12 = 10;

//Mux in "SIG" pin
int SIG_pin = A0;

void setup(){
  pinMode(s00, OUTPUT); 
  pinMode(s01, OUTPUT); 
  pinMode(s02, OUTPUT); 
  pinMode(s10, OUTPUT); 
  pinMode(s11, OUTPUT); 
  pinMode(s12, OUTPUT);
 
  
  digitalWrite(s00, LOW);
  digitalWrite(s01, LOW);
  digitalWrite(s02, LOW);
  digitalWrite(s10, LOW);
  digitalWrite(s11, LOW);
  digitalWrite(s12, LOW);
  Serial.begin(9600);
}

void loop(){

   Serial.print("CI1 pin1: ");
   Serial.println(readMux(1,0));
   
   delay(400);
   /*
   Serial.print("CI1 pin2: ");
   Serial.println(readMux(1,1));
   delay(400);
   Serial.print("CI1 pin3: ");
   Serial.println(readMux(1,2));
   Serial.print("CI1 pin4: ");
   Serial.println(readMux(1,3));
   Serial.print("CI1 pin5: ");
   Serial.println(readMux(1,4));
   */
   delay(400);
   
    
}
int readMux(int principal, int secundario){
  int controlPin0[] = {s00, s01, s02};
  int controlPin1[] = {s10, s11, s12};

  //pode-se usar um vetor para armazenar os 3 valores e depois fazer um laço FOR p/ escrever
  bool pr0 = bitRead(principal, 0);
  bool pr1 = bitRead(principal, 1);
  bool pr2 = bitRead(principal, 2);

  bool sec0 = bitRead(secundario, 0); 
  bool sec1 = bitRead(secundario, 1);
  bool sec2 = bitRead(secundario, 2);

 //Se estiverem como vetor, pode-se usar um laço FOR aqui para escrever os 3 valores
 digitalWrite(controlPin0[0], pr0);
 digitalWrite(controlPin0[1], pr1);
 digitalWrite(controlPin0[2], pr2);

 digitalWrite(controlPin1[0], sec0);  
 digitalWrite(controlPin1[1], sec1);  
 digitalWrite(controlPin1[2], sec2);  

  //read the value at the SIG pin
  int val = analogRead(SIG_pin);

  //return the value
  return val;
}

