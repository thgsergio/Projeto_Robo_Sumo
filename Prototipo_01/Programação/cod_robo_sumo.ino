/* *** Definições dos Pinos *** */
#define MOTOR_A1 10
#define MOTOR_A2 9
#define MOTOR_B1 6
#define MOTOR_B2 5
#define ECHO 11
#define TRIGGER 12
#define pino_sensor 2

/* *********** Variaveis importantes *********** */
int estado_sensor = 0;

int duracao_ult;
int distancia_ult;

int intervalo_troca_direcao = 1000;
int estado_motor = 0; // 0 = direita ; 1 = esquerda
int intervalo_anterior = 0;

int velocidade_motor;

/* *********** Configurações *********** */
void setup() {
  definir_velocidade(200);
  pinMode(pino_sensor, INPUT);
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);
  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(TRIGGER, OUTPUT);
}

/* ************ Função Principal ************ */
void loop() {
  // Sensor de linha
  estado_sensor = digitalRead(pino_sensor);

  // Sensor Ultrassônico
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10000);
  digitalWrite(TRIGGER, LOW);

  duracao_ult = pulseIn(ECHO, HIGH);
  distancia_ult = duracao_ult * (0.034 / 2);

  int tempo_atual = millis();
  
  // Loop principal
  if(estado_sensor == 0) {
    if (distancia_ult <= 50) {
      correr_frente();
      intervalo_anterior = tempo_atual;
    } else {
      procura_inimigos(estado_motor);
      if(tempo_atual - intervalo_anterior >= intervalo_troca_direcao){
        estado_motor = !estado_motor;
        intervalo_anterior = tempo_atual;
      }
    }
  } else if (estado_sensor == 1){
    correr_tras();
    intervalo_anterior = tempo_atual;
  }
}

void definir_velocidade(int valor){
  velocidade_motor = valor;
}

void correr_frente(){
  analogWrite(MOTOR_A1, velocidade_motor);
  analogWrite(MOTOR_B1, velocidade_motor);
  digitalWrite(MOTOR_A2, LOW);
  digitalWrite(MOTOR_B2, LOW);
}

void correr_tras(){
  digitalWrite(MOTOR_A1, LOW);
  digitalWrite(MOTOR_B1, LOW);
  analogWrite(MOTOR_A2, velocidade_motor);
  analogWrite(MOTOR_B2, velocidade_motor);
}

void virar_direita(){
  analogWrite(MOTOR_A1, velocidade_motor);
  digitalWrite(MOTOR_B1, LOW);
  digitalWrite(MOTOR_A2, LOW);
  analogWrite(MOTOR_B2, velocidade_motor);
}

void virar_esquerda(){
  digitalWrite(MOTOR_A1, LOW);
  analogWrite(MOTOR_B1, velocidade_motor);
  analogWrite(MOTOR_A2, velocidade_motor);
  digitalWrite(MOTOR_B2, LOW);
}

void procura_inimigos(int estado){
  if(estado)
    virar_direita();
  else
    virar_esquerda();
}
