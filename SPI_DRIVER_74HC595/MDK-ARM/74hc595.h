#include "main.h"

// 7 Segment display data. Only numeric.
uint8_t seven_segment_data[10] = 
{
	0x3f,
	0x06,
	0x5b,
	0x4f,
	0x66,
	0x6d,
	0x7d,
	0x07,
	0x7f,
	0x6f
};

// Transmits data to shift register over SPI.
void shift_out(uint8_t *data, uint16_t size, SPI_HandleTypeDef *hspi);

// Transmits data to shift register over SPI.
void shift_out(uint8_t *data, uint16_t size, SPI_HandleTypeDef *hspi)
{
	// Low on latch_1 to trigger first digit
	HAL_GPIO_WritePin(GPIOD, LATCH_1_Pin, GPIO_PIN_RESET);
	
	// Write data to SPI bus
	HAL_SPI_Transmit(hspi, data, size, 100);

	// Data is ready, set latch_1 to HIGH
	HAL_GPIO_WritePin(GPIOD, LATCH_1_Pin, GPIO_PIN_SET);
	
}

void seven_segment_count_exampe(SPI_HandleTypeDef *hspi)
{
	for(uint8_t index = 0; index < 10; index++)
	{
		shift_out(seven_segment_data + index, 1, hspi);
		HAL_Delay(1000);
	}
}