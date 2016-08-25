/*******************************************************************

                  Timer 
				  
********************************************************************
 FileName:        timer.c
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

/* Includes ------------------------------------------------------------------*/
#include "timer.h"
#include "UART.h"
#include <stm32f10x_type.h>
#include "misc.h"
#include "stm32f10x.h"
#include "ram.h"



void TimingDelay_Decrement(void)
{
  if (g_TimingDelay != 0x00)
  { 
    g_TimingDelay--;
  }
}
void Delay(__IO u32 nTime)
{ 
  g_TimingDelay = nTime;

  while(g_TimingDelay != 0);
}

#if 0
void Delay(u32 nTime) 
{
/* Enable the SysTick Counter */
SysTick_CounterCmd(SysTick_Counter_Enable);
g_TimingDelay = nTime;
while(g_TimingDelay != 0);
/* Disable the SysTick Counter */
SysTick_CounterCmd(SysTick_Counter_Disable);
/* Clear the SysTick Counter */
SysTick_CounterCmd(SysTick_Counter_Clear);
} 
#endif

void Delayms(u16 cnt)
{
	u16 i=0, j=0;
	for(j=0;j<cnt;j++)
		{
		for(i=0;i<10300;i++);	  //ÒÑ¾­µ÷ÊÔOK
		}
}




