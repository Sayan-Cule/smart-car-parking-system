# Smart Car Parking System

An IoT-based smart parking prototype developed using Arduino, ultrasonic sensors, a servo motor, and an ESP32.

## Overview

The system uses ultrasonic sensors to detect vehicle presence in parking spaces and at the entrance. Based on slot availability, the Arduino controls a servo-operated gate and sends parking status messages over serial communication.

The original academic project also included an Arduino IoT Cloud component.

## Hardware

- Arduino UNO
- HC-SR04 ultrasonic sensors
- Servo motor
- ESP32
- Breadboard and connecting wires
- Power supply

## Software

- Arduino IDE
- Arduino IoT Cloud
- Tinkercad

## Repository Structure

```text
smart-car-parking-system/
├── README.md
├── .gitignore
├── docs/
│   └── pin-connections.md
└── src/
    ├── arduino/
    │   └── parking.ino
    └── esp32/
        └── esp.ino
```

## How It Works

1. Two ultrasonic sensors monitor the parking slots.
2. A third ultrasonic sensor detects a vehicle at the entrance.
3. The Arduino determines whether a slot is available.
4. If a vehicle is detected and a slot is available, the servo opens the gate.
5. The Arduino reports slot status and parking information over serial communication.
6. The ESP32 sketch provides the serial/debug side of the system.

## Current Arduino Implementation

The available `parking.ino` actively checks **two parking slots** and one gate sensor. A third-slot implementation remains in the source as commented-out code.

The gate servo is controlled using:
- `servo.write(0)` to open
- `servo.write(90)` to close

## Arduino Dependencies

The Arduino sketch uses:

- NewPing
- Servo

Install the required libraries through the Arduino IDE before compiling.

## Pin Connections

See [docs/pin-connections.md](docs/pin-connections.md).

## Arduino IoT Cloud

The original project included an Arduino IoT Cloud dashboard and ESP32 cloud integration. The Cloud-generated `thingProperties.h` configuration and account-specific settings are not included because they are not part of the available source files.

No credentials, API keys, or account configuration are included in this repository.

## Project Status

This repository contains the source code currently available from the original academic project and is maintained as a portfolio/interview reference.
