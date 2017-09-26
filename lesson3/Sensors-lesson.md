#include <NewPing.h>
 
#define TRIGGER_PIN  10
#define ECHO_PIN     11
#define MAX_DISTANCE 20000
 
NewPing sonar(11, 10, MAX_DISTANCE);
 
void setup() {
  Serial.begin(115200);
}
 
void loop() {
  delay(1000);
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
