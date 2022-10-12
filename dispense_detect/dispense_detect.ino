const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), dispenseDetect, CHANGE);
}

void loop() {
  digitalWrite(ledPin, state);
}

void dispenseDetect() {
  state = !state;
  delay(5);
}