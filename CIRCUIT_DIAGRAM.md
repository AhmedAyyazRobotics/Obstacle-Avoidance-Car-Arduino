# Circuit Diagram & Wiring Guide

## Complete Wiring Diagram

### Arduino to L298N
- Pin 5 (PWM) → ENA
- Pin 2 → IN1
- Pin 3 → IN2
- Pin 6 (PWM) → ENB
- Pin 4 → IN3
- Pin 7 → IN4

### L298N to Motors
- OUT1/OUT2 → Left Motors
- OUT3/OUT4 → Right Motors

### Battery to L298N
- Battery (+7.4V) → +12V (L298N)
- Battery GND → GND (L298N & Arduino)

### HC-SR04 Sensor to Arduino
- Pin 8 → TRIG
- Pin 10 → ECHO
- 5V Pin → VCC
- GND Pin → GND

### Servo Motor to Arduino
- Pin 9 → Signal (Orange)
- 5V Pin → VCC (Red)
- GND Pin → GND (Brown)

## Important Notes

1. **Common Ground:** Connect Arduino GND to L298N GND (REQUIRED)
2. **Battery Power:** Connect battery to L298N, NOT directly to Arduino
3. **Motor Connections:** Ensure all 4 motors are wired to L298N outputs
4. **Sensor Pins:** TRIG=Pin 8, ECHO=Pin 10 (exact pins required)
5. **Servo Pin:** Pin 9 must be used for servo signal
6. **Voltage:** Battery should be 7-12V for L298N

## Verification Checklist

- [ ] Common ground between Arduino and L298N
- [ ] Battery connected to L298N (not Arduino)
- [ ] All motor wires secure to L298N outputs
- [ ] Sensor pins correct (8 and 10)
- [ ] Servo on pin 9
- [ ] Battery voltage 7-12V
