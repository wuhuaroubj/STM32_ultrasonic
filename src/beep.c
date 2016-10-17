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

 	/*ʹ��APB2����ʱ��*/   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC  , ENABLE);
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 , ENABLE);

/*-------------------gpio portA--------------------------*/
/*����GPIO�˿�Aλ��*/  
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;  	// for test timer

/*����GPIO�˿�A����*/  
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

/*����GPIO�˿�Aģʽ*/ 
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //����

/*�˿�B���ó�ʼ��*/ 
GPIO_Init(GPIOA, &GPIO_InitStructure);

/*-------------------gpio portB--------------------------*/

	/*����GPIO�˿�Bλ��*/  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_8;

	/*����GPIO�˿�B����*/  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	/*����GPIO�˿�Bģʽ*/ 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   //����

	/*�˿�B���ó�ʼ��*/ 
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/*���ô��ڶ˿�USART_1 ��USART_2 */
	GPIO_InitStructure.GPIO_Pin =( GPIO_Pin_9 | GPIO_Pin_2);     //USART1 TX  
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;            //�����������  
  	GPIO_Init(GPIOA, &GPIO_InitStructure);                     //A�˿�   
  
  	GPIO_InitStructure.GPIO_Pin =( GPIO_Pin_10 | GPIO_Pin_3);    //USART1 RX  
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;      //���ÿ�©����  
  	GPIO_Init(GPIOA, &GPIO_InitStructure);                     //A�˿�   

}


