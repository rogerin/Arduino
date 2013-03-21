

void setup()

{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  
 
   Serial.println("Pinos configurados..");
  Serial.println("Iniciando Programa...");
}

void loop()
{
 
  // recebe dados da serial
  if(Serial.available())
  {
    char c = Serial.read();
    // a = DESLIGA RELE1
    if(c == 'A'){
      Serial.println("Ligando pin 2");
      digitalWrite(2,1);
  
     
    }
    else if(c == 'a')
    {
      Serial.println("desligando pin 2");
      digitalWrite(2,0);    
    }
    
    
    
    
  }
    
}
