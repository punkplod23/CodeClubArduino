# Lesson about using two motors

The aim of this lesson is learn how to control two motors together and to make our robot move. 

I'm a little concerned that it will take more than an hour so it might stretch over two weeks. 


# Requirements
1. Robot with two motors and two wheels
2. Motor board
3. Arduino
4. Cable to connect Arduino to Pi
5. Wires to connect motors to motor board
6. Wires to connect motor board to Arduino
7. Breadboard
8. Battery connector
9. Battery
10. Raspberry Pi with Arduino IDE

# Summary of Steps
1. Assemble Pi 
2. Put Arduino on breadboard
3. Connect motors, motor board and Arduino (details below) 
4. Get the code, load it on the Arduino and test the motors (details below) 
5. Add power: connect battery to the breadboard (details below) 

# Step 3 - Connecting the motors and the motor board
To drive our motors from our Arduino we need to use a motor board
The motor board gives us extra power for the motor and allows us to control the speed and the direction of the motor. 

Putting together the motor board. 
1. Connect the motors to the green screws.
2. You will need to use both motor A and motor B - one for each motor.
3. The pins on the motor board are called A-IA, A-IB, B-IA, B-IB
4. Connect A-IA to pin 18 on the Arduino 
5. Connect A-IB to pin 19 on the Arduino
6. Connect B-IA to pin 20 on the Arduino 
7. Connect B-IB to pin 21 on the Arduino
8. Connect VCC on motor board to + on the breadboard
9. Connect GND (ground) on the Arduino to - on the motor board

### Remember:
Live, Positive, red, plus, all refer to the outgoing part of the circuit and this side of the circuit carries voltage into the components 

Earth, ground, black, negative, minus all refer to the incoming part of the circuit and carry voltage away from the components.

# Step 4 - Get the code and load it on the Arduino
We need to load the code on the Arduino. 
1. Use the USB cable to connect the Pi to the Arduino
2. Open up the Arduino IDE
3. Try the following script - cut and paste from internet into Arduino IDE

```Arduino C++
// defining the pins
int aIa = 18;    // motor a input a
int aIb = 19;    // motor a input b
int bIa = 20;    // motor b input a
int bIb = 21;    // motor b input b

// set up the pins modes
void setup() {
  pinMode(aIa, OUTPUT);
  pinMode(aIb, OUTPUT);
  pinMode(bIa, OUTPUT);
  pinMode(bIb, OUTPUT);  
  digitalWrite(aIa, LOW);
  digitalWrite(aIb, LOW);
  digitalWrite(bIa, LOW);
  digitalWrite(bIb, LOW);  
}

void loop() {

  //Motor A forward
  digitalWrite(aIa, HIGH);
  digitalWrite(aIb, LOW); 

  //Motor B forward
  digitalWrite(bIa, HIGH);
  digitalWrite(bIb, LOW); 
  
  delay(1000);
  
  //Motor A stop
  digitalWrite(aIa, LOW); 
  digitalWrite(aIb, LOW); 

  //Motor B stop
  digitalWrite(bIa, LOW);  
  digitalWrite(bIb, LOW);  

delay(1000);    
}

```

4. Verify the script and upload it onto the Arduino. 


# Step 5 - Add power: connect battery to the breadboard
Because our two motors need 2.5V of power each, we can't supply that power through the USB cable and the Arduino. 

We provide extra power through the breadboard with a 9V battery. 

1. Connect battery connector - red positive to + on breadboard
2. Connect battery connector - black negative to - on breadboard
3. Connect battery

Is motor board LED on?

Can we make the motors move?

Q: how do we supply power to the Arduino when the USB is not connected. 

# Trouble shooting
1. Going in circles - either change the wires or change the code
2. No light on motor board - probably one of the wires is not connected correctly

# Next steps
1. Improve the code to move it backwards
2. Get the bot to turn right and left. 
3. Get bot to travel in a square or programme it to move in a way you would like. 

