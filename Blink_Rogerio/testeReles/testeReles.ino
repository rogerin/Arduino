int velocidade = 200;
void setup()
{
 
  for (int i=30; i <= 39; i++){
     pinMode(i, OUTPUT);
   } 
   
 for (int i=30; i <= 39; i++){
     digitalWrite(i, 0);
     
   }
}

void loop()
{
  
  for (int i=30; i <= 39; i++){
     digitalWrite(i, 1);
     delay(velocidade);
   } 
  for (int i=32; i <= 39; i++){
     digitalWrite(i, 0);
     delay(velocidade);
   }

  for (int i=39; i >= 30; i--){
     digitalWrite(i, 1);
     delay(velocidade);
   }
      for (int i=39; i >= 30; i--){
     digitalWrite(i, 0);
     delay(velocidade);
   } 
   
  
    
}
