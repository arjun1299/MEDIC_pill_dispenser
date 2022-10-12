#include <dht.h>
#include <Servo.h>



#define dht_apin A1 // Analog Pin sensor is connected to
#define servoPill1 6
#define servoPill2 9
#define servoPill3 5
#define servoPill4 11

int SPEAKER = 10;    // The speaker is on pin 8
int freq = 50;  
char pillNum=0;
//char state = 0;
dht DHT;
const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;


Servo myservo1;
Servo myservo2,myservo3,myservo4;

void setup(){

  
    Serial.begin(38400); // Default communication rate of the Bluetooth module

  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  myservo1.attach(servoPill1);
  myservo2.attach(servoPill2);
  myservo3.attach(servoPill3);
  myservo4.attach(servoPill4);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), dispenseDetect, CHANGE);
  pinMode(SPEAKER, OUTPUT);

}//end "setup()"

void dispenseDetect() {
  state = 1;
  delay(5);
}

void dispenense()
{
  Serial.print("dispensing");
  Serial.println(pillNum);
  state=0;
  int pos;
  while(state!=1)

    {switch(pillNum)
    {
      case '1':
    for (pos = 4000; pos >= 400; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }

      break;
      
      case '2':
    for (pos = 4000; pos >= 400; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }
      break;

      
      case '3':
    
    for (pos = 4000; pos >= 400; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo3.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }
      break;
  
  
      case 4:
    for (pos = 4000; pos >= 400; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo4.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(1);                       // waits 15ms for the servo to reach the position
  }
      break;
  
    }
  } 

  pillNum=0;

}
int bzr=0;
void buzzer()
{


digitalWrite(10,HIGH);
delay(1000);

digitalWrite(10,LOW);
delay(1000);
bzr+=1;
}
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    /*
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");*/

    
    delay(1000);//Wait 5 seconds before accessing sensor again.

    if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    pillNum = Serial.read(); // Reads the data from the serial port
    Serial.print(pillNum);}

    if(pillNum=='1'||pillNum=='2'||pillNum=='3'||pillNum=='4')
    {if(DHT.humidity>=95)
      dispenense();










     else
        buzzer();

    if(bzr>=3)
      dispenense();

    }
      Serial.print(DHT.humidity);
    
 
  //Fastest should be once every two seconds.
 
}// end loop(
