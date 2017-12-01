int velocity = 100;//velocity of MIDI notes, must be between 0 and 127
//higher velocity usually makes MIDI instruments louder

int noteON = 144;//144 = 10010000 in binary, note on command
int noteOFF = 128;//128 = 10000000 in binary, note off command

int LDRPin1 = 14; // select the input pin for LDR - A0
int LDRPin2 = 15;// A1
int LDRPin3 = 16;// A1
int LDRPin4 = 17;// A1
int LDRPin5 = 18;// A1

int LDRPin1Val = 0; // variable to store the value coming from the sensor
int LDRPin2Val = 0; // variable to store the value coming from the sensor
int LDRPin3Val = 0; // variable to store the value coming from the sensor
int LDRPin4Val = 0; // variable to store the value coming from the sensor
int LDRPin5Val = 0; // variable to store the value coming from the sensor
const int TOLERANCE = 1020;



void setup() {
  Serial.begin(9600);
}



void readLDRs() {
  LDRPin1Val = analogRead(LDRPin1); // read the value from the sensor
  LDRPin2Val = analogRead(LDRPin2); // read the value from the sensor
  LDRPin3Val = analogRead(LDRPin3); // read the value from the sensor
  LDRPin4Val = analogRead(LDRPin4); // read the value from the sensor
  LDRPin5Val = analogRead(LDRPin5); // read the value from the sensor
  //Serial.println(LDRPin1Val); //prints the values coming from the sensor on the screen;
  //Serial.println(LDRPin2Val); //prints the values coming from the sensor on the screen;
  //Serial.println(LDRPin3Val); //prints the values coming from the sensor on the screen;
  //Serial.println(LDRPin4Val); //prints the values coming from the sensor on the screen;
  //Serial.println(LDRPin5Val); //prints the values coming from the sensor on the screen;
}




void loop() {
  readLDRs();
  
  if (LDRPin1Val < TOLERANCE) {
    int note = 50;
    //Serial.println("ldr1 - touched");
    MIDImessage(noteON, note, velocity);//turn note on
    delay(300);//hold note for 300ms
    MIDImessage(noteOFF, note, velocity);//turn note off
    delay(200);//wait 200ms until triggering next note
  } else {
    //Serial.println("");
  }

  if (LDRPin2Val < TOLERANCE) {
    int note = 60;
    //Serial.println("ldr2 - touched");
    MIDImessage(noteON, note, velocity);//turn note on
    delay(300);//hold note for 300ms
    MIDImessage(noteOFF, note, velocity);//turn note off
    delay(200);//wait 200ms until triggering next note
  } else {
    //Serial.println("");
  }

  if (LDRPin3Val < TOLERANCE) {
    int note = 70;
    //Serial.println("ldr3 - touched");
    MIDImessage(noteON, note, velocity);//turn note on
    delay(300);//hold note for 300ms
    MIDImessage(noteOFF, note, velocity);//turn note off
    delay(200);//wait 200ms until triggering next note
  } else {
    //Serial.println("");
  }

  if (LDRPin4Val < TOLERANCE) {
    int note = 80;
    //Serial.println("ldr4 - touched");
    MIDImessage(noteON, note, velocity);//turn note on
    delay(300);//hold note for 300ms
    MIDImessage(noteOFF, note, velocity);//turn note off
    delay(200);//wait 200ms until triggering next note
  } else {
    //Serial.println("");
  }

  if (LDRPin5Val < TOLERANCE) {
    int note = 90;
    //Serial.println("ldr5 - touched");
    MIDImessage(noteON, note, velocity);//turn note on
    delay(300);//hold note for 300ms
    MIDImessage(noteOFF, note, velocity);//turn note off
    delay(200);//wait 200ms until triggering next note
  } else {
    //Serial.println("");
  }

  delay(100);
}



//send MIDI message
void MIDImessage(int command, int MIDInote, int MIDIvelocity) {
  Serial.write(command);//send note on or note off command
  Serial.write(MIDInote);//send pitch data
  Serial.write(MIDIvelocity);//send velocity data
}
