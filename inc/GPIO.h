#ifndef _GPIO_H_
#define _GPIO_H_


#include <stm32f10x.h>
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define LED_ON   GPIO_ResetBits(GPIOB, GPIO_Pin_8);
#define LED_OFF	 GPIO_SetBits(GPIOB, GPIO_Pin_8);

#define TIMER_HIGH   GPIO_ResetBits(GPIOA, GPIO_Pin_0);
#define TIMER_LOW	 GPIO_SetBits(GPIOA, GPIO_Pin_0);


#define beep_rcc                    RCC_APB2Periph_GPIOC  
#define beep_gpio                   GPIOC
#define beep_pin                    (GPIO_Pin_13)

#define BeepOn()	GPIO_SetBits(beep_gpio, beep_pin);
#define BeepOff() GPIO_ResetBits(beep_gpio, beep_pin);

extern void GPIO_Initialization(void);

#endif
