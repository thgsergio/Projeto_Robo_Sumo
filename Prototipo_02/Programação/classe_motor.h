class DCMotor {
  private:
    int speed, in1, in2;
  
  public:

    DCMotor(){
      speed = 200;
    }
    DCMotor(int spd){
      if (spd > 255){
        speed = 255;
      }
      else if (spd < 0){
        speed = 0;
      }
      else {
        speed = spd;
      }
    }
    DCMotor(int spd, int pin1, int pin2) : DCMotor(spd){
      in1 = pin1;
      in2 = pin2;
    }
    
    void setPin(int pin1, int pin2){
      in1 = pin1;
      in2 = pin2;
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
    }

    int getSpeed(){
      return speed;
    }

    void setSpeed(int spd){
      if (spd > 255){
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
      analogWrite(in1, speed);
      digitalWrite(in2, LOW);
    }

    void backward(){
      digitalWrite(in1, LOW);
      analogWrite(in2, speed);
    }

    void stop(){
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
};

