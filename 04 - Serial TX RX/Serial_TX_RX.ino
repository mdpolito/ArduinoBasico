/*
 * Envia e recebe dados do computador para acender e apagar um LED
 */

//Definição das variáveis
int pinoEntrada = 10;
int pinoSaida = 7;
String comando = "";
boolean ledLigado = false; //Variável que armazena informação do estado do led, independente de quem executou (a string recebida do computador ou o push-button) 

void setup() {
  Serial.begin(9600); //Definie a velocidade da serial
  pinMode(pinoEntrada,INPUT); //Define a variável pinoEntrada como entrada
  pinMode(pinoSaida,OUTPUT);  //Define a variável pinoSaida como saída
  digitalWrite(pinoSaida,LOW); //Apaga o LED
}

void loop() {
  //Verifica se a serial tem informação a ser recebida
  if (Serial.available()) {
    //Enquanto existirem dados na serial, executa o loop
    while (Serial.available()){
      comando = Serial.readString(); //Lê uma string da serial
    }
    //Liga o led
    if(comando=="LIGA"){ 
      digitalWrite(pinoSaida,HIGH);
      ledLigado= true;    
    }
    //Desliga o led
    if(comando=="DESLIGA"){
      digitalWrite(pinoSaida,LOW);
      ledLigado = false;
    }
  }

  //Se o push-button for acionado, troca o estado do led e envia pela serial para o computador
  if(digitalRead(pinoEntrada) == LOW){
    if(ledLigado){
      digitalWrite(pinoSaida,LOW);
      ledLigado = false;
    }
    else {
      digitalWrite(pinoSaida,HIGH);
      ledLigado = true;
    }
    Serial.println(ledLigado);
    delay(500);
  }


}
