#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC

#define LED_CHUC GPIO_Pin_0 
#define LED_DONVI GPIO_Pin_1
#define ON GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)
unsigned char A[]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
int i=25 ,j, cnt =0, cnt2=0;	
unsigned char sttold=1 , sttnew=1;


void config(void);
void delay (unsigned int time);
void press_button(void);
void chay (void);
void run(void);
void solve(void);


GPIO_InitTypeDef LED;

int main()
{
	config();
	while(1)
	{
		chay();
	}
}
void config(void)
{
	GPIO_InitTypeDef LED;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
	//cau hinh  LED
	LED.GPIO_Mode = GPIO_Mode_Out_OD;
	LED.GPIO_Pin = GPIO_Pin_All;
	LED.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init (GPIOA, &LED);
	 // cau hinh chuc va don vi
	LED.GPIO_Mode = GPIO_Mode_Out_PP;
	LED.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	LED.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init (GPIOB, &LED);
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
void run(void)
{
	GPIO_ResetBits(GPIOB, LED_CHUC);
	GPIOA->ODR = 0X82;
	delay(1);
	GPIO_SetBits(GPIOB, LED_CHUC);
	
	GPIO_ResetBits(GPIOB, LED_DONVI);
	GPIOA->ODR =0X90;
	delay(1);
	GPIO_SetBits(GPIOB, LED_DONVI);
}
unsigned char maquet[]={0x2,0x1};
void chay (void)
{
	int i, j;	
	for(i=99; i>0; i--)
	{
		for(j=0; j<250;j++)
		{
			GPIO_ResetBits(GPIOB, LED_CHUC);
			GPIOA->ODR = A[i/10];
			delay(1);
			GPIO_SetBits(GPIOB, LED_CHUC);
			
			GPIO_ResetBits(GPIOB, LED_DONVI);
			GPIOA->ODR = A[i%10];
			delay(1);
			GPIO_SetBits(GPIOB, LED_DONVI);
		}
	}
}


void press_button(void)
{
	sttold = sttnew;
	sttnew = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6);	
	if(sttold ==1 && sttnew ==0)
	{
		i++;
	}
	for(j=0 ; j<250 ; j++)
	{	
		GPIO_ResetBits(GPIOB, LED_CHUC);
		delay(1);
		GPIOA->ODR = A[i/10];
		GPIO_SetBits(GPIOB, LED_CHUC);
		GPIO_ResetBits(GPIOB, LED_DONVI);
		delay(1);
		GPIOA->ODR = A[i%10];
		GPIO_SetBits(GPIOB, LED_DONVI);
	}
	delay(1);
	if(i > 99) 
	{
		i = 0;
	}
}

void solve(void)
{
	sttold = sttnew;
	sttnew = ON;
	if(sttnew == 0 && sttold == 1)
	{
		i++;	
	}
	GPIO_ResetBits(GPIOB, LED_CHUC);
	delay(1);
	GPIOA->ODR = A[i/10];
	GPIO_SetBits(GPIOB, LED_CHUC);
	GPIO_ResetBits(GPIOB, LED_DONVI);
	delay(1);
	GPIOA->ODR = A[i%10];
	GPIO_SetBits(GPIOB, LED_DONVI);		
}