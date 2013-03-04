int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;

int pin10 = 10;


void setup() {
  Serial.begin(9600);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin2,0);
  
}

void loop()
{
  if(Serial.available()){
    
   char c = Serial.read();
   switch(c) {
    case '1':
    digitalWrite(pin2, 1);
      break;
    case '2':
    digitalWrite(pin2, 0);
      break;
    case '3':
    digitalWrite(pin3, 1);
      break;
      case '4':
    digitalWrite(pin3, 0);
      break;
      case '5':
    digitalWrite(pin4, 1);
      break;
      case '6':
    digitalWrite(pin4, 0);
      break;
      case '7':
    digitalWrite(pin5, 1);
      break;
      case '8':
    digitalWrite(pin5, 0);
      break;
    case '9':
    digitalWrite(pin6, 1);
      break;
     case '0':
    digitalWrite(pin6, 0);
      break;
    
    case 'A':
    digitalWrite(pin7, 0);
      break;
      case 'a':
    digitalWrite(pin7, 1);
      break;
      
      
    case 'V':
    digitalWrite(pin10, 1);
      break;
      case 'v':
    digitalWrite(pin10, 0);
      break;
      
      
      
      
        
      
    
   }
 
   
   delay(100);
  }
}
