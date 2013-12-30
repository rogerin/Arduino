//Mux control pins
int s00 = 5;
int s01 = 6;
int s02 = 7;
int s10 = 8;
int s11 = 9;
int s12 = 10;

//Mux in "SIG" pin
int SIG_pin = 0;

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

  //Loop through and read all 16 values
  //Reports back Value at channel 6 is: 346
  //Principal fazer iteração de 0 até numero de secundarios a usar (no seu teste = 2)
 /*for(int princ = 0; princ < 8; princ ++){
  //Secundária, fazer o loop de 0 a 8
  for(int sec = 0; sec < 8; sec ++){
    Serial.print("Valor do Canal: ");
    Serial.print(princ,sec);
    Serial.print(" eh : ");
    Serial.println(readMux(princ,sec));
    delay(500);
   }
  }
*/


 Serial.print("0,0 : ");
 Serial.print(readMux(0,0));
 Serial.println("");
 
 Serial.print("0,1 : ");
 Serial.print(readMux(0,1));
 Serial.println("");
 
 Serial.print("0,2 : ");
 Serial.print(readMux(0,2));
 Serial.println("");
 
 
 Serial.print("0,3 : ");
 Serial.print(readMux(0,3));
 Serial.println("");
 
 Serial.print("0,4 : ");
 Serial.print(readMux(0,4));
 Serial.println("");
 
 
 Serial.print("1,0 : ");
 Serial.print(readMux(1,0));
 Serial.println("");
 
 Serial.print("1,1 : ");
 Serial.print(readMux(1,1));
 Serial.println("");
 
 Serial.print("1,2 : ");
 Serial.print(readMux(1,2));
 Serial.println("");
 
 
 Serial.print("1,3 : ");
 Serial.print(readMux(1,3));
 Serial.println("");
 
 Serial.print("1,4 : ");
 Serial.print(readMux(1,4));
 Serial.println("");
 
 delay(500);
   
}
int readMux(int principal, int secundario){
  int controlPin0[] = {s00, s01, s02};
  int controlPin1[] = {s10, s11, s12};

  int muxChannel[8][3]={
    {0,0,0}, //channel 0
    {1,0,0}, //channel 1
    {0,1,0}, //channel 2
    {1,1,0}, //channel 3
    {0,0,1}, //channel 4
    {1,0,1}, //channel 5
    {0,1,1}, //channel 6
    {1,1,1}  //channel 7
  };

  //loop through the 3 sig
 for(int i = 0; i < 3; i ++){
 digitalWrite(controlPin0[i], muxChannel[principal][i]);
   for(int ii = 0; ii < 3; ii ++){
     digitalWrite(controlPin1[ii], muxChannel[secundario][ii]);
    }
  }

  
  //read the value at the SIG pin
  int val = analogRead(SIG_pin);

  //return the value
  return val;
}

