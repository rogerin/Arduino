

int pin2 = 24;
int pin3 = 26;
int pin4 = 28;
int pin5 = 30;
int pin6 = 32;
int pin7 = 34;
int pin8 = 36;
int pin9 = 38;


int tempo = 400;


char c;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);

  digitalWrite(pin2, 1);
  digitalWrite(pin3, 1);
  digitalWrite(pin4, 1);
  digitalWrite(pin5, 1);
  digitalWrite(pin6, 1);
  digitalWrite(pin7, 1);
  digitalWrite(pin8, 1);
  digitalWrite(pin9, 1);
  
  Serial.begin(9600);

}

// the loop routine runs over and over again forever:
void loop() {
   umporum();  
  /*
  
  if(Serial.available()>0){
    c = Serial.read();
    
    if(c == '1'){
      
      pisca();
      
    
    } 
    if(c == '2'){
      umporum();  
    }
    
    if(c == '3'){
      digitalWrite(ledAmarelo, 1);
    
    } 
    if(c == '4'){
      digitalWrite(ledAmarelo, 0);  
    }
    
    
  
  }
  
  
  digitalWrite(ledVerde, 1);
  delay(10000);
  digitalWrite(ledVerde, 0);  
  digitalWrite(ledAmarelo, 1);    
  delay(4000);              
 digitalWrite(ledAmarelo, 0);
 digitalWrite(ledVermelho, 1);
 delay(6000);
 digitalWrite(ledVermelho, 0);
 */
}

void pisca()
{
 
      digitalWrite(pin2, 1);
      digitalWrite(pin3, 1);
      digitalWrite(pin4, 1);
      digitalWrite(pin5, 1);
      digitalWrite(pin6, 1);
      digitalWrite(pin7, 1);
      digitalWrite(pin8, 1);
      digitalWrite(pin9, 1);

      
     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
      digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);


     delay(tempo);
     
}

void umporum()
{
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
      digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);


      
     delay(tempo);
      digitalWrite(pin2, 1);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
      digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);


     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 1);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
      digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);


     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 1);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
      digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 1);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
      digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 1);
      digitalWrite(pin7, 0);
       digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 1);
            digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
            digitalWrite(pin8, 1);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
            digitalWrite(pin8, 0);
      digitalWrite(pin9, 1);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
            digitalWrite(pin8, 1);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 1);
            digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 1);
      digitalWrite(pin7, 0);
            digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 1);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
            digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 1);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
            digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

      
     delay(tempo);
      digitalWrite(pin2, 0);
      digitalWrite(pin3, 1);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
            digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

     delay(tempo);
      digitalWrite(pin2, 1);
      digitalWrite(pin3, 0);
      digitalWrite(pin4, 0);
      digitalWrite(pin5, 0);
      digitalWrite(pin6, 0);
      digitalWrite(pin7, 0);
            digitalWrite(pin8, 0);
      digitalWrite(pin9, 0);

    
  
}
