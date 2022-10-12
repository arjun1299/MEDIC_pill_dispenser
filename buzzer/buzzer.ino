
int SPEAKER = 10;    // The speaker is on pin 8

void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//buzzer();
digitalWrite(10,HIGH);
delay(1000);

digitalWrite(10,LOW);
delay(1000);
}

void buzzer()
{

  tone(SPEAKER, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(SPEAKER); 
}