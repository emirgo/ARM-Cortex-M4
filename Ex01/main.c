#include "stm32f4xx.h"                  // Device header
#include "Board_LED.h"
#include "Board_Buttons.h"
#include "stdbool.h"

void delay(uint32_t time)
{
	uint32_t index = 0;
	for(index = 0; index < time; index++);
}

int main(void)
{
	LED_Initialize();
	Buttons_Initialize();
	
	while(1)
	{
		if (Buttons_GetState())
		{
			LED_On(0);
			delay(500000);
			LED_Off(0);
			delay(500000);
		}
	}
	
	return 0;
}