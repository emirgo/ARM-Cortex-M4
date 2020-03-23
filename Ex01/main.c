#include "stm32f4xx.h"                  // Device header
#include "Board_LED.h"

void delay(uint32_t time)
{
	uint32_t index = 0;
	for(index = 0; index < time; index++);
}

int main(void)
{
	LED_Initialize();
	while(1)
	{
		LED_On(0);
		delay(500000);
		LED_Off(0);
		delay(500000);
	}
}