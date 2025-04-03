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
void roboProcura();

// Variáveis importantes
int estadoSensor = 0;

int distancia_oponente = 0;
 
// int intervalo_atual = 0;
// int intervalo_anterior = 0;
// int intervalo_roboForward = 1000;

// int intervalo_roboSearch = 1000;
// bool estado_roboSearch = 0; // 0 para não girar, 1 para girar
// int direcao_roboSearch = 0; // 0 para esquerda, 1 e 2 para direita, 3 para esquerda

// Configurações iniciais
void setup() {
  motor1.setPin(MOTOR_A1, MOTOR_A2);
  motor2.setPin(MOTOR_B1, MOTOR_B2);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(pino_sensor, INPUT);
  // Debug:
  Serial.begin(9600);
}

void loop() {
  estadoSensor = digitalRead(pino_sensor);
  //intervalo_atual = millis();

// Sensor ultrassônico
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGGER, LOW);
  distancia_oponente = (pulseIn(ECHO, HIGH)) * (0.034 / 2);

// Código para debugs
  Serial.print("Ultrassonic: ");
  Serial.println(distancia_oponente);

  Serial.print("Line sensor: ");
  Serial.println(estadoSensor);

  if (estadoSensor == 0){ // Enquanto o robô não vê a linha da arena...
    
    if(distancia_oponente <= 50){
        roboSetSpeed(250);

      while (estadoSensor != 1){
        estadoSensor = digitalRead(pino_sensor);
        roboForward();
      }

    }
    else {

      roboSetSpeed(120);

      // Procurar robô adversário
      roboProcura();

    }
  }

  else { // Identificou a linha: marcha ré e meia volta
    roboBackward();
    delay(1000);
    roboLeft();
    delay(1000);
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

void roboProcura(){
  roboForward();
  delay(300);
  roboLeft();
  delay(300);
}
