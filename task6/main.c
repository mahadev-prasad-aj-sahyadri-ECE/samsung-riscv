#include "ch32v00x.h"

#define A_Pin GPIO_Pin_0  
#define B_Pin GPIO_Pin_1  
#define Reset_Pin GPIO_Pin_4 
#define D_Pin GPIO_Pin_2  
#define Bo_Pin GPIO_Pin_3


void GPIO_Config(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = A_Pin | B_Pin | Reset_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = D_Pin | Bo_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

uint8_t DebounceReset() {
    static uint8_t lastState = 0;
    uint8_t currentState = GPIO_ReadInputDataBit(GPIOD, Reset_Pin);
    
    if (currentState == lastState) {
        return currentState;
    }
    
    for (volatile int i = 0; i < 10000; i++); // Simple delay for debounce
    lastState = GPIO_ReadInputDataBit(GPIOD, Reset_Pin);
    
    return lastState;
}

void Clear_LEDs() {
    GPIO_WriteBit(GPIOC, D_Pin, Bit_RESET);
    GPIO_WriteBit(GPIOC, Bo_Pin, Bit_RESET);
}

int main(void) {
    SystemInit(); 
    GPIO_Config();
    while (1) {
        if (DebounceReset()) {
            Clear_LEDs();
            continue; 
        }

        uint8_t A = GPIO_ReadInputDataBit(GPIOD, A_Pin);
        uint8_t B = GPIO_ReadInputDataBit(GPIOD, B_Pin);

        uint8_t Difference = A ^ B;   
        uint8_t Borrow = (!A) & B;   
        GPIO_WriteBit(GPIOC, D_Pin, Difference ? Bit_SET : Bit_RESET);
        GPIO_WriteBit(GPIOC, Bo_Pin, Borrow ? Bit_SET : Bit_RESET);
    }
}
