

# Smart Lighting System using IR Sensors and LDR

This project is a **smart lighting control system** that automatically adjusts LED brightness based on **ambient light** and **motion detection** using **IR sensors** and an **LDR**. It is designed to improve energy efficiency in indoor spaces such as hallways, staircases, or rooms.

---

## Features

* Detects motion using 8 IR sensors
* Uses an LDR to determine ambient light levels
* Controls LED brightness accordingly:

  * **Full brightness** when motion is detected in the dark
  * **Dim mode** when no motion is detected in the dark
  * **Turns off** LEDs during daytime or bright light
* Real-time status output to serial monitor for debugging and monitoring

---
<img width="677" height="336" alt="image" src="https://github.com/user-attachments/assets/e8a37f45-05eb-401a-901f-3b6ae7354bed" />


## Hardware Requirements

| Component         | Quantity  | Description                         |
| ----------------- | --------- | ----------------------------------- |
| IR Motion Sensors | 8         | Positioned to cover different zones |
| LDR Module        | 1         | To detect ambient light             |
| LED Strip or Bulb | 1         | Controlled via PWM                  |
| Arduino Board     | 1         | Uno, Nano, or compatible            |
| Resistors, Wires  | As needed | For safe and reliable connections   |

---

## Pin Configuration

| Component  | Pin(s) on Arduino |
| ---------- | ----------------- |
| IR Sensors | Digital Pins 5–12 |
| LDR        | Analog Pin A0     |
| LED Output | PWM Pin 3         |

---

## Working Principle

1. **Ambient Light Detection**
   The LDR reads the light intensity. If the reading is high (≥800), the system interprets this as **daytime** and turns off the LEDs.

2. **Motion Detection**
   When it's **dark** (LDR < 800), the system checks for motion using 8 IR sensors:

   * If **motion is detected**, the LED turns **fully ON** (100% brightness).
   * If **no motion**, the LED is set to **dim** (approximately 30% brightness).

3. **Energy Optimization**
   The LED is only active when necessary, ensuring efficient power usage in real-world deployments.

---

## Serial Monitor Output

```
LDR: 825 | Motion: 0
Daytime - LEDs OFF

LDR: 300 | Motion: 1
Motion detected - LEDs ON (100%)

LDR: 290 | Motion: 0
No motion - LEDs Dim (30%)
```

---

## Code Summary

### Variables

```cpp
int irSensors[8] = {5, 6, 7, 8, 9, 10, 11, 12}; // IR sensor pins
#define LDR_PIN A0                             // LDR analog pin
#define LED_CONTROL_PIN 3                      // PWM control for LED
```

### Main Logic

```cpp
- Read LDR value
- Check each IR sensor
- If bright → turn LEDs off
- If dark and motion → full brightness
- If dark and no motion → dim LED
```

---

## Getting Started

1. **Clone the repository**:

   ```bash
   git clone https://github.com/yourusername/smart-lighting-ir-ldr.git
   ```

2. **Upload the code**:

   * Open the `.ino` file in Arduino IDE
   * Connect your Arduino board
   * Upload the sketch

3. **Connect Components** as per the pin configuration

---

## Applications

* Smart corridors and staircases
* Motion-activated night lighting
* Classroom or office ambient lighting automation
* Energy-saving automation projects

---

## Author

**Sourashis Das**
Embedded Systems and IoT Developer



