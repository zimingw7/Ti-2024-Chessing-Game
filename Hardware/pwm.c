#include "pwm.h"
#include "led.h"

 
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//定时器PWM 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/4
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 


//TIM14 PWM部分初始化 
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM1_PWM_Init(u32 arr,u32 psc)//电机用
{		 					 
	//此部分需手动修改IO口设置
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  	  //TIM14时钟使能    
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE); 	//使能PORTE时钟	
	
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource9,GPIO_AF_TIM1);  //GPIOE9复用为定时器14
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource11,GPIO_AF_TIM1); //GPIOE11复用为定时器14
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource13,GPIO_AF_TIM1); //GPIOE13复用为定时器14
	GPIO_PinAFConfig(GPIOE,GPIO_PinSource14,GPIO_AF_TIM1); //GPIOE14复用为定时器14
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_11|GPIO_Pin_13|GPIO_Pin_14; //GPIOE
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                  //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	                          //速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                                //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                                  //上拉
	GPIO_Init(GPIOE,&GPIO_InitStructure);                                         //初始化PF9
	  
	
	TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStructure);//初始化定时器14
	
	//初始化TIM14 Channel1 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性低
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Reset;//在空闲时输出     低,这里的设置可以改变TIM_OCPolarity 如果没这句，第1通道有问题
//	TIM_OCInitStructure.TIM_Pulse =50;
	
//	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
//	TIM_OC2Init(TIM1, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC3Init(TIM1, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1
	TIM_OC4Init(TIM1, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM1 4OC1

//	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
//	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
	TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);  //使能TIM14在CCR1上的预装载寄存器
 
  TIM_ARRPreloadConfig(TIM1,ENABLE);//ARPE使能 
	
	TIM_Cmd(TIM1, ENABLE);  //使能TIM14
	
	TIM_CtrlPWMOutputs(TIM1,ENABLE);
 
  TIM_SetCompare3(TIM1,0); //先置零占空比
  TIM_SetCompare4(TIM1,0);
 
	}




void TIM9_PWM_Init(u32 arr,u32 psc) //舵机用TIM9_PWM_Init(10000-1,56-1);    // 舵机PWM  168000000/56/10000=300hz  
	{
    // 步骤1: 配置引脚功能（GPIO）
    // 使能GPIOE时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;              // 复用功能
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;            // 推挽输出
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;                                  //上拉
    GPIO_Init(GPIOE, &GPIO_InitStruct);	  
    // 将PE5引脚映射到TIM9通道1
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource5, GPIO_AF_TIM9);
	
	
	
	
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);    
    //GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;              // 复用功能
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;            // 推挽输出
	  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;                                  //上拉
    GPIO_Init(GPIOA, &GPIO_InitStruct);	  

    // 将PE5引脚映射到TIM9通道1
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM9);
	
	

    // 步骤2: 配置定时器（TIM9）
    // 使能TIM9时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);

    TIM_TimeBaseInitTypeDef TIM_BaseStruct;
    TIM_BaseStruct.TIM_Prescaler = psc;  // 预分频器，84MHz主频，计数频率为84MHz / 84 = 1MHz
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_BaseStruct.TIM_Period = arr;  // 自动重装载寄存器，设置为280000，即PWM周期为1/300秒 (300Hz)
    TIM_BaseStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    //TIM_BaseStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM9, &TIM_BaseStruct);

    // 步骤3: 配置PWM输出
    TIM_OCInitTypeDef TIM_OCStruct;
    TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_High;
		TIM_OCStruct.TIM_OCIdleState = TIM_OCIdleState_Reset;
    
    // 设置舵机初始位置的占空比，可以根据具体舵机的要求进行调整
    // 这里设置为1.5ms，即中间位置
    //TIM_OCStruct.TIM_Pulse = 500;
    
    TIM_OC1Init(TIM9, &TIM_OCStruct);
		TIM_OC2Init(TIM9, &TIM_OCStruct);

    // 使能TIM9通道1
    TIM_OC1PreloadConfig(TIM9, TIM_OCPreload_Enable);
		TIM_OC2PreloadConfig(TIM9, TIM_OCPreload_Enable);
		
		TIM_ARRPreloadConfig(TIM9,ENABLE);//ARPE使能 

    // 使能TIM9
    TIM_Cmd(TIM9, ENABLE);
		TIM_CtrlPWMOutputs(TIM9,ENABLE);
		
		
}
