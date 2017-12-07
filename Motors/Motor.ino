#include <NewPing.h>



int motorPinLeft = 9;//In1

//also use gnd and vcc


//int motorPinRight = 18????;
void setup() {
 pinMode(motorPinLeft, OUTPUT);
 //pinMode(motorPinRight, OUTPUT);
}
void loop() {
 digitalWrite(motorPinLeft, HIGH);
 //delay(1000); 
 //digitalWrite(motorPinRight, HIGH);
 //delay(1000);
}
