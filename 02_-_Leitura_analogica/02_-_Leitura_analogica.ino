/*
 * Lê uma porta analógica e informa o estado pela serial
 */

int pinoEntrada = A1;
int leituraPino;

void setup() {  
  //Define a velocidade da transmissão serial
  Serial.begin(9600);
}

void loop() { 
  //Lê o pino de entrada
  leituraPino = analogRead(pinoEntrada);

  //Informa o resultado da leitura pela porta serial;
  Serial.println(leituraPino);

  //Delay de 0,5s
  delay(500);
}
