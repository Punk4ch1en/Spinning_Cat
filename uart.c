#include "uart.h"

void init_uart(void) {
    // Initialize UART for 9600 baud rate, assuming a 1MHz clock
    __asm volatile (
        "LDR R0, =0x40002000\n"  // UART base address
        "MOV R1, #0x6\n"         // Set UART to 9600 baud
        "STR R1, [R0, #0x0]\n"
        "MOV R1, #0x7\n"         // Enable UART TX and RX
        "STR R1, [R0, #0x1]\n"
    );
}

void uart_send_char(char c) {
    // Wait for UART to be ready
    __asm volatile (
        "LDR R0, =0x40002000\n"
        "1: LDR R1, [R0, #0x2]\n"
        "TST R1, #0x20\n"
        "BEQ 1b\n"
        "STRB %0, [R0, #0x0]\n"
        : : "r" (c)
    );
}

void uart_send_string(const char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}
