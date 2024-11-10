#include "gpio.h"

void init_gpio(void) {
    // Example: Set GPIO for LED
    __asm volatile (
        "LDR R0, =0x40000000\n"  // GPIO base address
        "MOV R1, #1\n"           // Set pin 0 as output
        "STR R1, [R0]\n"
    );
}

void toggle_led(void) {
    __asm volatile (
        "LDR R0, =0x40000004\n"  // GPIO output register
        "LDR R1, [R0]\n"
        "EOR R1, R1, #1\n"
        "STR R1, [R0]\n"
    );
}
