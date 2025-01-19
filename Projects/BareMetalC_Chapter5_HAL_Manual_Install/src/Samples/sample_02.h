#include "stm32f0xx_hal.h"
#include "stdio.h"
#include "../Utilities/STM32F0xx-Nucleo/stm32f0xx_nucleo.h"

// Global variable for count
int count = 0;

// Button initialization
void Button_Init(void)
{
    // Button clock enable
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_ButtonInit;
    GPIO_ButtonInit.Pin = GPIO_PIN_0;  // Assuming button is on PA0
    GPIO_ButtonInit.Mode = GPIO_MODE_INPUT;
    GPIO_ButtonInit.Pull = GPIO_PULLUP;
    GPIO_ButtonInit.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_ButtonInit);
}

// Delay function
void delay_ms(int duration)
{
    HAL_Delay(duration);
}

int main(void)
{
    HAL_Init();
    Button_Init();  // Initialize the button

    GPIO_PinState previous_state = GPIO_PIN_RESET; // To track button state

    while (1)
    {
        // Read button state
        GPIO_PinState current_state = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

        // Detect button press (transition from RESET to SET)
        if (current_state == GPIO_PIN_SET && previous_state == GPIO_PIN_RESET)
        {
            delay_ms(100);  // Debouncing
            count++;        // Increment count on button press

            // Simple LED feedback (or any other indicator)
            if (count % 2 == 0) {
                HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_SET);  // LED ON
            } else {
                HAL_GPIO_WritePin(LED2_GPIO_PORT, LED2_PIN, GPIO_PIN_RESET);  // LED OFF
            }

        }

        previous_state = current_state;
    }
}
