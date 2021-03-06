

# Working with Motors

Last week it was Led’s, this week it's motors. Now you have built your first circuits, it’s time to show you how these look on paper to help you understand them.

# 1 – Circuit Diagrams
All electrical components including Leds and motors can be represented in a special type of drawing called a circuit diagram. We use a circuit diagram to make a map of how to build the circuit for other people to use.
If you remember the blinking led project from last week, here is the circuit diagram for that – remember, the blinking of the LED was controlled by the Arduino.
In this diagram, positive wires (+) carry volts to components and negative (-) wires carry volts away from components
 ![Circuit](circuit1.png)
<img src='https://github.com/punkplod23' />

Now let's change the circuit to add a motor that turns when the LED blinks on...
# 2 – Adding a motor
Add the motor in the diagram below, the symbol for a motor is:

![Circuit](circuit2.png)
<img src='https://github.com/punkplod23' />

# 3 – Positive and Negative Wires
Like many electrical components a motor has only two wires...positive and negative. Confusingly there are many ways to refer to the same thing and here are some of the most common. ..

Live, Positive, red, plus, all refer to the outgoing part of the circuit and this side of the circuit carries voltage into the components 

Earth, ground, black, negative, minus all refer to the incoming part of the circuit and carry voltage away from the components.

# 4 - Voltage

What is voltage? Well, for most of our circuits we make we will be using 5 volts. Think of voltage as the water moving through a pipe...without water in the pipe nothing will work. 
Now take a look at the circuit diagrams above again, they all have one thing in common. The wires are shown by a continuous line and if this line is broken, the circuit will stop working. 

# 5 - Connecting the Arduino and the motor board
To drive our motor from our Arduino we need to use a motor board
The motor board gives us extra power for the motor and allows us to control the speed and the direction of the motor. 

Putting together the motor board. 
1. Connect the motor to the green screws. 
2. Use motor A
3. Connect a pin on the Arduino (say No 10) to A-IA on the motor board
4. Connect a pin on the Arduino (say No 14) to A-IA on the motor board
5. Connect VCC on the Arduino to VCC on the motor board  (VCC gives voltage (power) to the motor)
6. Connect GND (ground) on the Arduino to GND on the motor board


# 6 - Load the code and test on the motor

```
void setup() {
  
  //Setup Channel A
  pinMode(10, OUTPUT); //Initiates Motor Channel A pin
  pinMode(14, OUTPUT); //Initiates Brake Channel A pin
  
}

void loop(){
  
  //forward @ full speed
  digitalWrite(10, HIGH); //Establishes forward direction of Channel A
  digitalWrite(14, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  
  delay(3000);
  
  digitalWrite(14, HIGH); //Eengage the Brake for Channel A

  delay(1000);
  
  //backward @ half speed
  digitalWrite(10, LOW); //Establishes backward direction of Channel A
  digitalWrite(14, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 123);   //Spins the motor on Channel A at half speed
  
  delay(3000);
  
  digitalWrite(14, HIGH); //Engage the Brake for Channel A
  
  delay(1000);
  
}
```

# 7 - Play with the code
Have a play and see if you understand everything the code is doing. 
Try changing the delays, the speeds and the directions. 
Challenge: how would you connect and code a second motor?



# Q. "Why are we drawing these diagrams all the time? I want to work with the wires..."
# A. A diagram helps you to plan out what you want to do in advance.  It helps to
1. 	Stop you from breaking components
2. 	Spot errors
3. 	Even prevent you getting an electric shock! 
4. 	Diagrams also mean that others can follow your work and copy it.
6.  Adding a switch to your circuit
Now try to follow your diagram you made and add a switch to your circuit you are building - What happens when you connect the switch in different places on the circuit?
Now we have a switch working, let's now add the motor to the circuit.  If we had added the motor before the switch, we could have never turned it off! 
7.  Adding a motor to the circuit
At this point your circuit will work and the motor will be able to be switched off and on by you at the switch
8.  Turning the motor round
Now, we already know from last week that the led only works one way so what about the motor?
Try connecting the positive and negative wires the other way round on the motor what happens to the way it moves? Why do you think this is?

Now we have built a circuit with a motor and a switch in, next week we will look at the making the circuit allow us to use and control two motors together. These motors will become the wheels of our robot. 
Using the Arduino we will help you connect the circuit and show you how to reverse each wheel. This will help steer the robot.
See you next week. 

Sources:
This is quite detailed code with serial port control but I found it useful. 
[https://www.bananarobotics.com/shop/How-to-use-the-HG7881-(L9110)-Dual-Channel-Motor-Driver-Module]
