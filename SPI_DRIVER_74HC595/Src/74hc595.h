// Author: Emirhan Gocturk
// Date: 4 April 2020

#include "main.h"

// 7 Segment display data. Only numeric.
uint8_t SEG_num_data[10] = 
{
	0xc0,
	0xf9,
	0x5b,
	0xa4,
	0x99,
	0x92,
	0x82,
	0xf8,
	0x80,
	0x90
};


// Transmits data to shift register over SPI.
void SEG_shift_out(uint8_t *data, uint16_t size, SPI_HandleTypeDef *hspi)
{
	// Low on latch_1 to trigger first digit
	HAL_GPIO_WritePin(GPIOD, LATCH_1_Pin, GPIO_PIN_RESET);
	
	// Write data to SPI bus
	HAL_SPI_Transmit(hspi, data, size, 100);

	// Data is ready, set latch_1 to HIGH
	HAL_GPIO_WritePin(GPIOD, LATCH_1_Pin, GPIO_PIN_SET);
}

void SEG_count_example(SPI_HandleTypeDef *hspi)
{
	for(uint8_t index = 0; index < 10; index++)
	{
		SEG_shift_out(SEG_num_data + index, 1, hspi);
		HAL_Delay(1000);
	}
}