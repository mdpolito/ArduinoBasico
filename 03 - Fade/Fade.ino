/*
 * Controla a luminosidade de um LED através de dois push_buttons
 */

int nivelSaida = 0;
int pinoLed = 5;
int pinoBotaoDiminui = 2;
int pinoBotaoAumenta = 3;

void setup() {
  //Define os pinos de entrada e saída  
  pinMode(pinoBotaoDiminui,INPUT);
  pinMode(pinoBotaoAumenta,INPUT);
  pinMode(pinoLed,OUTPUT);

  //Apaga o LED
  analogWrite(pinoLed,0);
}

void loop() {
  //Verifica se somente um botão foi pressionado e aumenta a luminosidade até chegar o nível máximo (255)
  if(digitalRead(pinoBotaoDiminui)==LOW && digitalRead(pinoBotaoAumenta)==HIGH && nivelSaida!=255){
    nivelSaida = nivelSaida + 1;
    analogWrite(pinoLed,nivelSaida);
    delay(10);
  } 
  
  //Verifica se somente um botão foi pressionado e diminui a luminosidade até chegar o nível mínimo (0)
  if(digitalRead(pinoBotaoDiminui)==HIGH && digitalRead(pinoBotaoAumenta)==LOW && nivelSaida!=0){
    nivelSaida = nivelSaida - 1;
    analogWrite(pinoLed,nivelSaida);
    delay(10);
  }

}
