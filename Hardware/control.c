#include "stm32f4xx.h"   
#include "control.h"


void Control_Init(void)
{
      GPIO_InitTypeDef  GPIO_InitStructure;

			RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);//ʹ��GPIOFʱ��
      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);//ʹ��GPIOFʱ��
	
			//GPIOF9,F10��ʼ������
			GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
			GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//
			GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��
  
      GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_14|GPIO_Pin_15;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;//��ͨ���ģʽ
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;//�������
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
			GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;//
			GPIO_Init(GPIOG, &GPIO_InitStructure);//��ʼ��

}








