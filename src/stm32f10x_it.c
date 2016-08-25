/**
  ******************************************************************************
  * @file    USART/Interrupt/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
//#include "platform_config.h"

/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */

/** @addtogroup USART_Interrupt
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  * @autor:	jason
   * @date:2016-8-24
  */


extern u32 	g_TimingDelay;
extern u8 g_TestSig;



void SysTick_Handler(void)
{
//	TimingDelay_Decrement();	
		if (g_TimingDelay != 0x00)
		{ 
		  g_TimingDelay--;
		}		
	if(g_TimingDelay % 2) 	
		{
			g_TestSig = 1;
		}	  
	else	 
		{
			g_TestSig = 0;
		}
}

extern unsigned char 	g_aRxBuffer1[100];
extern unsigned char 	g_RxCounter1;
extern unsigned char 	g_ReceiveState1;

extern unsigned char 	g_aRxBuffer2[100];
extern unsigned char 	g_RxCounter2;
extern unsigned char 	g_ReceiveState2;
/******************************************************************************/
/*            STM32F10x Peripherals Interrupt Handlers                        */
/******************************************************************************/

/**
  * @brief  This function handles USARTy global interrupt request.
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)  
{
	unsigned char Clear = Clear;// 这种定义方法，用来消除编译器“没有用到”的警告

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
	 //UART2_SendData(UART1_ReceiveData());
    /* Read one byte from the receive data register */
    g_aRxBuffer1[g_RxCounter1++] = USART1->DR;	//把接收到的字节保存，数组地址加1
	}
	else if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)
	{
	Clear = USART1->SR;	//读SR寄存器
	Clear = USART1->DR;	//读DR寄存器(先读SR再读DR,就是为了清除IDLE中断标志位)
	g_ReceiveState1= 1;	// 标记收到了一帧数据
	}

  while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);  
  USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}


void USART2_IRQHandler(void)  
{
	unsigned char Clear = Clear;// 这种定义方法，用来消除编译器“没有用到”的警告

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
	 //UART2_SendData(UART2_ReceiveData());
    /* Read one byte from the receive data register */
    g_aRxBuffer2[g_RxCounter2++] = USART2->DR;	//把接收到的字节保存，数组地址加1
	}
	else if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET)
	{
	Clear = USART2->SR;	//读SR寄存器
	Clear = USART2->DR;	//读DR寄存器(先读SR再读DR,就是为了清除IDLE中断标志位)
	g_ReceiveState2 = 1;	// 标记收到了一帧数据
	}

  while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);  
  USART_ClearITPendingBit(USART2, USART_IT_RXNE);
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
