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
	/*��ʼ��ϵͳʱ��72M*/
	SystemInit();

	/*����IO��*/
	GPIO_Initialization();

	/*�����ж����ȼ�*/
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
                if(g_ReceiveState1==1)//������յ�1֡����
                {		 Uart_Printf("g_ReceiveState11111\n");
                        g_ReceiveState1=0;
                        i=0;

                        while(g_RxCounter1--)// �ѽ��յ����ݷ��ͻش���
                        {
                                USART_SendData(USART1, g_aRxBuffer1[i++]);       //��UART1�յ��� ���ݣ���UART1��ӡ������  
                                while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
                        }
                        g_RxCounter1=0;
                }
			if(g_ReceiveState2==1)//������յ�1֡����
                {		 Uart_Printf("g_RxCounter2=%d\n",g_RxCounter2);
                        g_ReceiveState2=0;
                        i=0;

                        while(g_RxCounter2--)// �ѽ��յ����ݷ��ͻش���
                        {
                               //USART_SendData(USART1, g_aRxBuffer2[i++]);     //��UART2�յ��� ���ݣ��ٴ���UART1��ӡ������  
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



