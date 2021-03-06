/**
  ******************************************************************************
  * @file    gpio.c 
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

#include "GPIO.h"

GPIO_InitTypeDef GPIO_InitStructure;

/**********************************
  * @brief  GPIO initialization
  * @param  None
  * @retval None
***********************************/
void GPIO_Initialization(void)
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


//初始化端口C的pin13 蜂鸣器管脚高电平响，低电平不响
GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_InitStructure.GPIO_Pin   = beep_pin;
GPIO_Init(beep_gpio, &GPIO_InitStructure);

}


