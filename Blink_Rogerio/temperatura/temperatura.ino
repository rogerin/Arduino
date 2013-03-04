
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int pinoSensor = 0;
int valorLido = 0;
float temperatura = 0;
void setup() {
Serial.begin(9600);

Serial.print("inicio: ");

lcd.begin(16, 2);
lcd.print("Temperatura atual: ");    
}

void loop() {
valorLido = analogRead(pinoSensor);
temperatura = (valorLido * 0.00488);
temperatura = temperatura * 100;
Serial.print("Temperatura: ");
Serial.println(temperatura);

lcd.setCursor(0, 1);
lcd.print(temperatura);

delay(1000);
}

