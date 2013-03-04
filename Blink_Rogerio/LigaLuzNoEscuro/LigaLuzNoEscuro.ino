int pinDetecta  = A0;
int pinLed      = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(pinDetecta, INPUT);
  digitalWrite(pinLed, 0);
}

void loop()
{
     int valor = analogRead(pinDetecta);
     Serial.println(valor);
     
     if(valor < 200){
       
       digitalWrite(pinLed, 1);
     
     }
     if(valor > 200){
        digitalWrite(pinLed, 0);
     }
 
}
