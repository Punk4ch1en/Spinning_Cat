#include "utils.h"

void delay(uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        __asm volatile("NOP");  // No operation, just to waste time
    }
}

void init_hardware(void) {
    // Placeholder for hardware initialization
    // This would typically involve setting up clocks, GPIO, etc.
}
