//Inclui a biblioteca serial
#include <SoftwareSerial.h>

//Define os pinos para a comunicação serial do módulo bluetooth (RX, TX)
SoftwareSerial MinhaSerial(6,7);

//Define os pinos de saída
#define ESQUERDA_FRENTE 2
#define ESQUERDA_RE 3
#define DIREITA_FRENTE 4
#define DIREITA_RE 5

//Define a variável de comando
char comando = '0';

void setup(){
	//Inicia a serial configurada nas portas 6 e 7
	MinhaSerial.begin(115200);
  
	//Inicializa os pinos que irão acionar os motores
	pinMode(ESQUERDA_FRENTE,OUTPUT);
	pinMode(ESQUERDA_RE,OUTPUT);
	pinMode(DIREITA_FRENTE,OUTPUT);
	pinMode(DIREITA_RE,OUTPUT);

	//Coloca o carrinho parado
	digitalWrite(ESQUERDA_FRENTE,LOW);
	digitalWrite(ESQUERDA_RE,LOW);
	digitalWrite(DIREITA_FRENTE,LOW);
	digitalWrite(DIREITA_RE,LOW);
}


void loop(){
	if (MinhaSerial.available()) {
    while(MinhaSerial.available()) {
      comando = (char)MinhaSerial.read(); //Lê os dados provenientes do módulo bluetooth
	  }
   
		//Movimentação:

    //0 - Parar
    if (comando=='0') {
     digitalWrite(ESQUERDA_FRENTE,LOW);
     digitalWrite(ESQUERDA_RE,LOW);
     digitalWrite(DIREITA_FRENTE,LOW);
     digitalWrite(DIREITA_RE,LOW);
    }
    
    //1 - Andar para frente
    if (comando=='1') {
     digitalWrite(ESQUERDA_FRENTE,HIGH);
     digitalWrite(ESQUERDA_RE,LOW);
     digitalWrite(DIREITA_FRENTE,HIGH);
     digitalWrite(DIREITA_RE,LOW);
    }

    //2 - Andar para trás
    if (comando=='2') {
     digitalWrite(ESQUERDA_FRENTE,LOW);
     digitalWrite(ESQUERDA_RE,HIGH);
     digitalWrite(DIREITA_FRENTE,LOW);
     digitalWrite(DIREITA_RE,HIGH);
    }
    
    //3 - Direita para frente
    if (comando=='3') {
     digitalWrite(ESQUERDA_FRENTE,HIGH);
     digitalWrite(ESQUERDA_RE,LOW);
     digitalWrite(DIREITA_FRENTE,LOW);
     digitalWrite(DIREITA_RE,LOW);
    }

    //4 - Esquerda para frente
    if (comando=='4') {
     digitalWrite(ESQUERDA_FRENTE,LOW);
     digitalWrite(ESQUERDA_RE,LOW);
     digitalWrite(DIREITA_FRENTE,HIGH);
     digitalWrite(DIREITA_RE,LOW);
    }
    delay(100);
  }  
  else {
  //Coloca o carrinho parado
  digitalWrite(ESQUERDA_FRENTE,LOW);
  digitalWrite(ESQUERDA_RE,LOW);
  digitalWrite(DIREITA_FRENTE,LOW);
  digitalWrite(DIREITA_RE,LOW);
  }
}
