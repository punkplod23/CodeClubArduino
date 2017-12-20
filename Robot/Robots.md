# Robots – lesson plan

## Recap - 

We have now seen how the following components work on their own:

### Ultrasonic Distance Sensor
This sends out a “ping” like a submarine, and captures the return of the ping and is similar to using echo location in Bats, or the “ping” of a submarine

The time taken for the ping to be output and returned to the sensor is captured by the Arduino. Once we have the signal captured, we use the Arduino script to convert the time taken to distance in centimetres

#### Things to remember:
- The sensor does have a finite distance the ping can travel over
- The sensor is less accurate with closer objects – it’s harder to detect the time travelled by a ping over a shorter distance
- The sensor will not work if it is incorrectly positioned and does not return a ping – we need to provide code to handle for this scenario

### Electric motor 
The motors we use in Code Club are powered by two wires, one with voltage, and one to return the voltage to ground – we cannot power these directly from the Arduno in case we blow it up so we use the motor together with a Motor Board

### Motor Board
A switch that allows a small amount of electric to power a larger appliance – in this case a motor. If the Arduino switches the motor board off, no power goes to the motor, if the Arduino switches the motor on, power goes to the motor from an attached 9 volt battery – this gives more power to the motor than the Arduino can manage

### So how do we build a robot?
- Eyes – Ultrasonic sensor
- 2 x Motors – Drive the motor
- Breadboard
- Jumper Wires
- Batteries
- Program

### How does the Robot work?
The program on the Arduino reacts to the obstacles detected by the sensor and controls the motors to move around the object
That is it!

### What does the robot do?
Drives around autonomously (by itself without human control) until within set range of an obstacle. Once an obstacle is detected with the Sensor, motors are controlled to allow the robot to steer away from the obstacle and then continue on straight






