#include "Led7seg.h"
#include "stm32f10x.h"  
#include "stm32f10x_rcc.h"


led7seg_config_t led7seg_local_pin;
void Pin_Config( uint16_t PINx);
void led7seg_turn_off(uint16_t i);
void led7seg_turn_on(uint16_t i) ;
void delay_ms (unsigned int time);


PIN_Config 	Pin_value[]=
{
	{GPIOA , GPIO_Pin_0,			RCC_APB2Periph_GPIOA},		
	{GPIOA , GPIO_Pin_1,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_2,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_3,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_4,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_5,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_6,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_7,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_8,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_9,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_10,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_11,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_12,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_13,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_14,			RCC_APB2Periph_GPIOA},
	{GPIOA , GPIO_Pin_15,			RCC_APB2Periph_GPIOA},
	
	{GPIOB , GPIO_Pin_0,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_1,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_2,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_3,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_4,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_5,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_6,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_7,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_8,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_9,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_10,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_11,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_12,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_13,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_14,			RCC_APB2Periph_GPIOB},
	{GPIOB , GPIO_Pin_15,			RCC_APB2Periph_GPIOB},

	{GPIOC , GPIO_Pin_0,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_1,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_2,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_3,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_4,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_5,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_6,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_7,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_8,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_9,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_10,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_11,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_12,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_13,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_14,			RCC_APB2Periph_GPIOC},
	{GPIOC , GPIO_Pin_15,			RCC_APB2Periph_GPIOC},	
};

void Led_7seg_Inits(led7seg_config_t led7seg_pin)
{
	led7seg_local_pin = led7seg_pin;
	Pin_Config(led7seg_local_pin.PIN_A);
	Pin_Config(led7seg_local_pin.PIN_B);
	Pin_Config(led7seg_local_pin.PIN_C);
	Pin_Config(led7seg_local_pin.PIN_D);
	Pin_Config(led7seg_local_pin.PIN_E);
	Pin_Config(led7seg_local_pin.PIN_F);
	Pin_Config(led7seg_local_pin.PIN_G);
//	Pin_Config(led7seg_local_pin.number_led);
	Pin_Config(led7seg_local_pin.LED1);
	Pin_Config(led7seg_local_pin.LED2);
	Pin_Config(led7seg_local_pin.LED3);
	Pin_Config(led7seg_local_pin.LED4);
//	Pin_Config(led7seg_local_pin.mode);
}

void Pin_Config( uint16_t PINx)
{
	GPIO_InitTypeDef GPIO;
	RCC_APB2PeriphClockCmd(Pin_value[PINx].RCC_APB2Periph_GPIOx, ENABLE );
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
	GPIO.GPIO_Pin = Pin_value[PINx].PINx;
	GPIO.GPIO_Mode = OUTPUT;
	GPIO.GPIO_Speed = SPEED_50MHz;
	GPIO_Init(Pin_value[PINx].GPIOx, &GPIO );
}

void led7seg_numbers(uint16_t i)
{
	if(led7seg_local_pin.mode == catot)
	{
		if(i == 0)
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
		else if (i == 1 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
		else if (i == 2 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
		else if (i == 3 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
		else if (i == 4 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
		else if (i == 5 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
		else if (i == 6 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
		else if (i == 7 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
		else if (i == 8 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
			else if (i == 9 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
				else if (i == minus )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
	}
	else if(led7seg_local_pin.mode == anot)
	{
		if(i == 0)
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
		else if (i == 1 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
		else if (i == 2 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
		else if (i == 3 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
		else if (i == 4 )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
		else if (i == 5 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
		else if (i == 6 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
		else if (i == 7 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_on(led7seg_local_pin.PIN_G);
		}
		else if (i == 8 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_off(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
			else if (i == 9 )
		{
			led7seg_turn_off(led7seg_local_pin.PIN_A);
			led7seg_turn_off(led7seg_local_pin.PIN_B);
			led7seg_turn_off(led7seg_local_pin.PIN_C);
			led7seg_turn_off(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_off(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
			else if (i == minus )
		{
			led7seg_turn_on(led7seg_local_pin.PIN_A);
			led7seg_turn_on(led7seg_local_pin.PIN_B);
			led7seg_turn_on(led7seg_local_pin.PIN_C);
			led7seg_turn_on(led7seg_local_pin.PIN_D);
			led7seg_turn_on(led7seg_local_pin.PIN_E);
			led7seg_turn_on(led7seg_local_pin.PIN_F);
			led7seg_turn_off(led7seg_local_pin.PIN_G);
		}
	}
}



void led7seg_display(int led7seg_numbersDisplay )
{
	int i;
	i = led7seg_numbersDisplay;
	led7seg_turn_on(led7seg_local_pin.LED1);
	led7seg_turn_on(led7seg_local_pin.LED2);
	led7seg_turn_on(led7seg_local_pin.LED3);
	led7seg_turn_on(led7seg_local_pin.LED4);
	if(i == 0 || i > 0)
	{
		led7seg_turn_off(led7seg_local_pin.LED1);
		led7seg_numbers( i % 10);
		delay_ms(1);
		led7seg_turn_on(led7seg_local_pin.LED1);

		i/=10;
		led7seg_turn_off(led7seg_local_pin.LED2);
		led7seg_numbers( i % 10);
		delay_ms(1);
		led7seg_turn_on(led7seg_local_pin.LED2);
		i/=10;

		led7seg_turn_off(led7seg_local_pin.LED3);
		led7seg_numbers( i % 10);
		delay_ms(1);
		led7seg_turn_on(led7seg_local_pin.LED3);
		i/=10;

		led7seg_turn_off(led7seg_local_pin.LED4);
		led7seg_numbers( i % 10);
		delay_ms(1);
		led7seg_turn_on(led7seg_local_pin.LED4);
		i/=10;
	}
	else if( i < 0)
	{
		i = -i;
		led7seg_turn_off(led7seg_local_pin.LED1);
		led7seg_numbers( i % 10);
		delay_ms(1);
		led7seg_turn_on(led7seg_local_pin.LED1);

		i/=10;
		led7seg_turn_off(led7seg_local_pin.LED2);
		led7seg_numbers( i % 10);
		delay_ms(1);
		led7seg_turn_on(led7seg_local_pin.LED2);
		i/=10;

		led7seg_turn_off(led7seg_local_pin.LED3);
		led7seg_numbers(  i % 10);
		delay_ms(1);
		led7seg_turn_on(led7seg_local_pin.LED3);
		i/=10;

		led7seg_turn_off(led7seg_local_pin.LED4);
		led7seg_numbers(minus);
		delay_ms(1);
		led7seg_turn_on(led7seg_local_pin.LED4);
	}
}

void led7seg_turn_off(uint16_t i) 
{
	GPIO_ResetBits(Pin_value[i].GPIOx, Pin_value[i].PINx);
}

void led7seg_turn_on(uint16_t i) 
{
	GPIO_SetBits(Pin_value[i].GPIOx, Pin_value[i].PINx);
}

void delay_ms (unsigned int time) 
{
	unsigned int i,j;
	for(i=0; i<time;i++)
	{
		for(j = 0;j<0x2aff;j++);
	}
}
