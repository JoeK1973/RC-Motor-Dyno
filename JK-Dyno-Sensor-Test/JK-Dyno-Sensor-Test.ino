const byte ledPin = 13;
const byte interruptPin = 2;  // input pin that the interruption will be attached to
volatile byte state = LOW;  // variable that will be updated in the ISR
int passCount = 0;
int oldPass = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
}

void loop() {
  digitalWrite(LED_BUILTIN, state);
  if (passCount > oldPass) {
    oldPass = passCount;
    Serial.print(passCount);
    Serial.print('\n');
  }

}

void blink() {
  state = !state;
  if (state == LOW) {
    passCount += 1;
  }
  
}