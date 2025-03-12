#include "stm32f4xx.h"                  // Device header

/**
  * 函    数：LED初始化
  * 参    数：无
  * 返 回 值：无
  */
void LED_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

  //GPIOC13
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//
  GPIO_Init(GPIOC, &GPIO_InitStructure);//
	GPIO_SetBits(GPIOC,GPIO_Pin_13);
}

/**
  * 函    数：LED1开启
  * 参    数：无
  * 返 回 值：无
  */
void LED1_ON(void)
{
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
}

/**
  * 函    数：LED1关闭
  * 参    数：无
  * 返 回 值：无
  */
void LED1_OFF(void)
{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);	//设置PA1引脚为高电平
}

