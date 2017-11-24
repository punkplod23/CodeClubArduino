
#define trigPin 13
#define echoPin 12
#define leftMotorPinCW 2//in1
#define leftMotorPinCCW 3//in2
#define rightMotorPinCW 4//in3
#define rightMotorPinCCW 5//in4

int randNumber;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftMotorPinCW, OUTPUT);
  pinMode(rightMotorPinCW, OUTPUT);
  pinMode(leftMotorPinCCW, OUTPUT);
  pinMode(rightMotorPinCCW, OUTPUT);
  randomSeed(analogRead(0));
}


void forwards(){
  digitalWrite(leftMotorPinCW,LOW);
  digitalWrite(rightMotorPinCW,HIGH);
  digitalWrite(leftMotorPinCCW,HIGH);
  digitalWrite(rightMotorPinCCW,LOW);
  Serial.println("forwards");
}

void left(){
  digitalWrite(leftMotorPinCW,HIGH);
  digitalWrite(rightMotorPinCCW,LOW);
  digitalWrite(leftMotorPinCCW,LOW);
  digitalWrite(rightMotorPinCW,HIGH);
}

void right(){
  digitalWrite(leftMotorPinCW,LOW);
  digitalWrite(rightMotorPinCCW,HIGH);
  digitalWrite(leftMotorPinCCW,HIGH);
  digitalWrite(rightMotorPinCW,LOW);
}

void backwards(){ 
  digitalWrite(leftMotorPinCW,LOW);
  digitalWrite(rightMotorPinCCW,HIGH);
  digitalWrite(leftMotorPinCCW,HIGH);
  digitalWrite(rightMotorPinCW,LOW);
}

void loop() {
  randNumber = random(2);
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  forwards();
    
    if (distance < 30) { 
      //need to turn - random
      if (randNumber == 0){
        Serial.println("turning left");
        left();
      }
      else{
        Serial.println("turning right");
        right();
      }
    }
  
    if (distance >= 200 || distance <= 0){
      Serial.println("Out of range");
    }
    else {
      Serial.print(distance);
      Serial.println(" cm");
    }
    delay(500);
}


