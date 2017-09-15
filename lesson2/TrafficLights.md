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

# Circuit Diagram
(Use http://fritzing.org/download/?donation=0) to do this

# Sketch for Today 
```
const int buttonPin = 21; 
#define BUTTON_PIN        21  // Button

#define LONGPRESS_LEN    25  // Min nr of loops for a long press
#define DELAY            20  // Delay per loop in ms
int green = 10;
int yellow = 16;
int red = 18;
int button_pressed = 0;
int pressed = 0;

enum { EV_NONE=0, EV_SHORTPRESS, EV_LONGPRESS };

boolean button_was_pressed; // previous state
int button_pressed_counter; // press running duration

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(57600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);  
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH); // pull-up
  button_was_pressed = false;
  button_pressed_counter = 0;
}

int handle_button()
{
  int event;
  int button_now_pressed = !digitalRead(BUTTON_PIN); // pin low -> pressed

  if (!button_now_pressed && button_was_pressed) {
    if (button_pressed_counter < LONGPRESS_LEN)
      event = EV_SHORTPRESS;
    else
      event = EV_LONGPRESS;
  }
  else
    event = EV_NONE;

  if (button_now_pressed)
    ++button_pressed_counter;
  else
    button_pressed_counter = 0;

  button_was_pressed = button_now_pressed;
  return event;
}

// the loop function runs over and over again forever
void loop() {
   // handle button
  boolean event = handle_button();

  // do other things
  switch (event) {
    case EV_NONE:
      Serial.print(".");
      break;
    case EV_SHORTPRESS:
      Serial.print("S");
      pressed = 1;
      break;
    case EV_LONGPRESS:
      Serial.print("L");
      break;
  }

      Serial.write((button_pressed ?0  :1));
  if (pressed == 0) {
    
    digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
   
  }else{
    
    digitalWrite(green, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(green, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);   
                    // wait for a second
  digitalWrite(yellow, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(yellow, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);  
  pressed = 0;
  
  } 
}
```
