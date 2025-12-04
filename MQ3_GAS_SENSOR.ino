int mq3Pin = A0;
int value = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("MQ-3 Warming up...");
  delay(20000); // 20s warm-up delay (Important for accuracy)
}

void loop() {
  value = analogRead(mq3Pin);

  Serial.print("Alcohol Level: ");
  Serial.println(value);

  // Threshold: Adjust this based on your testing (usually > 200 is detection)
  if (value > 200) {
    Serial.println("Alcohol Detected!");
  }
  
  delay(500);
}