class DCMotor {
  
  public:
    int speed = 200, in1, in2;

    DCMotor();
    
    void setPin(pin1, pin2){
      in1 = pin1;
      in2 = pin2;
      pinMode(in1, OUTPUT);
      pinMode(in2, OUTPUT);
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

