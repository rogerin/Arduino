void setup()
{
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValor = analogRead(A0);
  Serial.println(sensorValor); 
  digitalWrite(12,1);
  delay(1000);
  digitalWrite(12,0);
  
}
