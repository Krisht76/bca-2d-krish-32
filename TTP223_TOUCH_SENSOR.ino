const int touchPin = 2;
const int ledPin = 3;

int ledState = LOW;
int lastTouchState = LOW;

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  int currentTouchState = digitalRead(touchPin);

  if (currentTouchState == HIGH && lastTouchState == LOW) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    delay(50);
  }

  lastTouchState = currentTouchState;

  delay(1);
}