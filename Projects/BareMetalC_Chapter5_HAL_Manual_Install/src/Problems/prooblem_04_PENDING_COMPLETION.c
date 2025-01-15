#include "../Utilities/STM32F0xx-Nucleo/stm32f0xx_nucleo.h"
#include "stm32f0xx.h"

// Morse code arrays for letters
int MORSE_H[4] = {100, 100, 100, 100};  // H
int MORSE_E[1] = {100};                  // E
int MORSE_L[4] = {100, 500, 100, 100};   // L
int MORSE_O[3] = {500, 500, 1000};       // O
int MORSE_W[3] = {100, 500, 500};        // W
int MORSE_R[3] = {100, 500, 100};        // R
int MORSE_D[3] = {500, 100, 100};        // D

// Global variables to cycle through characters
int count = 0;

// Function to add delay
void delay_ms(int duration) {
    HAL_Delay(duration);
}

// Function to blink Morse code
void blink_morse(int *morse_code, int size) {
    for (int i = 0; i < size; i++) {
        HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_SET);  // LED ON
        delay_ms(morse_code[i]);
        HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);  // LED OFF
        delay_ms(100);  // Short pause between signals
    }
}

int main(void) {
    GPIO_InitTypeDef GPIO_LedInit;   // LED initialization
    GPIO_InitTypeDef GPIO_ButtonInit; // Button initialization

    HAL_Init();

    // LED clock initialization
    LED2_GPIO_CLK_ENABLE();

    // Initialize LED
    GPIO_LedInit.Pin = LED2_PIN;
    GPIO_LedInit.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_LedInit.Pull = GPIO_PULLUP;
    GPIO_LedInit.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED2_GPIO_PORT, &GPIO_LedInit);

    // Button clock initialization
    USER_BUTTON_GPIO_CLK_ENABLE();

    // Initialize button
    GPIO_ButtonInit.Pin = USER_BUTTON_PIN;
    GPIO_ButtonInit.Mode = GPIO_MODE_INPUT;
    GPIO_ButtonInit.Pull = GPIO_PULLDOWN;
    GPIO_ButtonInit.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(USER_BUTTON_GPIO_PORT, &GPIO_ButtonInit);
    GPIO_PinState previous_state = GPIO_PIN_RESET; // To track button state

for (;;) {
    // Get the current state of the button
    GPIO_PinState current_state = HAL_GPIO_ReadPin(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN);

    // Detect button press (transition from RESET to SET)
    if (current_state == GPIO_PIN_SET && previous_state == GPIO_PIN_RESET) {
        delay_ms(1000);  // LED ON
        count++;       // Increment the count on button press

        // Reset count if it exceeds the number of letters
        if (count > 10) count = 1;

        // Blink the corresponding Morse code
        switch (count) {
            case 1: blink_morse(MORSE_H, sizeof(MORSE_H) / sizeof(MORSE_H[0])); break;
            case 2: blink_morse(MORSE_E, sizeof(MORSE_E) / sizeof(MORSE_E[0])); break;
            case 3: blink_morse(MORSE_L, sizeof(MORSE_L) / sizeof(MORSE_L[0])); break;
            case 4: blink_morse(MORSE_L, sizeof(MORSE_L) / sizeof(MORSE_L[0])); break;
            case 5: blink_morse(MORSE_O, sizeof(MORSE_O) / sizeof(MORSE_O[0])); break;
            case 6: blink_morse(MORSE_W, sizeof(MORSE_W) / sizeof(MORSE_W[0])); break;
            case 7: blink_morse(MORSE_O, sizeof(MORSE_O) / sizeof(MORSE_O[0])); break;
            case 8: blink_morse(MORSE_R, sizeof(MORSE_R) / sizeof(MORSE_R[0])); break;
            case 9: blink_morse(MORSE_L, sizeof(MORSE_L) / sizeof(MORSE_L[0])); break;
            case 10: blink_morse(MORSE_D, sizeof(MORSE_D) / sizeof(MORSE_D[0])); break;
            default: HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET); break;
        }
    }

    // Update previous state
    previous_state = current_state;
}
    return 0;
}

