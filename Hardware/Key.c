#include "key.h"
#include "delay.h" 
#include "stm32f4xx.h"



/*下面的方式是通过直接操作库函数方式读取IO*/
#define KEY1 		GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1) //PF1
#define KEY2 		GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)	//PF2 
#define KEY3 		GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3) //PF3
#define KEY4 	  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4)	//PF4



//按键初始化函数
void KEY_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//使能GPIOF时钟
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4; //KEY1 KEY2 KEY3 KEY4对应引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOF, &GPIO_InitStructure);//初始化GPIOF1,2,3,4
	
	 
 
} 
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0按下
//2，KEY1按下
//3，KEY2按下 
//4，WKUP按下 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY2>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
		delay_ms(5);//去抖动 
		key_up=0;
		if(KEY1==0){return 1;}
		else if(KEY2==0){return 2;}
		else if(KEY3==0){return 3;}
		else if(KEY4==0){return 4;}
	}else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)key_up=1; 	    
 	return 0;// 无按键按下
}




















