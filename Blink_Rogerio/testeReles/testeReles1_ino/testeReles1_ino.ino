/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int d = 200;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  
  digitalWrite(13, 1);
  digitalWrite(12, 1);
  digitalWrite(11, 1);
  digitalWrite(10, 1);
  digitalWrite(9, 1);
}

// the loop routine runs over and over again forever:
void loop() {
    digitalWrite(13, 0);
    delay(d);
    digitalWrite(12, 0);
    delay(1000);
    digitalWrite(11, 0);
    delay(d);
    digitalWrite(10, 0);
    delay(d);
    digitalWrite(9, 0);
    delay(d);
    digitalWrite(9, 1);
    delay(d);
    digitalWrite(10, 1);
    delay(d);
    digitalWrite(11, 1);
    delay(d);
    digitalWrite(12, 1);
    delay(d);
    digitalWrite(13, 1);
    delay(d);
}
