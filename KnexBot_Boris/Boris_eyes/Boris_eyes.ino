#include <Wire.h>  
#include <LiquidCrystal_I2C.h> // Using version 1.2.1

//connect SDA = A4 (transmits data)
//connect SCL = A5 (receives data)
// The LCD constructor - address shown is 0x27 - may or may not be correct for yours - use scanner
LiquidCrystal_I2C lcd1(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //magic
//LiquidCrystal_I2C lcd2(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //magic



void setup()
{
  Serial.begin(9600);
  lcd1.begin(16,2); // sixteen characters across - 2 lines
  lcd1.backlight();
  //lcd2.begin(16,2); // sixteen characters across - 2 lines
  //lcd2.backlight();
  sleeping();
  //awake();
}
 
 
void loop(){ 
}


void sleeping(){
  lcd1.setCursor(0,0); //(top left row 1)
  lcd1.print("################"); 
  lcd1.setCursor(0,1); //(line 2, position 1)
  lcd1.print("################"); 
}

  //lcd2.setCursor(0,0); //(top left row 1)
  //lcd2.print("################"); 
  //lcd2.setCursor(0,1); //(line 2, position 1)
  //lcd2.print("################"); 

void awake(){
  lcd1.setCursor(0,0); //(top left row 1)
  lcd1.print("|--------------|"); 
  lcd1.setCursor(0,1); //(line 2, position 1)
  lcd1.print("|_______O_______"); 
}

