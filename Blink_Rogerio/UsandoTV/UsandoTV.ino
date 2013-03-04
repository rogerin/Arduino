#include <TVout.h>

TVout TV;
unsigned char x,y;

int valor = 0;
char valor2[10];

void setup()  {
  x=0;
  y=0;
  TV.start_render(_NTSC);	//for devices with only 1k sram(m168) use TV.begin(_NTSC,128,56)
  Serial.begin(9600);
}

void loop() {
  TV.clear_screen();
  x=0;
  y=0;
  
  TV.clear_screen();
  TV.print_str(0,0,"Rogerio Filho");
  valor = analogRead(A0);
 itoa(valor,valor2,10);
  TV.print_str(0,8,"Sensor: ");
  TV.print_str(0,16,valor2);
  TV.delay_frame(60);
 }
