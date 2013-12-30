

int tempo = 200;

void setup() {                
  pinMode(23, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(53, OUTPUT);
  
  digitalWrite(23, 1);
  digitalWrite(25, 1);
  digitalWrite(27, 1);
  digitalWrite(29, 1);
  digitalWrite(31, 1);
  digitalWrite(33, 1);
  digitalWrite(35, 1);
  digitalWrite(37, 1);
  digitalWrite(39, 1);
  digitalWrite(41, 1);
  digitalWrite(43, 1);
  digitalWrite(45, 1);
  digitalWrite(47, 1);
  digitalWrite(49, 1);
  digitalWrite(51, 1);
  digitalWrite(53, 1);
}

void loop()
{
    for(int i = 23; i < 54; i = i + 2){
      digitalWrite(i, 0);
      delay(tempo);
    }
    
    for(int i = 53; i > 22; i = i - 2){
      digitalWrite(i, 1);
      delay(tempo);
    }
}
