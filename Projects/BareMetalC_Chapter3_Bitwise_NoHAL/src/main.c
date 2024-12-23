#include "stm32f0xx.h"  // Include CMSIS header for STM32F0

#define LED_PIN  (1 << 5) // LED connected to PA5 (Bit 5)

void delay_ms(uint32_t ms) {
    // Simple delay function using SysTick (assuming 8 MHz system clock)
    SysTick->LOAD = (ms * 8000) - 1; // Load the SysTick counter for delay
    SysTick->VAL = 0;  // Reset SysTick counter
    SysTick->CTRL = 0x05;  // Enable SysTick with system clock

    // Wait for the delay to finish
    while (!(SysTick->CTRL & (1 << 16)));  // Wait for the COUNTFLAG to be set
}

int main(void) {
    // Step 1: Enable clock for GPIOA (set bit 17 in RCC_AHBENR)
    RCC->AHBENR |= (1 << 17);  // Set bit 17 of the AHBENR register to enable GPIOA

    // Step 2: Configure PA5 as output using bitwise operations on the MODER register
    // Clear the MODER bits for PA5 (bits 10 and 11 in the MODER register)
    GPIOA->MODER &= ~(0x3 << (5 * 2));  // Clear bits 10 and 11 for PA5

    // Set PA5 to output mode (01 in MODER register)
    GPIOA->MODER |= (1 << (5 * 2));     // Set bits 10 and 11 to 01 (output mode)

    // Step 3: Toggle PA5 in an infinite loop
    while (1) {
        // Toggle PA5 (LED) using the ODR register
        GPIOA->ODR ^= LED_PIN;  // XOR PA5 in the ODR (Output Data Register) to toggle it

        delay_ms(500);  // Delay for 500 ms
    }
}


