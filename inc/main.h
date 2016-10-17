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

#define DebugMsg	1    //�������Ҫ��ӡ��Ϣ��������Ҫ������ѭ�������ܺͼ���ʱ�䣬����Ϊ0ȥ����ӡdebug��Ϣ��


/* RT-Thread version information */
#define UTR_VERSION                      1L              /**< major version number */
#define UTR_SUBVERSION                   0L              /**< minor version number */
#define UTR_REVISION                     1L              /**< revise version number */


/* RT-Thread version */
#define UTRHREAD_VERSION                ((UTR_VERSION * 10000) + \
                                         (UTR_SUBVERSION * 100) + UTR_REVISION)
																				 
#define DETECT_DISTANCE   150    //��λΪ����(mm)
																				 
#endif

