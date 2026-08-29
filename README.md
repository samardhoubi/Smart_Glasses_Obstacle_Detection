# ESP32 Smart Obstacle Detector Glasses

An assistive technology project designed to help blind and visually impaired people become aware of obstacles.

## Project Idea

This project is designed as a smart glasses system that helps blind and visually impaired people detect obstacles.

It uses an ultrasonic sensor to detect obstacles in front of the user. The sensor continuously measures the distance between the user and nearby objects.

When an obstacle is detected, the ESP32 processes the distance information and activates a buzzer to warn the user.

## Components

- ESP32
- Ultrasonic Sensor
- Buzzer
- Jumper Wires

## How It Works

The ultrasonic sensor continuously measures the distance to obstacles in front of the user.

The ESP32 processes this information and controls the buzzer based on how close the obstacle is:

- More than 100 cm: No warning
- Between 50 and 100 cm: Slow beeping
- Between 20 and 50 cm: Fast beeping
- Less than 20 cm: Continuous warning

## Connections

### Ultrasonic Sensor

- TRIG → GPIO 26
- ECHO → GPIO 25
- GND → GND
- VCC → 5V

### Buzzer

- Signal → GPIO 27
- GND → GND

## Technologies Used

- ESP32
- Arduino IDE
- C++
- Ultrasonic Distance Sensing
