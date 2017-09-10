# Traffic Lights
Today we are going to build a traffic light.

# Sketch for Today 
(Note include button for start reset)
```
int green = 10;
int yellow = 16;
int red = 18;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  
}
```
