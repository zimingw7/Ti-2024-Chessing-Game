#ifndef __MOTOR_H
#define __MOTOR_H

#include "sys.h"
#include "led.h"


#define AIN1 PFout(7)
#define AIN2 PFout(8)
#define BIN1 PFout(9)
#define BIN2 PFout(10)

#define CIN1 PGout(15)
#define CIN2 PGout(14)
#define DIN1 PGout(11)
#define DIN2 PGout(10)

 


void MotorB_Set(int Motor3,int Motor4);
void motorPidSetSpeed(float Motor1SetSpeed,float Motor2SetSpeed);
void carturn (int jiaodu);
void carwalk (int juli);
void carrun(float Speedleft, float Speedright);
void carrunback ( float Speedleft, float Speedright);
void catchthing (void);
void putthing (void);
int thiscolor();
void  look_for_road (void);
#endif

