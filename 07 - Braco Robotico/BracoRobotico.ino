#include <Servo.h>

int controleServoCabeca = A0;
int controleServoProf = A1;
int controleServoAlt = A2;
int controleServoRot = A3;

int pinoServoCabeca = 11;
int pinoServoProf = 9;
int pinoServoAlt = 5;
int pinoServoRot = 3;

int anguloMinCabeca = 0;
int anguloMaxCabeca = 35;

int anguloMinProf = 45;
int anguloMaxProf = 180;

int anguloMinAlt = 95;
int anguloMaxAlt = 180;

int anguloMinRot = 0;
int anguloMaxRot = 180;

Servo servoCabeca;
Servo servoProf;
Servo servoAlt;
Servo servoRot;

void setup() {
  servoCabeca.attach(pinoServoCabeca);
  servoProf.attach(pinoServoProf);
  servoAlt.attach(pinoServoAlt);
  servoRot.attach(pinoServoRot);
}

void loop() {
  servoCabeca.write(map(analogRead(controleServoCabeca),0,1023,anguloMinCabeca,anguloMaxCabeca));
  servoProf.write(map(analogRead(controleServoProf),0,1023,anguloMinProf,anguloMaxProf));
  servoAlt.write(map(analogRead(controleServoAlt),0,1023,anguloMinAlt,anguloMaxAlt));
  servoRot.write(map(analogRead(controleServoRot),0,1023,anguloMinRot,anguloMaxRot));
}
