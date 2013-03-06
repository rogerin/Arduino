#include <SPI.h>
#include <Ethernet.h>
#include <Bounce.h>
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



#define BUTTON1 22
#define BUTTON2 23
#define BUTTON3 24
#define BUTTON4 25
#define BUTTON5 26
#define BUTTON6 27
#define BUTTON7 28
#define BUTTON8 29
#define BUTTON9 30
#define BUTTON10 31
#define BUTTON11 32
#define BUTTON12 33
#define BUTTON13 34
#define BUTTON14 35
#define BUTTON15 36
#define BUTTON16 37

int RELE1 = LOW;
int RELE2 = LOW;
int RELE3 = LOW;
int RELE4 = LOW;
int RELE5 = LOW;
int RELE6 = LOW;
int RELE7 = LOW;
int RELE8 = LOW;
int RELE9 = LOW;
int RELE10 = LOW;
int RELE11 = LOW;
int RELE12 = LOW;
int RELE13 = LOW;
int RELE14 = LOW;
int RELE15 = LOW;
int RELE16 = LOW;


// Configurando delay`s
int delay_botoes = 50;
int delay_programa = 100;

Bounce bon1 = Bounce( BUTTON1, 10 ); 
Bounce bon2 = Bounce( BUTTON2, 10 ); 
Bounce bon3 = Bounce( BUTTON3, 10 );
Bounce bon4 = Bounce( BUTTON4, 10 );
Bounce bon5 = Bounce( BUTTON5, 10 );
Bounce bon6 = Bounce( BUTTON6, 10 );
Bounce bon7 = Bounce( BUTTON7, 10 );
Bounce bon8 = Bounce( BUTTON8, 10 );
Bounce bon9 = Bounce( BUTTON9, 10 );
Bounce bon10 = Bounce( BUTTON10, 10 );
Bounce bon11 = Bounce( BUTTON11, 10 );
Bounce bon12 = Bounce( BUTTON12, 10 );
Bounce bon13 = Bounce( BUTTON13, 10 );
Bounce bon14 = Bounce( BUTTON14, 10 );
Bounce bon15 = Bounce( BUTTON15, 10 );
Bounce bon16 = Bounce( BUTTON16, 10 );

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando programa..");
  Ethernet.begin(mac,ip,gateway,subnet);
  server.begin();
  Serial.println("Server ativo no IP: ");
  Serial.print(Ethernet.localIP());
  servidor.begin(9600);
  
  
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(BUTTON3, INPUT);
    pinMode(BUTTON4, INPUT);
    pinMode(BUTTON5, INPUT);
    pinMode(BUTTON6, INPUT);
    pinMode(BUTTON7, INPUT);
    pinMode(BUTTON8, INPUT);
    pinMode(BUTTON9, INPUT);
    pinMode(BUTTON10, INPUT);
    pinMode(BUTTON11, INPUT);
    pinMode(BUTTON12, INPUT);
    pinMode(BUTTON13, INPUT);
    pinMode(BUTTON14, INPUT);
    pinMode(BUTTON15, INPUT);
    pinMode(BUTTON16, INPUT);
    digitalWrite(BUTTON1, HIGH);
    digitalWrite(BUTTON2, HIGH);
    digitalWrite(BUTTON3, HIGH);
    digitalWrite(BUTTON4, HIGH);
    digitalWrite(BUTTON5, HIGH);
    digitalWrite(BUTTON6, HIGH);
    digitalWrite(BUTTON7, HIGH);
    digitalWrite(BUTTON8, HIGH);
    digitalWrite(BUTTON9, HIGH);
    digitalWrite(BUTTON10, HIGH);
    digitalWrite(BUTTON11, HIGH);
    digitalWrite(BUTTON12, HIGH);
    digitalWrite(BUTTON13, HIGH);
    digitalWrite(BUTTON14, HIGH);
    digitalWrite(BUTTON15, HIGH);
    digitalWrite(BUTTON16, HIGH);
  
}
void loop()
{
  if ( bon1.update() ) {
     if ( bon1.read() == HIGH) {
       if ( RELE1 == LOW ) {
         RELE1 = HIGH;
         //Serial.println("RELE1 ATIVADO");
         
         servidor.print("a");
       } else {
         RELE1 = LOW;
         servidor.print("b");
         //Serial.println("RELE1 DESATIVADO");
         
       }
       
     }
   }  
   
 
   if ( bon2.update() ) {
     if ( bon2.read() == HIGH) {
       if ( RELE2 == LOW ) {
         RELE2 = HIGH;
          //Serial.println("RELE2 ATIVADO");
          servidor.print("c");
       } else {
         RELE2 = LOW;
         //Serial.println("RELE2 DESATIVADO");
         servidor.print("d");
       }
     
     }
   }
   
   if ( bon3.update() ) {
     if ( bon3.read() == HIGH) {
       if ( RELE3 == LOW ) {
         RELE3 = HIGH;
          servidor.print("e");
       } else {
         RELE3 = LOW;
         servidor.print("f");
       }
 
     }
   }
  /* 
   if ( bon4.update() ) {
     if ( bon4.read() == HIGH) {
       if ( RELE4 == LOW ) {
         RELE4 = HIGH;
          servidor.print("g");
       } else {
         RELE4 = LOW;
         servidor.print("h");
       }
       digitalWrite(LUZ4,RELE4);
     }
   }
   
   if ( bon5.update() ) {
     if ( bon5.read() == HIGH) {
       if ( RELE5 == LOW ) {
         RELE5 = HIGH;
          servidor.print("i");
       } else {
         RELE5 = LOW;
         servidor.print("j");
       }
       digitalWrite(LUZ5,RELE5);
     }
   }
   
   if ( bon6.update() ) {
     if ( bon6.read() == HIGH) {
       if ( RELE6 == LOW ) {
         RELE6 = HIGH;
          servidor.print("l");
       } else {
         RELE6 = LOW;
         servidor.print("m");
       }
       digitalWrite(LUZ6,RELE6);
     }
   }
   
   if ( bon7.update() ) {
     if ( bon7.read() == HIGH) {
       if ( RELE7 == LOW ) {
         RELE7 = HIGH;
         servidor.print("n");
       } else {
         RELE7 = LOW;
         servidor.print("o");
       }
       digitalWrite(LUZ7,RELE7);
     }
   }
   
   if ( bon8.update() ) {
     if ( bon8.read() == HIGH) {
       if ( RELE8 == LOW ) {
         RELE8 = HIGH;
          servidor.print("p");
       } else {
         RELE8 = LOW;
         servidor.print("q");
       }
       digitalWrite(LUZ8,RELE8);
     }
   }
   
   if ( bon9.update() ) {
     if ( bon9.read() == HIGH) {
       if ( RELE9 == LOW ) {
         RELE9 = HIGH;
          servidor.print("r");
       } else {
         RELE9 = LOW;
         servidor.print("s");
       }
       digitalWrite(LUZ9,RELE9);
     }
   }
   
   if ( bon10.update() ) {
     if ( bon10.read() == HIGH) {
       if ( RELE10 == LOW ) {
         RELE10 = HIGH;
          servidor.print("t");
       } else {
         RELE10 = LOW;
         servidor.print("u");
       }
       digitalWrite(LUZ10,RELE10);
     }
   }
   
   if ( bon11.update() ) {
     if ( bon11.read() == HIGH) {
       if ( RELE11 == LOW ) {
         RELE11 = HIGH;
         servidor.print("v");
       } else {
         RELE11 = LOW;
         servidor.print("x");
       }
       digitalWrite(LUZ11,RELE11);
     }
   }
   
   if ( bon12.update() ) {
     if ( bon12.read() == HIGH) {
       if ( RELE12 == LOW ) {
         RELE12 = HIGH;
          servidor.print("y");
       } else {
         RELE12 = LOW;
         servidor.print("w");
       }
       digitalWrite(LUZ12,RELE12);
     }
   }
   
   if ( bon13.update() ) {
     if ( bon13.read() == HIGH) {
       if ( RELE13 == LOW ) {
         RELE13 = HIGH;
          Serial.println("RELE13 ATIVADO");
       } else {
         RELE13 = LOW;
         Serial.println("RELE13 DESATIVADO");
       }
       digitalWrite(LUZ13,RELE13);
     }
   }
   
   if ( bon14.update() ) {
     if ( bon14.read() == HIGH) {
       if ( RELE14 == LOW ) {
         RELE14 = HIGH;
          Serial.println("RELE14 ATIVADO");
       } else {
         RELE14 = LOW;
         Serial.println("RELE14 DESATIVADO");
       }
       digitalWrite(LUZ14,RELE14);
     }
   }
   
   if ( bon15.update() ) {
     if ( bon15.read() == HIGH) {
       if ( RELE15 == LOW ) {
         RELE15 = HIGH;
          Serial.println("RELE15 ATIVADO");
       } else {
         RELE15 = LOW;
         Serial.println("RELE15 DESATIVADO");
       }
       digitalWrite(LUZ15,RELE15);
     }
   }
   
   if ( bon16.update() ) {
     if ( bon16.read() == HIGH) {
       if ( RELE16 == LOW ) {
         RELE16 = HIGH;
          Serial.println("RELE16 ATIVADO");
       } else {
         RELE16 = LOW;
         Serial.println("RELE16 DESATIVADO");
       }
       digitalWrite(LUZ16,RELE16);
     }
   }
   
*/

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
              
              client.print("\"val_media\" : \"");
              client.print(media);
              client.print("\"},");
            
            
            
            if (acao == "001"){
              servidor.print("a");
              RELE1 = HIGH;
            }
            
            else if (acao == "002"){
              servidor.print("b");
              RELE1 = LOW;
            }
            else if (acao == "003"){
              servidor.print("c");
              RELE2 = HIGH;
            }
            else if (acao == "004"){
              servidor.print("d");
              RELE2 = LOW;
            }
            else if (acao == "005"){
              servidor.print("e");
              RELE3 = HIGH;
            }
            else if (acao == "006"){
              servidor.print("f");
              RELE3 = LOW;
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
            
            client.print("\"LUZ1\" : \"");
            if(RELE1 == HIGH){
               client.print("001");
            } else if (RELE1 == LOW) {
               client.print("002");
            }
            client.print("\",");
            
            
            client.print("\"LUZ2\" : \"");
            if(RELE2 == HIGH){
               client.print("003");
            } else if (RELE2 == LOW) {
               client.print("004");
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
            
            
            
           
            client.print("\"");
            
            client.print("})");
            
            digitalWrite(22, 1);
         }          
          break;
        }
        if(c == '\n') { continua = true; }
        else if (c != '\r') { continua = false; }
      }
    }
     delay(1);
     digitalWrite(22, 0);
     client.stop();
  }
}
