#ifndef _MAIN_H_
#define _MAIN_H_

#include <stm32f10x.h>
#include "stdio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"	
#include "stm32f10x_flash.h"
#include "GPIO.h"
#include "UART.h"
#include "NVIC.h"

#define DebugMsg	1    //如果不需要打印信息，或者需要提升主循环的性能和减少时间，设置为0去掉打印debug信息！


/* RT-Thread version information */
#define UTR_VERSION                      1L              /**< major version number */
#define UTR_SUBVERSION                   0L              /**< minor version number */
#define UTR_REVISION                     1L              /**< revise version number */


/* RT-Thread version */
#define UTRHREAD_VERSION                ((UTR_VERSION * 10000) + \
                                         (UTR_SUBVERSION * 100) + UTR_REVISION)
																				 
#define DETECT_DISTANCE   150    //单位为毫米(mm)
																				 
#endif

