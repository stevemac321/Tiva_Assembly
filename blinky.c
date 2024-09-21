//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2012-2020 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.2.0.295 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/timer.h"     // For Timer functions
#include "driverlib/interrupt.h" // For interrupt functions
#include "driverlib/sysctl.h"    // For system control (clock, peripherals)


void PortFunctionInit(void);
void scan();

// "scan.s"  is assembly code version that turns on the LED if the button is pushed, its the lower right button
int main(void) {
    // Initialize GPIO
    PortFunctionInit();

    while (1) {
        scan();
    }
}

// here is a "C" code version that turns on the LED if the button is pushed, its the lower right button
#if 0


#define LED_PIN GPIO_PIN_3
#define BUTTON_PIN GPIO_PIN_0
void cscan();

int main(void) {
    // Initialize GPIO
    PortFunctionInit();

    volatile int i = 0;
    while (1) {
        cscan();
    }
}
void cscan()
{
    // Read the button state (0 if pressed, 1 if not pressed due to pull-up)
     if (GPIOPinRead(GPIO_PORTF_BASE, BUTTON_PIN) == 0) {
         // Button pressed, turn on LED
         GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN, LED_PIN);
     } else {
         // Button not pressed, turn off LED
         GPIOPinWrite(GPIO_PORTF_BASE, LED_PIN, 0);
     }
}
#endif


// io.s is a "blinky" using the assembly.
#if 0

void toggle(const int flag);

int main(void) {
    // Initialize GPIO
    PortFunctionInit();

    volatile int i = 0;
    while (1) {
           // Blinky mode with a delay loop
           for (i=0; i < 2000000; i++) {
               // Simple delay loop
           }
           toggle(1);  // Turn on the LED

           for (i = 0; i < 2000000; i++) {
               // Simple delay loop
           }
           toggle(0);  // Turn off the LED
    }
}
#endif




void PortFunctionInit(void) {
    // Set system clock to 50MHz
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Enable peripheral for GPIOF (buttons and LED)
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    // Unlock PF0 because it is locked by default
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= BUTTON_PIN;

    // Configure PF0 as input with pull-up resistor
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, BUTTON_PIN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, BUTTON_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    // Configure PF3 (LED) as output
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_PIN);
}

