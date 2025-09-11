#include "../classe_motor.h"

#define MOTOR_A1 10
#define MOTOR_A2 9
#define MOTOR_B1 6
#define MOTOR_B2 5

DCMotor motor1, motor2;

int tempo = 2000;

void frente();
void tras();
void esquerda();
void direita();
void parar();

void setup(){
  motor1.setPin(MOTOR_A1, MOTOR_A2);
  motor2.setPin(MOTOR_B1, MOTOR_B2);
}

void loop(){
    frente();
    delay(tempo);
    parar();
    delay(tempo);

    tras();
    delay(tempo);
    parar();
    delay(tempo);

    esquerda();
    delay(tempo);
    parar();
    delay(tempo);

    direita();
    delay(tempo);
    parar();
    delay(tempo);
}

void frente(){
  motor1.forward();
  motor2.forward();
}
void tras(){
  motor1.backward();
  motor2.backward();
}
void esquerda(){
  motor1.backward();
  motor2.forward();
}
void direita(){
  motor1.forward();
  motor2.backward();
}
void parar(){
  motor1.stop();
  motor2.stop();
}
