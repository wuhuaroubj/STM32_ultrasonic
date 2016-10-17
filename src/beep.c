/**
  ******************************************************************************
  * @file    gpio.c 
  * @author  jason
  * @version 1.0
  * @date    2016-10-14
  * @brief   BEEP
  ******************************************************************************
  * @attention
  *
  *
  * 
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/

#include "beep.h"

GPIO_InitTypeDef GPIO_InitStructure;

/**********************************
  * @brief  beep initialization
  * @param  None
  * @retval None
***********************************/
void Beep_Initialization(void)
{

 	/*使能APB2外设时钟*/   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC  , ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 , ENABLE);

/*-------------------gpio portA--------------------------*/
/*设置GPIO端口A位号*/  
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;  	// for test timer

/*设置GPIO端口A速率*/  
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

/*设置GPIO端口A模式*/ 
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //推挽

/*端口B配置初始化*/ 
GPIO_Init(GPIOA, &GPIO_InitStructure);

/*-------------------gpio portB--------------------------*/

	/*设置GPIO端口B位号*/  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_8;

	/*设置GPIO端口B速率*/  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/*设置GPIO端口B模式*/ 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //推挽

	/*端口B配置初始化*/ 
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/*设置串口端口USART_1 和USART_2 */
	GPIO_InitStructure.GPIO_Pin =( GPIO_Pin_9 | GPIO_Pin_2);     //USART1 TX  
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;            //复用推挽输出  
  	GPIO_Init(GPIOA, &GPIO_InitStructure);                     //A端口   
  
  	GPIO_InitStructure.GPIO_Pin =( GPIO_Pin_10 | GPIO_Pin_3);    //USART1 RX  
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;      //复用开漏输入  
  	GPIO_Init(GPIOA, &GPIO_InitStructure);                     //A端口   

}


