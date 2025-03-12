#include "key.h"
#include "delay.h" 
#include "stm32f4xx.h"



/*����ķ�ʽ��ͨ��ֱ�Ӳ����⺯����ʽ��ȡIO*/
#define KEY1 		GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1) //PF1
#define KEY2 		GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)	//PF2 
#define KEY3 		GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3) //PF3
#define KEY4 	  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_4)	//PF4



//������ʼ������
void KEY_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);//ʹ��GPIOFʱ��
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4; //KEY1 KEY2 KEY3 KEY4��Ӧ����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOF, &GPIO_InitStructure);//��ʼ��GPIOF1,2,3,4
	
	 
 
} 
//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����
//3��KEY2���� 
//4��WKUP���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
		delay_ms(5);//ȥ���� 
		key_up=0;
		if(KEY1==0){return 1;}
		else if(KEY2==0){return 2;}
		else if(KEY3==0){return 3;}
		else if(KEY4==0){return 4;}
	}else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)key_up=1; 	    
 	return 0;// �ް�������
}




















