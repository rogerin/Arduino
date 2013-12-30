#include <SPI.h>
#include <Ethernet.h>
#include <Bounce.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

IPAddress ip(192,168,1,111);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

EthernetServer server(1001);

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

#define LUZ1 38
#define LUZ2 39
#define LUZ3 6
#define LUZ4 41
#define LUZ5 42
#define LUZ6 43
#define LUZ7 44
#define LUZ8 45
#define LUZ9 46
#define LUZ10 47
#define LUZ11 48
#define LUZ12 49
#define LUZ13 2
#define LUZ14 3
#define LUZ15 4
#define LUZ16 5

int RELE1 = 1;
int RELE2 = 1;
int RELE3 = 1;
int RELE4 = 1;
int RELE5 = 1;
int RELE6 = 1;
int RELE7 = 1;
int RELE8 = 1;
int RELE9 = 1;
int RELE10 = 1;
int RELE11 = 1;
int RELE12 = 1;
int RELE13 = 1;
int RELE14 = 1;
int RELE15 = 1;
int RELE16 = 1;

Bounce bon1 = Bounce( BUTTON1, 50 ); 
Bounce bon2 = Bounce( BUTTON2, 50 ); 
Bounce bon3 = Bounce( BUTTON3, 50 );
Bounce bon4 = Bounce( BUTTON4, 50 );
Bounce bon5 = Bounce( BUTTON5, 50 );
Bounce bon6 = Bounce( BUTTON6, 50 );
Bounce bon7 = Bounce( BUTTON7, 50 );
Bounce bon8 = Bounce( BUTTON8, 50 );
Bounce bon9 = Bounce( BUTTON9, 50 );
Bounce bon10 = Bounce( BUTTON10, 50 );
Bounce bon11 = Bounce( BUTTON11, 50 );
Bounce bon12 = Bounce( BUTTON12, 50 );
Bounce bon13 = Bounce( BUTTON13, 50 );
Bounce bon14 = Bounce( BUTTON14, 50 );
Bounce bon15 = Bounce( BUTTON15, 50 );
Bounce bon16 = Bounce( BUTTON16, 50 );


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

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando programa..");
  Ethernet.begin(mac,ip,gateway,subnet);
  server.begin();
  Serial.println("Server ativo no IP: ");
  Serial.print(Ethernet.localIP());
  
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
    digitalWrite(BUTTON1, 1);
    digitalWrite(BUTTON2, 1);
    digitalWrite(BUTTON3, 1);
    digitalWrite(BUTTON4, 1);
    digitalWrite(BUTTON5, 1);
    digitalWrite(BUTTON6, 1);
    digitalWrite(BUTTON7, 1);
    digitalWrite(BUTTON8, 1);
    digitalWrite(BUTTON9, 1);
    digitalWrite(BUTTON10, 1);
    digitalWrite(BUTTON11, 1);
    digitalWrite(BUTTON12, 1);
    digitalWrite(BUTTON13, 1);
    digitalWrite(BUTTON14, 1);
    digitalWrite(BUTTON15, 1);
    digitalWrite(BUTTON16, 1);
    
    
    // Configurando RELES
    pinMode(LUZ1,OUTPUT);
    pinMode(LUZ2,OUTPUT);
    pinMode(LUZ3,OUTPUT);
    pinMode(LUZ4,OUTPUT);
    pinMode(LUZ5,OUTPUT);
    pinMode(LUZ6,OUTPUT);
    pinMode(LUZ7,OUTPUT);
    pinMode(LUZ8,OUTPUT);
    pinMode(LUZ9,OUTPUT);
    pinMode(LUZ10,OUTPUT);
    pinMode(LUZ11,OUTPUT);
    pinMode(LUZ12,OUTPUT);
    pinMode(LUZ13,OUTPUT);
    pinMode(LUZ14,OUTPUT);
    pinMode(LUZ15,OUTPUT);
    pinMode(LUZ16,OUTPUT);
 
    digitalWrite(LUZ1,RELE1);
    digitalWrite(LUZ2,RELE2);
    digitalWrite(LUZ3,RELE3);
    digitalWrite(LUZ4,RELE4);
    digitalWrite(LUZ5,RELE5);
    digitalWrite(LUZ6,RELE6);
    digitalWrite(LUZ7,RELE7);
    digitalWrite(LUZ8,RELE8);
    digitalWrite(LUZ9,RELE9);
    digitalWrite(LUZ10,RELE10);
    digitalWrite(LUZ11,RELE11);
    digitalWrite(LUZ12,RELE12);
    digitalWrite(LUZ13,RELE13);
    digitalWrite(LUZ14,RELE14);
    digitalWrite(LUZ15,RELE15);
    digitalWrite(LUZ16,RELE16);
    
  }
void loop()
{
  if ( bon1.update() ) {
     if ( bon1.read() == 1) {
       if ( RELE1 == 0 ) {
         RELE1 = 1;
       } else {
         RELE1 = 0;
       }
       digitalWrite(LUZ1,RELE1);
     }
   }  
 
   if ( bon2.update() ) {
     if ( bon2.read() == 1) {
       if ( RELE2 == 0 ) {
         RELE2 = 1;
       } else {
         RELE2 = 0;
       }
       digitalWrite(LUZ2,RELE2);
     }
   }
   
   if ( bon3.update() ) {
     if ( bon3.read() == 1) {
       if ( RELE3 == 0 ) {
         RELE3 = 1;
       } else {
         RELE3 = 0;
       }
        digitalWrite(LUZ3,RELE3);
     }
   }

   if ( bon4.update() ) {
     if ( bon4.read() == 1) {
       if ( RELE4 == 0 ) {
         RELE4 = 1;
       } else {
         RELE4 = 0;
       }
        digitalWrite(LUZ4,RELE4);
        Serial.println(RELE4);
     }
   }
   
   if ( bon5.update() ) {
     if ( bon5.read() == 1) {
       if ( RELE5 == 0 ) {
             RELE5 = 1;
       } else {
         RELE5 = 0;
       }
        digitalWrite(LUZ5,RELE5);
     }
   }
   
   if ( bon6.update() ) {
     if ( bon6.read() == 1) {
       if ( RELE6 == 0 ) {
          RELE6 = 1;
       } else {
         RELE6 = 0;
       }
        digitalWrite(LUZ6,RELE6);
     }
   }
     
   if ( bon7.update() ) {
     if ( bon7.read() == 1) {
       if ( RELE7 == 0 ) {
         RELE7 = 1;
       } else {
         RELE7 = 0;
       }
        digitalWrite(LUZ7,RELE7);
     }
   }
   
   if ( bon8.update() ) {
     if ( bon8.read() == 1) {
       if ( RELE8 == 0 ) {
         RELE8 = 1;
       } else {
         RELE8 = 0;
       }
        digitalWrite(LUZ8,RELE8);
     }
   }
   
   if ( bon9.update() ) {
     if ( bon9.read() == 1) {
       if ( RELE9 == 0 ) {
         RELE9 = 1;
       } else {
         RELE9 = 0;
       }
        digitalWrite(LUZ9,RELE9);
     }
   }
   
   if ( bon10.update() ) {
     if ( bon10.read() == 1) {
       if ( RELE10 == 0 ) {
         RELE10 = 1;
       } else {
         RELE10 = 0;
       }
        digitalWrite(LUZ10,RELE10);
     }
   }
   
   if ( bon11.update() ) {
     if ( bon11.read() == 1) {
       if ( RELE11 == 0 ) {
         RELE11 = 1;
       } else {
         RELE11 = 0;
       }
        digitalWrite(LUZ11,RELE11);
     }
   }
   
   if ( bon12.update() ) {
     if ( bon12.read() == 1) {
       if ( RELE12 == 0 ) {
         RELE12 = 1;
       } else {
         RELE12 = 0;
       }
        digitalWrite(LUZ12,RELE12);
     }
   }
   
   if ( bon13.update() ) {
     if ( bon13.read() == 1) {
       if ( RELE13 == 0 ) {
         RELE13 = 1;
       } else {
         RELE13 = 0;
       }
        digitalWrite(LUZ13,RELE13);
     }
   }
   
   if ( bon14.update() ) {
     if ( bon14.read() == 1) {
       if ( RELE14 == 0 ) {
         RELE14 = 1;
       } else {
         RELE14 = 0;
       }
        digitalWrite(LUZ14,RELE14);
     }
   }
 
   if ( bon15.update() ) {
     if ( bon15.read() == 1) {
       if ( RELE15 == 0 ) {
         RELE15 = 1;
       } else {
         RELE15 = 0;
       }
        digitalWrite(LUZ15,RELE15);
     }
   }
   
   if ( bon16.update() ) {
     if ( bon16.read() == 1) {
       if ( RELE16 == 0 ) {
         RELE16 = 1;
       } else {
         RELE16 = 0;
       }
        digitalWrite(LUZ16,RELE16);
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
          client.println("Access-Control-Al0-Origin: *");
          client.println();
          
          int iniciofrente = linha.indexOf("?");
        
          if(iniciofrente>-1){     //verifica se o comando veio
            iniciofrente     = iniciofrente+6; //pega o caractere seguinte
            int fimfrente    = iniciofrente+3; //esse comando espero 3 caracteres
            String acao    = linha.substring(iniciofrente,fimfrente);//recupero o valor do comando
            
            if      ( acao == "001"){ RELE1 = HIGH; digitalWrite(LUZ1, RELE1); } 
            else if ( acao == "002"){ RELE1 = LOW; digitalWrite(LUZ1, RELE1);  } 
            
            else if ( acao == "003"){ RELE2 = HIGH; digitalWrite(LUZ2, RELE2); }
            else if ( acao == "004"){ RELE2 = LOW; digitalWrite(LUZ2, RELE2); }
            
            else if ( acao == "005"){ RELE3 = HIGH; digitalWrite(LUZ3, RELE3);  } 
            else if ( acao == "006"){ RELE3 = LOW; digitalWrite(LUZ3, RELE3); }
            
            else if ( acao == "007"){ RELE4 = HIGH; digitalWrite(LUZ4, RELE4); }
            else if ( acao == "008"){ RELE4 = LOW; digitalWrite(LUZ4, RELE4);  } 
            
            else if ( acao == "009"){ RELE5 = HIGH; digitalWrite(LUZ5, RELE5); }
            else if ( acao == "010"){ RELE5 = LOW; digitalWrite(LUZ5, RELE5); }
            
            else if ( acao == "011"){ RELE6 = HIGH; digitalWrite(LUZ6, RELE6);  } 
            else if ( acao == "012"){ RELE6 = LOW; digitalWrite(LUZ6, RELE6); }
            
            else if ( acao == "013"){ RELE7 = HIGH; digitalWrite(LUZ7, RELE7); }
            else if ( acao == "014"){ RELE7 = LOW; digitalWrite(LUZ7, RELE7);  } 
            
            else if ( acao == "015"){ RELE8 = HIGH; digitalWrite(LUZ8, RELE8); }
            else if ( acao == "016"){ RELE8 = LOW; digitalWrite(LUZ8, RELE8); }
            
            else if ( acao == "017"){ RELE9 = HIGH; digitalWrite(LUZ9, RELE9);  } 
            else if ( acao == "018"){ RELE9 = LOW; digitalWrite(LUZ9, RELE9); }
            
            else if ( acao == "019"){ RELE10 = HIGH; digitalWrite(LUZ10, RELE10); }
            else if ( acao == "020"){ RELE10 = LOW; digitalWrite(LUZ10, RELE10);  } 
            
            else if ( acao == "021"){ RELE11 = HIGH; digitalWrite(LUZ11, RELE11); }
            else if ( acao == "022"){ RELE11 = LOW; digitalWrite(LUZ11, RELE11); }
            
            else if ( acao == "023"){ RELE12 = HIGH; digitalWrite(LUZ12, RELE12); }
            else if ( acao == "024"){ RELE12 = LOW; digitalWrite(LUZ12, RELE12); }
            
            else if ( acao == "025"){ RELE13 = HIGH; digitalWrite(LUZ13, RELE13); }
            else if ( acao == "026"){ RELE13 = LOW; digitalWrite(LUZ13, RELE13); }
            
            else if ( acao == "027"){ RELE14 = HIGH; digitalWrite(LUZ14, RELE14); }
            else if ( acao == "028"){ RELE14 = LOW; digitalWrite(LUZ14, RELE14); }
            
            else if ( acao == "029"){ RELE15 = HIGH; digitalWrite(LUZ15, RELE15); }
            else if ( acao == "030"){ RELE15 = LOW; digitalWrite(LUZ15, RELE15); }
            
            else if ( acao == "031"){ RELE16 = HIGH; digitalWrite(LUZ16, RELE16); }
            else if ( acao == "032"){ RELE16 = LOW; digitalWrite(LUZ16, RELE16); }
            
            else {}
            
            
            client.print("dados({ \"acao\" : \"" + acao+"\", \"ip\" : \""+Ethernet.localIP()+"\""); //so imprime devolta o valor do comando, aqui vc faz o que quiser ;)
         
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
            client.print("\"},");
              
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
            } else if (RELE2 == LOW) {
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
               
            client.print("\"LUZ6\" : \"");
            if(RELE6 == HIGH){
               client.print("011");
            } else if (RELE6 == LOW) {
               client.print("012");
            }
            client.print("\",");
                
            client.print("\"LUZ7\" : \"");
            if(RELE7 == HIGH){
               client.print("013");
            } else if (RELE7 == LOW) {
               client.print("014");
            }
            client.print("\",");
               
            client.print("\"LUZ8\" : \"");
            if(RELE8 == HIGH){
               client.print("015");
            } else if (RELE8 == LOW) {
               client.print("016");
            }
            client.print("\",");
                
            client.print("\"LUZ9\" : \"");
            if(RELE9 == HIGH){
               client.print("017");
            } else if (RELE9 == LOW) {
               client.print("018");
            }
            client.print("\",");
               
            client.print("\"LUZ10\" : \"");
            if(RELE10 == HIGH){
               client.print("019");
            } else if (RELE10 == LOW) {
               client.print("020");
            }
            client.print("\",");
               
            client.print("\"LUZ11\" : \"");
            if(RELE11 == HIGH){
               client.print("021");
            } else if (RELE11 == LOW) {
               client.print("022");
            }
            client.print("\",");
               
            client.print("\"LUZ12\" : \"");
            if(RELE12 == HIGH){
               client.print("023");
            } else if (RELE12 == LOW) {
               client.print("024");
            }
            client.print("\",");
               
            client.print("\"LUZ13\" : \"");
            if(RELE13 == HIGH){
               client.print("025");
            } else if (RELE13 == LOW) {
               client.print("026");
            }
            client.print("\",");
               
            client.print("\"LUZ14\" : \"");
            if(RELE14 == HIGH){
               client.print("027");
            } else if (RELE14 == LOW) {
               client.print("028");
            }
            client.print("\",");
               
            client.print("\"LUZ15\" : \"");
            if(RELE15 == HIGH){
               client.print("029");
            } else if (RELE15 == LOW) {
               client.print("030");
            }
            client.print("\",");
                
            client.print("\"LUZ16\" : \"");
            if(RELE16 == HIGH){
               client.print("031");
            } else if (RELE16 == LOW) {
               client.print("032");
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
