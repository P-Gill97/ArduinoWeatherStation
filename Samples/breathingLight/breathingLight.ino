/**

 * A PWM modulation is made in software because GPIO16 can't
 * be used with analogWrite().
 * This code is from 
 * https://arduining.com/2015/08/20/nodemcu-breathing-led-with-arduino-ide/
*/

#define LED     D0                   // Led in NodeMCU at pin GPIO16 (D0).
 
#define BRIGHT    350                // max led intensity (1-500)
#define INHALE    1250               // Inhalation time in milliseconds.
#define PULSE     INHALE*1000/BRIGHT // How long is the LED on
#define REST      1000               // Rest Between Inhalations.

void setup() {                
  pinMode(LED, OUTPUT);   
}

void loop() {
  // increasing intensity, Inhalation: 
  for (int i=1;i<BRIGHT;i++){
    // turn the LED on.
    digitalWrite(LED, true);
    // wait i*10 microseconds
    delayMicroseconds(i*10);
    // turn the LED off
    digitalWrite(LED,false); 
    // wait PULSE-i*10 microseconds
    delayMicroseconds(PULSE - i*10);
    yield();                         // to prevent watchdog firing.
  }
  // decreasing intensity, Exhalation (half time):
  for (int i=BRIGHT-1;i>0;i--){
    // turn the LED on.
    digitalWrite(LED, true);
    // wait i*10 microseconds
    delayMicroseconds(i*10);
    // turn the LED off.
    digitalWrite(LED,false);
    // wait PULSE-i*10
    delayMicroseconds(PULSE- i*10);
    yield();                         //to prevent watchdog firing.
  }
  delay(REST);                      
}
