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
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);    //打开USART1时钟


	
         //将结构体设置为缺省状态
       USART_StructInit(&USART_InitStructure);
		 
       //波特率设置为115200
       USART_InitStructure.USART_BaudRate = BaudRate;
	   
       //一帧数据的宽度设置为8bits
       USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	   
       //在帧结尾传输1个停止位
       USART_InitStructure.USART_StopBits = USART_StopBits_1;
	   
       //奇偶失能模式，无奇偶校验
       USART_InitStructure.USART_Parity = USART_Parity_No;
	   
       //发送/接收使能
       USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	   
       //硬件流控制失能
       USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	   
       //设置串口x
       USART_Init(USART1, &USART_InitStructure);
     
       //打开串口x的中断响应函数
       USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
       //打开串口x的接收一帧数据中断响应函数
       USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);
       //打开串口x
       USART_Cmd(USART1, ENABLE);	

}

void UART2_Initialization(unsigned int BaudRate)
{
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);    //打开USART2时钟

         //将结构体设置为缺省状态
       USART_StructInit(&USART_InitStructure);
		 
       //波特率设置为115200
       USART_InitStructure.USART_BaudRate = BaudRate;
	   
       //一帧数据的宽度设置为8bits
       USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	   
       //在帧结尾传输1个停止位
       USART_InitStructure.USART_StopBits = USART_StopBits_1;
	   
       //奇偶失能模式，无奇偶校验
       USART_InitStructure.USART_Parity = USART_Parity_No;
	   
       //发送/接收使能
       USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	   
       //硬件流控制失能
       USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	   
       //设置串口x
       USART_Init(USART2, &USART_InitStructure);
     
       //打开串口x的接收单个字节中断响应函数
       USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);

       //打开串口x的接收一帧数据中断响应函数
       USART_ITConfig(USART2, USART_IT_IDLE, ENABLE);
       //打开串口x
       USART_Cmd(USART2, ENABLE);	

}

/**********************************
  * @brief  UART send data( 1 byte)
  * @param  UARTx and Data
  * @retval None
***********************************/
void UART_SendData(USART_TypeDef* USARTx, unsigned char dat)
{	
	///while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE)!=RESET);	//(该寄存器为空，可以往里存放数据)
	USART_SendData(USARTx, dat);
	//while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);//(该寄存器中的数据已全部发送完成)
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
    vsprintf(string,fmt,ap);//将多个形参所指的字符串合并到string中

   	putsUART1(string);
//	putsUART2(string);

    va_end(ap);
}
