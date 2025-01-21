#include "classe_motor.h"

/* *** Definições dos Pinos *** */
#define MOTOR_A1 10
#define MOTOR_A2 9
#define MOTOR_B1 6
#define MOTOR_B2 5
#define ECHO 11
#define TRIGGER 12
#define pino_sensor 2 

// Criação dos objetos motor
DCMotor motor1; // Motor à esquerda, robô em 1ª pessoa como referencial
DCMotor motor2; // Motor à direita, robô em 1ª pessoa como referencial

// Protótipo das funções de movimentação do robô
void roboSetSpeed(int);
void roboForward();
void roboBackward();
void roboLeft();
void roboRight();
void roboStop();

// Variáveis importantes
int estadoSensor = 0;

int intervalo_atual = 0;
int intervalo_anterior = 0;
int intervalo_roboForward = 1000;

// Configurações iniciais
void setup() {
  motor1.setPin(MOTOR_A1, MOTOR_A2);
  motor2.setPin(MOTOR_B1, MOTOR_B2);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(pino_sensor, INPUT);
}

void loop() {
  estadoSensor = digitalRead(pino_sensor);
  intervalo_atual = millis();
  if (estadoSensor == 0){
    if (intervalo_atual - intervalo_anterior < intervalo_roboForward){
      roboForward();
    }
    else{
      intervalo_anterior = intervalo_atual;
      roboStop();
    }
  }
  else {

  }


}

// Definição das funções de movimentação do robô
void roboSetSpeed(int speed){
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
}

void roboForward(){
  motor1.forward();
  motor2.forward();
}

void roboBackward(){
  motor1.backward();
  motor2.backward();
}

void roboLeft(){
  motor1.backward();
  motor2.forward();
}

void roboRight(){
  motor1.forward();
  motor2.backward();
}

void roboStop(){
  motor1.stop();
  motor2.stop();
}
