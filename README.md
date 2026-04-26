# Cyclic_Executive_Task_Manager

## Overview:
Develop a circuit implemented on an Arduino Uno R3 development board that enables the user of the program to specify an LED number and its blinking interval (in msecs) that they defined LED should flash at. The blinking of the LEDs must continue asynchronously with any input from the user by entering their desired blinking interval into the terminal, which in turn adjusts the blinking interval of the corresponding LED.

## Purpose:
Design and build an embedded system that enables user to independently set the blinking intervals of the corresponding two LEDs

## Technologies Used:
- Programming Language: Arduino C (Arduino IDE 2.3.3 or better)
- Tools/Equipmenent:
  - Arduino Uno R3 development board (ELEGOO Uno R3)

## Setup, installation, or usuage instructions:
- Runs upon an Arduino Uno R3 compatible development board

## Key Features:
- System implements polled and round-robin cyclic executive task manager based upon a function pointer array
- Blink rate (in milliseconds) of each LED are set independently of the other LED through the IDE serial monitor
- Setting of an LED blink rate (in milliseconds) does not interfere with the blinking of the LEDs until the new LED and blink rate are specified

## Contribution: This was an individual project.

## Sample Output:

## Reflection/Lesson Learned/Challenge:
