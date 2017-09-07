# Lesson 1

# What is a micro-controller
A micro controller is a computer embedded on a single chip soley for the purpose of handling IO (input/Output). With pin outs and ins.
<br /><img src='http://d1gsvnjtkwr6dd.cloudfront.net/large/IC-ATMEGA168A-PU_LRG.jpg' width='200px' />

# What is an Arduino?
An Arduino is a microcontroller, Arduino are coded in c very similar to the microbit.

# Why use a micro contoller over a computer.
1. Cost (micro controllers are cheaper than computers)
2. Power consumption, micro controllers require less power than computers.

# Why Arduino
1. Cost (Cost around: £1.71 per board)
2. BBC microbits are £13 per board.
3. You will sooner or later blow a micro controller destroying £2 not an issue destorying £13 scary.

# What is the C language.
1. A C language variant is used in arduino.
2. C is the godfarther of modern day programming languages.
3. C has a little more definition in opening and closing statements.
a. Varables are declared like this (type name = value;) example (int number = 1;) (String string = "Im a string";) (Char char = 'a';)
b. functions start with a return type (string functionname(){ return "hello world";})
c. Wiggly lines () {} these are used a lot more to close statements unlike python which tends to use:
d. Line spacing not important though for sanity borrow something from python.
4. C was invented in 1974 by Dennis Ritchie.
5. Dennis Ritchie passed away in the zame year as Steve Jobs, There would not have been a Steve Jobs without Dennis Ritchie more people know tha name Steve Jobs than Dennis Ritchie.

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
1. <img src='https://i2.wp.com/solidutopia.com/fr/wp-content/uploads/sites/5/2014/03/Arduino-board-choice.png?resize=614%2C597' />
2. First thing we have to do is setup the board we are using with the ide.
3. There are 2 options get the ide to detect the board, not recommended it ussually gets this incorrectly.
4. So lets just select this board, in tools something should say board: hover over this the select "Arduino Leonardo"
5. The port should show autmaticly.


# Our first Sketch
1. We are now going to use the serial monitor back amd forth to create a simple feedback loop over serial.
2. You will send it a number using the Serial console the arduino will start counting that number back to you.
3. Pay attentiom to the blue light on the arduino.
4. Our Code copy below and past it into the editor.

```
//We use int to define a variable
int number_total = 0;
//Define means this is number_to_add is always 10
#define number_to_add 10

//Setup is a function in arduino for initialisation
void setup() {
    //Serial is for getting feedback from the device
    //9600 is the baud rate we are using
    Serial.begin(9600);
    //Serial print outputs to the serial monitor
    Serial.println("Serial conection started, waiting for instructions...");
}

//Loop function is somthing that runs forever.
//Void means a return type in this case nothing
void loop() {
    //Loop while the serial is available
    while (Serial.available() > 0)
    {
        //Take Serial input and cast it to number
        int number = Serial.parseInt();
        number_total += number; 
        
        // Process number if not 0
        if (number != 0)
        {
            //Output message to Serial
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
}
```
5. Click the tick icon this verifies the code has no bugs.
6. Click arrow right icon this sends it to the device.
7. Now in the tools Select serial monitor
8. A new screen should appear 
9. <img src='https://i.pinimg.com/736x/0f/22/f4/0f22f4ec352d43f49af08db2975631a6.jpg' />
10. Change the bottom 3 select options to both nl & cr, 9600 baud (We specified this baud rate earlier)
9. Where you can type in some text in this screen type in some numbers and hit send.
10. Did it add 10 to the number you entered.
11. We created a small calculator.

# Challenges.
1. Can you change the baud rate and view the output
2. Can you change the number?
3. Can you get this to divide/Substract/ a number
4. Can you get this script to output text. (Look as string and char casting in Arduino)

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
