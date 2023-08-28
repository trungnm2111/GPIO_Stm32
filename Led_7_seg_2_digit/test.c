#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC

void config(void)
{
	GPIO_InitTypeDef LED;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
	//cau hinh  LED
	LED.GPIO_Mode = GPIO_Mode_Out_OD;
	LED.GPIO_Pin = GPIO_Pin_All;
	LED.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init (GPIOA , &LED);
	 // cau hinh chuc va don vi
//	LED.GPIO_Mode = GPIO_Mode_Out_PP;
//	LED.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
//	LED.GPIO_Speed= GPIO_Speed_50MHz;
//	GPIO_Init (GPIOB, &LED);
	// cau hinh button
	LED.GPIO_Mode = GPIO_Mode_IPU;
	LED.GPIO_Pin = GPIO_Pin_6;
	LED.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init (GPIOB, &LED);
}


void delay (unsigned int time) 
{
	unsigned int i,j;
	for(i=0; i<time;i++)
	{
		for(j = 0;j<0x2aff;j++);
	}
}