/*
  ******************************************************************************
  * @file		systick.h                                                              *
  * @author	NGUYEN MINH TRUNG                                                        *
  * @date		00/00/0000                                                         *
  ******************************************************************************
*/
#ifndef _LED_DON_H_
#define _LED_DON_H_

/******************************************************************************/
#include "stm32f10x.h"
#include "stm32f10x_rcc.h" 

/******************************************************************************/

/******************************************************************************/
void led_don_delay(uint16_t time);
void led_don_config(void);
void led_don_blinkled (void);
/******************************************************************************/
#endif
