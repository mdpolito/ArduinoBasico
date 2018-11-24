/*
  Exemplo de um servidor para monitorar uma porta no Arduino
*/

#include <Ethernet.h>

// MAC Address
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

// Endereço de IP (Verificar o IP da rede através do comando "ipconfig")
IPAddress ip(192, 168, 0, 20);

// Inicializa o servidor na porta padrão (porta 80)
EthernetServer server(80);


void setup() {  
  //Configura a porta de entrada para o monitoramento
  pinMode(6, INPUT);
  
  // Inicializa o servidor
  Ethernet.begin(mac, ip);
  server.begin();
}

void loop() {
  
  // Lê o estado do LED
  String estadoLed = leEstadoLed();
  
  // Verifica se há requisição do cliente
  EthernetClient client = server.available();
  if (client) {
    boolean linhaEmBranco = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        
        // Verifica o término da requisição HTTP que finaliza com uma linha em branco
        if (c == '\n' && linhaEmBranco) {
          //Envia o response para o cliente e sai do loop com o comando break
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 2"); //Faz uma requisição a cada 2 segundos
          client.println("<!DOCTYPE HTML>");
          client.println();
          client.println("<html>");
          client.println("<center> <font size=6> Verificando estado do LED <p>");
          client.println("<b>" + estadoLed + "</b>");
          client.println("</html>");
          break;
        }
        
        //Verifica se a próxima linha está em branco
        if (c == '\n') {
          linhaEmBranco = true;
        } else if (c != '\r') {
          linhaEmBranco = false;
        }
        
      }
    }
    // Tempo para o navegador receber a resposta
    delay(10);
    // Finaliza a conexão
    client.stop();
  }
}


// ======================================
// Método que lê o nível aplicado no LED
// ======================================
String leEstadoLed() {   
  if (digitalRead(6) == HIGH){
    return "ACESO";
  }
  else if(digitalRead(6) == LOW) {
    return "APAGADO";
  }
}
