#ifndef _UART_H_
#define _UART_H_

#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
#include "GPIO.h"












extern void UART1_Initialization(unsigned int BaudRate);
extern void UART2_Initialization(unsigned int BaudRate);

extern void UART_SendData(USART_TypeDef * USARTx, unsigned char dat);
extern void UART1_SendData(unsigned char dat);
extern void UART2_SendData(unsigned char dat);
extern void UART3_SendData(unsigned char dat);

extern void UART_SendStr(USART_TypeDef * USARTx, unsigned char * dat, unsigned int size);
extern void UART1_SendStr(unsigned char * dat, unsigned int size);
extern void UART2_SendStr(unsigned char * dat, unsigned int size);
extern void UART3_SendStr(unsigned char * dat, unsigned int size);

extern unsigned char UART1_ReceiveData(void);
extern unsigned char UART2_ReceiveData(void);
extern unsigned char UART3_ReceiveData(void);
extern void Uart_Printf(char *fmt,...);

#endif


