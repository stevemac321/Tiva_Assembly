    .sect ".rodata"
    .align 2

GPIO_PORTF_BASE   .equ 0x40025000     ; Base address for GPIO Port F
GPIODATA_OFFSET   .equ 0x3FC          ; Offset for the Data Register (all pins)
GPIO_PIN_0        .equ 0x01           ; Pin 0 corresponds to bit 0 (Button)
GPIO_PIN_3        .equ 0x08           ; Pin 3 corresponds to bit 3 (LED)

    .sect ".text"
    .thumb
    .global scan

scan:
    ; Load the base address of GPIO Port F
    movw    r2, #GPIO_PORTF_BASE & 0xFFFF
    movt    r2, #GPIO_PORTF_BASE >> 16

    ; Read the button state (PF0) from GPIODATA
    ldr     r0, [r2, #GPIODATA_OFFSET]  ; Load contents of GPIODATA (read current state)
    tst     r0, #GPIO_PIN_0             ; Test if PF0 is pressed

    ; If the button is pressed (0 due to pull-up), jump to set_high
    beq     set_high
    ; Otherwise, jump to set_low
    b       set_low

set_high:
    ; Set the GPIO Pin 3 (turn on LED)
    mov     r0, #GPIO_PIN_3
    str     r0, [r2, #GPIODATA_OFFSET]  ; Write value to GPIODATA to turn LED on
    b       done

set_low:
    ; Clear the GPIO Pin 3 (turn off LED)
    mov     r0, #0x00
    str     r0, [r2, #GPIODATA_OFFSET]  ; Write value to GPIODATA to turn LED off

done:
    bx      lr                          ; Return from function
    .end
