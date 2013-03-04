int analogPin0 = A0;
int analogPin1 = A1;
int analogPin2 = A2;
int analogPin3 = A3;
int analogPin4 = A4;

int st1 = 0;
int st2 = 0;
int st3 = 0;
int st4 = 0;
int st5 = 0;

float t1 = 0;
float t2 = 0;
float t3 = 0;
float t4 = 0;
float t5 = 0;
float media = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  st1 = analogRead(analogPin0);
  st2 = analogRead(analogPin1);
  st3 = analogRead(analogPin2);
  st4 = analogRead(analogPin3);
  st5 = analogRead(analogPin4);
  
  //Serial.println(readValue);
  t1 = (st1 * 0.0049);
  t1 = t1 * 100;
  Serial.println("Temperatura 1: ");
  Serial.print(t1);
  Serial.print("C ");
  
  t2 = (st2 * 0.0049);
  t2 = t2 * 100;
  Serial.println("Temperatura 2: ");
  Serial.print(t2);
  Serial.print("C ");
  
  t3 = (st3 * 0.0049);
  t3 = t3 * 100;
  Serial.println("Temperatura 3: ");
  Serial.print(t3);
  Serial.print("C ");
  
  t4 = (st4 * 0.0049);
  t4 = t4 * 100;
  Serial.println("Temperatura 4: ");
  Serial.print(t4);
  Serial.print("C ");
  
  t5 = (st5 * 0.0049);
  t5 = t5 * 100;
  Serial.println("Temperatura 5: ");
  Serial.print(t5);
  Serial.print("C ");
  Serial.println("===");
  Serial.println("Media: ");
  media = (t1+t2+t3+t4+t5)/5;
  Serial.print(media);
  Serial.println("===");
  Serial.println();
  
  
    
  delay(1000);
  
}

