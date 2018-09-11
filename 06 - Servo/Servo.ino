//Inclui a biblioteca do servo motor
#include <Servo.h>

//Define uma variável do tipo Servo
Servo servo;

int pinoServo = 9; //pino onde o servo motor será ligado
int pinoPot = A0; //pino de ligação do potenciômetro
int leitura; //variável de leitura analógica

int anguloMinimo = 45; //ângulo mínimo de rotação do servo motor
int anguloMaximo = 135; //ângulo máximo de rotação do servo motor

void setup() {
  servo.attach(pinoServo); //conecta o servo
  servo.write(0); //Coloca o servo na posição de zero grau para uma referência
  delay(2000); //Aguarda 2 segundos
}

void loop() {
  leitura = analogRead(pinoPot); //Lê o valor do potenciômetro pela entrada analógica - varia de 0 (zero volts) a 1023 (5 Volts)
  leitura = map(leitura, 0, 1023, anguloMinimo, anguloMaximo); //Remapeia o valor lido para o mínimo e o máximo de rotação
  servo.write(leitura); //Faz o servo se posicionar no ângulo remapeado
}
