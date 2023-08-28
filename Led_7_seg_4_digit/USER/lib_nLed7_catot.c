#include "stm32f10x.h"                  // Device header
#include "lib_nLed7.h"



unsigned int chusoK[4]; 
unsigned int maQuetK[] = {0xfffe , 0xfffd , 0xfbff , 0xf7ff };
unsigned char soK[]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void tachChuSoK(unsigned long temp, int soled)
{
	int i;
	for(i=0 ; i< soled ; i++ )
	{
		chusoK[i] = temp%10;
		temp = temp /10;
	}
}

void quetLedK(int soled)
{
	int i, j;
				
	for(i =0 ; i< 120; i++) // toc do thay doi gt 1 led
	{
		for(j = 0; j < soled ; j++) // quet led 
		{	
			GPIOB->ODR = 0xffff;
			GPIOB->ODR = maQuetK[j];		 		// cong b lam nv quet led 
			GPIOA ->ODR = soK[chusoK[j]];		 // so duoc quet truyen cho cong a;	
			delay(1);
		}
	}	
}

int demk;
void run_catot(void)
{
	
	for(demk =0; demk <9999; demk++)
	{
		tachChuSoK(demk, 3);
		quetLedK(3);
	}
}
void solve(void)
{
	uint16_t cnt,i, j;
	for(cnt = 0; cnt < 10000; cnt++ )
	{
		GPIOB->ODR = 0xffff;
		for(j = 0; j < 12 ; j++)
		{
		i = cnt;
		GPIO_ResetBits(GPIOB , GPIO_Pin_0);
		GPIOA->ODR = soK[i % 10];
		delay(1);
		GPIO_SetBits(GPIOB , GPIO_Pin_0);
		
		i/=10;
		GPIO_ResetBits(GPIOB , GPIO_Pin_1);
		GPIOA->ODR = soK[(i) % 10];
		delay(1);
		GPIO_SetBits(GPIOB , GPIO_Pin_1);
		
		i/=10;
		GPIO_ResetBits(GPIOB , GPIO_Pin_10);
		GPIOA->ODR = soK[(i)  % 10];
		delay(1);
		GPIO_SetBits(GPIOB , GPIO_Pin_10);
		
		i/=10;
		GPIO_ResetBits(GPIOB , GPIO_Pin_11);
		GPIOA->ODR = soK[(i)  % 10];
		delay(1);
		GPIO_SetBits(GPIOB , GPIO_Pin_11);
		}
	}
}
//void test_led(void)
//{
//uint16_t cnt,i, j;
//	for(cnt = 0; cnt < 10000; cnt++ )
//	{
//		turn_on(localPinLed7seg.LED1);
//		turn_on(localPinLed7seg.LED2);
//		turn_on(localPinLed7seg.LED3);
//		turn_on(localPinLed7seg.LED4);
//		for(j = 0; j < 120 ; j++)
//		{
//			i = cnt;
//			turn_off(localPinLed7seg.LED1);
//			number( i % 10);
//			delay(1);
//			turn_on(localPinLed7seg.LED1);
//			if(localPinLed7seg.number_led > 2 || localPinLed7seg.number_led == 2 )
//			{
//				i/=10;
//				turn_off(localPinLed7seg.LED2);
//				number(i % 10);
//				delay(1);
//				turn_on(localPinLed7seg.LED2);
//			}
//			if(localPinLed7seg.number_led > 3 || localPinLed7seg.number_led == 3)
//			{
//				i/=10;
//				turn_off(localPinLed7seg.LED3);
//				number(i  % 10);
//				delay(1);
//				turn_on(localPinLed7seg.LED3);
//			}
//			if(localPinLed7seg.number_led > 4 || localPinLed7seg.number_led == 4)
//			{
//				i/=10;
//				turn_off(localPinLed7seg.LED4);
//				number(i  % 10);
//				delay(1);
//				turn_on(localPinLed7seg.LED4);
//			}
//		}
//	}
//}
