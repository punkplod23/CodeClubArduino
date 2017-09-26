```/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10*/

#define trigPin 13
#define echoPin 12
#define leftMotorPinCW 11
#define leftMotorPinCCW 6
#define rightMotorPinCW 10
#define rightMotorPinCCW 9


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(leftMotorPinCW, OUTPUT);
  pinMode(rightMotorPinCCW, OUTPUT);
  pinMode(leftMotorPinCW, OUTPUT);
  pinMode(rightMotorPinCCW, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  //default = forwards
    digitalWrite(leftMotorPinCW,HIGH); 
    digitalWrite(rightMotorPinCW,HIGH);

  //something close by
  if (distance < 30) {
    //need to turn - (left turn)
    digitalWrite(leftMotorPinCCW,HIGH);
    digitalWrite(leftMotorPinCW,LOW);
    digitalWrite(rightMotorPinCCW,LOW);
    digitalWrite(rightMotorPinCW,HIGH);  
  }

  //need to sort out which is clockwise.
  
  /*//right turn
    digitalWrite(leftMotorPinCCW,LOW);
    digitalWrite(leftMotorPinCW,HIGH);
    digitalWrite(rightMotorPinCCW,HIGH);
    digitalWrite(rightMotorPinCW,LOW);  */

  //too far away 
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}```
