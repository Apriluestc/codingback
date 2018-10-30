#ifndef __GAME_H__

#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//棋盘的行数和列数
#define ROWS 3
#define COLS 3

//初始化棋盘
void init_board(char board[ROWS][COLS], int row, int col);
//展示棋盘
void show_board(char board[ROWS][COLS], int row, int col);
//玩家落子
void player_move(char board[ROWS][COLS], int row, int col);
//电脑落子
void computer_move(char board[ROWS][COLS], int row, int col);
//判断是否赢了
char ISwin(char board[ROWS][COLS], int row, int col);

#endif //__GAME_H__
