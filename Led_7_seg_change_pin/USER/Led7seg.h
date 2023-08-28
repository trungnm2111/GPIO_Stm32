/*
  ******************************************************************************
  * @file		led7seg.h                                                              *
  * @author	NGUYEN MINH TRUNG                                                        *
  * @date		00/00/0000                                                         *
  ******************************************************************************
*/

#ifndef _LED7SEG_H_
#define _LED7SEG_H_

/******************************************************************************/

#include "stm32f10x.h"
#include "stm32f10x_rcc.h" 

/******************************************************************************/
#define	HIGH							1
#define LOW 							0	
#define OUTPUT  					GPIO_Mode_Out_PP
#define INPUT  						GPIO_Mode_IN_FLOATING
#define INPUT_PULLUP  		GPIO_Mode_IPU
#define INPUT_PULLUDOWN  	GPIO_Mode_IPD
#define OUTPUT_OD  				GPIO_Mode_Out_OD
#define AF_OD  						GPIO_Mode_AF_OD
#define AF_PP  						GPIO_Mode_AF_PP

#define SPEED_10MHz  			GPIO_Speed_10MHz
#define SPEED_20MHz  			GPIO_Speed_2MHz
#define SPEED_50MHz  			GPIO_Speed_50MHz

#define PA0 			(0u)
#define PA1				(1u)
#define PA2				(2u)
#define PA3				(3u)
#define PA4				(4u)
#define PA5				(5u)
#define PA6				(6u)
#define PA7				(7u)
#define PA8				(8u)
#define PA9				(9u)
#define PA10			(10u)
#define PA11			(11u)
#define PA12			(12u)
#define PA13			(13u)
#define PA14			(14u)
#define PA15			(15u)

#define PB0				(16u)
#define PB1				(17u)		
#define PB2				(18u)
#define PB3				(19u)
#define PB4				(20u)
#define PB5				(21u)
#define PB6				(22u)
#define PB7				(23u)
#define PB8				(24u)
#define PB9				(25u)
#define PB10			(26u)
#define PB11			(27u)
#define PB12			(28u)
#define PB13			(29u)
#define PB14			(30u)
#define PB15			(31u)

#define PC0 			(32u)
#define PC1 			(33u)			
#define PC2 			(34u)
#define PC3 			(35u)
#define PC4 			(36u)
#define PC5 			(37u)
#define PC6 			(38u)
#define PC7 			(39u)
#define PC8 			(40u)
#define PC9 			(41u)
#define PC10 			(42u)
#define PC11 			(43u)
#define PC12 			(44u)
#define PC13 			(45u)
#define PC14 			(46u)
#define PC15 			(47u)

#define PORTA 			1
#define PORTB 			2
#define PORTC 			3

#define catot 			11
#define anot 				10
#define minus 			14
/******************************************************************************/

typedef struct
{
	GPIO_TypeDef*				GPIOx;
	uint16_t						PINx;	
	uint32_t						RCC_APB2Periph_GPIOx;
}PIN_Config;


typedef struct 
{
	uint8_t PIN_A;
	uint8_t PIN_B; 
	uint8_t PIN_C; 
	uint8_t PIN_D; 
	uint8_t PIN_E;
	uint8_t PIN_F; 
	uint8_t PIN_G;
	
	uint8_t number_led;
	uint8_t LED1;
	uint8_t LED2;
	uint8_t LED3;
	uint8_t LED4;	
	uint8_t mode;
	
} led7seg_config_t;

void Led_7seg_Inits( led7seg_config_t led7seg_pin);
void led7seg_display(int led7seg_numbersDisplay );
void led7seg_turn_on(uint16_t i);
void led7seg_turn_off(uint16_t i);

/******************************************************************************/
#endif


