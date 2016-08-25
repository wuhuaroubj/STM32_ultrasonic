#ifndef _GPIO_H_
#define _GPIO_H_


#include <stm32f10x.h>
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define LED_ON   GPIO_ResetBits(GPIOB, GPIO_Pin_8);
#define LED_OFF	 GPIO_SetBits(GPIOB, GPIO_Pin_8);

#define TIMER_HIGH   GPIO_ResetBits(GPIOA, GPIO_Pin_0);
#define TIMER_LOW	 GPIO_SetBits(GPIOA, GPIO_Pin_0);

extern void GPIO_Initialization(void);

#endif
