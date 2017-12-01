#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <LiquidCrystal_I2C.h> // Using version 1.2.1

//LCD
//connect SDA = A4 (transmits data)
//connect SCL = A5 (receives data)
// The LCD constructor - address shown is 0x27 - may or may not be correct for yours - use scanner
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //magic

File myFile;
String strFileName = "Test.txt";
int intTemp = 0;
int intSpeed = 0;
int intPotPin = 15;//for Potentiometer
int intTempPin = 14;//for Temperature
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  10;      // the number of the LED pin
int buttonState = 0;         // variable for reading the pushbutton status

void setup(){   
    //Serial.begin(9600);
    // initialize the LED pin as an output:
    pinMode(ledPin, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
    
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
  
      if (!SD.begin(4)) {
        //Serial.println("initialization failed!");
      return;
      }

    //LCD on
    lcd.begin(16,2); // sixteen characters across - 2 lines
    lcd.backlight();
    lcd.setCursor(0,0); //(top left row 1)
    //lcd.print(intSpeed); 
    //lcd.setCursor(1,1); //(line 2, position 1)
    getState();
}

 
void getState(){
    intTemp = analogRead(intTempPin);//read temp value
    intSpeed = analogRead(intPotPin);//read potentiometer value
    lcd.setCursor(0,0);
    lcd.print("temperature ");
    lcd.print(intTemp);
    lcd.setCursor(1,1);
    lcd.print("speed ");
    lcd.print(intSpeed);
    }


void wait(){
    delay(1000);
}


void printToFile(){
    String strTemp = ("Temp: ");
    String strSpeed = ("Speed: ");
    myFile.println(strTemp + intTemp);
    myFile.println(strSpeed + intSpeed);
    }


void loop(){
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    
    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
          // turn LED on:
          digitalWrite(ledPin, HIGH);
          //Serial.println("led high");
          myFile.close();
    } 
    else {
          // turn LED off:
          digitalWrite(ledPin, LOW);
          //Serial.println("led low");
          wait();
          getState();
          myFile = SD.open(strFileName, FILE_WRITE);
          //if file opens ok
              if (myFile) {
                    Serial.println("file open");
                    printToFile();
                    myFile.close();
                    }
              else {
                    // if the file didn't open, print an error:
                    //Serial.println("error opening test.txt");
                    }
          } 
 }










  
  // re-open the file for reading:
  //myFile = SD.open("test.txt");
  //if (myFile) {
  //  Serial.println("test.txt:");
    // read from the file until there's nothing else in it:
   // while (myFile.available()) {
   //   Serial.write(myFile.read());
    //}
    // close the file:
    //myFile.close();
  //} else {
    // if the file didn't open, print an error:
   // Serial.println("error opening test.txt");
  //}
