int State;

void setup() {
  Serial.begin(9600);
  pinMode(11, INPUT);
  pinMode(10, OUTPUT);
  }

void loop() {
  digitalWrite(10, HIGH);
  wait();
  getState();
  digitalWrite(10, LOW);
  wait();
  getState();
  }

void getState(){
  State = digitalRead(11);
  Serial.println(State);
  }

void wait(){
  delay(1000);
}

