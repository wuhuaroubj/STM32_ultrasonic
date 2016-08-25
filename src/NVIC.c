 /**
  ******************************************************************************
  * @file    NVIC.c 
  * @author  joy
  * @version 1.0
  * @date    2016-8-22
  * @brief   
  ******************************************************************************
  * @attention
  *
  *
  * 
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/

#include "NVIC.h"


NVIC_InitTypeDef NVIC_InitStructure;

void SysTick_Configuration(void) 
{

/* Select AHB clock(HCLK) as SysTick clock source */     
SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);         
/* Set SysTick Priority to 3 */      
 //NVIC_SystemHandlerPriorityConfig(SystemHandler_SysTick, 3, 0);
//SysTick_LOAD_RELOAD=72000;

//NVIC_InitStructure.NVIC_IRQChannel = SysTick_IRQn;	  //ѡ��uart2�ж�
//NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; //��ռʽ�ж����ȼ�����Ϊ0
//NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		  //��Ӧʽ�ж����ȼ�����Ϊ0
//NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 								  //ʹ���ж�
//NVIC_Init(&NVIC_InitStructure);

if (SysTick_Config(SystemCoreClock / 1000))
{ 
  /* Capture error */ 
  while (1);
}

/* SysTick interrupt each 1ms with HCLK equal to 72MHz */ 
        
/* Enable the SysTick Interrupt */     
//SysTick_ITConfig(ENABLE);
}
/**********************************
  * @brief  NVIC initialization
  * @param  None
  * @retval None
***********************************/
void NVIC_initialization(void)
{
        
 
 		/*ѡ���жϷ���2*/
        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);                          
        
        				   
		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;     //ѡ��uart1�ж�
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //��ռʽ�ж����ȼ�����Ϊ0
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;        //��Ӧʽ�ж����ȼ�����Ϊ0
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                                   //ʹ���ж�
        NVIC_Init(&NVIC_InitStructure);
 
 		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;     //ѡ��uart2�ж�
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //��ռʽ�ж����ȼ�����Ϊ0
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;        //��Ӧʽ�ж����ȼ�����Ϊ0
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                                   //ʹ���ж�
        NVIC_Init(&NVIC_InitStructure);
		SysTick_Configuration();
}
//if (SysTick_Config(SystemCoreClock / 1000))
//{ 
  /* Capture error */ 
//  while (1);
//}

//SysTick_Configuration: ����SysTick  





