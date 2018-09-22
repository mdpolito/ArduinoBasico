#include <Servo.h>

int controleServoGarra = A0;
int controleServoProf = A1;
int controleServoAlt = A2;
int controleServoRot = A3;

int pinoServoGarra = 11;
int pinoServoProf = 9;
int pinoServoAlt = 5;
int pinoServoRot = 3;

int anguloMinGarra = 0;
int anguloMaxGarra = 35;

int anguloMinProf = 45;
int anguloMaxProf = 180;

int anguloMinAlt = 95;
int anguloMaxAlt = 180;

int anguloMinRot = 0;
int anguloMaxRot = 180;

Servo servoGarra;
Servo servoProf;
Servo servoAlt;
Servo servoRot;

void setup() {
  servoGarra.attach(pinoServoGarra);
  servoProf.attach(pinoServoProf);
  servoAlt.attach(pinoServoAlt);
  servoRot.attach(pinoServoRot);
}

void loop() {
  servoGarra.write(map(analogRead(controleServoGarra),0,1023,anguloMinGarra,anguloMaxGarra));
  servoProf.write(map(analogRead(controleServoProf),0,1023,anguloMinProf,anguloMaxProf));
  servoAlt.write(map(analogRead(controleServoAlt),0,1023,anguloMinAlt,anguloMaxAlt));
  servoRot.write(map(analogRead(controleServoRot),0,1023,anguloMinRot,anguloMaxRot));
}
