#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "lib.h"

GPIO_InitTypeDef LED;

int main()
{
	config();
	while(1)
	{
		solve();
	}
}
