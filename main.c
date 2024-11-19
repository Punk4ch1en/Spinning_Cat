#include <stdint.h>
#include "utils.h"

// Main entry point of the firmware
int main(void) {
    // Initialize hardware
    init_hardware();

    // Main loop
    while (1) {
        // Example: Toggle an LED
        toggle_led();
        
        // Example: Delay
        delay(1000000);  // Delay for 1 second (assuming 1MHz clock)
    }

    return 0;
}

// Inline assembly example for toggling an LED
void toggle_led(void) {
    __asm volatile (
        "LDR R0, =0x40000000\n"  // Assume LED control register is at this address
        "LDR R1, [R0]\n"         // Load current value
        "EOR R1, R1, #1\n"       // Toggle the LED bit
        "STR R1, [R0]\n"         // Store back
    );
}
