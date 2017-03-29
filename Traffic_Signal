/*
 * Traffic signal project 1.0
 * Arduino day 2017
 * Parmg.org Group
 * 
 * Requirements
 * 1. Breadboard
 * 2. Arduino Nano v3
 * 3. LEDs 
 * 4. Cables
 * 
 * Instructions
 * 1. Install Arduino on the Breadboard
 * 2. Connect Arduino GND to Breadboard Minus line
 * 3. Connect Arduino D1 to long leg in Green LED (Green signal)
 * 4. Connect Arduino D2 to long leg in Yallow LED (Yallow signal) 
 * 5. Connect Arduino D3 to long leg in RED LED (RED signal) 
 * 6. Connect All LEDs short leg to  Breadboard Minus line
 * 
 */


void setup() {
  // LEDs pins
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  
  // Start Green signal
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(1,HIGH);
  // wait 10s
  delay(10000); 

  // Start Yallow signal
  digitalWrite(1,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
  // wait 3s
  delay(3000);

  // Start RED signal
  digitalWrite(1,LOW);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  // wait 10s
  delay(10000);

}
