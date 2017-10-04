```
#include <NewPing.h>
 
#define TRIGGER_PIN  14
#define ECHO_PIN     15
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, TRIGGER_PIN, MAX_DISTANCE);

int pin1 = 10;
int pin2 = 11;
int pin4 = 12;
int pin5 = 13;
unsigned int pingSpeed = 50; // How frequently are we going to send out a ping (in milliseconds). 50ms would be 20 times a second.
unsigned long pingTimer;     // Holds the next ping time.
int current_distance = 20000000;

void setup() {
  
  //Setup Channel A
  pinMode(pin1, OUTPUT); //Initiates Motor Channel A pin
  pinMode(pin2, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(pin4, OUTPUT); //Initiates Motor Channel A pin
  pinMode(pin5, OUTPUT);  //Initiates Brake Channel A pin
    Serial.begin(115200);
     pingTimer = millis(); // Start now.
}

void forward(){

  //Motor A forward @ full speed
  digitalWrite(pin1, HIGH); //Establishes forward direction of Channel A
  digitalWrite(pin2, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  digitalWrite(pin4, LOW);  //Establishes backward direction of Channel B
  digitalWrite(pin5, HIGH);   //Disengage the Brake for Channel B
  analogWrite(3, 255);    //Spins the motor on Channel B at half speed
  
  
}

void tankMovement(){

  //Motor A forward @ full speed
  digitalWrite(pin1, HIGH); //Establishes forward direction of Channel A
  digitalWrite(pin2, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed

  //Motor B backward @ half speed
  digitalWrite(pin4, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(pin5, LOW);   //Disengage the Brake for Channel B
  analogWrite(3, 255);    //Spins the motor on Channel B at half speed
  
  
}


void loop(){

  if (millis() >= pingTimer) {   // pingSpeed milliseconds since last ping, do another ping.
    pingTimer += pingSpeed;      // Set the next ping time.
    sonar.ping_timer(echoCheck); // Send out the ping, calls "echoCheck" function every 24uS where you can check the ping status.
  }

  if(current_distance < 7){
  tankMovement();
  }else{
       forward();
   
  }
  
}
void echoCheck() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
  if (sonar.check_timer()) { // This is how you check to see if the ping was received.
    // Here's where you can add code.
    current_distance = sonar.ping_result / US_ROUNDTRIP_CM;

  }
}
```
