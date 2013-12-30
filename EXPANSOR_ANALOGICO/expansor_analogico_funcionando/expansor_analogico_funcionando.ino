
//Mux control pins
int s0 = 5;
int s1 = 6;
int s2 = 7;

//Mux in "SIG" pin
int SIG_pin = 0;


void setup(){
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
 
  Serial.begin(9600);
}


void loop(){

  //Loop through and read all 16 values
  //Reports back Value at channel 6 is: 346

  for(int i = 0; i < 8; i ++){
    Serial.print("Valor do Canal: ");
    Serial.print(i);
    Serial.print(" eh : ");
    Serial.println(readMux(i));
    delay(500);
  }
 
  

}


int readMux(int channel){
  int controlPin[] = {s0, s1, s2};

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

  //loop through the 4 sig
  for(int i = 0; i < 3; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }

  //read the value at the SIG pin
  int val = analogRead(SIG_pin);

  //return the value
  return val;
}
