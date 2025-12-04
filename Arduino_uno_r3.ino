#define AOUT_PIN A0
#define LED_PIN 13
#define BUZZER_PIN 8 // New: Digital Pin connected to the buzzer/speaker

// Calibration Values (Update these based on your setup!)
const int DRY_VALUE = 800;
const int WET_VALUE = 300;

const int DRY_THRESHOLD_PERCENT = 40;
const int NUM_SAMPLES = 10; // New: Number of samples to take for averaging

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT); // Initialize buzzer pin
}

// Function to read and average multiple sensor samples
int getAverageReading() {
  long totalValue = 0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    totalValue += analogRead(AOUT_PIN);
    delay(5); // Small delay between samples
  }
  return totalValue / NUM_SAMPLES;
}

void loop() {
  // 1. Read and Average Analog Value
  int analogValue = getAverageReading(); 

  // 2. Convert to Percentage
  int moisturePercent = map(analogValue, DRY_VALUE, WET_VALUE, 0, 100);
  
  if (moisturePercent < 0) {
    moisturePercent = 0;
  }
  if (moisturePercent > 100) {
    moisturePercent = 100;
  }

  // 3. Serial Monitor Output
  Serial.print("Avg Analog Reading: ");
  Serial.print(analogValue);
  Serial.print(" | Moisture Level: ");
  Serial.print(moisturePercent);
  Serial.print("% (");
  
  // 4. Moisture Level Classification and Alert Control
  if (moisturePercent >= 70) {
    Serial.println("Very Wet - Don't Water)");
    digitalWrite(LED_PIN, LOW); 
    noTone(BUZZER_PIN); // Turn buzzer OFF
  } else if (moisturePercent >= 40) {
    Serial.println("Moist - Good to Go)");
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN); // Turn buzzer OFF
  } else {
    Serial.println("TOO DRY! Please Water Now!)");
    digitalWrite(LED_PIN, HIGH); // Turn LED ON
    // New: Play an audible tone for 500ms
    tone(BUZZER_PIN, 1000, 500); // Play 1000 Hz tone for 500ms
  }
  
  delay(2000); // Wait 2 seconds before the next check
}