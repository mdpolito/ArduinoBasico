/*
 * Programa de efeito visual em um conjunto de 10 Leds 
 * 
 */


//Define as varáveis que representam os pinos onde os Leds estarão ligados
int LED0 = 2;
int LED1 = 3;
int LED2 = 4;
int LED3 = 5;
int LED4 = 6;
int LED5 = 7;
int LED6 = 8;
int LED7 = 9;
int LED8 = 10;
int LED9 = 11;

//Define um array de 10 leds
int LED[] = {LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8, LED9};


void setup() {
 //Define os pinos conectados aos leds como pinos de saída
 pinMode(LED0,OUTPUT);
 pinMode(LED1,OUTPUT);
 pinMode(LED2,OUTPUT);
 pinMode(LED3,OUTPUT);
 pinMode(LED4,OUTPUT);
 pinMode(LED5,OUTPUT);
 pinMode(LED6,OUTPUT);
 pinMode(LED7,OUTPUT);
 pinMode(LED8,OUTPUT);
 pinMode(LED9,OUTPUT);
}

void loop() {  
  //Chama cada método de efeito visual dos leds
  sequencia_1();
  sequencia_2();
  sequencia_3();
  sequencia_4();
  sequencia_5();
  sequencia_6();
  sequencia_7();
}


//***************************************************************************
//Método que apaga todos os Leds e os mantêm apagados por um determinado tempo (em milisegundos)
//***************************************************************************
void apagaLeds(int tempo) {
  for (int posLED = 0; posLED < 10; posLED++) {
      digitalWrite(LED[posLED],LOW);
  }
  delay(tempo);
}


//***************************************************************************
//Método que acende todos os Leds e os mantêm acesos por um determinado tempo (em milisegundos)
//***************************************************************************
void acendeLeds(int tempo) {
  for (int posLED = 0; posLED < 10; posLED++) {
      digitalWrite(LED[posLED],HIGH);
  }
  delay(tempo);
}


//***************************************************************************
//Método que faz os leds acenderem da esquerda para a direita aumentando a velocidade até que todos fiquem acesos
//***************************************************************************
void sequencia_1() {
  apagaLeds(500);
  int tempo = 50;
  do {
    for (int posLED = 0; posLED < 10; posLED++) {
      digitalWrite(LED[posLED],HIGH);
      delay(tempo);
    }
    delay(500);
    for (int posLED = 0; posLED < 10; posLED++) {
      digitalWrite(LED[posLED],LOW);
      delay(tempo);
    }
    tempo = tempo - 5;  
  } while (tempo > 0);
}

//***************************************************************************
//Método que faz os leds acenderem da direita para a esquera aumentando a velocidade até que todos fiquem acesos
//***************************************************************************
void sequencia_2() {
  apagaLeds(500);
  int tempo = 50;
  do {
    for (int posLED = 9; posLED >= 0; posLED--) {
      digitalWrite(LED[posLED],HIGH);
      delay(tempo);
    }
    delay(500);
    for (int posLED = 9; posLED >= 0; posLED--) {
      digitalWrite(LED[posLED],LOW);
      delay(tempo);
    }
    tempo = tempo - 5;  
  } while (tempo > 0);
}


//***************************************************************************
//Método que faz todos os leds piscarem juntos
//***************************************************************************
void sequencia_3() {
  apagaLeds(500);
  int tempo = 200;
  int contador = 0;

  do {
    acendeLeds(tempo);
    apagaLeds(tempo);
    contador++;
  } while (contador < 5);
}


//***************************************************************************
//Método que faz um led aceso percorrer todo o conjunto e depois faz um led apagado percorrer todo o conjunto
//***************************************************************************
void sequencia_4() {
  int tempo = 65;
  
  apagaLeds(500);
  digitalWrite(LED0,HIGH);
  delay(tempo);
  int contador = 0;
  do {
    for (int posLED = 1; posLED < 10; posLED++) {
      digitalWrite(LED[posLED],HIGH);
      digitalWrite(LED[posLED-1],LOW);
      delay(tempo);
    };
    for (int posLED = 8; posLED >= 0; posLED--) {
      digitalWrite(LED[posLED],HIGH);
      digitalWrite(LED[posLED+1],LOW);
      delay(tempo);
    }
    contador++;
  } while (contador < 3);

  acendeLeds(500);
  digitalWrite(LED0,LOW);
  delay(tempo);
  contador = 0;
  do {
    for (int posLED = 1; posLED < 10; posLED++) {
      digitalWrite(LED[posLED],LOW);
      digitalWrite(LED[posLED-1],HIGH);
      delay(tempo);
    };
    for (int posLED = 8; posLED >= 0; posLED--) {
      digitalWrite(LED[posLED],LOW);
      digitalWrite(LED[posLED+1],HIGH);
      delay(tempo);
    }
    contador++;
  } while (contador < 3);
}


//***************************************************************************
//Método que faz os leds acenderem das extremidades para o centro
//***************************************************************************
void sequencia_5() {
  apagaLeds(500);
  int tempo = 100;
  int contador = 0;
  do {
    for (int posLED = 0; posLED < 5; posLED++) {
      digitalWrite(LED[posLED],HIGH);
      digitalWrite(LED[9-posLED],HIGH);
      delay(tempo);
    };
    for (int posLED = 4; posLED >= 0; posLED--) {
      digitalWrite(LED[posLED],LOW);
      digitalWrite(LED[9-posLED],LOW);
      delay(tempo);
    }
    contador++;
  } while (contador < 5);
}


//***************************************************************************
//Método que faz um led piscar de forma aleatória
//***************************************************************************
void sequencia_6() {
  apagaLeds(500);
  int tempo = 100;
  int contador = 0;
  long ledPos;
  do {
    ledPos = random(0,10);
    digitalWrite(LED[ledPos],HIGH);
    delay(tempo);
    digitalWrite(LED[ledPos],LOW);
    contador++;
  } while (contador < 50);
}


//***************************************************************************
//Método que faz os leds acenderem e depois apagarem de forma aleatória
//***************************************************************************
void sequencia_7() {
  int tempo = 100;
  int contador = 0;
  
  apagaLeds(500);
  long ledPos;
  do {
    ledPos = random(0,10);
    digitalWrite(LED[ledPos],HIGH);
    delay(tempo);
    contador++;
  } while (contador < 20);
  acendeLeds(500);
  
  contador = 0;
  do {
    ledPos = random(0,10);
    digitalWrite(LED[ledPos],LOW);
    delay(tempo);
    contador++;
  } while (contador < 20);
  apagaLeds(500);
}
