#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "stm32f4xx.h"
#include "menu.h"
#include "LED.h"
#include "stdbool.h"
#include "Serial.h"
#include "pwm.h"
#include "control.h"
#include "motor.h"
#include "move.h"


extern gridItem item[8]; // 使用 extern 声明来访问 main.c 中定义的 item
gridItem tmp[8];
gridItem back[8];
char OledString[100];
int menuflag = 0;
int XX,YY;
int num;
int old;
int new1;
int ox=0,oy=0;
int nx,ny;
int num,row0,col0;
int a,b,c,d,e,f,g,h,i;//棋盘上格子读数
extern int play_mode = 0;
const char delimiters[] = ",";
int a1,b1,c1,d1,e1;//接收端变量

bool val = false;
int count=0;
void valuation(void);
void backup(void);


void getTouchData(void);
void catchchess(void);
void handlebutton(void);
void TIM3_Int_Init(u16 arr,u16 psc);
void delta(void);
void osis(void);
void figure();
void TIM3_Start(void);
void TIM3_Stop(void);



int getXwithNumber(int num){
	
}

int main(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	TIM3_Int_Init(7200,10000);
	Control_Init(); 
	delay_init(168);
	OLED_Init(); 
	KEY_Init();
	TIM1_PWM_Init(1000-1,840-1);     //电机PWM
	Serial_Init();
	Serial2_Init();
	Serial3_Init();
	Serial4_Init();
  
	LED_Init();
	
	
 
  while(1){
		
		//valuation();
		
		      OLED_ShowNum(1,3,count,4);
	  	  // OLED_ShowNum(2,3,tmp[1].c,4);
		    //  OLED_ShowNum(3,3,tmp[2].c,4);
		     // OLED_ShowNum(4,3,tmp[3].c,4);
		
		
	//	OLED_ShowNum(1,3,tmp[0].c,4);
	//	OLED_ShowNum(2,3,tmp[1].c,4);
		//OLED_ShowNum(3,3,tmp[2].c,4);
		//OLED_ShowNum(4,3,tmp[3].c,4);
	//	LED1_ON();
	//	delay_ms(100);
	//	LED1_OFF();
	//	delay_ms(100);
		
			//OLED_ShowNum(1,1,c1,4);
		//	OLED_ShowNum(3,1,d1,4);
	
	   //sprintf(OledString, "Vr:%5f",1.001); 
			//OLED_ShowString(2,1,OledString);
		/*
		//返回主菜单
	if(KEY_Scan(1)==3) {
			delay_ms(10);	  //防抖
			while(KEY_Scan(1)==2); //按下后不松手，则停在这
			delay_ms(10);	  //防抖			
		  OLED_Clear();
			menuflag=0;
		}
		
		if(menuflag == 0){
		menu1();
		}
		else if(menuflag == 1){
		menu_grid();
		}else if(menuflag == 3){
		menu_chess();
		}
		
		*/
		 
      getTouchData();
			
			

	}
}

void getTouchData(void){
if (Serial_RxFlag == 1)		//如果接收到数据包
		{
			
			
			/*将收到的数据包与预设的指令对比，以此决定将要执行的操作*/
			if (strcmp(Serial_RxPacket, "Play_Mode_Black") == 0)			//如果收到LEFT_MIMI_ON指令
			{
		  			//OLED清除指定位置，并显示接收到的数据包
				//	OLED_ShowString(3, 1, "Play_Mode_Black");	
				
				setE1Num(0);
				play_mode = 0;
			
			  Chess_Init(1,1,1);
				backup();
				
		
				
			}
			else if (strcmp(Serial_RxPacket, "Play_Mode_White") == 0)	//如果收到LED_OFF指令
			{
			   //OLED_ShowString(3, 1, "Play_Mode_White");	
				setE1Num(1);
				play_mode = 1;
				
				 Chess_Init(1,1,0);
				 backup();
			}
			else if	(strcmp(Serial_RxPacket,"Play_Stop") == 0)					//上述所有条件均不满足，即收到了未知指令
			{
				//	OLED_ShowString(3,1,"Play_Stop      ");
			}
			else if(strcmp(Serial_RxPacket,"Play_Start")==0)
			{
				TIM3_Start();
					//OLED_ShowString(3,1,"Play_Start     ");
				
				if (play_mode == 0){
				
				//compareAndPrint(tmp,back,8);
					valuation();
					delta();
					osis();
					
					 //OLED_ShowNum(1,3,row0,4);
	  	     //OLED_ShowNum(2,3,col0,4);
					
					
					play_chess(row0,col0) ;
					delay_ms(1000);
					backup();
				}
				else if (play_mode == 1){
					
				  valuation();
					delta();
					osis();
					play_chess(row0,col0);
					backup();
				
				}
					
			
				
			}
				else if	(strcmp(Serial_RxPacket,"Play_Recover") == 0)				
			{
				//	OLED_ShowString(3,1,"Play_Stop      ");
				valuation();
				figure();
				movita(nx,ny,ox,oy);
				
			}
			else{
					//splitString(Serial_RxPacket);
			char a = Serial_RxPacket[0];//a1当前模式只有0 和 1
			char b = Serial_RxPacket[2];//棋子颜色白 0 黑 1
		  char c = Serial_RxPacket[4];//row 行
		  char d = Serial_RxPacket[6];//col 列
			char e = Serial_RxPacket[8];//棋子列表
				
				a1 = a-'0';
				b1 = b-'0';
				c1 = c-'0';
				d1 = d-'0';
				e1 = e-'0';
			handlebutton();
			}
			
			Serial_RxFlag = 0;			//处理完成后，需要将接收数据包标志位清零，否则将无法接收后续数据包
		}
	}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
		count++;
	}

	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}
	
void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);  ///使能TIM3时钟
	
  TIM_TimeBaseInitStructure.TIM_Period = arr; 	//自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;  //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);//初始化TIM3
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE); //允许定时器3更新中断
	//TIM_Cmd(TIM3,ENABLE); //使能定时器3
	
	NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn; //定时器3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01; //抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03; //子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
}

void TIM3_Start(void)
{
    TIM_Cmd(TIM3, ENABLE); // 使能定时器3
}

void TIM3_Stop(void)
{
    TIM_Cmd(TIM3, DISABLE); // 关闭定时器3
}




void catchchess(){
 MotorB_Set(800,0);
}

void releasechess(){
 MotorB_Set(800,800);
}


//将任意
void put_block1(){
	
		delay_ms(100);
	
}
void fight(){ 
}

void chess(){

}

void handlebutton(){
   if (c1==0&&d1==0){
		switch (e1){
			case 0:		
				c0to1();
				break;
			case 1:
				c1to1();
				break;
			case 2:
				c2to1();
				break;
			case 3:
				c3to1();
				break;
		  case 4:
				c4to1();
				break;
			case 5:
				c5to1();
				break;
			case 6:
				c6to1();
				break;
			case 7:
				c7to1();
				break;
			case 8:
				c8to1();
				break;
			case 9:
				c9to1();
				break;
		}
	 }
	
	   if (c1==0&&d1==1){
		switch (e1){
			case 0:
				c0to2();
				break;
			case 1:
				c1to2();
				break;
			case 2:
				c2to2();
				break;
			case 3:
				c3to2();
				break;
		  case 4:
				c4to2();
				break;
			case 5:
				c5to2();
				break;
			case 6:
				c6to2();
				break;
			case 7:
				c7to2();
				break;
			case 8:
				c8to2();
				break;
		
			case 9:
				c9to2();
				break;
		
	
		
		}
	 }
	 
	   if (c1==0&&d1==2){
		switch (e1){
			case 0:
				c0to3();
				break;
			case 1:
				c1to3();
				break;
			case 2:
				c2to3();
				break;
			case 3:
				c3to3();
				break;
		  case 4:
				c4to3();
				break;
			case 5:
				c5to3();
				break;
			case 6:
				c6to3();
				break;
			case 7:
				c7to3();
				break;
			case 8:
				c8to3();
				break;
		
			case 9:
				c9to3();
				break;
		
	
		
		}
	 }
	   if (c1==1&&d1==0){
		switch (e1){
			case 0:
				c0to4();
				break;
			case 1:
				c1to4();
				break;
			case 2:
				c2to4();
				break;
			case 3:
				c3to4();
				break;
		  case 4:
				c4to4();
				break;
			case 5:
				c5to4();
				break;
			case 6:
				c6to4();
				break;
			case 7:
				c7to4();
				break;
			case 8:
				c8to4();
				break;
			case 9:
				c9to4();
				break;
		
	
		
		}
	 }
	 
	   if (c1==1&&d1==1){
		switch (e1){
			case 0:
				c0to5();
				break;
			case 1:
				c1to5();
				break;
			case 2:
				c2to5();
				break;
			case 3:
				c3to5();
				break;
		  case 4:
				c4to5();
				break;
			case 5:
				c5to5();
				break;
			case 6:
				c6to5();
				break;
			case 7:
				c7to5();
				break;
			case 8:
				c8to5();
				break;
		
			case 9:
				c9to5();
				break;
		
	
		
		}
	 }
	 
	   if (c1==1&&d1==2){
		switch (e1){
			case 0:
				c0to6();
				break;
			case 1:
				c1to6();
				break;
			case 2:
				c2to6();
				break;
			case 3:
				c3to6();
				break;
		  case 4:
				c4to6();
				break;
			case 5:
				c5to6();
				break;
			case 6:
				c6to6();
				break;
			case 7:
				c7to6();
				break;
			case 8:
				c8to6();
				break;
		
			case 9:
				c9to6();
				break;
		
	
		
		}
	 }
	 
	   if (c1==2&&d1==0){
		switch (e1){
			case 0:
				c0to7();
				break;
			case 1:
				c1to7();
				break;
			case 2:
				c2to7();
				break;
			case 3:
				c3to7();
				break;
		  case 4:
				c4to7();
				break;
			case 5:
				c5to7();
				break;
			case 6:
				c6to7();
				break;
			case 7:
				c7to7();
				break;
			case 8:
				c8to7();
				break;
		
			case 9:
				c9to7();
				break;
		
	
		
		}
	 }
	 
	   if (c1==2&&d1==1){
		switch (e1){
			case 0:
				c0to8();
				break;
			case 1:
				c1to8();
				break;
			case 2:
				c2to8();
				break;
			case 3:
				c3to8();
				break;
		  case 4:
				c4to8();
				break;
			case 5:
				c5to8();
				break;
			case 6:
				c6to8();
				break;
			case 7:
				c7to8();
				break;
			case 8:
				c8to8();
				break;
		
			case 9:
				c9to8();
				break;
		
	
		
		}
	 }
	 
	   if (c1==2&&d1==2){
		switch (e1){
			case 0:
				c0to9();
				break;
			case 1:
				c1to9();
				break;
			case 2:
				c2to9();
				break;
			case 3:
				c3to9();
				break;
		  case 4:
				c4to9();
				break;
			case 5:
				c5to9();
				break;
			case 6:
				c6to9();
				break;
			case 7:
				c7to9();
				break;
			case 8:
				c8to9();
				break;
		
			case 9:
				c9to9();
				break;
		
	
		
		}
	 }
	 
	}

	void valuation(void){
			tmp[0].x = item[2].x;
			tmp[0].y = item[2].y;
			tmp[0].c = item[2].c;
		
			tmp[1].x = item[1].x;
			tmp[1].y = item[1].y;
			tmp[1].c = item[1].c;
		
			tmp[2].x = item[0].x;
			tmp[2].y = item[0].y;
			tmp[2].c = item[0].c;
		
			tmp[3].x = item[5].x;
			tmp[3].y = item[5].y;
			tmp[3].c = item[5].c;
		
			tmp[4].x = item[4].x;
			tmp[4].y = item[4].y;
			tmp[4].c = item[4].c;
		
			tmp[5].x = item[3].x;
			tmp[5].y = item[3].y;
			tmp[5].c = item[3].c;
			
			tmp[6].x = item[8].x;
			tmp[6].y = item[8].y;
			tmp[6].c = item[8].c;
			
			tmp[7].x = item[7].x;
			tmp[7].y = item[7].y;
			tmp[7].c = item[7].c;
			
			tmp[8].x = item[6].x;
			tmp[8].y = item[6].y;
			tmp[8].c = item[6].c;
	
	}
	void backup(){
			
			back[0].x = item[2].x;
			back[0].y = item[2].y;
			back[0].c = item[2].c;
		
			back[1].x = item[1].x;
			back[1].y = item[1].y;
			back[1].c = item[1].c;
		
			back[2].x = item[0].x;
			back[2].y = item[0].y;
			back[2].c = item[0].c;
		
			back[3].x = item[5].x;
			back[3].y = item[5].y;
			back[3].c = item[5].c;
		
			back[4].x = item[4].x;
			back[4].y = item[4].y;
			back[4].c = item[4].c;
		
			back[5].x = item[3].x;
			back[5].y = item[3].y;
			back[5].c = item[3].c;
			
			back[6].x = item[8].x;
			back[6].y = item[8].y;
			back[6].c = item[8].c;
			
			back[7].x = item[7].x;
			back[7].y = item[7].y;
			back[7].c = item[7].c;
			
			back[8].x = item[6].x;
			back[8].y = item[6].y;
			back[8].c = item[6].c;
	
	
	}
	
	
void delta(){

	for (int i=0;i<=8;i++){
	if((tmp[i].c-back[i].c)<0){
	
		num=9-i;
	 }
 }
}

void osis(){
 
  switch (num){
	   
		case 1:
			row0=0;
		  col0=0;
		  XX=144;
	    YY=27;
		 break;
		case 2:
			row0=0;
		  col0=1;
			XX=143;
	    YY=52;
		 break;
		case 3:
			row0=0;
		  col0=2;
		XX=43;
	    YY=27;
     break;		
		case 4:
			row0=1;
		  col0=0;
			XX=102;
	    YY=56;
		 break;
		case 5:
			row0=1;
		  col0=1;
			XX=73;
	    YY=56;
		 break;
		case 6:
			row0=1;
		  col0=2;
			XX=43;
	    YY=56;
		 break;
		case 7:
			row0=2;
		  col0=0;
			XX=102;
	    YY=85;
		 break;
		case 8:
			row0=2;
		  col0=1;
			XX=73;
	    YY=85;
		 break;
		case 9:
			row0=2;
		  col0=2;
	    XX=43;
	    YY=85;
	}


}

void figure(){
	for (int i =0;i<=8;i++){
	if((tmp[i].c-back[i].c)<0){
	
		num=i+1;//old
	}
}
osis();
ox = XX;
oy = YY;
for (int i =0;i<=8;i++){
	if((tmp[i].c-back[i].c)>0){
	
		num=i+1;//new
	}
}
osis();
nx = XX;
ny = YY;
}



                                                   


