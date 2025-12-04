int gasPin = A0;
int gasLevel = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  gasLevel = analogRead(gasPin);

  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  if (gasLevel > 400) {
    Serial.println("DANGER: High Gas Detected!");
  }
  
  delay(500);
}