#include "../classe_two_motor.h"

#define MOTOR_A1 10
#define MOTOR_A2 9
#define MOTOR_B1 6
#define MOTOR_B2 5
#define SENSOR 2

SumoRobotController robo;
int sensorRead;

void setup(){
    robo.setPins(MOTOR_A1, MOTOR_A2, MOTOR_B1, MOTOR_B2);
    pinMode(SENSOR, INPUT);
}

void loop(){
    sensorRead = digitalRead(SENSOR);

    if(sensorRead){
        robo.forward();
    }
    else{
        robo.stop();
    }
}
