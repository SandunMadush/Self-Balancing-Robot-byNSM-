int enA = 10;
int enB = 11;
int in1 = 9;
int in2 = 8;
int in3 = 4;
int in4 = 6;
const int pinIRd = 7;
const int pinIRa = A0;
const int pinLED = 13;
int IRvalueA = 0;
int IRvalueD = 0;
void setup(){
  Serial.begin(9600);
  pinMode(pinIRd,INPUT);
  pinMode(pinIRa,INPUT);
  pinMode(pinLED,OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  
}

void loop(){

  Serial.print("Analog Reading=");
  Serial.print(IRvalueA);
  Serial.print("\t Digital Reading=");
  Serial.println(IRvalueD);

    if (IRvalueD == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    MotorControl(1,1,255);
  }
  else {
    digitalWrite(LED_BUILTIN, LOW);
    MotorControl(1,-1,255);
}


  delay(500);
  
  IRvalueA = analogRead(pinIRa);
  IRvalueD = digitalRead(pinIRd);
  
  
  
  
}

void MotorControl(int Mname, int rotation, int spd){
  int pwm;
  int pA;
  int pB;
  
  // 1 = left motor
  // 2 = right motor

  if (Mname == 1){
    pwm = enA;
    pA = in1;
    pB = in2;
  }else if (Mname == 2){
    pwm = enB;
    pA = in3;
    pB = in4;
  }else{
    return;
  }

  /*
   * -1 = backword
   * 0 = stop
   * 1 = forword
   */

  if (rotation == 0){
    digitalWrite (pA, LOW);
    digitalWrite (pB, LOW);
    
  }else if (rotation == 1){
    digitalWrite (pA, HIGH);
    digitalWrite (pB, LOW);
    
  }else if (rotation == -1){
    digitalWrite (pA, LOW);
    digitalWrite (pB, HIGH);
  }
  analogWrite (pwm, spd);
  
}
