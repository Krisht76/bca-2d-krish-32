int pirPin = 2;
int val = 0;

void setup() {
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(pirPin);

  if (val == HIGH) {
    Serial.println("Motion Detected!");
  } else {
    Serial.println("No Motion");
  }
  
  delay(1000);
}