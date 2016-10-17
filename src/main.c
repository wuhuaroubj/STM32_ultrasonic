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
/*��ʼ��ϵͳʱ��72M*/
SystemInit();

/*����IO��*/
GPIO_Initialization();

/*�����ж����ȼ�*/
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
	Delay(100);	//����ط�����ȡ������������������ø��ӣ�������ѭ��ʱ��䳤��������Ϊ�˴�ӡ��ʾ�ÿ��������ӳٵġ�
#if 0
	if(g_ReceiveState2==1)//������յ�1֡����
		{
			Uart_Printf("g_ReceiveState2222\n");
			g_ReceiveState2=0;
			i=0;

			while(g_RxCounter2--)// �ѽ��յ����ݷ��ͻش���
			{
				USART_SendData(USART2, g_aRxBuffer1[i++]);       //��UART1�յ��� ���ݣ���UART1��ӡ������  
				while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
			}
				g_RxCounter2=0;
		}
#endif
	if(g_ReceiveState1==1)//������յ�1֡����
		{		/// Uart_Printf("g_RxCounter1=%d\n",g_RxCounter1);
		g_ReceiveState1=0;
		// i=0;
		// while(g_RxCounter1--)// �ѽ��յ����ݷ��ͻش���
		//  /{
		//USART_SendData(USART1, g_aRxBuffer2[i++]);     //��UART2�յ��� ���ݣ��ٴ���UART1��ӡ������  
		//while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
		//Uart_Printf("data[%d]=0x%x\r\n",g_RxCounter1,g_aRxBuffer1[i++]);

		// }
		distance=g_aRxBuffer1[0];
		distance = (distance<<8|g_aRxBuffer1[1]);
		g_RxCounter1=0;
		}

	if(distance<DETECT_DISTANCE)
		{	
			if(++Cnt>5)		//������⵽���������ֵ�򱨾�
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
		Cnt=0;		//һ����һ�μ�⵽������ֵ����ֹͣ����������cnt����
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
	Uart_Printf(" 2014 - 2016 Copyright by �Ĵ����ǿ����޹�˾\r\n");
	Uart_Printf("	www.hibaoxing.com\r\n");
	Uart_Printf("\r\n___________________________________________________\r\n");
	BeepOn();
	Delay(1000);
	BeepOn();
}

// __MAIN.C__ END


