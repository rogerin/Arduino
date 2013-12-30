#include <SPI.h>
#include <Ethernet.h>
#include <IRremote.h>

IRsend irsend;

byte BOTAO1 = 0;
byte BOTAO2 = 0;
byte BOTAO3 = 0;
byte BOTAO4 = 0;
byte BOTAO5 = 0;
byte BOTAO6 = 0;

byte RELE1 = 0;
byte RELE2 = 0;
byte RELE3 = 0;
byte RELE4 = 0;
byte RELE5 = 0;
byte RELE6 = 0;

/* 
   #######################
   ##### Arduino Mega ####
   #######################
   
   # Pinos exclusivos para o Mega
   
   10 = SS For Ethernet Controller
   4  = SS For SD Card
   50 = MISO
   51 = MOSI
   52 = SCK
   54 = Hardware SS
*/
byte porta_botao1 = 30;
byte porta_botao2 = 31;
byte porta_botao3 = 32;
byte porta_botao4 = 33;
byte porta_botao5 = 34;
byte porta_botao6 = 35;

byte porta_rele1 = 22;
byte porta_rele2 = 23;
byte porta_rele3 = 24;
byte porta_rele4 = 25;
byte porta_rele5 = 26;
byte porta_rele6 = 27;

// Configurando delay`s
int delay_botoes = 50;
int delay_programa = 100;
int pinBip = 28;

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

IPAddress ip(192,168,0,111);
IPAddress gateway(192,168,0,1);
IPAddress subnet(255,255,255,0);

EthernetServer server(80);
void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando programa..");
  Ethernet.begin(mac,ip,gateway,subnet);
  server.begin();
  Serial.println("Server ativo no IP: ");
  Serial.print(Ethernet.localIP());
  
  Serial.println("Configurando Botões");
  // CONFIGURANDO BOTOES
  pinMode(porta_botao1, INPUT);
  pinMode(porta_botao2, INPUT);
  pinMode(porta_botao3, INPUT);
  pinMode(porta_botao4, INPUT);
  pinMode(porta_botao5, INPUT);
  pinMode(porta_botao6, INPUT);
  
  Serial.println("Configurando Bip");
  pinMode(pinBip, OUTPUT);
  digitalWrite(pinBip, 0);
  
  Serial.println("Ativando Botões");
  // ATIVANDO BOTOES
  digitalWrite(porta_botao1, 1);
  digitalWrite(porta_botao2, 1);
  digitalWrite(porta_botao3, 1);
  digitalWrite(porta_botao4, 1);
  digitalWrite(porta_botao5, 1);
  digitalWrite(porta_botao6, 1);
  
  Serial.println("Configurando RELÉS");
  // CONFIGURANDO RELÉS
  pinMode(porta_rele1, OUTPUT);
  pinMode(porta_rele2, OUTPUT);
  pinMode(porta_rele3, OUTPUT);
  pinMode(porta_rele4, OUTPUT);
  pinMode(porta_rele5, OUTPUT);
  pinMode(porta_rele6, OUTPUT);
  
  Serial.println("Configurando Estado inicial dos Relés");
  // ESTADO INICIAL DOS RELÉS
  digitalWrite(porta_rele1, RELE1);
  digitalWrite(porta_rele2, RELE2);
  digitalWrite(porta_rele3, RELE3);
  digitalWrite(porta_rele4, RELE4);
  digitalWrite(porta_rele5, RELE5);
  digitalWrite(porta_rele6, RELE6);

  Serial.println("Configurando infravermelho...");
  pinMode(9, OUTPUT);
  
  Serial.println("Configuracao basica concluida...");
  Serial.println("Programa iniciado!");
  
}

void loop()
{
  // Ler botoes
  BOTAO1 = digitalRead(porta_botao1);
  BOTAO2 = digitalRead(porta_botao2);
  BOTAO3 = digitalRead(porta_botao3);
  BOTAO4 = digitalRead(porta_botao4);
  BOTAO5 = digitalRead(porta_botao5);
  BOTAO6 = digitalRead(porta_botao6);
  
  if(BOTAO1 == 0){
    Serial.println("Botao 1 pressionado");
    RELE1 = !RELE1;
    digitalWrite(porta_rele1, RELE1);
    delay(delay_botoes); 
  }
   
  if(BOTAO2 == 0){
    Serial.println("Botao 2 pressionado");
    RELE2 = !RELE2;
    digitalWrite(porta_rele2, RELE2);
    delay(delay_botoes); 
  }
   
  if(BOTAO3 == 0){
    Serial.println("Botao 3 pressionado");
    RELE3 = !RELE3;
    digitalWrite(porta_rele3, RELE3);
    delay(delay_botoes); 
  }
  if(BOTAO4 == 0){
    Serial.println("Botao 4 pressionado");
    RELE4 = !RELE4;
    digitalWrite(porta_rele4, RELE4);
    delay(delay_botoes); 
  }
  if(BOTAO5 == 0){
    Serial.println("Botao 5 pressionado");
    RELE5 = !RELE5;
    digitalWrite(porta_rele5, RELE5);
    delay(delay_botoes); 
  }
  if(BOTAO6 == 0){
    Serial.println("Botao 6 pressionado");
    RELE6 = !RELE6;
    digitalWrite(porta_rele6, RELE6);
    delay(delay_botoes); 
  }
  // Botoes finalizado
  
  
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
        Serial.print(c);
  
        if(c == '\n' && continua)
        {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/javascript");
                //  header('Content-Type: text/javascript; charset=utf8');
                //header('Access-Control-Allow-Origin: http://www.example.com/');
          //client.println("Server: LigaFacil Projeto Casa LFPC");
          client.println("Access-Control-Allow-Origin: *");
          client.println();
          //client.println("Conectado com sucesso no IP: ");
          //client.print(Ethernet.localIP());
          
          int iniciofrente = linha.indexOf("?");
        
          if(iniciofrente>-1){     //verifica se o comando veio
            iniciofrente     = iniciofrente+6; //pega o caractere seguinte
            int fimfrente    = iniciofrente+3; //esse comando espero 3 caracteres
            String acao    = linha.substring(iniciofrente,fimfrente);//recupero o valor do comando
       
 
           client.print(" dados({ \"acao\" : \"" + acao+"\", \"ip\" : \""+Ethernet.localIP()+"\"})"); //so imprime devolta o valor do comando, aqui vc faz o que quiser ;)
         
           Serial.println("Valor a tratar: ");
           Serial.print(acao);
           
           if(acao == "001") { 
             Serial.println("Liga luz 1");
              RELE1 = 1;
              digitalWrite(porta_rele1, RELE1);
              bip();
              delay(delay_botoes);
   
           }
           else if (acao == "002") { 
             Serial.println("Desliga luz 1"); 
              RELE1 = 0;
              digitalWrite(porta_rele1, RELE1);
              bip();
              delay(delay_botoes);
           }

           else if (acao == "003") { 
             Serial.println("Liga luz 2"); 
              RELE2 = 1;
              digitalWrite(porta_rele2, RELE2);
              bip();
              delay(delay_botoes);
           }
          else if (acao == "004") { 
             Serial.println("Desliga luz 2"); 
              RELE2 = 0;
              digitalWrite(porta_rele2, RELE2);
              bip();
              delay(delay_botoes);
           }
           else if (acao == "005") { 
             Serial.println("Liga luz 3"); 
               RELE3 = 1;
              digitalWrite(porta_rele3, RELE3);
              bip();
              delay(delay_botoes);
           }
           else if (acao == "006") { 
             Serial.println("Desliga luz 3"); 
              RELE3 = 0;
              digitalWrite(porta_rele3, RELE3);
              bip();
              delay(delay_botoes);
           }
           else if (acao == "007") { 
             Serial.println("Liga luz 4"); 
               RELE4 = 1;
              digitalWrite(porta_rele4, RELE4);
              bip();
              delay(delay_botoes);
           }
           else if (acao == "008") { 
             Serial.println("Desliga luz 4"); 
               RELE4 = 0;
              digitalWrite(porta_rele4, RELE4);
              bip();
              delay(delay_botoes);
           }
           else if (acao == "009") { 
             Serial.println("Liga luz 5"); 
               RELE5 = 1;
              digitalWrite(porta_rele5, RELE5);
              bip();
              delay(delay_botoes);
           }
           else if (acao == "010") { 
             Serial.println("Desliga luz 5"); 
               RELE5 = 0;
              digitalWrite(porta_rele5, RELE5);
              bip();
              delay(delay_botoes);
           }
           
         else if(acao == "019") {
          Serial.println("Liga TV");
          for (int i = 0; i < 1; i++) {
            irsend.sendNEC(0x8076807F, 32); 
            delay(100);
          }
            bip();
        }
        
        // V = envia codigo aumenta volume da tv
        else if (acao == "023") {
         Serial.println("Volume ++");
         for (int i = 0; i < 1; i++) {
          irsend.sendNEC(0x80767887, 32); 
          delay(100);
          }
          bip();
        }
      
        // v = envia codigo baixa volume da tv
         else if(acao == "022"){
          Serial.println("Volume --");
          for (int i = 0; i < 1; i++) {
            irsend.sendNEC(0x8076F807, 32); 
            delay(100);
          }
          bip();
        }
      
        // V = envia codigo muda de canal para mais tv
        else if(acao == "021"){
          Serial.println("Canal ++");
          for (int i = 0; i < 1; i++) {
            irsend.sendNEC(0x807620DF, 32); 
            delay(100);
          }
          bip();
        }
        
        // V = envia codigo muda de canal para menos tv
         else if(acao == "020"){
          Serial.println("Canal --");
          for (int i = 0; i < 1; i++) {
            irsend.sendNEC(0x8076A05F, 32); 
            delay(100);
          }
          bip();
        }

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
  delay(50);
}

void bip()
{
  digitalWrite(pinBip,1);
  delay(5);
  digitalWrite(pinBip,0);
}


