
//Define as variáveis
int pinoSaida = 10;
long tempoInicial;
long tempoFinal;
long tempoTotal;
double capacitancia;
int pinoCapacitor;
double resistencia = 1000.0;

void setup() {
  //Configura o pino para saída
  pinMode(pinoSaida,OUTPUT);
  digitalWrite(pinoSaida,LOW);

  //Configura a velocidade da serial
  Serial.begin(9600);
}

void loop() {
  
  //Coloca o pino em estado baixo para descarregar o capacitor
  digitalWrite(pinoSaida,LOW);
  
  //Lê a tensão no capacitor
  pinoCapacitor = analogRead(A0);
  
  //Continua a descarga do capacitor enquanto a sua tensão for maior que 0,05 Volts 
  while(pinoCapacitor > 10) { //Se 1023 corresponde a 5 Volts, então 0,05 Volts corresponde a 10  
    pinoCapacitor = analogRead(A0);
  }
  
  //Marca o tempo inicial 
  tempoInicial = micros();
  
  //Coloca o pino em estado alto para carregar o capacitor
  digitalWrite(pinoSaida,HIGH);

  //Continua a carga do capacitor enquanto sua tensão for menor que 3,16 Volts (63,2% de 5 Volts)
  while(pinoCapacitor < 647) { //Se 1023 corresponde a 5 Volts, então 3,16 Volts corresponde a 647  
    pinoCapacitor = analogRead(A0);
  }

  //Marca o tempo final
  tempoFinal = micros();
  
  //Calcula o tempo total (constante de tempo)
  tempoTotal = tempoFinal - tempoInicial;

  //Calcula a capacitância
  capacitancia = tempoTotal / resistencia;

  //Envia o valor do capacitor pela serial
  Serial.println("Capacitância: " + (String)capacitancia);

}
