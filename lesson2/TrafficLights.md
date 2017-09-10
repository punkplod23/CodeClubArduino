# Traffic Lights
Today we are going to build a circuit for controlling traffic lights. But its not going to work correctly to start with because we are going to use 3 different types of reisitor.
<img src="http://beno.org.uk/trafficlight/o9.JPG" />


# What we will be using today
1. 3 different varying resistor types
2. 3 differenct coloured LEDs.
3. 3 different pins to send power down and light the pins in a specific order in a loop.
4. A push button

# What is a resistor
Resistors are used to reduce current flow, sometimes when we supply current (power) to a component we do not want to introduce to much current else it stands the chance of going bang/pop/fizz.
<img src="https://openclipart.org/download/276048/resistor.svg" alt="resistor" />
Different resistors resist the flow of currently this you can see by the diagram below.
<img src="https://www.digikey.com/-/media/Images/Marketing/Resources/Calculators/resistor-color-chart.jpg?la=en-US&ts=72364a89-2139-476a-8a54-8d78dacd29ff" />

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
