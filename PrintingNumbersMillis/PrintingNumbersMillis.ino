void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 1; i < 11; i++) {
    Serial.println(i);
    int currentMillis = millis();
    while (millis() - currentMillis < 1000) {
      // Just wait
    }
  }
}
