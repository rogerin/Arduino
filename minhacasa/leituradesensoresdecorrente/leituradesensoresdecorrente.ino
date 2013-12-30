#include <SPI.h>
#include <Ethernet.h>
#include <Bounce.h>
#include <IRremote.h>
//Mux control pins
int s00 = 5;
int s01 = 6;
int s02 = 7;

IRsend irsend;

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

IPAddress ip(192,168,1,123);
IPAddress gateway(192,168,1,254);
IPAddress subnet(255,255,255,0);

EthernetServer server(1000);

#define BUTTON1 22
#define BUTTON2 24
#define BUTTON3 26


#define LUZ1 23
#define LUZ2 25
#define LUZ3 27
#define LUZ4 29
#define LUZ5 31


int RELE1 = LOW;
int RELE2 = LOW;
int RELE3 = LOW;
int RELE4 = LOW;
int RELE5 = LOW;


Bounce bon1 = Bounce( BUTTON1, 10 ); 
Bounce bon2 = Bounce( BUTTON2, 10 ); 
Bounce bon3 = Bounce( BUTTON3, 10 ); 


void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando programa..");
  Ethernet.begin(mac,ip,gateway,subnet);
  Serial.println("Server ativo no IP: ");
  Serial.print(Ethernet.localIP());
  server.begin();
  
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(BUTTON3, INPUT);
    
    digitalWrite(BUTTON1, HIGH);
    digitalWrite(BUTTON2, HIGH);
    digitalWrite(BUTTON3, HIGH);
    
    pinMode(LUZ1, OUTPUT);
    pinMode(LUZ2, OUTPUT);
    pinMode(LUZ3, OUTPUT);
    pinMode(LUZ4, OUTPUT);
    pinMode(LUZ5, OUTPUT);
    
    
    
    // configurando infravermelho
    pinMode(9, OUTPUT);
}
void loop()
{
  if ( bon1.update() ) {
     if ( bon1.read() == HIGH) {
       if ( RELE1 == LOW ) {
         RELE1 = HIGH;
         
       } else {
         RELE1 = LOW;
         
       }
       digitalWrite(LUZ1, RELE1);
     }
   }  
 
   if ( bon2.update() ) {
     if ( bon2.read() == HIGH) {
       if ( RELE2 == LOW ) {
         RELE2 = HIGH;
       } else {
         RELE2 = LOW;
       }
       digitalWrite(LUZ2, RELE2);
     }
   }
   if ( bon3.update() ) {
     if ( bon3.read() == HIGH) {
       if ( RELE3 == LOW ) {
         RELE3 = HIGH;
       } else {
         RELE3 = LOW;
       }
       digitalWrite(LUZ3, RELE3);
     }
   }
   
   

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
 
            client.print("  dados({ \"acao\" : \"" + acao+"\", \"ip\" : \""+Ethernet.localIP()+"\","); //so imprime devolta o valor do comando, aqui vc faz o que quiser ;)
         
            Serial.println(acao);  
            if      ( acao == "001"){ RELE1 = HIGH; digitalWrite(LUZ1, RELE1); } 
            else if ( acao == "002"){ RELE1 = LOW; digitalWrite(LUZ1, RELE1);  } 
            
            else if ( acao == "003"){ RELE2 = HIGH; digitalWrite(LUZ2, RELE2); }
            else if ( acao == "004"){ RELE2 = LOW; digitalWrite(LUZ2, RELE2); }
            
            else if ( acao == "005"){ RELE3 = HIGH; digitalWrite(LUZ3, RELE3); }
            else if ( acao == "006"){ RELE3 = LOW; digitalWrite(LUZ3, RELE3); }
            
            else if ( acao == "007"){ RELE4 = HIGH; digitalWrite(LUZ4, RELE4); }
            else if ( acao == "008"){ RELE4 = LOW; digitalWrite(LUZ4, RELE4); }
            
            else if ( acao == "009"){ RELE5 = HIGH; digitalWrite(LUZ5, RELE5); }
            else if ( acao == "010"){ RELE5 = LOW; digitalWrite(LUZ5, RELE5); }
            
            
            
            // Controle de TV
            else if(acao == "005") { 
              Serial.println("Liga TV");
              for (int i = 0; i < 1; i++) {
                irsend.sendNEC(0x8076807F, 32); 
                delay(100);
              }
            }
        
          // V = envia codigo aumenta volume da tv
          else if (acao == "006") {
            Serial.println("Volume ++");
             for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x80767887, 32); 
              delay(100);
            }
          }
      
          // v = envia codigo baixa volume da tv
          else if(acao == "007"){
            Serial.println("Volume --");
            for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x8076F807, 32); 
              delay(100);
            }
          }
      
          // V = envia codigo muda de canal para mais tv
          else if(acao == "008"){
            Serial.println("Canal ++");
            for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x807620DF, 32); 
              delay(100);
            }
          }
        
          // V = envia codigo muda de canal para menos tv
          else if(acao == "009"){
            Serial.println("Canal --");
            for (int i = 0; i < 1; i++) {
              irsend.sendNEC(0x8076A05F, 32); 
              delay(100);
            }
          }
        
            client.print("\"LUZ1\" : \"");
            if(RELE1 == HIGH){
               client.print("001");
            } else if (RELE1 == LOW) {
               client.print("002");
            }
            client.print("\",");
            
            client.print("\"LUZ3\" : \"");
            if(RELE3 == HIGH){
               client.print("005");
            } else if (RELE3 == LOW) {
               client.print("006");
            }
            client.print("\",");
            
            client.print("\"LUZ4\" : \"");
            if(RELE4 == HIGH){
               client.print("007");
            } else if (RELE4 == LOW) {
               client.print("008");
            }
            client.print("\",");
            
            client.print("\"LUZ5\" : \"");
            if(RELE5 == HIGH){
               client.print("009");
            } else if (RELE5 == LOW) {
               client.print("010");
            }
            client.print("\",");
            
            
            client.print("\"LUZ2\" : \"");
            if(RELE2 == HIGH){
               client.print("003");
            } else if (RELE2 == LOW) {
               client.print("004");
            }
            client.print("\"");
            

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



int readMux(int principal, int secundario){
  int controlPin0[] = {s00, s01, s02};
  int controlPin1[] = {s10, s11, s12};

  //pode-se usar um vetor para armazenar os 3 valores e depois fazer um laço FOR p/ escrever
  bool pr0 = bitRead(principal, 0);
  bool pr1 = bitRead(principal, 1);
  bool pr2 = bitRead(principal, 2);

  bool sec0 = bitRead(secundario, 0); 
  bool sec1 = bitRead(secundario, 1);
  bool sec2 = bitRead(secundario, 2);

 //Se estiverem como vetor, pode-se usar um laço FOR aqui para escrever os 3 valores
 digitalWrite(controlPin0[0], pr0);
 digitalWrite(controlPin0[1], pr1);
 digitalWrite(controlPin0[2], pr2);

 digitalWrite(controlPin1[0], sec0);  
 digitalWrite(controlPin1[1], sec1);  
 digitalWrite(controlPin1[2], sec2);  

  //read the value at the SIG pin
  int val = analogRead(SIG_pin);

  //return the value
  return val;
}

