# Lesson 1

# What is a micro-controller
A is a computer embedded on a single chip soley for the purpose of handling IO (input/Output). With pin outs and ins.

# What is an Arduino?
An Arduino is a microcontroller, Arduino are coded in c very similar to the microbit.

# Why use a micro contoller over a computer.
1. Cost (micro controllers are cheaper than computers)
2. Power consumption, micro controllers require less power than computers.

# Why Arduino
1. Cost (Cost around: £1.71 per board)
2. BBC microbits are £13 per board.
3. You will sooner or later blow a micro controller destroying £2 not an issue destorying £13 scary.

# What is C language.
1. A C language variant is used in arduino.
2. C is the godfarther of modern day programming languages.
3. C was invented in 1974 by Dennis Ritchie.
4. Dennis Ritchie passed away in the zame year as Steve Jobs, There would not have been a Steve Jobs without Dennis Ritchie.

Micro Controllers are everywhere to home appliances to industrial machinaey to traffic lights.

# What is Serial Baud

1. The baud rate is the rate at which information is transferred in a communication channel. In the serial port context, "9600 baud" means that the serial port is capable of transferring a maximum of 9600 bits per second
2. In essecnce its how information is sent and received.

# Objective
Over the next few lessons we are going to leane how to use the Arduino to do a variety of things.
1. Flash a light.
2. Read sensor input.
3. Spin a motor.
4. Build a autonmouse obstacle avoiding robot like here.https://youtu.be/xrPiDkLb_2M

# What is the Arduino IDE.
1. IDE is an abbreviation for integrated development enviroment its the program we code in.
2. In Arduino our programs are reffered to as sketches. I think its a silly name aswell.

# Installing the Arduino IDE.
1. In the raspberry PI open the terminal.
   Shortcut(Ctrl+alt+t)
2. Type in ```sudo apt-get install arduino```
3. Wait for Install.

# Arduino Micro board.
1. We will be using the Arduino Mico board. A break down ot its pin setup is below.
<img src='http://tinkersphere.com/1398-thickbox_default/pro-micro-5v-16mhz-arduino-compatible-atmega32u4-breakout.jpg' />

# Using Arduino
1. Open Arduino should be in the programming menu.
<img src='https://i2.wp.com/solidutopia.com/fr/wp-content/uploads/sites/5/2014/03/Arduino-board-choice.png?resize=614%2C597' />
2. First thing we have to do is setup the board we are using with the ide.
3. There are 2 options get the ide to detevt the board, not recommended it ussually gets this incorrectly.
4. So lets just select this board (get name of board.

# Our first Sketch
1. We are now going to use the serial monitor back amd forth to create a simple feedback loop over serial.
2. You will send it a number using the Serial console the arduino will start counting that number back to you.
3. Pay attentiom to the blue light on the arduino.
4. Our Code

'''// Buffer to store incoming commands from serial port
int number_total = 0;
#define number_to_add 10

void setup() {
    Serial.begin(9600);
    Serial.println("Serial conection started, waiting for instructions...");
}

void loop() {
    while (Serial.available() > 0)
    {
      
        int number = Serial.parseInt();
        number_total += number; 
       
        // Process message when new line character is recieved
        if (number != 0)
        {
            Serial.print("Calculate: ");
            Serial.print(number_total);
            Serial.print(" + ");
            Serial.print(number_to_add);
            Serial.print(" = ");
            Serial.print(number_total+number_to_add);
            Serial.print("\n");
            number_total = 0;

        }
    }
}'''

# LESSON 2 Start Notes

# Breaboard
1. A Breadboard is away of quickly prototyping a circuit that does not need to be soldered.
2. We can connect a vareity of components to a breadboard.
3. We always need to regulate power to these components else they will be damaged or blow up.
<img src='https://images-na.ssl-images-amazon.com/images/I/71CBqkJtZvL._SL1280_.jpg'/>

# Lets Flash an LED
1. Firstly lets create a circuit like below.
<img src='http://idledev.com/wp-content/uploads/2015/03/arduino-blink-wiring.jpg'>
2. Components Required Resistor, Led, Breadboard and Arduino.
