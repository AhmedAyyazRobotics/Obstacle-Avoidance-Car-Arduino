# Obstacle-Avoidance-Car-Arduino
4-Wheel obstacle avoidance robot car using Arduino Uno, L298N motor driver, HC-SR04 ultrasonic sensor, and continuous rotation servo motor
## Project Overview

This is an obstacle avoidance robot built with Arduino Uno that:
- Detects obstacles using HC-SR04 ultrasonic sensor
- Scans left/right using continuous rotation servo motor
- Controls 4 DC motors via L298N motor driver
- Makes intelligent decisions to navigate around obstacles
- Powered by 7.4V Li-ion batteries

## Hardware Components

- **Microcontroller:** Arduino Uno
- **Motor Driver:** L298N Dual H-Bridge
- **Distance Sensor:** HC-SR04 Ultrasonic Sensor
- **Servo Motor:** Continuous Rotation SG90
- **Motors:** 4x DC Geared Motors
- **Power:** 2x 3.7V Li-ion Batteries (7.4V)
- **Chassis:** 4-Wheel Robot Car Kit

## Pin Configuration

### L298N Motor Driver
- ENA → Arduino Pin 5 (PWM)
- IN1 → Arduino Pin 2
- IN2 → Arduino Pin 3
- ENB → Arduino Pin 6 (PWM)
- IN3 → Arduino Pin 4
- IN4 → Arduino Pin 7

### HC-SR04 Sensor
- TRIG → Arduino Pin 8
- ECHO → Arduino Pin 10
- VCC → Arduino 5V
- GND → Arduino GND

### Servo Motor
- Signal → Arduino Pin 9
- VCC → Arduino 5V
- GND → Arduino GND

## How It Works

1. **Obstacle Detection:** HC-SR04 sensor measures distance continuously
2. **Scanning:** When obstacle detected, servo rotates to scan left and right
3. **Decision Making:** Arduino compares distances and chooses the path with more clearance
4. **Movement:** Motors move forward or turn based on sensor data
5. **Repeat:** Process continues autonomously

## Code Features

- Distance threshold: 30cm
- Motor speed: 150 PWM (reduced for safer navigation)
- Servo rotation time: 400ms (~180 degrees)
- Serial debugging enabled

## How to Upload

1. Connect Arduino to computer via USB
2. Open Arduino IDE
3. Paste the code into the IDE
4. Select Board: Arduino Uno
5. Select Port: COM (your Arduino port)
6. Click Upload

## Power Notes

- Use 7.4V battery (2x 3.7V Li-ion cells in series)
- Ensure common ground between Arduino and L298N
- Battery voltage should be 7-12V for L298N

## Future Improvements

- Add line-following capability
- Implement OLED display for sensor readings
- Add Bluetooth control
- Upgrade to ESP32 for WiFi connectivity

## Author

Ahmed Ayyaz  
NUST H-12 SEECS (Batch 2025)

## License

MIT License - See LICENSE file for details
