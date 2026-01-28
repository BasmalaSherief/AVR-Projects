# 🌡️ Temperature-Controlled Fan System (AVR ATmega32)

[![Microcontroller](https://img.shields.io/badge/AVR-ATmega32-blue)]()
[![Architecture](https://img.shields.io/badge/Architecture-Layered-orange)]()
[![Status](https://img.shields.io/badge/Status-Completed-success)]()

## 📖 Description
This project implements a **Smart Fan Controller System** based on the AVR **ATmega32** microcontroller. The system automatically adjusts the fan speed in real-time according to the ambient temperature readings, ensuring optimal cooling and energy efficiency.

The software is built on a **Layered Architecture Model**, prioritizing modularity and maintainability. It utilizes a comprehensive set of custom-written drivers:
* **MCAL:** GPIO, ADC, PWM
* **HAL:** DC Motor, LM35 Temperature Sensor, LCD

The system continuously displays the **Temperature** and **Fan State** on a 16x2 LCD, providing immediate feedback to the user.

## 📺 Project Demo
*Watch the system automatically adjust speed as the temperature rises.*

[**▶️ Watch the Hardware Simulation Video**](assets/demo.mp4)

## 🧠 System Logic & Speed Control
The system operates based on five distinct temperature ranges. The fan speed is controlled via **PWM (Pulse Width Modulation)** signals to the DC Motor driver.

| Temperature Range (°C) | Fan State | Speed % |
| :--- | :--- | :--- |
| **Temp < 30°C** | 🛑 OFF | 0% |
| **30°C ≤ Temp < 60°C** | 🟢 ON | 25% |
| **60°C ≤ Temp < 90°C** | 🟡 ON | 50% |
| **90°C ≤ Temp < 120°C** | 🟠 ON | 75% |
| **Temp ≥ 120°C** | 🔴 ON | 100% |

## 🏗️ Software Architecture
The code is organized into three distinct layers to decouple the hardware from the application logic:

1.  **Application Layer (`main.c`):**
    * Handles the main infinite loop.
    * Reads the temperature via the HAL.
    * Decides the motor speed based on the logic table above.
    * Updates the LCD display.

2.  **HAL (Hardware Abstraction Layer):**
    * **LM35 Driver:** Converts the raw ADC digital value into a Celsius temperature value.
    * **DC Motor Driver:** Controls the rotation direction (CW/ACW/Stop) and speed.
    * **LCD Driver:** Manages text and number rendering on the screen.

3.  **MCAL (Microcontroller Abstraction Layer):**
    * **ADC Driver:** Configures the Analog-to-Digital Converter to read the LM35 sensor.
    * **PWM Driver (Timer0):** Generates the PWM signal on `PB3` (OC0) to control motor speed.
    * **GPIO Driver:** Handles low-level pin directions and digital I/O.

## 🔌 Hardware Connections
* **ATmega32:** The brain of the system.
* **LM35 Sensor:** Connected to ADC Channel 2 (`PA2`).
* **DC Motor:** Controlled via L293D Bridge (Input pins on `PB0`, `PB1`).
* **LCD (16x2):** Data mode (8-bit) connected to Port C, Control pins on Port D.

## 🚀 How to Run
1.  **Clone the Repo:**
    ```bash
    git clone [https://github.com/BasmalaSherief/AVR-Projects.git](https://github.com/BasmalaSherief/AVR-Projects.git)
    ```
2.  **Open in IDE:** Import the project into **Eclipse (with AVR Plugin)** or **Microchip Studio**.
3.  **Simulate:** Open the Proteus file (`.pdsprj`) to see the circuit logic in action.
4.  **Flash:** Burn the generated `.hex` file to your ATmega32 using a USBasp or similar programmer.