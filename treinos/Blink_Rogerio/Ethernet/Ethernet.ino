#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(10,0,0,110); // ip que o arduino assumirá
IPAddress gateway(10,0,0,1); // ip do roteador
IPAddress subnet(255, 255, 255, 255);

EthernetServer server(80);

void setup(){
  Serial.begin(9600);
  Ethernet.begin(mac,ip,gateway, subnet);
  server.begin();
}
void loop(){
  EthernetClient client = server.available();
  if(client) {
    boolean currentLineIsBlank = true;
    String vars;
    int varOnOff = 0;
    while(client.connected()){
      if(client.available()){
        char c = client.read();
       
        if(c == '\n' && currentLineIsBlank){
          client.println("HTTP/1.1 200 OK");
          client.println();
          client.println("true");
        } 
        if(c == '\n'){
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(100);
    client.stop();
  }
   delay(200); 
}

