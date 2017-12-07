#include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1

//connect SDA = A4 (transmits data)
//connect SCL = A5 (receives data)
// The LCD constructor - address shown is 0x27 - may or may not be correct for yours - use scanner
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //magic

int State;
int val = 0;
int potPin = 14;//for potentiometer


void setup()
{
  Serial.begin(9600);
  pinMode(11, INPUT); 
  pinMode(10, OUTPUT);
  lcd.begin(16,2); // sixteen characters across - 2 lines
  lcd.backlight();
  lcd.setCursor(0,0); //(top left row 1)
  lcd.print("Speed"); 
  lcd.setCursor(1,1); //(line 2, position 1)
  getState();
}
 
 
void loop(){
  digitalWrite(10, HIGH);
  wait();
  getState();
  digitalWrite(10, LOW);
  wait();
  getState();
}


void getState(){
  //State = digitalRead(11);
  val = analogRead(potPin);//read potentiometer value
  //Serial.println(State);
  lcd.setCursor(1,1);
  //lcd.print(State);
  //Serial.println(val);
  lcd.print(val);
  }


void wait(){
  delay(1);
}
