#include "stm32f4xx.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>
#include "serial.h"
#include "stdbool.h"
#include <string.h>


uint8_t Serial_RxPacket[100];				//定义接收数据包数组，数据包格式"@MSG\r\n"
uint8_t Serial_RxFlag;					//定义接收数据包标志位
char gcode[100];
uint8_t openmv_data[30] = {0};//一共26个
//extern int chess_data[29]={0};//一共24个


gridItem item[8];

// 定义一个结构体来存储变量的当前值和上次检查的值
typedef struct {
    int value;
    int last_value;
} Variable;

// 检查变量是否稳定的函数
bool checkStability(Variable *var, int stability_time, void (*callback)()) {
    // 如果当前值和上次检查的值相同
    if (var->value == var->last_value) {
        static int stable_time = 0;
        stable_time++;  // 累计稳定时间

        // 如果稳定时间达到指定的稳定时间阈值
        if (stable_time >= stability_time) {
            stable_time = 0;  // 重置稳定时间
            (*callback)();    // 调用回调函数
            return true;      // 返回稳定并且调用了函数
        }
    } else {
        var->last_value = var->value;  // 更新上次检查的值
    }

    return false;  // 变量不稳定
}

// 示例的回调函数
void stabilizationDetected() {
    printf("变量稳定，调用了滤波函数。\n");
    // 这里可以调用你的滤波函数或者其他处理函数
	
	
	
	
	
}







// 比较函数，用于 qsort 排序
int compareItems(const void* a, const void* b) {
    gridItem* item1 = (gridItem*)a;
    gridItem* item2 = (gridItem*)b;

    // 按照从上到下，从左到右的顺序比较
    if (item1->y != item2->y) {
        return item1->y - item2->y;  // 按照 y 坐标升序排列
    }
    else {
        return item1->x - item2->x;  // 如果 y 坐标相同，按照 x 坐标升序排列
		
    }
}

void Serial_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);//ʹ��USART1ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //ʹ��GPIOAʱ��
	
	//����1��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9����ΪUSART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10����ΪUSART1
	

	//USART1�˿�����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA9��GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOA,&GPIO_InitStructure); //��ʼ��PA9��PA10
	

	//USART1 ��ʼ������
	USART_InitStructure.USART_BaudRate = 115200;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART1, &USART_InitStructure); //��ʼ������1
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART1, ENABLE);
	
}

void Serial3_Init(void)     //����������
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);//ʹ��USART3ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //ʹ��GPIODʱ��
	
	//����3��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource8,GPIO_AF_USART3); //GPIOD8����ΪUSART3
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource9,GPIO_AF_USART3); //GPIOD9����ΪUSART3
	

	//USART3�˿�����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; //GPIOD8��GPIOD9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOD,&GPIO_InitStructure); //��ʼ��PD8��PD9
	

	//USART3 ��ʼ������
	USART_InitStructure.USART_BaudRate = 115200;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART3, &USART_InitStructure); //��ʼ������3
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART3, ENABLE);
	
}


void Serial2_Init(void)     //���ڶ�����
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);//ʹ��USART2ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); //ʹ��GPIOAʱ��
	
	//����2��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource5,GPIO_AF_USART2); //GPIOA2����ΪUSART2
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource6,GPIO_AF_USART2); //GPIOA3����ΪUSART2
	

	//USART2�˿�����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6; //GPIOA2��GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOD,&GPIO_InitStructure); //��ʼ��PA2��PA3
	

	//USART2 ��ʼ������
	USART_InitStructure.USART_BaudRate = 115200;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(USART2, &USART_InitStructure); //��ʼ������2
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART2, ENABLE);
	
}

void Serial4_Init(void)     //����������
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);//ʹ��USART2ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE); //ʹ��GPIOAʱ��
	
	//����2��Ӧ���Ÿ���ӳ��
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource10,GPIO_AF_UART4); //GPIOA2����ΪUSART2
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource11,GPIO_AF_UART4); //GPIOA3����ΪUSART2
	

	//USART2�˿�����
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11; //GPIOA2��GPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //����
	GPIO_Init(GPIOC,&GPIO_InitStructure); //��ʼ��PA2��PA3
	

	//USART2 ��ʼ������
	USART_InitStructure.USART_BaudRate = 115200;//����������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ
  USART_Init(UART4, &USART_InitStructure); //��ʼ������2
	
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(UART4, ENABLE);
	
}











void Serial_SendByte(uint8_t Byte)
{
	USART_SendData(USART1, Byte);
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

 void Serial2_SendByte(uint8_t Byte)
{
	USART_SendData(USART2, Byte);
	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
}

void Serial3_SendByte(uint8_t Byte)
{
	USART_SendData(USART3, Byte);
	while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
}

void Serial4_SendByte(uint8_t Byte)
{
	USART_SendData(UART4, Byte);
	while (USART_GetFlagStatus(UART4, USART_FLAG_TXE) == RESET);
}

void Serial_SendArray(uint8_t *Array, uint16_t Length)
{
	uint16_t i;
	for (i = 0; i < Length; i ++)
	{
		Serial_SendByte(Array[i]);
	}
}

void Serial_SendString(char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i ++)
	{
		Serial_SendByte(String[i]);
	}
}

uint32_t Serial_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y --)
	{
		Result *= X;
	}
	return Result;
}

void Serial_SendNumber(uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i ++)
	{
		Serial_SendByte(Number / Serial_Pow(10, Length - i - 1) % 10 + '0');
	}
}

void Serial3_SendString(char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i ++)
	{
		Serial3_SendByte(String[i]);
	}
}


//USART1 ȫ���жϷ�����
void USART1_IRQHandler(void)//ޓ˕openmv˽ߝ׶}
{
	 static int i=0;
   if(USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)
   {
	    openmv_data[i++] = USART_ReceiveData(USART1);
		if(openmv_data[0]!=0xa3) i=0;
		if(i==29)
		{
			if(openmv_data[28] == 0xc3)
			{
				item[0].x  = openmv_data[1];
				item[0].y  = openmv_data[10];
				item[0].c  = openmv_data[19];
				
				item[1].x  = openmv_data[2];
				item[1].y  = openmv_data[11];
				item[1].c  = openmv_data[20];
				
				item[2].x  = openmv_data[3];
				item[2].y  = openmv_data[12];
				item[2].c  = openmv_data[21];
				
				item[3].x  = openmv_data[4];
				item[3].y  = openmv_data[13];
				item[3].c  = openmv_data[22];
				
				item[4].x  = openmv_data[5];
				item[4].y  = openmv_data[14];
				item[4].c  = openmv_data[23];
				
				item[5].x  = openmv_data[6];
				item[5].y  = openmv_data[15];
				item[5].c  = openmv_data[24];
				
				item[6].x  = openmv_data[7];
				item[6].y  = openmv_data[16];
				item[6].c  = openmv_data[25];
				
				item[7].x  = openmv_data[8];
				item[7].y  = openmv_data[17];
				item[7].c  = openmv_data[26];
				
				item[8].x  = openmv_data[9];
				item[8].y  = openmv_data[18];
				item[8].c  = openmv_data[27];
				
				int itemCount = sizeof(item) / sizeof(item[0]);

        // 使用 qsort 对 item 数组进行排序，使用自定义的比较函数 compareItems
        qsort(item, itemCount, sizeof(gridItem), compareItems);
				
				
				/*Variable var = { item[0].c, item[0].c };  // 初始时当前值和上次值相同
				
				if (checkStability(&var, 3, stabilizationDetected)) {
                // 在这里可以添加额外的处理逻辑
         }
*/
				
				
				 
				/*/棋盘中心点x坐标
				chess_data[0] = openmv_data[1];
				chess_data[1] = openmv_data[2];
				chess_data[2] = openmv_data[3];
				chess_data[3] = openmv_data[4];
				chess_data[4] = openmv_data[5];
				chess_data[5] = openmv_data[6];
				chess_data[6] = openmv_data[7];
				chess_data[7] = openmv_data[8];
				chess_data[8] = openmv_data[9];
				
				//棋盘中心点y轴坐标
				chess_data[9] = openmv_data[10];
				chess_data[10] = openmv_data[11];
				chess_data[11] = openmv_data[12];
				chess_data[12] = openmv_data[13];
				chess_data[13] = openmv_data[14];
				chess_data[14] = openmv_data[15];
				chess_data[15] = openmv_data[16];
				chess_data[16] = openmv_data[17];
				chess_data[17] = openmv_data[18];
					
				//判断黑白棋
				chess_data[18] = openmv_data[19];
				chess_data[19] = openmv_data[20];
				chess_data[20] = openmv_data[21];
				chess_data[21] = openmv_data[22];
				chess_data[22] = openmv_data[23];
				chess_data[23] = openmv_data[24];
				chess_data[24] = openmv_data[25];
				chess_data[25] = openmv_data[26];
				chess_data[26] = openmv_data[27];
				*/
			}
			i=0;
			
			USART_ClearITPendingBit(USART1, USART_IT_RXNE);
		}
   }	 
}	



void USART3_IRQHandler(void)
{
   if(USART_GetITStatus(USART3,USART_IT_RXNE)!=RESET)
   {
	    //char tmp[] = USART_ReceiveData(USART3);
	   // Serial_SendByte(thr);
      
	    
		  USART_ClearITPendingBit(USART3, USART_IT_RXNE);
	 }

}



void USART2_IRQHandler(void)
{
	static uint8_t flag = 0;		//定义表示当前状态机状态的静态变量
	static uint8_t pRxPacket = 0;	//定义表示当前接收数据位置的静态变量
   if(USART_GetITStatus(USART2,USART_IT_RXNE)!=RESET)
   {
	  uint8_t RxData = USART_ReceiveData(USART2);			//读取数据寄存器，存放在接收的数据变量
	  Serial2_SendByte(RxData);
		/*使用状态机的思路，依次处理数据包的不同部分*/
		
		/*当前状态为0，接收数据包包头*/
		if (flag == 0)
		{
			if (RxData == 'Y' && Serial_RxFlag == 0)		//如果数据确实是包头，并且上一个数据包已处理完毕
			{
				flag = 1;			//置下一个状态
				pRxPacket = 0;			//数据包的位置归零
			}
		}
		/*当前状态为1，接收数据包数据，同时判断是否接收到了第一个包尾*/
		else if (flag == 1)
		{
			if (RxData == 'Z')			//如果收到第一个包尾
			{
				flag=0;
				Serial_RxPacket[pRxPacket]='\0';
				Serial_RxFlag=1;
			}
			else						//接收到了正常的数据
			{
				Serial_RxPacket[pRxPacket] = RxData;		//将数据存入数据包数组的指定位置
				pRxPacket ++;			//数据包的位置自增
			}
		}
		  USART_ClearITPendingBit(USART2, USART_IT_RXNE);
	 }

}


void UART4_IRQHandler(void)
{
   if(USART_GetITStatus(UART4,USART_IT_RXNE)!=RESET)
   {
//	    thr = USART_ReceiveData(UART4);
//	    Serial_SendByte(thr);
      
	    
		  USART_ClearITPendingBit(UART4, USART_IT_RXNE);
	 }

}


void movechessTo(int x, int y, int z){
sprintf(gcode, "G90 X%d Y%d Z%d\n",x,y,z); 
Serial3_SendString(gcode);
}




