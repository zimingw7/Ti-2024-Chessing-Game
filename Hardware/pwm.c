#include "pwm.h"
#include "led.h"

 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//��ʱ��PWM ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2014/5/4
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 


//TIM14 PWM���ֳ�ʼ�� 
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM1_PWM_Init(u32 arr,u32 psc)//�����
{		 					 
	//�˲������ֶ��޸�IO������
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  	  //TIM14ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//ʹ��PORTEʱ��	
	
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource9,GPIO_AF_TIM1);  //GPIOE9����Ϊ��ʱ��14
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource11,GPIO_AF_TIM1); //GPIOE11����Ϊ��ʱ��14
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource13,GPIO_AF_TIM1); //GPIOE13����Ϊ��ʱ��14
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource14,GPIO_AF_TIM1); //GPIOE14����Ϊ��ʱ��14
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14; //GPIOE
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                  //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	                          //�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                                //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                                  //����
	GPIO_Init(GPIOE,&GPIO_InitStructure);                                         //��ʼ��PF9
	  
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);//��ʼ����ʱ��14
	
	//��ʼ��TIM14 Channel1 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ե�
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//�ڿ���ʱ���     ��,��������ÿ��Ըı�TIM_OCPolarity ���û��䣬��1ͨ��������
//	TIM_OCInitStructure.TIM_Pulse =50;
	
//	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
//	TIM_OC2Init(TIM1, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM1 4OC1

//	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
//	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);  //ʹ��TIM14��CCR1�ϵ�Ԥװ�ؼĴ���
 
  TIM_ARRPreloadConfig(TIM1,ENABLE);//ARPEʹ�� 
	
	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIM14
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
 
  TIM_SetCompare3(TIM1,0); //������ռ�ձ�
  TIM_SetCompare4(TIM1,0);
 
	}




void TIM9_PWM_Init(u32 arr,u32 psc) //�����TIM9_PWM_Init(10000-1,56-1);    // ���PWM  168000000/56/10000=300hz  
	{
    // ����1: �������Ź��ܣ�GPIO��
    // ʹ��GPIOEʱ��
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;              // ���ù���
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;            // �������
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;                                  //����
    GPIO_Init(GPIOE, &GPIO_InitStruct);	  
    // ��PE5����ӳ�䵽TIM9ͨ��1
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);
	
	
	
	
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);    
    //GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;              // ���ù���
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;            // �������
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;                                  //����
    GPIO_Init(GPIOA, &GPIO_InitStruct);	  

    // ��PE5����ӳ�䵽TIM9ͨ��1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM9);
	
	

    // ����2: ���ö�ʱ����TIM9��
    // ʹ��TIM9ʱ��
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_BaseStruct;
    TIM_BaseStruct.TIM_Prescaler = psc;  // Ԥ��Ƶ����84MHz��Ƶ������Ƶ��Ϊ84MHz / 84 = 1MHz
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = arr;  // �Զ���װ�ؼĴ���������Ϊ280000����PWM����Ϊ1/300�� (300Hz)
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    //TIM_BaseStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM9, &TIM_BaseStruct);

    // ����3: ����PWM���
    TIM_OCInitTypeDef TIM_OCStruct;
    TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_High;
		TIM_OCStruct.TIM_OCIdleState = TIM_OCIdleState_Reset;
    
    // ���ö����ʼλ�õ�ռ�ձȣ����Ը��ݾ�������Ҫ����е���
    // ��������Ϊ1.5ms�����м�λ��
    //TIM_OCStruct.TIM_Pulse = 500;
    
    TIM_OC1Init(TIM9, &TIM_OCStruct);
		TIM_OC2Init(TIM9, &TIM_OCStruct);

    // ʹ��TIM9ͨ��1
    TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable);
		TIM_OC2PreloadConfig(TIM9, TIM_OCPreload_Enable);
		
		TIM_ARRPreloadConfig(TIM9,ENABLE);//ARPEʹ�� 

    // ʹ��TIM9
    TIM_Cmd(TIM9, ENABLE);
		TIM_CtrlPWMOutputs(TIM9,ENABLE);
		
		
}
