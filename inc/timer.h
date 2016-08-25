/*******************************************************************

                  Timer Headfile

********************************************************************
 FileName:        timer.h
 Dependencies:    None
 Processor:       
 Compiler:        
 Company:         
 author:		jason
********************************************************************
 File Description:

 Change History:
  Rev   Date         Description
  1.0   2016/08/24     firt

*******************************************************************/
#ifndef _TIMER_H
#define _TIMER_H
#include <stm32f10x.h>
#include "stdio.h"

extern void SysTick_Configuration(void);
extern void SysTickInit(void);
extern void SysTickHandler(void);
extern void Delay(u32 nTime);

extern void Delayms(u16 cnt);

#endif/*end of  _TIMER_H*/



