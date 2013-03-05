#include <SPI.h>
#include <Ethernet.h> 
#include <SoftwareSerial.h>
/*
 Note:
 Not all pins on the Mega and Meg a 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 
 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

*/
SoftwareSerial servidor(8,9);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

IPAddress ip(192,168,1,111);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

EthernetServer server(80);

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

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando programa..");
  Ethernet.begin(mac,ip,gateway,subnet);
  server.begin();
  Serial.println("Server ativo no IP: ");
  Serial.print(Ethernet.localIP());
  servidor.begin(9600);
  
}
void loop()
{
  EthernetClient client = server.available();
  if(client)
  {
    boolean continua = true;
    String linha = "";

    while(client.connected())
    {
      if(client.available()){
        char c = client.read();
        linha.concat(c);
  
        if(c == '\n' && continua)
        {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/javascript");
          client.println("Access-Control-Allow-Origin: *");
          client.println();
          
          int iniciofrente = linha.indexOf("?");
        
          if(iniciofrente>-1){     //verifica se o comando veio
            iniciofrente     = iniciofrente+6; //pega o caractere seguinte
            int fimfrente    = iniciofrente+3; //esse comando espero 3 caracteres
            String acao    = linha.substring(iniciofrente,fimfrente);//recupero o valor do comando
       
 
            client.print("  dados({ \"acao\" : \"" + acao+"\", \"ip\" : \""+Ethernet.localIP()+"\""); //so imprime devolta o valor do comando, aqui vc faz o que quiser ;)
         
            Serial.println(acao);

            //servidor.print(acao);
            
            if(acao == "tem"){
              client.print(", \"temp\": {");
              st1 = analogRead(analogPin0);
              st2 = analogRead(analogPin1);
              st3 = analogRead(analogPin2);
              st4 = analogRead(analogPin3);
              st5 = analogRead(analogPin4);
              
              t1 = (st1 * 0.0049);
              t1 = t1 * 100;
              client.print("\"quarto1\" : \"");
              client.print(t1);
              client.print("\",");
              
              t2 = (st2 * 0.0049);
              t2 = t2 * 100;
              client.print("\"quarto2\" : \"");
              client.print(t2);
              client.print("\",");
              
              t3 = (st3 * 0.0049);
              t3 = t3 * 100;
              client.print("\"quarto3\" : \"");
              client.print(t3);
              client.print("\",");
              
              t4 = (st4 * 0.0049);
              t4 = t4 * 100;
              client.print("\"quarto4\" : \"");
              client.print(t4);
              client.print("\",");
              
              t5 = (st5 * 0.0049);
              t5 = t5 * 100;
              client.print("\"quarto5\" : \"");
              client.print(t1);
              client.print("\",");
              
              media = (t1+t2+t3+t4+t5)/5;
              
              client.print("\"media\" : \"");
              client.print(media);
              client.print("\"}");
            }
            else if (acao == "001"){
              servidor.print("a");
            }
            
            else if (acao == "002"){
              servidor.print("b");
            }
            else if (acao == "003"){
              servidor.print("c");
            }
            else if (acao == "004"){
              servidor.print("d");
            }
            else if (acao == "005"){
              servidor.print("e");
            }
            else if (acao == "006"){
              servidor.print("f");
            }
            else if (acao == "007"){
              servidor.print("g");
            }
            else if (acao == "008"){
              servidor.print("h");
            }
            else if (acao == "009"){
              servidor.print("i");
            }
            else if (acao == "010"){
              servidor.print("j");
            }
            else if (acao == "011"){
              servidor.print("l");
            }
            else if (acao == "012"){
              servidor.print("m");
            }
            else if (acao == "013"){
              servidor.print("n");
            }
            else if (acao == "014"){
              servidor.print("o");
            }
            else if (acao == "015"){
              servidor.print("p");
            }
            else if (acao == "016"){
              servidor.print("q");
            }
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            client.print("})");
         }          
          break;
        }
        if(c == '\n') { continua = true; }
        else if (c != '\r') { continua = false; }
      }
    }
     delay(1);
     client.stop();
  }
}
