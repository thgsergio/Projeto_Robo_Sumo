#include "../classe_two_motor.h"

/* *** Definições dos Pinos *** */
#define MOTOR_A1 10
#define MOTOR_A2 9
#define MOTOR_B1 6
#define MOTOR_B2 5
#define ECHO 11
#define TRIGGER 12
#define pino_sensor 2 

// Criação dos objeto controlador
SumoRobotController robo;

// Variáveis importantes
int estadoSensor = 0;
float duracao_pulso = 0;
int distancia_oponente = 0;

// Procura do inimigo
void roboProcura(){
  robo.forward();
  delay(300);
  robo.left();
  delay(300);
}

// Configurações iniciais
void setup() {
  robo.setPins(MOTOR_A1, MOTOR_A2, MOTOR_B1, MOTOR_B2);
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
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGGER, LOW);
  
  duracao_pulso = pulseIn(ECHO, HIGH);
  distancia_oponente = (duracao_pulso * 0.0343) / 2;

  // Código para debugs
  Serial.print("Ultrassonic: ");
  Serial.println(distancia_oponente);

  Serial.print("Line sensor: ");
  Serial.println(estadoSensor);

  if (estadoSensor == 0){ // Enquanto o robô não vê a linha da arena...
    
    if(distancia_oponente <= 50){
        robo.setSpeed(250);

      while (estadoSensor != 1){
        estadoSensor = digitalRead(pino_sensor);
        robo.forward();
      }

    }
    else {

      robo.setSpeed(120);

      // Procurar robô adversário
      roboProcura();

    }
  }

  else { // Identificou a linha: marcha ré e meia volta
    robo.backward();
    delay(1000);
    robo.right();
    delay(1000);
  }
}
