# Cyclic_Executive_Task_Manager

## Overview:
- Design and build an embedded system implemented on an Arduino Uno R3 development board that enables the user to independently control the blinking interval (in milliseconds) of two LEDs via the Serial Monitor terminal
- Use a cyclic executive (round-robin scheduler) and non-blocking timing to ensure both LEDs operate concurrently without interfering with user input

## Purpose:
Demonstrate real-time embedded system design, asynchronous task execution, and iteractive hardware control via serial communication to provide real-time control and response based on user input

## Technologies Used:
- Language: Arduino C/C++
- Platform: Arduino IDE 2.3.3 or better
- Tools/Equipment Required:
  - Arduino Uno R3 development board (ELEGOO Uno R3)
  - Arduino IDE 2.3.3 or better
  - 2 LEDs
  - 2 Resistors (10kΩ resistors were used in this setup)
  - Breadboard and wires
  - Laptop or other computer to run the Arduino IDE
  - Cable to connect laptop/computer to the Arduino board

## Setup Instructions:
Hardware Setup:
<img width="1428" height="597" alt="image" src="https://github.com/user-attachments/assets/df2a4688-b763-44df-8446-ca48cdbba41c" />
- Runs upon an Arduino Uno R3 compatible development board
- Download Arduino IDE 2.3.3 or better onto laptop/computer

## How to Run
1. Open the Arduino IDE
2. Connect the Arduino Uno R3 board via USB
3. Upload the provided CE_Task_Manager.ino to the Arduino IDE
4. After compiling and verifying the code, upload the code to the Arduino Uno Board
5. Open the Serial Monitor within the Arduino Uno IDE
6. Follow prompts:
   - Enter LED number (1 or 2)
   - Enter blinking interval for corresponding LED in milliseconds

## Key Features:
- Implements polled and round-robin cyclic executive task manager
- Independent control of multiple LEDs
- Real-time user interaction facilitated through Serial Monitor (within the Arduino IDE application)
- Non-blocking execution
- Input validation for invalid LED numbers or blinking intervals

## Contribution: 
This was an individual project. I designed and implemented the circuit, asynchronous LED control logic, serial input handling system, and testing and validation procedures.

## Sample Test/Usage Dialog:
<img width="1392" height="1020" alt="image" src="https://github.com/user-attachments/assets/1847020d-92ac-4cdc-8329-840a9987a2c2" />

## Reflection: 
- Learning how real-time systems can manage multiple tasks simutaneously
- Designing a responsive input system without blocking execution
