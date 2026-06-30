# Problems Faced & Solutions

## Problem 1: Motor Connection Issue

**Issue:**
- Needed to control 4 DC motors independently
- Only had L298N motor driver (controls 2 motors max)
- No stepper motor capable of controlling all 4 motors simultaneously

**Solution:**
- Paired motors in parallel: soldered two motors together
- Connected one positive and one negative terminal from each pair to L298N outputs
- Result: OUT1/OUT2 controls both left motors, OUT3/OUT4 controls both right motors
- **Learning:** Basic soldering technique - connecting motor wires safely

**Code Impact:**
- Single speed value (analogWrite) controls both motors on same side
- Both motors on same side spin at identical speed

---

## Problem 2: Servo Motor Type Mismatch

**Issue:**
- Project required standard servo motor (SG90) for precise angle positioning
- Only had continuous rotation servo motor available
- Standard servo rotates to specific angles (0-180°) and holds position
- Continuous servo only spins continuously in one direction or stops

**Solution:**
- Used time-based calibration instead of angle-based control
- Calculated rotation speed: ~60 RPM = 6°/second
- For ~180° rotation needed: 180°/6°/sec = 30 seconds
- Optimized through testing: found 400ms gives ~180° rotation

**Code Workaround:**
```cpp
#define ROTATION_TIME 400  // milliseconds for ~180 degrees

// Rotate left
myServo.write(30);
delay(ROTATION_TIME);  // Wait for ~180 degrees
myServo.write(90);     // Stop at center
```

**Learning:** Adaptive problem-solving when exact components unavailable

---

## Problem 3: Battery Power vs USB Power

**Issue:**
- Sensor and motors worked perfectly on USB power (Arduino connected to computer)
- Switching to battery power caused:
  - Motors not responding
  - Sensor not detecting obstacles
  - Erratic car behavior

**Root Cause:**
- Motor driver pulling high current from battery
- Voltage sag on power lines
- Arduino's 5V regulator couldn't handle the load
- Arduino and sensor receiving unstable 5V

**Solution:**
- Ensured proper power connections:
  - Battery → L298N +12V (not Arduino)
  - Common ground between Battery, L298N, and Arduino (CRITICAL)
  - Arduino 5V used only for sensor and servo (light loads)
  - Added stable power from battery through L298N GND

**Learning:** Importance of power management and common ground in Arduino projects

---

## Problem 4: Sensor Not Detecting Obstacles Properly

**Issue:**
- HC-SR04 sensor returning zero or unrealistic values
- Car moving at maximum speed without detecting obstacles
- No obstacle avoidance happening

**Solution:**
- Added timeout to pulseIn() function: `pulseIn(ECHO, HIGH, 30000)`
- Implemented distance validation:
```cpp
  if (dist == 0 || dist > 400) {
    return 400;  // Return max distance if no valid reading
  }
```
- Reduced speed threshold to 30cm (earlier was 25cm)
- Added serial debugging to monitor actual distances

**Learning:** Sensor reliability requires proper error handling and validation

---

## Problem 5: Car Moving Too Fast & Hitting Obstacles

**Issue:**
- Motor speed set to 220 PWM (near maximum)
- Car couldn't stop in time when detecting obstacles
- Continuous collisions

**Solution:**
- Reduced motor speed from 220 to 150 PWM
- Increased detection distance threshold from 25cm to 30cm
- Car now has enough reaction time and can stop safely

**Code Change:**
```cpp
analogWrite(ENA, 150);  // Reduced from 220
if (distance > 30) {    // Increased from 25
  moveForward();
}
```

---

## Skills Learned

### Soldering
- Safely connecting motor wires to L298N terminals
- Proper solder joint technique
- Heat management to avoid damaging components

### Problem-Solving
- Adapting to unavailable components
- Testing and calibration (servo rotation time)
- Debugging with Serial Monitor

### Power Management
- Importance of common ground
- Battery vs USB power differences
- Current distribution in circuits

### Sensor Calibration
- HC-SR04 distance measurement validation
- Error handling in sensor readings
- Distance threshold adjustment

---

## Lessons for Future Projects

1. **Always have common ground** between all components
2. **Power management is critical** - separate high-current and low-current circuits
3. **Test with actual power source** - USB may mask power issues
4. **Sensor validation is essential** - always check for zero/error values
5. **Speed tuning matters** - too fast = collisions, too slow = impractical
6. **Time-based workarounds** can work when exact components unavailable

---

## What Worked Well

- L298N motor driver flexibility
- Arduino Uno's PWM pins for speed control
- HC-SR04 sensor accuracy after proper calibration
- Continuous servo with time-based rotation
- Soldered motor connections held strong under operation
