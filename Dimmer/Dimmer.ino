int ledPin = 2;
int freq = 1000;
int resolution = 8;

void setup() {
  ledcAttach(ledPin, freq, resolution);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readString();
    input.trim();

    // NOTE: Theres a better way to do this without using a bunch of if statements. See if you can figure it out!
    // HINT: It involves a bit of math!
    if (input == "0") {
      ledcWrite(ledPin, 0);
    }
    else if (input == "1") {
      ledcWrite(ledPin, 50);
    }
    else if (input == "2") {
      ledcWrite(ledPin, 100);
    }
    else if (input == "3") {
      ledcWrite(ledPin, 150);
    }
    else if (input == "4") {
      ledcWrite(ledPin, 200);
    }
    else if (input == "5") {
      ledcWrite(ledPin, 250);
    }
  }
}
