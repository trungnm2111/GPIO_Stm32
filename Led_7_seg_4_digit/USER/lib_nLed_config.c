#include "stm32f10x.h"                  // Device header
#include "lib_nLed7.h"

void config(void)
{
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
	GPIO_InitTypeDef GPIO;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_GPIOB, ENABLE );
	//cau hinh led
	GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3
									 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6  ;
	GPIO.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO);
	
	// cau hinh soled
	GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_10 | GPIO_Pin_11 ;
	GPIO.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO);
	
}

void delay(unsigned int time)
{
	unsigned int i, j;
	for(i=0 ; i < time ; i++)
	{
		for(j=0 ; j<0x2aff ; j++);
	}
}
