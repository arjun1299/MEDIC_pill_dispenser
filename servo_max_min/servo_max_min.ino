#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(9);
  myservo.writeMicroseconds(1500);  // set servo to mid-point
} 

void loop() {
  
  myservo.writeMicroseconds(400);  // set servo to mid-point
  delay(1000);
  myservo.writeMicroseconds(20000);  // set servo to mid-point
  delay(1000);
  } 
