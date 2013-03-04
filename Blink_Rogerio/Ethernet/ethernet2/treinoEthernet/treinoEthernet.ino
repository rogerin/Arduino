#include <SPI.h>
#include <Ethernet.h>



byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(192,168,0,111); // ip que o arduino assumirá
IPAddress gateway(192,168,0,1); // ip do roteador
IPAddress subnet(255, 255, 255, 0);

EthernetServer server(80);

int pino = 9;

void setup()
{
  Ethernet.begin(mac,ip,gateway, subnet);
  server.begin();
  Serial.begin(9600);
  pinMode(pino, OUTPUT);
  digitalWrite(pino,0);
}

void loop()
{
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
        
        if(c == '\n' && currentLineIsBlank){
          client.print("HTTP/1.0 200 OK");
          client.println("Content-Type: text/html");
          client.print("Connection: close");
          client.println();
          
          client.println('<p><span class="span2">Luz 1</span><a href="http://192.168.0.111/luz1on" class="btn btn-success"> Liga </a><a href="http://192.168.0.111/luz1off" class="btn btn-danger"> Desliga </a></p>');

          
          if(varOnOff == 0){
             client.print("false"); 
          }
            else if (varOnOff == 1) {
              digitalWrite(pino,1);              
              client.print("true");
            }
            else if (varOnOff == 2) {
              digitalWrite(pino,0);
              client.print("true");
             }
           else {
             client.print("false"); 
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
    delay(1);
    client.stop();
  }
}
