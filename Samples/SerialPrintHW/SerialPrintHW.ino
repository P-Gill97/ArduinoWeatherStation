
int counter = 1;

void setup() {

  Serial.begin(115200); 
 
}

void loop() {
 // printing hello world over and over again. using serial print
 Serial.print(counter);
  Serial.println(  " Hello world.");
// increment counter 
counter++;

  // delay one second 
  delay(1000);
}
