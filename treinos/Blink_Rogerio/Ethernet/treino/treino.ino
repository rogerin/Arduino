#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10,0,0, 177);

// String que representa o estado dos dispositivos
char Luz[7] = "0000L#";
 
EthernetServer server(8081); // Cria o servidor na porta 8081
 
// String onde é guardada as msgs recebidas
char msg[7] = "0000L#";
 
void setup() {
  Ethernet.begin(mac, ip);
  server.begin();
  pinMode(26,OUTPUT); digitalWrite(26, HIGH); 
  pinMode(27,OUTPUT); digitalWrite(27, HIGH);
  pinMode(28,OUTPUT); digitalWrite(28, HIGH);
  pinMode(29,OUTPUT); digitalWrite(29, HIGH);
  pinMode(30,OUTPUT); digitalWrite(30, HIGH);
  pinMode(31,OUTPUT); digitalWrite(31, HIGH);
}
 
void loop() {
  EthernetClient client = server.available();
  // SE receber um caracter...
  if (client) {
    // guarda o caracter na string 'msg'
    msg[1]=msg[2];
    msg[2]=msg[3];
    msg[3]=msg[4];
    msg[4]=msg[5];
    msg[5]=msg[6];
    msg[6] = client.read();
   
    if (msg[6]=='#') {
      switch(msg[5]) {
        case 'R':
          // Se receber o comando 'R#' envia de volta o status dos
          //   dispositivos. (Que é a string 'Luz')
          client.write(Luz);
        break;
        case 'P':
          /* Caso P#, aciona o pino do portão pequeno por 1s.
          digitalWrite(A4,HIGH);
          delay(1000);
          digitalWrite(A4,LOW);
          */
        break;
        case 'G':
          /* Caso G#, aciona o pino do portão pequeno por 1s.
          digitalWrite(A5,HIGH);
          delay(1000);
          digitalWrite(A5,LOW);
  */        
        break;
        case 'L':
          // Caso L#, ele copia os 4 bytes anteriores p/ a
          //   string 'Luz' e cada byte representa um
          // dispositivo, onde '1'=ON e '0'=OFF
          Luz[0]=msg[1];
          Luz[1]=msg[2];
          Luz[2]=msg[3];
          Luz[3]=msg[4];
          if (Luz[0]=='1') digitalWrite(26,HIGH); else digitalWrite(26,LOW);
          if (Luz[1]=='1') digitalWrite(27,HIGH); else digitalWrite(27,LOW);
          if (Luz[2]=='1') digitalWrite(28,HIGH); else digitalWrite(28,LOW);
          if (Luz[3]=='1') digitalWrite(29,HIGH); else digitalWrite(29,LOW);
        break;
       
      }
    }
  }
}
 
