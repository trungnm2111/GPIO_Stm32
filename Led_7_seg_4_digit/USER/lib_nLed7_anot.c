#include "stm32f10x.h"                  // Device header
#include "lib_nLed7.h"


unsigned char chusoA[4]; 

unsigned long temp, dem; // temp : so hien thi ra led, soled: so chu so hien thi

void tachChuSoA(unsigned long temp, int soled)
{
	int i;
	for(i=0 ; i< soled ; i++ )// 
	{
		chusoA[i] = temp%10;
		temp = temp /10;
	}
}

unsigned int maQuetA[] = {0x0001, 0x0002, 0x0400, 0x0800};
unsigned char soA[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void quetLedA(int soled)
{
	int i, j;
	for(i =0 ; i< 10; i++) // toc do thay doi gt 1 led
	{
		for(j = 0; j< soled; j++) // quet led 
		{	
			GPIOA->ODR = 0X0000;
			GPIOB->ODR = maQuetA[j];
			GPIOA->ODR = soA[chusoA[j]];
			delay(1);
		}
	}	
}

int dema ;

void run_anot(void)
{
	for(dema =0; dema <9999; dema++)
	{
		tachChuSoA(dema, 4);
		quetLedA(4);
	}
}
