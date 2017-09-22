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
  
  digitalWrite(14, HIGH); //Eengage the Brake for Channel A
  
  delay(1000);
  
}
```
