#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "led_don.h"  

int main()
{
	led_don_config();
	while (1)
	{	
		led_don_blinkled();
	}
}	
