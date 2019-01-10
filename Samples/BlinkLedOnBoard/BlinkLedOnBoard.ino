boolean ledState = false; 
void setup() {
  Serial.begin(115200);
  pinMode(D0, OUTPUT);
}

void loop() {
  digitalWrite(D0, ledState);
  ledState = !ledState;
  delay(1000); 
}
