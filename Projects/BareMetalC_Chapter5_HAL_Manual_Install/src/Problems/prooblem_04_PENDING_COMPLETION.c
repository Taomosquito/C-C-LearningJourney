#include "../Utilities/STM32F0xx-Nucleo/stm32f0xx_nucleo.h"
#include "stm32f0xx.h"
#include "stdio.h"

// Defining Morse code patterns as bit patterns
const uint16_t morse_H = 0b1111;    // ....   -> 1 represents dot, 0 represents dash
const uint16_t morse_E = 0b1;       // .      -> 1 represents dot
const uint16_t morse_L = 0b1011;    // .-..   -> 1 represents dot, 0 represents dash
const uint16_t morse_O = 0b111;     // ---    -> 1 represents dot, 0 represents dash
const uint16_t morse_W = 0b11101;   // .--   -> 1 represents dot, 0 represents dash
const uint16_t morse_R = 0b10101;   // .-.   -> 1 represents dot, 0 represents dash
const uint16_t morse_D = 0b1101;    // -..   -> 1 represents dot, 0 represents dash

#define DOT 100     
#define DASH 500    
#define PAUSE 200  

void delay_ms(int duration) {
    HAL_Delay(duration);
}

// Function to compute bit length dynamically
int get_morse_length(uint16_t pattern) {
    int length = 0;
    while (pattern) {
        length++;
        pattern >>= 1;
    }
    return length;
}

// Function to blink Morse code using bitwise extraction
void blink_morse(uint16_t morse_pattern) {
    int length = get_morse_length(morse_pattern);  // Get the actual bit length

    for (int i = length - 1; i >= 0; i--) {  // Process from most significant bit (leftmost)
        if ((morse_pattern >> i) & 1) {
            HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_SET);  
            delay_ms(DOT);
        } else {
            HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_SET);  
            delay_ms(DASH);
        }
        HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);
        delay_ms(PAUSE);  
    }
}

int main(void) {
    GPIO_InitTypeDef GPIO_LedInit;
    GPIO_InitTypeDef GPIO_ButtonInit;

    HAL_Init();
    LED2_GPIO_CLK_ENABLE();

    GPIO_LedInit.Pin = LED2_PIN;
    GPIO_LedInit.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_LedInit.Pull = GPIO_PULLUP;
    GPIO_LedInit.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED2_GPIO_PORT, &GPIO_LedInit);

    USER_BUTTON_GPIO_CLK_ENABLE();

    GPIO_ButtonInit.Pin = USER_BUTTON_PIN;
    GPIO_ButtonInit.Mode = GPIO_MODE_INPUT;
    GPIO_ButtonInit.Pull = GPIO_PULLDOWN;
    GPIO_ButtonInit.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(USER_BUTTON_GPIO_PORT, &GPIO_ButtonInit);

    uint16_t morse_letters[] = {morse_H, morse_E, morse_L, morse_L, morse_O, morse_W, morse_R, morse_D};
    int letter_index = 0;
    int total_letters = sizeof(morse_letters) / sizeof(morse_letters[0]);

    for (;;) {
        GPIO_PinState current_state = HAL_GPIO_ReadPin(USER_BUTTON_GPIO_PORT, USER_BUTTON_PIN);
        GPIO_PinState previous_state = GPIO_PIN_RESET;

        if (current_state == GPIO_PIN_SET && previous_state == GPIO_PIN_RESET) {
            delay_ms(1000);
            blink_morse(morse_letters[letter_index]);  
            letter_index = (letter_index + 1) % total_letters;  
        }
            previous_state = current_state;
        
    }
    return 0;
}
