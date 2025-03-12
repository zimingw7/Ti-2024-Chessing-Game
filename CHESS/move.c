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


void c0to1(){
	  movechessTo(144,3,15);//移动上方
		delay_ms(500);//等待
		movechessTo(143,3,28);//下降
		delay_ms(2200);//等待
		catchchess();//开吸
		delay_ms(500);//
	  movechessTo(143,3,15);//上降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(500);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	  delay_ms(200);//等待
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c0to2(){
	  movechessTo(144,3,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,3,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	 movechessTo(143,3,15);//上生
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c0to3(){
movechessTo(144,3,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,3,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,3,15);
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	delay_ms(500);//
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c0to4(){
movechessTo(144,3,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,3,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,3,15);
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	  delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c0to5(){
    movechessTo(144,3,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,3,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,3,15);
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,15);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	  delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c0to6(){
    movechessTo(144,3,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,3,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	  movechessTo(143,3,15);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c0to7(){
movechessTo(144,3,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,3,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,3,15);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);}
void c0to8(){
movechessTo(144,3,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,3,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,3,15);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c0to9(){
movechessTo(144,3,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,3,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,3,15);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
	
void c1to1(){
movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,27,15);//下降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);


}
void c1to2(){
movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(143,27,15);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c1to3(){
movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,27,15);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c1to4(){
movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(143,27,15);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c1to5(){
	movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,27,15);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
	
}
void c1to6(){
movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,27,15);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c1to7(){
movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,27,18);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c1to8(){
movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,27,18);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}


void movita(int startx,int starty,int endx,int endy)
{
movechessTo(startx,starty,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(startx,starty,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(startx,starty,18);//下降
	  movechessTo(endx,endy,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(endx,endy,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}



void c1to9(){
movechessTo(144,27,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,27,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
	
void c2to1(){
movechessTo(143,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,52,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,52,18);//下降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c2to2(){
movechessTo(144,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(144,52,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(144,52,18);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c2to3(){
movechessTo(144,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,52,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,52,18);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c2to4(){
movechessTo(144,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,52,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(143,52,18);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c2to5(){
movechessTo(144,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,52,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,52,18);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c2to6(){
movechessTo(144,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,27,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,52,18);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c2to7(){
movechessTo(144,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,52,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,52,18);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c2to8(){movechessTo(144,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,52,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(143,52,18);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);}
void c2to9(){
movechessTo(144,52,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,52,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,52,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
	
void c3to1(){
movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,78,18);//下降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c3to2(){
movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,78,18);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c3to3(){
movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,78,18);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c3to4(){
	movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,78,18);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);}
void c3to5(){
movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,78,18);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c3to6(){
movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(143,78,18);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c3to7(){
movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,78,28);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);}
void c3to8(){
movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,78,18);//下降
		delay_ms(500);//等待
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c3to9(){
movechessTo(143,78,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(143,78,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(143,78,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
	
void c4to1(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(142,103,18);//下降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c4to2(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(142,103,18);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c4to3(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(142,103,18);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c4to4(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(142,103,18);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c4to5(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(142,103,18);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c4to6(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(142,103,18);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c4to7(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(142,103,18);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c4to8(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(142,103,18);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c4to9(){
movechessTo(142,103,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(142,103,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(142,103,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
	
void c5to1(){
movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c5to2(){
movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c5to3(){
movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c5to4(){movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);}
void c5to5(){
movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c5to6(){movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);}
void c5to7(){
movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c5to8(){
movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c5to9(){
	movechessTo(9,19,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(9,19,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(9,19,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
	
void c6to1(){
movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(8,47,18);//下降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c6to2(){
movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(8,47,18);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c6to3(){
    movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(8,47,18);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c6to4(){
movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(8,47,18);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c6to5(){
movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(8,47,18);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c6to6(){
movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(8,47,18);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c6to7(){
movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(8,47,18);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c6to8(){
movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(8,47,18);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c6to9(){
movechessTo(8,47,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(8,47,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(8,47,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
	
void c7to1(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(7,70,18);//下降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c7to2(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,70,18);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c7to3(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,70,18);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c7to4(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,70,18);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c7to5(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,70,18);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c7to6(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,70,18);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c7to7(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,70,18);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c7to8(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,70,18);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c7to9(){
movechessTo(7,70,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,70,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(7,70,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
	
void c8to1(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,94,18);//下降
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c8to2(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,94,18);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c8to3(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,94,18);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c8to4(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,94,18);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c8to5(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,94,18);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c8to6(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,94,18);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c8to7(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(7,94,18);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c8to8(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(7,94,18);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);

}
void c8to9(){
movechessTo(7,94,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(7,94,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(7,94,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
	
void c9to1(){
movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(6,119,18);//下降
	  movechessTo(6,119,15);
	  movechessTo(102,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	  delay_ms(200);//
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c9to2(){
movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(6,119,18);//下降
	  movechessTo(73,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c9to3(){movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(6,119,18);//下降
	  movechessTo(43,27,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,27,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);}
void c9to4(){
movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(6,119,18);//下降
	  movechessTo(102,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c9to5(){
movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(6,119,18);//下降
	  movechessTo(73,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c9to6(){
movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(6,119,18);//下降
	  movechessTo(43,56,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,56,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c9to7(){
movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
		movechessTo(6,119,18);//下降
	  movechessTo(102,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(102,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c9to8(){
movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(6,119,18);//下降
	  movechessTo(73,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(73,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
void c9to9(){
movechessTo(6,119,15);//移动棋子上方
		delay_ms(2200);//等待
		movechessTo(6,119,28);//下降
		delay_ms(500);//等待
		catchchess();//开吸
		delay_ms(500);//
	movechessTo(6,119,18);//下降
	  movechessTo(43,85,15);//移动到目标上方
		delay_ms(1000);//等待
		movechessTo(43,85,25);//下降
		delay_ms(1000);//等待
		releasechess(); //放气
	 delay_ms(200);
	  movechessTo(0,0,0);//移动到原点
	  delay_ms(2200);
}
	

