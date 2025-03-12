#include "motor.h"
#include "led.h"
#include "Serial.h"
#include "delay.h"

#define xiaotiao 1.2
#define datiao 2


extern float Speed1;
extern float Speed2;

int turntime=0;
int turnsign=0;
float turnspeed = 0;
int walktime=0;
int walksign=0;
float walkspeed = 0;
float Speedleft;
float Speedright;
extern int hd[9];
extern int modenow;
extern int hcl0;
extern int hcl1;
extern int hcl2;
extern int lastTime;


void MotorB_Set(int Motor3,int Motor4)//开环速度控制左/右，带限幅自行调整，速度-1000（向后）到1000（向前）可调
{
  //根据正负设置方向
  if(Motor3<0) 
	{	
		CIN1 = 0;
	  CIN2 = 1; 
	}
	else if(Motor3==0)
	{	
		CIN1 = 1;
	  CIN2 = 1; 
	}
	else 
	{	
	 CIN1 = 1;
	 CIN2 = 0;
  }
  if(Motor4<0) 
	{
		DIN1 = 1;
		DIN2 = 0;
	}
	else if(Motor4==0)
	{	
		DIN1 = 1;
	  DIN2 = 1; 
	}
  else 
	{
		DIN1 = 0;
		DIN2 = 1;
	}
	

//然后设置占空比
	if(Motor3<0)
	{
	  if(Motor3<-950) Motor3=-950;
		TIM_SetCompare3(TIM1,-Motor3);
	}
	else
	{
	  if(Motor3>950) Motor3=950;
		TIM_SetCompare3(TIM1,Motor3);
	}
	
	if(Motor4<0)
	{
	  if(Motor4<-950) Motor4=-950;
		TIM_SetCompare4(TIM1,-Motor4);
	}
	else
	{
	  if(Motor4>950) Motor4=950;
		TIM_SetCompare4(TIM1,Motor4);
	}


}




		













