    .sect ".text"
    .thumb
    .global toggle

toggle:
    movw    r2, #0x5000          ; Load lower half of GPIO_PORTF_BASE into R2
    movt    r2, #0x4002          ; Load upper half of GPIO_PORTF_BASE into R2
    movw    r3, #0x0008          ; Load GPIO_PIN_3 into R3

    cmp     r0, r1
    beq     set_high
    bne     set_low

set_high:
    str     r3, [r2, #0x3FC]     ; Write GPIO_PIN_3 to GPIO_PORTF_BASE + GPIODATA
    b       store_value

set_low:
    mov     r0, #0x00
    str     r0, [r2, #0x3FC]     ; Write 0x00 to GPIO_PORTF_BASE + GPIODATA

store_value:
    bx      lr

    .end
