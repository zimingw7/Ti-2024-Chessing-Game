#include "delay.h"
#include "oled.h"
#include "led.h" 
#include "Key.h"
#include "stdlib.h"
extern int menuflag;

int flag=1; 
int flag2=1;
int flag3=1;
int current_row,current_col;

int mode = 1;
extern int chess_color = 0;//白一黑二
extern int grid[1]={0};
/**********************************************************

                     以下为一级菜单

**********************************************************/
void menu1()           
{
	   
		if(KEY_Scan(1)==1)       //第一个按键 : 下一个
		{		
			delay_ms(10);	  //防抖
			while(KEY_Scan(1)==1) ; //按下后不松手，则停在这
			delay_ms(10);	  //防抖
			flag++;
			if(flag==4) flag=1;			
		}
		
		if(KEY_Scan(1)==2)       // 按键2 ***确认***
		{
			delay_ms(10);	  //防抖
			while(KEY_Scan(1)==2); //按下后不松手，则停在这
			delay_ms(10);	  //防抖			
		
			menuflag =flag;
		}
		
		switch(flag)      //光标移动
		{
			case 1:
			{
		
			   OLED_ShowString(1,3,"*Grid");//模式
	       OLED_ShowString(2,3,"Fight");//应对
         OLED_ShowString(3,3,"Chess");//指定下棋
			}break;
			case 2:
			{
		
				 OLED_ShowString(1,3,"Grid");//模式
	       OLED_ShowString(2,3,"*Fight");//应对
         OLED_ShowString(3,3,"Chess");//指定下棋
			}break;
			case 3:
			{
			
				 OLED_ShowString(1,3,"Grid");//模式
	       OLED_ShowString(2,3,"Fight");//格子
         OLED_ShowString(3,3,"*Chess");//调试
			}break;
		}		
		
	
}

int menu_grid()           
{
	
//			sprintf(OledString, "hw:%.2d",Tracking_DO); 
//			OLED_ShowString(4,1,OledString);
	
		if(KEY_Scan(1)==1)       //***下一项***
		{		
			delay_ms(10);	  //防抖
			while(KEY_Scan(1)==1); //按下后不松手，则停在这
			delay_ms(10);	  //防抖
			flag2++;

			if(flag2==3) flag2=1;			
		}
		
		if(KEY_Scan(1)==2)       //***确认***
		{
			delay_ms(10);	  //防抖
			while(KEY_Scan(1)==2); //按下后不松手，则停在这
			delay_ms(10);	  //防抖			
			OLED_Clear();
			chess_color=flag2;   //返回你的选择
		}
		switch(flag2)      //光标移动
		{
			case 1:
			{
			   OLED_ShowString(1,3,"*White");//显示一个字符号串
	       OLED_ShowString(2,3,"Black");//显示一个字符号串
			}break;
			case 2:
			{
				 OLED_ShowString(1,3,"White");//显示一个字符号串
         OLED_ShowString(2,3,"*Black");//显示一个字符号串
			}break;
			
		}		
	}

/*

                     以下为二级菜单

*/
void menu_chess()           
{
	

		if(KEY_Scan(1)==1)       //***下一项***
		{		
			delay_ms(10);	  //防抖
			while(KEY_Scan(1)==1); //按下后不松手，则停在这
			delay_ms(10);	  //防抖
			flag3++;
			if(flag3==3) flag3=1;			
		}
		
		if(KEY_Scan(1)==2)       //***确认***
		{
			delay_ms(10);	  //防抖
			while(KEY_Scan(1)==1); //按下后不松手，则停在这
			delay_ms(10);	  //防抖	
			OLED_Clear();
			grid[0]=current_row;
			grid[1]=current_col;
		
		}
		
		if(KEY_Scan(1)==4)       //***增加一***
		{		
			delay_ms(10);	  //防抖
			while(KEY_Scan(1)==4); //按下后不松手，则停在这
			delay_ms(10);	  //防抖
			
			
	  	if(flag3==1){
			current_row++;
				if(current_row==3) current_row = 0;
			}//这是行	
			if(flag3 == 2){
				current_col++;
				if (current_col == 3) current_col =0;
			}
		
		}
		
		
		switch(flag3)      //光标移动
		{
			case 1:
			{
        OLED_ShowString(3,1,"*row^"+current_row);
				OLED_ShowString(2,1,"col^"+current_col);
				
			}break;
			case 2:
			{
				OLED_ShowString(3,1,"row^"+current_row);
				OLED_ShowString(2,1,"*col^"+current_col);
			}break;
		
		
		}		
		
	}


/**********************************************************

                     以下为三级菜单

**********************************************************/
