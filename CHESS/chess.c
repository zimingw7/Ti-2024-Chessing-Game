#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "Serial.h"

#define BOARD_SIZE 3
#define EMPTY ' '
char  PLAYER_X  = 'X';// 白
char  PLAYER_O  = 'O';// 黑
extern int play_mode;
int e3 =0;

char board[BOARD_SIZE][BOARD_SIZE]; 
extern gridItem tmp[8];
int gorow,gocol,goc;


// 初始化棋盘
void initialize_board(int initrow,int initcol,char board[BOARD_SIZE][BOARD_SIZE],int mode) {
	
    for (int i=0;i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = EMPTY;
        }
    }
		if (mode == 1){
			PLAYER_X  = 'O';// 白
      PLAYER_O  = 'X';// 黑
		  board[initrow][initcol] =PLAYER_O ;
		}
}

// 打印当前棋盘状态
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// 评估当前局面的得分
int evaluate(char board[BOARD_SIZE][BOARD_SIZE]) {
    // 检查所有可能的获胜情况
    for (int player = 0; player <= 1; ++player) {
        char symbol = (player == 0) ? PLAYER_X : PLAYER_O;
        // 检查行和列
        for (int i = 0; i < BOARD_SIZE; ++i) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
                return (symbol == PLAYER_X) ? 1 : -1;
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
                return (symbol == PLAYER_X) ? 1 : -1;
        }
        // 检查对角线
        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
            return (symbol == PLAYER_X) ? 1 : -1;
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
            return (symbol == PLAYER_X) ? 1 : -1;
    }

    // 如果没有获胜者，检查是否平局
    bool is_full = true;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                is_full = false;
                break;
            }
        }
        if (!is_full) {
            break;
        }
    }
    if (is_full) {
        return 0; // 平局
    }

    return 2; // 游戏未结束
}

// Minimax算法实现
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, bool is_maximizing) {
    int score = evaluate(board);
    if (score != 2) {
        return score;
    }

    if (is_maximizing) {
        int best_score = -1000; // 任意足够小的值
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    int move_score = minimax(board, depth + 1, false);
                    board[i][j] = EMPTY;
                    if (move_score > best_score) {
                        best_score = move_score;
                    }
                }
            }
        }
        return best_score;
    }
    else {
        int best_score = 1000; // 任意足够大的值
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    int move_score = minimax(board, depth + 1, true);
                    board[i][j] = EMPTY;
                    if (move_score < best_score) {
                        best_score = move_score;
                    }
                }
            }
        }
        return best_score;
    }
}

void setE1Num(int mode){
if(mode==1){
	e3=5;
}else{
	e3=0;
}
}



// 计算机走棋的函数，使用Minimax选择最佳位置
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int best_score = -1000; // 任意足够小的值
    int best_move_row = -1;
    int best_move_col = -1;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_X;
                int move_score = minimax(board, 0, false);
                board[i][j] = EMPTY;
                if (move_score > best_score) {
                    best_score = move_score;
                    best_move_row = i;
                    best_move_col = j;
                }
            }
        }
    }

    board[best_move_row][best_move_col] = PLAYER_X;
		
		
		
		LED1_OFF();
		
		
		
	int	c1=best_move_row;
	int d1=	best_move_col;
	    e3++;
		if(e3==10)e3=0;
		
		  if (c1==0&&d1==0){
		switch (e3){
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
		switch (e3){
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
		switch (e3){
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
		switch (e3){
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
		switch (e3){
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
		switch (e3){
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
		switch (e3){
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
		switch (e3){
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
		switch (e3){
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
	 
	TIM3_Stop();	
	LED1_ON();
}

void  Chess_Init(int initrow,int initcol,int mode){
    initialize_board(initrow,initcol,board,mode);
}


// 放到主循环
void play_chess(int row,int col) {
        if (board[row][col] != EMPTY) {
            OLED_ShowString(1,5,"repeat");
					
           //p return;
        }
        board[row][col] = PLAYER_O;

        // 检查玩家是否获胜或者平局
        int result = evaluate(board);
        if (result == 1) {
            OLED_ShowString(2,5,"win");
            //break;
        }
        else if (result == 0) {
           // printf("平局！\n");
          //  break;
        }

        // 计算机走棋
       // printf("计算机正在思考...\n");
        computer_move(board);

        // 检查计算机是否获胜或者平局
        result = evaluate(board);
        if (result == -1) {
            OLED_ShowString(3,5,"lose");
           // break;
        }
        else if (result == 0) {
            //printf("平局！\n");
           // break;
        }
}

/*void compareAndPrint(gridItem tmp[], gridItem back[], int size) {
    for (int i = 0; i < size; ++i) {
        if (tmp[i].x != back[i].x || tmp[i].y != back[i].y || tmp[i].c != back[i].c) {
				//	
					
						if(i<=2) {	
							
									gorow = 0;
									if(i == 1|| i == 4||i == 7) gocol = 0;
					
									else if(i==2||i==5||i==8) gocol = 1;
					 
									else gocol = 2;				
						}
						
					  else if(2<i<=5){ 
								  gorow = 1;
									if(i == 1|| i == 4||i == 7) gocol = 0;
					
									else if(i==2||i==5||i==8) gocol = 1;
					 
									else gocol = 2;
						}
					
						else {
							
					    gorow = 2;
						
						    if(i == 1|| i == 4||i == 7) gocol = 0;
					
					      else if(i==2||i==5||i==8) gocol = 1;
					 
					       else gocol = 2;
          
					 
						}
						goc=tmp[i].c;
        }
    }
		
		////OLED_ShowNum(1,3,gorow,4);
		///OLED_ShowNum(2,3,gocol,4);
		///OLED_ShowNum(3,3,goc,4);
		
		play_chess(gorow,gocol);
}
*/


