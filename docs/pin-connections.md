# Pin Connections

The following connections match the current `src/arduino/parking.ino` source.

## Arduino UNO

| Component | Pin |
|---|---:|
| Slot 1 ultrasonic TRIG | 6 |
| Slot 1 ultrasonic ECHO | 7 |
| Slot 2 ultrasonic TRIG | 4 |
| Slot 2 ultrasonic ECHO | 5 |
| Gate ultrasonic TRIG | 10 |
| Gate ultrasonic ECHO | 11 |
| Servo signal | 9 |

## ESP32

The available `src/esp32/esp.ino` defines:

| Signal | ESP32 GPIO |
|---|---:|
| RX2 | 16 |
| TX2 | 17 |

The `Serial2.begin(...)` line is currently commented out in the available ESP32 source, so this repository does not claim a fully configured ESP32-to-Arduino serial link from that sketch alone.
