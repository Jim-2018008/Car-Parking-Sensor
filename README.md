# Car-Parking-Sensor

---

# PWM and Interfacing in Arduino

## Description

This repository contains the code and simulation files for a personal project focused on **PWM (Pulse Width Modulation) and Interfacing in Arduino**. The main objective of this project is to explore the functionalities of PWM and how to interface an ultrasonic sensor and an LCD display using an Arduino.

## Objectives

1. To understand and implement PWM.
2. To interface an ultrasonic sensor and an LCD display with an Arduino.

## Components

### Software
- Arduino IDE

### Hardware
- Breadboard
- Arduino UNO
- Wires
- Ultrasonic sensor HC-SR04
- LCD display (LM016L in Proteus)
- LED
- Buzzer

## Experimental Setup

1. **Connections**: Connect the ultrasonic sensor, LCD display, LED, and buzzer appropriately.
2. **Coding**: Write a code that:
   - If the distance is larger than the max threshold (e.g., 60 cm):
     - The LCD displays "No one near" on the first line and the distance on the second line.
     - The LED is off.
     - The buzzer is off.
   - If the distance is lower than the min threshold (e.g., 10 cm):
     - The LCD displays "Danger" on the first line and the distance on the second line.
     - The LED blinks (2.5 sec ON, 2.5 sec OFF) with 100% duty cycle.
     - The buzzer beeps (only when the LED is off) with 100% duty cycle.
   - Otherwise:
     - The LCD displays the distance on the first line and "approach: x%" (where x is the duty cycle) on the second line.
     - The buzzer beeps (only when the LED is off) with the same duty cycle as the LED.

## Explanation

For accurate results, important values such as distance and duty cycle are printed on the serial monitor. In Proteus, to simulate fading LEDs, AC voltmeters may be used in parallel with the LED and the buzzer, and speakers may be used instead of buzzers for better visualization.

## Resources

- [Ultrasonic sensor calibration](https://projecthub.arduino.cc/panagorko/next-level-ultrasonic-sensor-df5768)
- [LCD display tutorial](https://www.makerguides.com/character-lcd-arduino-tutorial/)

## Contact

For any questions or further information, please contact [er.nafish.ahanaf@gmail.com](mailto:er.nafish.ahanaf@gmail.com).

---
