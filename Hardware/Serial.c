#include "stm32f4xx.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>
#include "serial.h"
#include "stdbool.h"
#include <string.h>


uint8_t Serial_RxPacket[100];				//ÂÆö‰πâÊé•Êî∂Êï∞ÊçÆÂåÖÊï∞ÁªÑÔºåÊï∞ÊçÆÂåÖÊ†ºÂºè"@MSG\r\n"
uint8_t Serial_RxFlag;					//ÂÆö‰πâÊé•Êî∂Êï∞ÊçÆÂåÖÊ†áÂøó‰Ωç
char gcode[100];
uint8_t openmv_data[30] = {0};//‰∏ÄÂÖ±26‰∏™
//extern int chess_data[29]={0};//‰∏ÄÂÖ±24‰∏™


gridItem item[8];

// ÂÆö‰πâ‰∏Ä‰∏™ÁªìÊûÑ‰ΩìÊù•Â≠òÂÇ®ÂèòÈáèÁöÑÂΩìÂâçÂÄºÂíå‰∏äÊ¨°Ê£ÄÊü•ÁöÑÂÄº
typedef struct {
    int value;
    int last_value;
} Variable;

// Ê£ÄÊü•ÂèòÈáèÊòØÂê¶Á®≥ÂÆöÁöÑÂáΩÊï∞
bool checkStability(Variable *var, int stability_time, void (*callback)()) {
    // Â¶ÇÊûúÂΩìÂâçÂÄºÂíå‰∏äÊ¨°Ê£ÄÊü•ÁöÑÂÄºÁõ∏Âêå
    if (var->value == var->last_value) {
        static int stable_time = 0;
        stable_time++;  // Á¥ØËÆ°Á®≥ÂÆöÊó∂Èó¥

        // Â¶ÇÊûúÁ®≥ÂÆöÊó∂Èó¥ËææÂà∞ÊåáÂÆöÁöÑÁ®≥ÂÆöÊó∂Èó¥ÈòàÂÄº
        if (stable_time >= stability_time) {
            stable_time = 0;  // ÈáçÁΩÆÁ®≥ÂÆöÊó∂Èó¥
            (*callback)();    // Ë∞ÉÁî®ÂõûË∞ÉÂáΩÊï∞
            return true;      // ËøîÂõûÁ®≥ÂÆöÂπ∂‰∏îË∞ÉÁî®‰∫ÜÂáΩÊï∞
        }
    } else {
        var->last_value = var->value;  // Êõ¥Êñ∞‰∏äÊ¨°Ê£ÄÊü•ÁöÑÂÄº
    }

    return false;  // ÂèòÈáè‰∏çÁ®≥ÂÆö
}

// Á§∫‰æãÁöÑÂõûË∞ÉÂáΩÊï∞
void stabilizationDetected() {
    printf("ÂèòÈáèÁ®≥ÂÆöÔºåË∞ÉÁî®‰∫ÜÊª§Ê≥¢ÂáΩÊï∞„ÄÇ\n");
    // ËøôÈáåÂèØ‰ª•Ë∞ÉÁî®‰Ω†ÁöÑÊª§Ê≥¢ÂáΩÊï∞ÊàñËÄÖÂÖ∂‰ªñÂ§ÑÁêÜÂáΩÊï∞
	
	
	
	
	
}







// ÊØîËæÉÂáΩÊï∞ÔºåÁî®‰∫é qsort ÊéíÂ∫è
int compareItems(const void* a, const void* b) {
    gridItem* item1 = (gridItem*)a;
    gridItem* item2 = (gridItem*)b;

    // ÊåâÁÖß‰ªé‰∏äÂà∞‰∏ãÔºå‰ªéÂ∑¶Âà∞Âè≥ÁöÑÈ°∫Â∫èÊØîËæÉ
    if (item1->y != item2->y) {
        return item1->y - item2->y;  // ÊåâÁÖß y ÂùêÊ†áÂçáÂ∫èÊéíÂàó
    }
    else {
        return item1->x - item2->x;  // Â¶ÇÊûú y ÂùêÊ†áÁõ∏ÂêåÔºåÊåâÁÖß x ÂùêÊ†áÂçáÂ∫èÊéíÂàó
		
    }
}

void Serial_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);// πƒ‹USART1 ±÷”
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); // πƒ‹GPIOA ±÷”
	
	//¥Æø⁄1∂‘”¶“˝Ω≈∏¥”√”≥…‰
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1); //GPIOA9∏¥”√Œ™USART1
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1); //GPIOA10∏¥”√Œ™USART1
	

	//USART1∂Àø⁄≈‰÷√
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA9”ÎGPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//∏¥”√π¶ƒ‹
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//ÀŸ∂»50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //Õ∆ÕÏ∏¥”√ ‰≥ˆ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //…œ¿≠
	GPIO_Init(GPIOA,&GPIO_InitStructure); //≥ı ºªØPA9£¨PA10
	

	//USART1 ≥ı ºªØ…Ë÷√
	USART_InitStructure.USART_BaudRate = 115200;//≤®Ãÿ¬ …Ë÷√
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//◊÷≥§Œ™8Œª ˝æ›∏Ò Ω
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//“ª∏ˆÕ£÷πŒª
	USART_InitStructure.USART_Parity = USART_Parity_No;//Œﬁ∆Ê≈º–£—ÈŒª
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//Œﬁ”≤º˛ ˝æ›¡˜øÿ÷∆
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	// ’∑¢ƒ£ Ω
  USART_Init(USART1, &USART_InitStructure); //≥ı ºªØ¥Æø⁄1
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART1, ENABLE);
	
}

void Serial3_Init(void)     //¥Æø⁄»˝≈‰÷√
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);// πƒ‹USART3 ±÷”
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); // πƒ‹GPIOD ±÷”
	
	//¥Æø⁄3∂‘”¶“˝Ω≈∏¥”√”≥…‰
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource8,GPIO_AF_USART3); //GPIOD8∏¥”√Œ™USART3
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource9,GPIO_AF_USART3); //GPIOD9∏¥”√Œ™USART3
	

	//USART3∂Àø⁄≈‰÷√
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; //GPIOD8”ÎGPIOD9
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//∏¥”√π¶ƒ‹
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//ÀŸ∂»50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //Õ∆ÕÏ∏¥”√ ‰≥ˆ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //…œ¿≠
	GPIO_Init(GPIOD,&GPIO_InitStructure); //≥ı ºªØPD8£¨PD9
	

	//USART3 ≥ı ºªØ…Ë÷√
	USART_InitStructure.USART_BaudRate = 115200;//≤®Ãÿ¬ …Ë÷√
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//◊÷≥§Œ™8Œª ˝æ›∏Ò Ω
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//“ª∏ˆÕ£÷πŒª
	USART_InitStructure.USART_Parity = USART_Parity_No;//Œﬁ∆Ê≈º–£—ÈŒª
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//Œﬁ”≤º˛ ˝æ›¡˜øÿ÷∆
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	// ’∑¢ƒ£ Ω
  USART_Init(USART3, &USART_InitStructure); //≥ı ºªØ¥Æø⁄3
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART3, ENABLE);
	
}


void Serial2_Init(void)     //¥Æø⁄∂˛≈‰÷√
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);// πƒ‹USART2 ±÷”
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE); // πƒ‹GPIOA ±÷”
	
	//¥Æø⁄2∂‘”¶“˝Ω≈∏¥”√”≥…‰
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource5,GPIO_AF_USART2); //GPIOA2∏¥”√Œ™USART2
	GPIO_PinAFConfig(GPIOD,GPIO_PinSource6,GPIO_AF_USART2); //GPIOA3∏¥”√Œ™USART2
	

	//USART2∂Àø⁄≈‰÷√
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6; //GPIOA2”ÎGPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//∏¥”√π¶ƒ‹
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//ÀŸ∂»50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //Õ∆ÕÏ∏¥”√ ‰≥ˆ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //…œ¿≠
	GPIO_Init(GPIOD,&GPIO_InitStructure); //≥ı ºªØPA2£¨PA3
	

	//USART2 ≥ı ºªØ…Ë÷√
	USART_InitStructure.USART_BaudRate = 115200;//≤®Ãÿ¬ …Ë÷√
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//◊÷≥§Œ™8Œª ˝æ›∏Ò Ω
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//“ª∏ˆÕ£÷πŒª
	USART_InitStructure.USART_Parity = USART_Parity_No;//Œﬁ∆Ê≈º–£—ÈŒª
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//Œﬁ”≤º˛ ˝æ›¡˜øÿ÷∆
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	// ’∑¢ƒ£ Ω
  USART_Init(USART2, &USART_InitStructure); //≥ı ºªØ¥Æø⁄2
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_Cmd(USART2, ENABLE);
	
}

void Serial4_Init(void)     //¥Æø⁄Àƒ≈‰÷√
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);// πƒ‹USART2 ±÷”
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE); // πƒ‹GPIOA ±÷”
	
	//¥Æø⁄2∂‘”¶“˝Ω≈∏¥”√”≥…‰
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource10,GPIO_AF_UART4); //GPIOA2∏¥”√Œ™USART2
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource11,GPIO_AF_UART4); //GPIOA3∏¥”√Œ™USART2
	

	//USART2∂Àø⁄≈‰÷√
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11; //GPIOA2”ÎGPIOA3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//∏¥”√π¶ƒ‹
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//ÀŸ∂»50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //Õ∆ÕÏ∏¥”√ ‰≥ˆ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //…œ¿≠
	GPIO_Init(GPIOC,&GPIO_InitStructure); //≥ı ºªØPA2£¨PA3
	

	//USART2 ≥ı ºªØ…Ë÷√
	USART_InitStructure.USART_BaudRate = 115200;//≤®Ãÿ¬ …Ë÷√
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//◊÷≥§Œ™8Œª ˝æ›∏Ò Ω
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//“ª∏ˆÕ£÷πŒª
	USART_InitStructure.USART_Parity = USART_Parity_No;//Œﬁ∆Ê≈º–£—ÈŒª
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//Œﬁ”≤º˛ ˝æ›¡˜øÿ÷∆
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	// ’∑¢ƒ£ Ω
  USART_Init(UART4, &USART_InitStructure); //≥ı ºªØ¥Æø⁄2
	
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


//USART1 »´æ÷÷–∂œ∑˛ŒÒ∫Ø ˝
void USART1_IRQHandler(void)//ﬁìÀïopenmvÀΩﬂù◊∂}
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

        // ‰ΩøÁî® qsort ÂØπ item Êï∞ÁªÑËøõË°åÊéíÂ∫èÔºå‰ΩøÁî®Ëá™ÂÆö‰πâÁöÑÊØîËæÉÂáΩÊï∞ compareItems
        qsort(item, itemCount, sizeof(gridItem), compareItems);
				
				
				/*Variable var = { item[0].c, item[0].c };  // ÂàùÂßãÊó∂ÂΩìÂâçÂÄºÂíå‰∏äÊ¨°ÂÄºÁõ∏Âêå
				
				if (checkStability(&var, 3, stabilizationDetected)) {
                // Âú®ËøôÈáåÂèØ‰ª•Ê∑ªÂä†È¢ùÂ§ñÁöÑÂ§ÑÁêÜÈÄªËæë
         }
*/
				
				
				 
				/*/Ê£ãÁõò‰∏≠ÂøÉÁÇπxÂùêÊ†á
				chess_data[0] = openmv_data[1];
				chess_data[1] = openmv_data[2];
				chess_data[2] = openmv_data[3];
				chess_data[3] = openmv_data[4];
				chess_data[4] = openmv_data[5];
				chess_data[5] = openmv_data[6];
				chess_data[6] = openmv_data[7];
				chess_data[7] = openmv_data[8];
				chess_data[8] = openmv_data[9];
				
				//Ê£ãÁõò‰∏≠ÂøÉÁÇπyËΩ¥ÂùêÊ†á
				chess_data[9] = openmv_data[10];
				chess_data[10] = openmv_data[11];
				chess_data[11] = openmv_data[12];
				chess_data[12] = openmv_data[13];
				chess_data[13] = openmv_data[14];
				chess_data[14] = openmv_data[15];
				chess_data[15] = openmv_data[16];
				chess_data[16] = openmv_data[17];
				chess_data[17] = openmv_data[18];
					
				//Âà§Êñ≠ÈªëÁôΩÊ£ã
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
	static uint8_t flag = 0;		//ÂÆö‰πâË°®Á§∫ÂΩìÂâçÁä∂ÊÄÅÊú∫Áä∂ÊÄÅÁöÑÈùôÊÄÅÂèòÈáè
	static uint8_t pRxPacket = 0;	//ÂÆö‰πâË°®Á§∫ÂΩìÂâçÊé•Êî∂Êï∞ÊçÆ‰ΩçÁΩÆÁöÑÈùôÊÄÅÂèòÈáè
   if(USART_GetITStatus(USART2,USART_IT_RXNE)!=RESET)
   {
	  uint8_t RxData = USART_ReceiveData(USART2);			//ËØªÂèñÊï∞ÊçÆÂØÑÂ≠òÂô®ÔºåÂ≠òÊîæÂú®Êé•Êî∂ÁöÑÊï∞ÊçÆÂèòÈáè
	  Serial2_SendByte(RxData);
		/*‰ΩøÁî®Áä∂ÊÄÅÊú∫ÁöÑÊÄùË∑ØÔºå‰æùÊ¨°Â§ÑÁêÜÊï∞ÊçÆÂåÖÁöÑ‰∏çÂêåÈÉ®ÂàÜ*/
		
		/*ÂΩìÂâçÁä∂ÊÄÅ‰∏∫0ÔºåÊé•Êî∂Êï∞ÊçÆÂåÖÂåÖÂ§¥*/
		if (flag == 0)
		{
			if (RxData == 'Y' && Serial_RxFlag == 0)		//Â¶ÇÊûúÊï∞ÊçÆÁ°ÆÂÆûÊòØÂåÖÂ§¥ÔºåÂπ∂‰∏î‰∏ä‰∏Ä‰∏™Êï∞ÊçÆÂåÖÂ∑≤Â§ÑÁêÜÂÆåÊØï
			{
				flag = 1;			//ÁΩÆ‰∏ã‰∏Ä‰∏™Áä∂ÊÄÅ
				pRxPacket = 0;			//Êï∞ÊçÆÂåÖÁöÑ‰ΩçÁΩÆÂΩíÈõ∂
			}
		}
		/*ÂΩìÂâçÁä∂ÊÄÅ‰∏∫1ÔºåÊé•Êî∂Êï∞ÊçÆÂåÖÊï∞ÊçÆÔºåÂêåÊó∂Âà§Êñ≠ÊòØÂê¶Êé•Êî∂Âà∞‰∫ÜÁ¨¨‰∏Ä‰∏™ÂåÖÂ∞æ*/
		else if (flag == 1)
		{
			if (RxData == 'Z')			//Â¶ÇÊûúÊî∂Âà∞Á¨¨‰∏Ä‰∏™ÂåÖÂ∞æ
			{
				flag=0;
				Serial_RxPacket[pRxPacket]='\0';
				Serial_RxFlag=1;
			}
			else						//Êé•Êî∂Âà∞‰∫ÜÊ≠£Â∏∏ÁöÑÊï∞ÊçÆ
			{
				Serial_RxPacket[pRxPacket] = RxData;		//Â∞ÜÊï∞ÊçÆÂ≠òÂÖ•Êï∞ÊçÆÂåÖÊï∞ÁªÑÁöÑÊåáÂÆö‰ΩçÁΩÆ
				pRxPacket ++;			//Êï∞ÊçÆÂåÖÁöÑ‰ΩçÁΩÆËá™Â¢û
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




