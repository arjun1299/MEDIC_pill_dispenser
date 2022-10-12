#include <Servo.h>



Servo myservo;

void setup() 
{ 
  myservo.attach(9);
  myservo.writeMicroseconds(1500);  // set servo to mid-point
} 

void loop() {
  
 // myservo.writeMicroseconds(400);  // set servo to mid-point
  //delay(1000);
  //myservo.writeMicroseconds(4000);  // set servo to mid-point
  //delay(1000);
    int pos;
/*    for (pos = 400; pos <= 4000; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }*/
    for (pos = 4000; pos >= 400; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }

  } 
