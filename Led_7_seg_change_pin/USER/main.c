#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "Led7seg.h"


int main()
{
	led7seg_config_t led7seg_pin;
	
	led7seg_pin.PIN_A = PA0;
	led7seg_pin.PIN_B = PA1;
	led7seg_pin.PIN_C = PA2;
	led7seg_pin.PIN_D = PA3;
	led7seg_pin.PIN_E = PA4;
	led7seg_pin.PIN_F = PA5;
	led7seg_pin.PIN_G = PA6;
	led7seg_pin.number_led = 4;
	led7seg_pin.LED1 = PB0;
	led7seg_pin.LED2 = PB1;
	led7seg_pin.LED3 = PB10;
	led7seg_pin.LED4 = PB11;
	led7seg_pin.mode = catot;

	Led_7seg_Inits( led7seg_pin);

 	while(1)
	{
		led7seg_display(1234);
	}
}
