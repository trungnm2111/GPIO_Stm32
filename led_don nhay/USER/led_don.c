#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "led_don.h"                  // Device header

void led_don_delay(uint16_t time)
{
	uint16_t i, j;
	for(i = 0 ; i < time ; i++)
	{
		for(j = 0 ; j < 0x2aff ; j++);
	}
}
void led_don_config(void)
{
	GPIO_InitTypeDef GPIO;
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
	GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO.GPIO_Pin = GPIO_Pin_1 ;
	GPIO.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init (GPIOA, &GPIO );
}
void led_don_blinkled (void)
{
	GPIO_ResetBits(GPIOA, GPIO_Pin_1 );
	led_don_delay (1000);
	GPIO_SetBits(GPIOA , GPIO_Pin_1);
	led_don_delay (1000);
}