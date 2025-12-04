int sensorPin = A0; 
float voltage;
float tempC;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(sensorPin);

  // Convert reading (0-1023) to Voltage (0-5V)
  voltage = reading * (5.0 / 1023.0);

  // Convert Voltage to Celsius (10mV = 1 degree)
  tempC = voltage * 100; 

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(1000);
}