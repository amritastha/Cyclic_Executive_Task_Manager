# Cyclic_Executive_Task_Manager

## Overview:
Design and build an embedded system implemented on an Arduino Uno R3 development board that enables the user of the program to specify an LED number and its blinking interval (in msecs) that they defined LED should flash at. The blinking of the LEDs must continue asynchronously with any input from the user by entering their desired blinking interval into the terminal, which in turn adjusts the blinking interval of the corresponding LED.

## Purpose:
Develop a system for users to interactively select which LED to illuminate and adjust the corresponding LED's blinking interval by utilizing the Serial Monitor for user input to communicate directly with the Arduino board and the circuit breadboard, providing real-time control and response based on user input

## Technologies Used:
- Programming Language: Arduino C (Arduino IDE 2.3.3 or better)
- Tools/Equipment Required:
  - Arduino Uno R3 development board (ELEGOO Uno R3)
  - Arduino IDE 2.3.3 or better
  - 2 LEDs
  - 2 10kΩ Resistors
  - Breadboard and wires
  - Laptop or other computer to run the Arduino IDE
  - Cable to connect laptop/computer to the Arduino board

## Setup Instructions:
Hardware Setup:
<img width="1428" height="597" alt="image" src="https://github.com/user-attachments/assets/df2a4688-b763-44df-8446-ca48cdbba41c" />

- Runs upon an Arduino Uno R3 compatible development board
- Download Arduino IDE 2.3.3 or better onto laptop/computer

1. Open the Arduino IDE
2. Connect the Arduino Uno R3 board via USB
3. Upload the provided CE_Task_Manager.ino to the Arduino IDE
4. After compiling and verifying the code, upload the code to the Arduino Uno Board
5. Open the Serial Monitor within the Arduino Uno IDE
6. Follow prompts:
   - Enter LED number (1 or 2)
   - Enter blinking interval for corresponding LED in milliseconds

## Key Features:
- System implements polled and round-robin cyclic executive task manager based upon a function pointer array
- User interaction with the circuit is facilitated through Serial Monitor within the Arduino IDE application
- Blink rate (in milliseconds) of each LED are set independently of the other LED
- Setting of an LED blink rate (in milliseconds) does not interfere with the blinking of the LEDs until the new LED and blink rate are specified
- Input validation

## Contribution: 
This was an individual project. I designed and implemented the circuit on the breadboard, asynchronous LED control logic, serial input handling system, and testing and validation procedures.

## Sample Test/Usage Dialog:
<img width="1392" height="1020" alt="image" src="https://github.com/user-attachments/assets/1847020d-92ac-4cdc-8329-840a9987a2c2" />

## Reflection: 
I learned how real-time systems can manage multiple tasks simutaneously
