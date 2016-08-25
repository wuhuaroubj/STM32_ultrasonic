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




ErrorStatus HSEStartUpStatus;









/**********************************
  * @brief  Main program.
  * @param  None
  * @retval None
***********************************/

int main(void)
{	
	u16 distance=0;
	unsigned char i=0;
	unsigned char a[] = {"Made by Joy! "};
	/*初始化系统时钟72M*/
	SystemInit();

	/*设置IO口*/
	GPIO_Initialization();

	/*设置中断优先级*/
	NVIC_initialization();
	
	

	UART1_Initialization(115200);
	UART2_Initialization(9600);
	Uart_Printf("hello world1111 \n");
	UART1_SendStr(a,sizeof(a));
	UART2_SendStr(a,sizeof(a));
	Uart_Printf("hello world2222 \n");

	
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
	  
  while (1)
  {				UltrasonicHandle();
  				Delay(2000);
                if(g_ReceiveState1==1)//如果接收到1帧数据
                {		 Uart_Printf("g_ReceiveState11111\n");
                        g_ReceiveState1=0;
                        i=0;

                        while(g_RxCounter1--)// 把接收到数据发送回串口
                        {
                                USART_SendData(USART1, g_aRxBuffer1[i++]);       //从UART1收到的 数据，从UART1打印出来。  
                                while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
                        }
                        g_RxCounter1=0;
                }
			if(g_ReceiveState2==1)//如果接收到1帧数据
                {		 Uart_Printf("g_RxCounter2=%d\n",g_RxCounter2);
                        g_ReceiveState2=0;
                        i=0;

                        while(g_RxCounter2--)// 把接收到数据发送回串口
                        {
                               //USART_SendData(USART1, g_aRxBuffer2[i++]);     //从UART2收到的 数据，再传给UART1打印出来。  
                                //while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
								Uart_Printf("data[%d]=0x%x\n",g_RxCounter2,g_aRxBuffer2[i++]);
								
                        }
						 distance=g_aRxBuffer2[0];
						distance = (distance<<8|g_aRxBuffer2[1]);
						Uart_Printf("the distance is 0x%x,%d mm\n",distance,distance);
                        g_RxCounter2=0;
                }
  }
}



