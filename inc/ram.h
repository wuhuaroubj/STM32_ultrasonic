/*******************************************************************

                  Global Variable Definitions

********************************************************************
 FileName:        ram.h
 Dependencies:    None
 Processor:       
 Compiler:        
 Company:         
 author:		jason
********************************************************************
 File Description:

 Change History:
  Rev   Date         Description
  1.1   2016/08/24     Add base signed types

*******************************************************************/
#ifndef _RAM_H
#define _RAM_H
//#include "GenericTypeDefs.h"
#include <stm32f10x.h>
#include "stdio.h"
#include "stm32f10x_type.h"


//结构体定义
typedef enum
{
  BTN_Num1=1,
  BTN_Num2,
  BTN_Num3,
  BTN_Num4,
  BTN_Num5,  
  BTN_Num6,
  BTN_Num7,
  BTN_Num8,
  BTN_Num9,
  BTN_Num10,
  BTN_Num11,
  BTN_Num12,
  BTN_Repeat,
  BTN_Nothing,
  BTN_Max
} ButtonType;

typedef enum
{
  PowerOnState=1,	//	1开机
  StandbyState,		//	2待机
  MaxState
} StateType;








extern unsigned char 	g_aRxBuffer1[100];
extern unsigned char 	g_RxCounter1;
extern unsigned char 	g_ReceiveState1;

extern unsigned char 	g_aRxBuffer2[100];
extern unsigned char 	g_RxCounter2;
extern unsigned char 	g_ReceiveState2;

extern u32 	g_TimingDelay;
extern u8 g_TestSig;


#endif

