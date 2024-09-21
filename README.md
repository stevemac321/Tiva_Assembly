Here's an updated README file for your project, focusing more on the `scan.s` feature, while still mentioning the other demo options.

---

# Tiva Assembly Button Detection and Blinky Project

## Overview
This project demonstrates the use of ARM assembly alongside C code to control GPIO pins on the Tiva C Series microcontroller. It includes multiple demos showcasing button detection and LED control. The primary focus is the **button detection assembly function** `scan`, which reads the button state and toggles an LED. In addition, the project also contains other demos, including a **C-based button detection** and an **assembly-based blinky**.

## Files
- **blinky.c**: The main C file, which initializes the microcontroller, configures the GPIO pin for the on-board LED (PF3), and provides alternative ways to toggle the LED.
- **scan.s**: The assembly code file containing the `scan` function that detects a button press and toggles the LED accordingly.
- **io.s**: Another assembly file that contains the `toggle` function for basic LED blinking functionality.

## Main Features
### 1. Button Detection in Assembly (`scan.s`)
The **`scan` function** detects when the button connected to **PF0** is pressed. It toggles the LED connected to **PF3** based on the button state. The function uses direct GPIO register manipulation in assembly language to read the button input and set the LED output.

- **movw, movt**: Load the base address of the GPIO port.
- **cmp, beq, bne**: Compare the button state with the input mask to determine if it is pressed.
- **set_high, set_low**: These labels handle turning the LED on or off by writing directly to the GPIO data register.

### 2. Button Detection in C (`cscan` in `blinky.c`)
There is also a **C-based button detection** function, `cscan()`, which achieves the same button detection and LED toggling behavior but using TivaWare API calls.

- **GPIOPinRead**: Reads the current state of the button.
- **GPIOPinWrite**: Toggles the LED based on the button state.

### 3. Blinky Demo in Assembly (`toggle` in `io.s`)
A simpler blinky demo is also available, where the LED connected to **PF3** toggles on and off with a delay loop in between.

- **toggle**: An assembly function that receives a flag to turn the LED on or off.

## How to Build and Run

### Prerequisites
- Texas Instruments Code Composer Studio (CCS)
- TivaWare library installed
- A Tiva C Series development board (e.g., TM4C123G)

### Steps
1. Clone this repository to your local machine.
2. Open Code Composer Studio and import this project.
3. Ensure that `blinky.c`, `scan.s`, and `io.s` are part of the project.
4. Build the project in CCS.
5. Load the binary onto your Tiva C development board.

### Running the Demos
The project defaults to running **`scan.s`** for button detection. You can switch between the C-based and assembly-based button detection or blinky demos by enabling the relevant code block in the `main` function using `#if 0` / `#endif` blocks.

- **Button Detection (Assembly)**: This is the default demo and runs when the program is uploaded. The LED toggles based on the button state.
- **Button Detection (C)**: To switch to the C implementation, adjust the `#if 0` block around `cscan()`.
- **Blinky (Assembly)**: The simple blinky demo is available by switching to the `#if 0` block containing the `toggle` function.

## License
This project is released under the GPL Version 2 License. 

---

