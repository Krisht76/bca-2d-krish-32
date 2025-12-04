#define AOUT_PIN A0
#define LED_PIN 13

const int DRY_VALUE = 800;
const int WET_VALUE = 300;

const int DRY_THRESHOLD_PERCENT = 40;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int analogValue = analogRead(AOUT_PIN); 

  int moisturePercent = map(analogValue, DRY_VALUE, WET_VALUE, 0, 100);
  
  if (moisturePercent < 0) {
    moisturePercent = 0;
  }
  if (moisturePercent > 100) {
    moisturePercent = 100;
  }

  Serial.print("Analog Reading: ");
  Serial.print(analogValue);
  Serial.print(" | Moisture Level: ");
  Serial.print(moisturePercent);
  Serial.print("% (");
  
  if (moisturePercent >= 70) {
    Serial.println("Very Wet - Don't Water)");
    digitalWrite(LED_PIN, LOW);
  } else if (moisturePercent >= 40) {
    Serial.println("Moist - Good to Go)");
    digitalWrite(LED_PIN, LOW);
  } else {
    Serial.println("TOO DRY! Please Water Now!)");
    digitalWrite(LED_PIN, HIGH);
  }
  
  delay(1000);
}