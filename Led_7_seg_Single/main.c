#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC

void config(void);
void run(void);
void delay(unsigned int time);
unsigned char sttold=1 , sttnew=1;
unsigned short int tmp=0 ;


int main(){
	config();
	while(1){
		run();
	}
}

void config(void){
	GPIO_InitTypeDef LED;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB , ENABLE);
	// CAU HINH LED;
	LED.GPIO_Mode = GPIO_Mode_Out_PP;
	LED.GPIO_Pin =GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3 |
									GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6;
	LED.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &LED);
	
// CAU HINH BUTTON
	LED.GPIO_Mode = GPIO_Mode_IPU;
	LED.GPIO_Pin = GPIO_Pin_6;
	LED.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&LED);
}

void delay(unsigned int time){
	unsigned int i, j;
	for(i=0 ; i<time ;i++){
		for(j=0;j<0x2aff;j++);
	}
}

void run(void){
	unsigned char A[]={0x3f, 0x6, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x7, 0x7f, 0x6f  };
	int i;
	sttnew= sttold;
	sttnew= GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6);
	for(i =0; i<10; i++){
//		if( GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)==0){
			GPIOA->ODR = A[i];
		delay(1000);
//		}
//		if(tmp!=0 ){
//				GPIOA->ODR =A[i];
//				tmp=0;
//		}
//		else{
//			i=i-1;
//			GPIOA->ODR = A[i];
//		}
		}
	}
