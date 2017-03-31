/*
 * Parking Space Indicator using Ultrasonic Sensor project 1.0
 * Arduino day 2017
 * Parmg.org Group
 * 
 * Requirements
 * 1. Breadboard
 * 2. Arduino 
 * 3. HC-SR04 Ultrasonic Sensor
 * 4. LED
 * 5. Cables
 * 
 * Instructions
 * 1. Install Arduino on the Breadboard
 * 2. Connect Arduino 5V to Ultrasonic Sensor VCC
 * 3. Connect Arduino GND to Ultrasonic Sensor GND
 * 4. Connect Arduino Pin 11 to Ultrasonic Sensor (INPUT) TRIG
 * 5. Connect Arduino Pin 12 to Ultrasonic Sensor (OUTPUT) ECHO
 * 6. Connect Arduino GND to Breadboard Minus line
 * 7. Connect Arduino D8 to long leg in LED
 * 8. Connect LED short leg to Breadboard Minus line
 * 
 */
 
int trigPin = 11;
int echoPin = 12;
int ledPin  = 8;

long duration, cm, inches;
 
void setup() {
  
  //Serial Port begin
  Serial.begin (9600);
  
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
 
void loop()
{
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  
  // Convert the time into a distance, we will divide the duration by 2, since the time is since the wave started until it got back. 
  // Than divide it by The speed of sound in air. 29.1 For cm and 74 for inches 
  // if you need more info here is a good link about the speed of the sound in air http://www.sengpielaudio.com/calculator-speedsound.htm
  cm     = (duration/2) / 29.1;
  inches = (duration/2) / 74; 

  if(inches <= 5.0 )
  {
    // if its close to 5 inches, turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // if its not close to 5 inches or more turn the LED off  
    digitalWrite(ledPin, LOW);
  }
  
  // Send the distance to the computer using Serial protocol
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  // Delay 50ms before next reading.
  delay(50);
}
