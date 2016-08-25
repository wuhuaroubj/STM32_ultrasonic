/**
  ******************************************************************************
  * @file    uart.c 
  * @author  joy
  * @version 1.0
  * @date    2016-8-22
  * @brief   GPIO
  ******************************************************************************
  * @attention
  *
  *
  * 
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include "UART.h"


USART_InitTypeDef USART_InitStructure;


void UART1_Initialization(unsigned int BaudRate)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);    //��USART1ʱ��


	
         //���ṹ������Ϊȱʡ״̬
       USART_StructInit(&USART_InitStructure);
		 
       //����������Ϊ115200
       USART_InitStructure.USART_BaudRate = BaudRate;
	   
       //һ֡���ݵĿ������Ϊ8bits
       USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	   
       //��֡��β����1��ֹͣλ
       USART_InitStructure.USART_StopBits = USART_StopBits_1;
	   
       //��żʧ��ģʽ������żУ��
       USART_InitStructure.USART_Parity = USART_Parity_No;
	   
       //����/����ʹ��
       USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	   
       //Ӳ��������ʧ��
       USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	   
       //���ô���x
       USART_Init(USART1, &USART_InitStructure);
     
       //�򿪴���x���ж���Ӧ����
       USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
       //�򿪴���x�Ľ���һ֡�����ж���Ӧ����
       USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);
       //�򿪴���x
       USART_Cmd(USART1, ENABLE);	

}

void UART2_Initialization(unsigned int BaudRate)
{
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);    //��USART2ʱ��

         //���ṹ������Ϊȱʡ״̬
       USART_StructInit(&USART_InitStructure);
		 
       //����������Ϊ115200
       USART_InitStructure.USART_BaudRate = BaudRate;
	   
       //һ֡���ݵĿ������Ϊ8bits
       USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	   
       //��֡��β����1��ֹͣλ
       USART_InitStructure.USART_StopBits = USART_StopBits_1;
	   
       //��żʧ��ģʽ������żУ��
       USART_InitStructure.USART_Parity = USART_Parity_No;
	   
       //����/����ʹ��
       USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	   
       //Ӳ��������ʧ��
       USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	   
       //���ô���x
       USART_Init(USART2, &USART_InitStructure);
     
       //�򿪴���x�Ľ��յ����ֽ��ж���Ӧ����
       USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

       //�򿪴���x�Ľ���һ֡�����ж���Ӧ����
       USART_ITConfig(USART2, USART_IT_IDLE, ENABLE);
       //�򿪴���x
       USART_Cmd(USART2, ENABLE);	

}

/**********************************
  * @brief  UART send data( 1 byte)
  * @param  UARTx and Data
  * @retval None
***********************************/
void UART_SendData(USART_TypeDef* USARTx, unsigned char dat)
{	
	///while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE)!=RESET);	//(�üĴ���Ϊ�գ���������������)
	USART_SendData(USARTx, dat);
	//while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);//(�üĴ����е�������ȫ���������)
}




/**********************************
  * @brief  UART1 send data( 1 byte)
  * @param  Data
  * @retval None
***********************************/
void UART1_SendData(unsigned char dat)
{	
	//while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)!=RESET);
	USART_SendData(USART1, dat);
	//while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
}




/**********************************
  * @brief  UART2 send data( 1 byte)
  * @param  Data
  * @retval None
***********************************/
void UART2_SendData(unsigned char dat)
{	
	//while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)!=RESET);
	USART_SendData(USART2, dat);
	//while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
}




/**********************************
  * @brief  UART3 send data( 1 byte)
  * @param  Data
  * @retval None
***********************************/
void UART3_SendData(unsigned char dat)
{	
	//while(USART_GetFlagStatus(USART3,USART_FLAG_TXE)!=RESET);
	USART_SendData(USART3, dat);
	//while(USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);//
}








/**********************************
  * @brief  UART send string data
  * @param  UARTx and String data
  * @retval None
***********************************/
void UART_SendStr(USART_TypeDef* USARTx, unsigned char *dat, unsigned int size)
{	
	int	i;
	for(i = 0 ; i < size ; i++)
	{
		UART_SendData(USARTx, *dat);
		dat ++;
	}	
}




/**********************************
  * @brief  UART1 send string data
  * @param  String data
  * @retval None
***********************************/
void UART1_SendStr(unsigned char *dat, unsigned int size)
{	
	while(*dat)
		{
		while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
		USART_SendData(USART1, *dat);
		dat++;
		}	
}




/**********************************
  * @brief  UART2 send string data
  * @param  String data
  * @retval None
***********************************/
void UART2_SendStr(unsigned char *dat, unsigned int size)
{	
	while(*dat)
		{
		while(!USART_GetFlagStatus(USART2,USART_FLAG_TXE));
		USART_SendData(USART2, *dat);
		dat++;
		}	
}




/**********************************
  * @brief  UART3 send string data
  * @param  String data
  * @retval None
***********************************/
void UART3_SendStr(unsigned char *dat, unsigned int size)
{	
	int i;
	for(i = 0 ; i < size-1 ; i++)
	{
		while(!USART_GetFlagStatus(USART3,USART_FLAG_TXE));
		USART_SendData(USART3, *dat);
		dat ++;
	}	
}



/**********************************
  * @brief  UART1 Receive data
  * @param  None
  * @retval data
***********************************/
unsigned char UART1_ReceiveData(void)
{
	unsigned char dat = USART_ReceiveData(USART1);
	return dat;
}

/**********************************
  * @brief  UART2 Receive data
  * @param  None
  * @retval data
***********************************/
unsigned char UART2_ReceiveData(void)
{
	unsigned char dat = USART_ReceiveData(USART2);
	return dat;
}

/**********************************
  * @brief  UART3 Receive data
  * @param  None
  * @retval data
***********************************/
unsigned char UART3_ReceiveData(void)
{
	unsigned char dat = USART_ReceiveData(USART3);
	return dat;
}
//#define putcUART2(c)           do{while(!U2STAbits.TRMT); WriteUART2((int)(c));}while(0)

void putsUART1(const char* buffer)
{
	char* buffertemp;
	buffertemp = (char*)buffer;
	while(*buffertemp)
		{
		//putcUART1(*buffertemp);
		while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
		USART_SendData(USART1, *buffertemp);
		buffertemp++;
		}
}
void putsUART2(const char* buffer)
{
	char* buffertemp;
	buffertemp = (char*)buffer;
	while(*buffertemp)
		{
		//putcUART1(*buffertemp);
		while(!USART_GetFlagStatus(USART2,USART_FLAG_TXE));
		USART_SendData(USART2, *buffertemp);
		buffertemp++;
		}
}
char string[256];
void Uart_Printf(char *fmt,...)
{
    va_list ap;

    va_start(ap,fmt);
    vsprintf(string,fmt,ap);//������β���ָ���ַ����ϲ���string��

   	putsUART1(string);
//	putsUART2(string);

    va_end(ap);
}
