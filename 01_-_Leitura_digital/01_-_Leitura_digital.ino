/*
 * Lê uma porta digital e informa o estado pela serial
 */

int pinoEntrada = 10;
boolean leituraPino;

void setup() {  
  //Configura o pino como entrada
  pinMode(pinoEntrada, INPUT);

  //Define a velocidade da transmissão serial
  Serial.begin(9600);
}

void loop() { 
  //Lê o pino de entrada
  leituraPino = digitalRead(pinoEntrada);

  //Informa o resultado da leitura pela porta serial
  Serial.println(leituraPino);

  //Delay de 0,5s
  delay(500);
}
