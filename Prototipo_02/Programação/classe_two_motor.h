#ifndef SUMO_ROBOT_CONTROLLER_H
#define SUMO_ROBOT_CONTROLLER_H

typedef enum{
    MOTOR_A,
    MOTOR_B
} Motors;

class SumoRobotController {
    private:
        // Motor A: esquerda
        // Motor B: direita
        int motor_a1, motor_a2, motor_b1, motor_b2;
        int speed;

        void motorForward(Motors motor){
            if(motor == MOTOR_A){
                analogWrite(motor_a1, speed);
                digitalWrite(motor_a2, LOW);
            }
            else if (motor == MOTOR_B){
                analogWrite(motor_b1, speed);
                digitalWrite(motor_b2, LOW);
            }
        }
        void motorBackward(Motors motor){
            if(motor == MOTOR_A){
                digitalWrite(motor_a1, LOW);
                analogWrite(motor_a2, speed);
            }
            else if (motor == MOTOR_B){
                digitalWrite(motor_b1, LOW);
                analogWrite(motor_b2, speed);
            }
        }
        void motorStop(Motors motor){
            if(motor == MOTOR_A){
                digitalWrite(motor_a1, LOW);
                digitalWrite(motor_a2, LOW);
            }
            else if(motor == MOTOR_B){
                digitalWrite(motor_b1, LOW);
                digitalWrite(motor_b2, LOW);
            }
        }

    public:
        SumoRobotController() : motor_a1(0), motor_a2(0), motor_b1(0), motor_b2(0) {
            speed = 200;
        }
        SumoRobotController(int a1, int a2, int b1, int b2) : speed(200) {
            setPins(a1, a2, b1, b2);
        }
        
        void setPins(int a1, int a2, int b1, int b2){
            motor_a1 = a1;
            motor_a2 = a2;
            motor_b1 = b1;
            motor_b2 = b2;
            pinMode(motor_a1, OUTPUT);
            pinMode(motor_a2, OUTPUT);
            pinMode(motor_b1, OUTPUT);
            pinMode(motor_b2, OUTPUT);
        }


        int getSpeed(){
            return speed;
        }

        void setSpeed(int spd){
            if (spd > 255){ // Valor máximo
                speed = 255;
            }
            else if (spd < 0){
                speed = 0;
            }
            else {
                speed = spd;
            }
        }


        void forward(){
            motorForward(MOTOR_A);
            motorForward(MOTOR_B);
        }

        void backward(){
            motorBackward(MOTOR_A);
            motorBackward(MOTOR_B);
        }

        void left(){
            motorBackward(MOTOR_A);
            motorForward(MOTOR_B);
        }

        void right(){
            motorForward(MOTOR_A);
            motorBackward(MOTOR_B);
        }

        void stop(){
            motorStop(MOTOR_A);
            motorStop(MOTOR_B);
        }

};

#endif