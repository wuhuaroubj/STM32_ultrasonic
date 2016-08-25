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

/* Includes ------------------------------------------------------------------*/
#include "ram.h"


unsigned char 	g_aRxBuffer1[100];
unsigned char 	g_RxCounter1;
unsigned char 	g_ReceiveState1;

unsigned char 	g_aRxBuffer2[100];
unsigned char 	g_RxCounter2;
unsigned char 	g_ReceiveState2;

u32 	g_TimingDelay = 0;
u8 g_TestSig = 0;



