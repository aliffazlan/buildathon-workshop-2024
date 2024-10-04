#include "BluetoothSerial.h" 

BluetoothSerial SerialBT;

const int ledPin = 2;  // Pin where the LED is connected

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Start Bluetooth with a name
  SerialBT.begin("im smelly");  // Change this name to whatever you like
  Serial.println("Bluetooth device is ready to pair.");

  Serial.begin(9600);
}

void loop() {
  // Check if there's any data received via Bluetooth
  if (SerialBT.available()) {
    String input = SerialBT.readString();
    input.trim();

    Serial.print("Received via Bluetooth: ");
    Serial.println(input);

    // Control the LED based on the received command
    // You can add more if statements for more functions if you want!
    if (input == "on") {
      digitalWrite(ledPin, HIGH);
      SerialBT.println("LED is ON");
    } else if (input == "off") {
      digitalWrite(ledPin, LOW); 
      SerialBT.println("LED is OFF");
    } else {
      SerialBT.println("Invalid command. Type 'on' or 'off'.");
    }
  }
}