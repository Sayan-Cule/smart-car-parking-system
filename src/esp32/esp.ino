#define RXp2 16
#define TXp2 17

#include "thingProperties.h"

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  delay(1500);

  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  String slots;

  ArduinoCloud.update();

  if (Serial2.available()) {
    Serial.println("Available");

    String message = Serial2.readStringUntil('\n');
    Serial.println(message);

    if (message == "message") {
      Serial.println("Got message");
      status = Serial2.readStringUntil('\n');
    }
    else if (message == "slots") {
      Serial.println("Got slots");

      slots = Serial2.readStringUntil('\n');
      if (slots == "1")
        gate_1 = true;
      else
        gate_1 = false;

      slots = Serial2.readStringUntil('\n');
      if (slots == "1")
        gate_2 = true;
      else
        gate_2 = false;
    }
    else if (message == "message2") {
      car_stat = Serial2.readStringUntil('\n');
    }

    Serial.println("out of loop");
  }
}

void onGate1Change() {
}
