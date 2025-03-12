#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>
#include "stm32f4xx.h"    

typedef struct {
	int x;
	int y;
	int c;
}gridItem;




extern uint8_t Serial_RxFlag;
extern uint8_t Serial_TxPacket[];
extern uint8_t Serial_RxPacket[];

void Serial_Init(void);
void Serial2_Init(void);     //串口二配置
void Serial3_Init(void);     //串口三配置
void Serial4_Init(void);    //串口四配置

void Serial3_SendString(char *String);

void Serial_SendByte(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendString(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);
void Serial_SendPacket(void);
uint8_t Serial_GetRxFlag(void);



#endif
