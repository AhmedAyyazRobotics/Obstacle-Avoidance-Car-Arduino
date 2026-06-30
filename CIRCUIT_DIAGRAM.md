# Circuit Diagram & Wiring Guide

## Complete Wiring Diagram
Arduino Uno          L298N Motor Driver       Motors
Pin 5 (PWM) ------> ENA
Pin 2 -----------> IN1
Pin 3 -----------> IN2                       OUT1/OUT2 -----> Left Motors
Pin 6 (PWM) ------> ENB
Pin 4 -----------> IN3
Pin 7 -----------> IN4                       OUT3/OUT4 -----> Right Motors
Battery (+7.4V) -----> +12V (L298N)
Battery GND ---------> GND (L298N & Arduino)
HC-SR04 Sensor
Pin 8 -----------> TRIG
Pin 10 ---------> ECHO
5V Pin ---------> VCC
GND Pin --------> GND
Servo Motor
Pin 9 -----------> Signal (Orange)
5V Pin ---------> VCC (Red)
GND Pin --------> GND (Brown)
## Step-by-Step Wiring

1. Connect Arduino GND to L298N GND (common ground - IMPORTANT)
2. Connect battery positive to L298N +12V
3. Connect battery negative to L298N GND and Arduino GND
4. Wire motor control pins (2,3,4,7) to L298N IN pins
5. Wire PWM pins (5,6) to L298N ENA/ENB
6. Connect motors to L298N outputs
7. Connect sensor TRIG/ECHO to pins 8/10
8. Connect servo signal to pin 9
9. Connect 5V and GND for sensor and servo from Arduino

## Verification Checklist

- [ ] Common ground between Arduino and L298N
- [ ] Battery connected to L298N (not Arduino directly)
- [ ] All motor wires secure
- [ ] Sensor pins correct (8=TRIG, 10=ECHO)
- [ ] Servo signal on pin 9
- [ ] Battery voltage between 7-12V
