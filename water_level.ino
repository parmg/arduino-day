/*
 * Water level project 1.0
 * Arduino day 2017
 * Parmg.org Group
 * 
 * Requirements
 * 1. Breadboard
 * 2. Arduino Nano v3
 * 3. HC-SR04 Ultrasonic Sensor
 * 4. LEDs 
 * 5. Cables
 * 
 * Instructions
 * 1. Install Arduino on the Breadboard
 * 2. Connect Arduino 5V to Ultrasonic Sensor VCC
 * 3. Connect Arduino GND to Ultrasonic Sensor GND
 * 4. Connect Arduino D3 to Ultrasonic Sensor ECHO
 * 5. Connect Arduino D4 to Ultrasonic Sensor TRIG
 * 6. Connect Arduino GND to Breadboard Minus line
 * 7. Connect Arduino D10 to long leg in LED (high level)
 * 8. Connect Arduino D9 to long leg in LED (medium level) 
 * 9. Connect Arduino D8 to long leg in LED (low level led) 
 * 10. Connect All LEDs short leg to  Breadboard Minus line
 * 
 */

#define echoPin 3 // Echo Pin
#define trigPin 4 // Trigger Pin

#define LowPin 10 // low level LED
#define MidPin 9  // medium level LED
#define HigPin 8  // high level LED

#define LowRange 10 // Low Range
#define MidRange 20 // Mid Range
#define HigRange 30 // Hi Range

long duration, distance; // Duration used to calculate distance

void setup() {
  // send logs
  Serial.begin (9600);
  // to send soundwaves
  pinMode(trigPin, OUTPUT);
  // to receive soundwaves
  pinMode(echoPin, INPUT);
  // LEDs pins
  pinMode(LowPin, OUTPUT);
  pinMode(MidPin, OUTPUT);
  pinMode(HigPin, OUTPUT);
}

void loop() {
  /* The following trigPin/echoPin cycle is used to determine the
  distance of the nearest object by bouncing soundwaves off of it. */ 

  // stop pin
  digitalWrite(trigPin, LOW);
  // wait for 2ms
  delayMicroseconds(2);
  
  // send soundwaves
  digitalWrite(trigPin, HIGH);
  // wait for 10ms
  delayMicroseconds(10);
  // stop pin
  digitalWrite(trigPin, LOW);
  // read the soundwaves
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance (in cm) based on the speed of sound.
  distance = duration/58.2;
 
  if (distance > 0 and distance <= LowRange){
    digitalWrite(HigPin, LOW);
    digitalWrite(MidPin, LOW);
    digitalWrite(LowPin, HIGH); // On
    Serial.println("LowPin");
  } else if (distance > LowRange and distance <= MidRange){
    digitalWrite(HigPin, LOW);
    digitalWrite(MidPin, HIGH); // On
    digitalWrite(LowPin, LOW);
    Serial.println("MidPin");
  } else {
    digitalWrite(HigPin, HIGH); // On
    digitalWrite(MidPin, LOW);
    digitalWrite(LowPin, LOW);
    Serial.println("HigPin");
  }
  
  // Send the distance to the computer using Serial protocol
  Serial.println(distance);

  // Delay 300ms before next reading.
  delay(300);
}
