#include <SPI.h>
#include <Ethernet.h>
#include <IRremote.h>


// Configuração de botoes e Reles
byte BOTAO1 = 0;
byte BOTAO2 = 0;
byte BOTAO3 = 0;

byte RELE1 = 1;
byte RELE2 = 1;
byte RELE3 = 1;
/*
byte porta_b1 = 22;
byte porta_b2 = 23;
byte porta_b3 = 24;

byte porta_r1 = 25;
byte porta_r2 = 26;
byte porta_r3 = 27;
*/


byte porta_b1 = 2;
byte porta_b2 = 3;
byte porta_b3 = 4;

byte porta_r1 = 5;
byte porta_r2 = 6;
byte porta_r3 = 7;



byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(10,0,0,105); // ip que o arduino assumirá
IPAddress gateway(10,0,0,1); // ip do roteador
IPAddress subnet(255, 255, 255, 255);

EthernetServer server(80);
IRsend irsend;

void setup(){
  Serial.begin(9600);
  Ethernet.begin(mac,ip,gateway, subnet);
  server.begin();
  
  pinMode(porta_b1, INPUT);
  pinMode(porta_b2, INPUT);
  pinMode(porta_b3, INPUT);
  
  digitalWrite(porta_b1, 1);
  digitalWrite(porta_b2, 1);
  digitalWrite(porta_b3, 1);
  
  pinMode(porta_r1, OUTPUT);
  pinMode(porta_r2, OUTPUT);
  pinMode(porta_r3, OUTPUT);
  
  digitalWrite(porta_r1, 1);
  digitalWrite(porta_r2, 1);
  digitalWrite(porta_r3, 1);  
  
  }
void loop(){
 BOTAO1 = digitalRead(porta_b1);
 BOTAO2 = digitalRead(porta_b2);
 BOTAO3 = digitalRead(porta_b3);
 
 if(BOTAO1 == 0){
  RELE1 = !RELE1;
  digitalWrite(porta_r1, RELE1);
  delay(100); 
 }
 
 if(BOTAO2 == 0){
  RELE2 = !RELE2;
  digitalWrite(porta_r2, RELE2);
  delay(100); 
 }
 
 if(BOTAO3 == 0){
  RELE3 = !RELE3;
  digitalWrite(porta_r3, RELE3);
  delay(100); 
 }
 
  EthernetClient client = server.available();
  if(client) {
    boolean currentLineIsBlank = true;
    String vars;
    int varOnOff = 0;
    while(client.connected()){
      if(client.available()){
        char c = client.read();
        Serial.print(c);
        vars.concat(c);
        if(vars.endsWith("/luz1on")) varOnOff = 1;
        else if (vars.endsWith("/luz1off")) varOnOff = 2;
        else if (vars.endsWith("/luz2on")) varOnOff = 3;
        else if (vars.endsWith("/luz2off")) varOnOff = 4;
        else if (vars.endsWith("/ventiladoron")) varOnOff = 5;
        else if (vars.endsWith("/ventiladoroff")) varOnOff = 6;
        
        // TV
        else if (vars.endsWith("/tvonoff")) varOnOff = 7;
        else if (vars.endsWith("/cmenos")) varOnOff = 8;
        else if (vars.endsWith("/cmais")) varOnOff = 9;
        else if (vars.endsWith("/vmenos")) varOnOff = 10;
        else if (vars.endsWith("/vmais")) varOnOff = 11;
        
        // Sensores
        else if (vars.endsWith("/luminosidade")) varOnOff = 12;
        
        if(c == '\n' && currentLineIsBlank){
          client.println("HTTP/1.1 200 OK");
          
          client.println();
          client.println("<div id=\"result\">");
          if(varOnOff == 0){
             client.println("false"); 
          }
          else if (varOnOff == 1) {
            RELE3 = !RELE3;
            digitalWrite(porta_r3, RELE3);
            delay(100); 
            client.println("true");
          }
          else if (varOnOff == 2) {
            digitalWrite(8, 0);
            client.println("true");
         }
          else if (varOnOff == 3) {
            digitalWrite(9, 1);
            client.println("true");
         }
          else if (varOnOff == 4) {
            digitalWrite(9, 0);
            client.println("true");
         }
          else if (varOnOff == 5) {
            digitalWrite(10, 1);
            client.println("true");
         }
          else if (varOnOff == 6) {
            digitalWrite(10, 0);
            client.println("true");
         }
         
         // TV
          else if (varOnOff == 7) {
            for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x8076807F, 32); 
              delay(100);
            }
            client.println("true");
         }
         
          else if (varOnOff == 8) {
            for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x8076A05F, 32); 
              delay(100);
            }
            client.println("true");
         }
         
          else if (varOnOff == 9) {
            for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x807620DF, 32); 
              delay(100);
            }
            client.println("true");
         }
         
          else if (varOnOff == 10) {
            for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x8076F807, 32); 
              delay(100);
            }
            client.println("true");
         }
         
          else if (varOnOff == 11) {
            for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x80767887, 32); 
              delay(100);
            }
            client.println("true");
         }
         
          else if (varOnOff == 12) {
            client.println(analogRead(0));
         }
         
         // FIM COMANDOS TV
         
         
         
         
         
         
         
         
         
         else {
             client.println("false"); 
         }
          break;
        }
        if(c == '\n'){
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    client.println("</div>");
    delay(1);
    client.stop();
  }
   delay(200); 
}

