/**
  ******************************************************************************
  * @file    main.c 
  * @author  joy
  * @version 1.0
  * @date    2016-8-22
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  *
  * 
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "ram.h"
#include "ultrasonic.h"
#include "timer.h"
#include "GPIO.h"

void ultra_show_version(void);


ErrorStatus HSEStartUpStatus;









/**********************************
  * @brief  Main program.
  * @param  None
  * @retval None
***********************************/

int main(void)
{	
u16 distance=0;
unsigned char Cnt=0;
//	unsigned char i=0;
/*初始化系统时钟72M*/
SystemInit();

/*设置IO口*/
GPIO_Initialization();

/*设置中断优先级*/
NVIC_initialization();


UART1_Initialization(9600);
UART2_Initialization(115200);
	
ultra_show_version();

LED_ON;

#if 0
TIMER_HIGH;
//Delay(1000);
while(1)
{
TIMER_LOW;
Delay(1);
TIMER_HIGH;
Delayms(1);
}
#endif

Cnt = 0;

while (1)
{
	UltrasonicHandle();
	Delay(100);	//这个地方可以取消掉，如果后续程序变得复杂，或者主循环时间变长。现在是为了打印显示好看，故意延迟的。
#if 0
	if(g_ReceiveState2==1)//如果接收到1帧数据
		{
			Uart_Printf("g_ReceiveState2222\n");
			g_ReceiveState2=0;
			i=0;

			while(g_RxCounter2--)// 把接收到数据发送回串口
			{
				USART_SendData(USART2, g_aRxBuffer1[i++]);       //从UART1收到的 数据，从UART1打印出来。  
				while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
			}
				g_RxCounter2=0;
		}
#endif
	if(g_ReceiveState1==1)//如果接收到1帧数据
		{		/// Uart_Printf("g_RxCounter1=%d\n",g_RxCounter1);
		g_ReceiveState1=0;
		// i=0;
		// while(g_RxCounter1--)// 把接收到数据发送回串口
		//  /{
		//USART_SendData(USART1, g_aRxBuffer2[i++]);     //从UART2收到的 数据，再传给UART1打印出来。  
		//while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
		//Uart_Printf("data[%d]=0x%x\r\n",g_RxCounter1,g_aRxBuffer1[i++]);

		// }
		distance=g_aRxBuffer1[0];
		distance = (distance<<8|g_aRxBuffer1[1]);
		g_RxCounter1=0;
		}

	if(distance<DETECT_DISTANCE)
		{	
			if(++Cnt>5)		//连续检测到五次少于阈值则报警
			{
			#if(1==DebugMsg)
			Uart_Printf("beep on\r\n");
			#endif		
			BeepOn();
			Cnt=0;
			}
		}
	else
		{
		Cnt=0;		//一旦有一次检测到超过阈值，就停止报警，并将cnt清零
		BeepOff();
		}
		
	#if(1==DebugMsg)
		Uart_Printf("the distance is 0x%x,%d mm\r\n",distance,distance);
	#endif
		
	}
}


/**
 * This function will show the version of this code
 */
void ultra_show_version(void)
{
	Uart_Printf("\r\n___________________________________________________\r\n");
	Uart_Printf("\r\n \\ | /\r\n");
	Uart_Printf("- BXKJ - sichuang baoxing technology\r\n");
	Uart_Printf(" / | \\     %d.%d.%d build %s\r\n",
								UTR_VERSION, UTR_SUBVERSION, UTR_REVISION, __DATE__);
	Uart_Printf(" 2014 - 2016 Copyright by 四川宝星科有限公司\r\n");
	Uart_Printf("	www.hibaoxing.com\r\n");
	Uart_Printf("\r\n___________________________________________________\r\n");
	BeepOn();
	Delay(1000);
	BeepOn();
}

// __MAIN.C__ END


