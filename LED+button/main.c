#include "stm32f10x.h"                  // Device header
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC

#define ON GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6) 
#define OFF (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7))  
GPIO_InitTypeDef GPIO;
	unsigned char sttold =1, sttnew =1;
	unsigned short int dem=0;

void config(void);
void delay(unsigned int time);
void run_button(void);
void solve1(void);


int main(){
	config();
	while(1){	
				run_button();	
			}		
	}

void config(void){
	// cap xung clock.
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOB , ENABLE);
	//cai dat button
		GPIO.GPIO_Mode = GPIO_Mode_IPU;
		GPIO.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 ;
		GPIO.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO );
	
	// cai dat LED
	GPIO.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO.GPIO_Pin = GPIO_Pin_13 ;
	GPIO.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init (GPIOC,&GPIO);

}



void delay(unsigned int time){
	unsigned int i, j;
	for(i=0 ;i< time ;i++){
		for(j=0 ; j<0x2aff ;j++);
	}
}


void run_button(void){
	if(ON ==0 )
		GPIO_ResetBits (GPIOC, GPIO_Pin_13  );
	if(OFF ==0)
		GPIO_SetBits (GPIOC, GPIO_Pin_13  );
}	

void solve1(void){
				sttold =sttnew;
				sttnew = ON;
				if(sttnew==0 && sttold ==1) {dem++;}
				if(dem%2==0) {GPIOA->ODR = 0xff;}
				else {GPIOA->ODR = 0x00;}
				delay(1);
}