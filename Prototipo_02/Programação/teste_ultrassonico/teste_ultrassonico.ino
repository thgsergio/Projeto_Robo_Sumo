#include "../classe_two_motor.h"

#define MOTOR_A1 10
#define MOTOR_A2 9
#define MOTOR_B1 6
#define MOTOR_B2 5
#define ECHO 11
#define TRIGGER 12

SumoRobotController robo;
double duracao;
float distancia;

void setup(){
    robo.setPins(MOTOR_A1, MOTOR_A2, MOTOR_B1, MOTOR_B2);
    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
}

void loop(){
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  duracao = pulseIn(ECHO, HIGH); // Em microssegundos
  distancia = (duracao * 0.0343) / 2; // Em centímetros

  if(distancia >= 50){
    robo.forward();
  }
  else{
    robo.backward();
  }

}