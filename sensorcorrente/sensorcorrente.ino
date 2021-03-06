int VQ;
int ACSPin = A2;
void setup() {
  Serial.begin(9600);
  VQ = determineVQ(ACSPin); //Quiscent output voltage - the average voltage ACS712 shows with no load (0 A)
  delay(1000);
}
void loop() {
  Serial.print("ACS712:");
  Serial.print(readCurrent(ACSPin),3);
  Serial.println(" mA");
  delay(150);
}

int determineVQ(int PIN) {
  Serial.print("estimating avg. quiscent voltage:");
  long VQ = 0;
  //read 5000 samples to stabilise value
  for (int i=0; i<10000; i++) {
    VQ += abs(analogRead(PIN));
    delay(1);//depends on sampling (on filter capacitor), can be 1/80000 (80kHz) max.
  }

  VQ /= 10000;
  Serial.print(map(VQ, 0, 1023, 0, 5000));Serial.println(" mV");
  return int(VQ);
}

float readCurrent(int PIN) {
  int current = 0;
  int sensitivity = 185;//change this to 100 for ACS712-20A or to 66 for ACS712-30A
  //read 5 samples to stabilise value
  for (int i=0; i<200; i++) {
    current += abs(analogRead(PIN) - VQ);
    delay(1);
  }
  current = map(current/200, 0, 1023, 0, 5000);
  return float(current)/sensitivity;
}
