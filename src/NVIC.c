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

//NVIC_InitStructure.NVIC_IRQChannel = SysTick_IRQn;	  //选择uart2中断
//NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3; //抢占式中断优先级设置为0
//NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		  //响应式中断优先级设置为0
//NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 								  //使能中断
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
        
 
 		/*选择中断分组2*/
        NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);                          
        
        				   
		NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;     //选择uart1中断
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; //抢占式中断优先级设置为0
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;        //响应式中断优先级设置为0
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                                   //使能中断
        NVIC_Init(&NVIC_InitStructure);
 
 		NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;     //选择uart2中断
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //抢占式中断优先级设置为0
        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;        //响应式中断优先级设置为0
        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;                                   //使能中断
        NVIC_Init(&NVIC_InitStructure);
		SysTick_Configuration();
}
//if (SysTick_Config(SystemCoreClock / 1000))
//{ 
  /* Capture error */ 
//  while (1);
//}

//SysTick_Configuration: 配置SysTick  





