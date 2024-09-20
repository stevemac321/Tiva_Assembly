# Tiva Assembly Blinky Project

## Overview
This project demonstrates the use of ARM assembly alongside C to control GPIO pins on the Tiva C Series microcontroller. The assembly function `toggle` is used to toggle the state of the LED connected to pin PF3. The C code continuously blinks the LED with a delay loop in between toggles.

## Files
- **blinky.c**: The main C file, which initializes the microcontroller, configures the GPIO pin for the on-board LED (PF3), and calls the assembly function `toggle` to control the LED.
- **io.s**: The assembly code file that contains the `toggle` function, responsible for turning the LED on and off by writing to the GPIO port.

## Assembly (io.s)

The `toggle` function in the assembly file uses direct register manipulation to control GPIO pins. Here's a breakdown of the assembly code:

- **movw, movt**: Load the lower and upper half of the GPIO port base address into register `r2`.
- **cmp, beq, bne**: Compare the input parameter (`r0`) to decide whether to turn the LED on or off.
- **set_high, set_low**: These labels handle writing to the GPIO pin to set it high (turn on the LED) or low (turn off the LED).

## C Code (blinky.c)

The C code performs the following tasks:

1. Initializes the GPIO peripheral for port F.
2. Configures pin PF3 as an output pin.
3. Calls the `toggle` function (written in assembly) to turn the LED on and off.
4. Contains delay loops between toggling to create a visible blinking effect.

### Function `toggle`
This function is defined in assembly and called from C with a single parameter, `flag`:
- `1` to turn the LED on.
- `0` to turn the LED off.

## How to Build and Run
### Prerequisites
- Texas Instruments Code Composer Studio (CCS)
- TivaWare library installed
- A Tiva C Series development board (e.g., TM4C123G)

### Steps
1. Clone this repository to your local machine.
2. Open Code Composer Studio and import this project.
3. Ensure that `blinky.c` and `io.s` are part of the project.
4. Build the project in CCS.
5. Load the binary onto your Tiva C development board.
6. Observe the LED (connected to PF3) blinking on and off.

## License
This project is released under the GPL Version 2 License. See [LICENSE](LICENSE) for details.
