int touchPin = 2;
int buzzerPin = 9;
int val = 0;

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  val = digitalRead(touchPin);

  if (val == HIGH) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}