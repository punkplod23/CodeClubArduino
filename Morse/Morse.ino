int dotButtonPin = 2;    
int dashButtonPin =  3;      
int dotButtonState = 0;
int dashButtonState=0;     
int dotCount = 0;
int dashCount = 0;

void setup() {
  pinMode(dotButtonPin, INPUT);
  pinMode(dashButtonPin, INPUT);
}

void dotCounter(){
  dotCount = dotCount + 1;
  Serial.print("Dot");
  Serial.print(" ");
  Serial.print(dotCount);
}

void dashCounter(){
  dashCount = dashCount = 1;
  Serial.print("Dash");
  Serial.print(" ");
  Serial.print(dashCount);
  
}
   
void loop() {
  dotButtonState = digitalRead(dotButtonPin);
  dashButtonState = digitalRead(dashButtonPin);
  
  if (dotButtonState == HIGH) {
    delay(1000);
    dotCounter();    
  }
  if (dashButtonState ==HIGH){
    delay(1000);
    dashCounter();
  }  
}
