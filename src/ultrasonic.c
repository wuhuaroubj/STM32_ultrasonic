/*******************************************************************

                  Ultrasonic Module Driver

********************************************************************
 FileName:        ultrasonic.c
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
#include "ultrasonic.h"
#include "UART.h"
#include "timer.h"

void UltrasonicHandle(void)
{
	//Uart_Printf("******start******\n");
	UART2_SendData(0xe8);
	Delay(1);
	UART2_SendData(0x02);
	Delay(1);
	UART2_SendData(0xb4);
	Delay(1);
	//Uart_Printf("******end******\n");
}


