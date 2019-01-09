void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // setting up Flash button (Pin D3) for input 
  pinMode(D3,INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // use digital read to read input 
  Serial.println(digitalRead(D3));
  delay(200);
}
