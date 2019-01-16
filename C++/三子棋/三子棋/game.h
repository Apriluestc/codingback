#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int g_N = 3;
const char g_ChessFlag = ' ';

typedef struct Coordinate	//坐标类
{
	int x;
	int y;
}Coordinate;

class TicTocTae
{
public:
	TicTocTae()	//棋盘初始化
	{
		InitChessBoard();
	}
	//菜单显示
	void menu()
	{
		printf("*********1.play     0.exit*********\n");
	}
	void game()
	{
		//定义一个棋盘
		char ChessBoard[g_N][g_N];
		char ret = 0;
		//初始化棋盘
		InitChessBoard();
		//展示棋盘
		show_board(ChessBoard, g_N, g_N);
		//产生一个随机数种子
		srand((unsigned int)time(NULL));
		while (1)
		{
			//玩家走
			player_move(ChessBoard, g_N, g_N);
			//判断玩家是否赢了
			if ((ret = ISwin(ChessBoard, g_N, g_N)) != ' ')
				break;
			//没有赢就再次展示棋盘
			show_board(ChessBoard, g_N, g_N);
			//电脑走
			computer_move(ChessBoard, g_N, g_N);
			//判断电脑是否赢了
			if ((ret = ISwin(ChessBoard, g_N, g_N)) != ' ')
				break;
			//没有赢就再次展示棋盘
			show_board(ChessBoard, g_N, g_N);
		}
		//走到这一步说明有人赢了或者平局了
		//那就需要判断谁输谁赢
		if (ret == 'X')
		{
			//玩家赢
			printf("你赢了\n");
		}
		else if (ret == '0')
		{
			//电脑赢
			printf("你输了\n");
		}
		else if (ret == 'q')
		{
			printf("平局！！\n");
		}
		//最后展示棋盘
		show_board(ChessBoard, g_N, g_N);
	}
	//棋盘显示
	void show_board(char board[g_N][g_N], int row, int col)
	{
		int i = 0;
		for (i = 0; i<row; i++)
		{
			printf(" %c | %c | %c \n",
				board[i][0], board[i][1], board[i][2]);
			if (i != 2)
				printf("---|---|---\n");
		}
	}
	void test()
	{
		int input = 0;
		do
		{
			//打印菜单
			menu();
			//玩家选择
			printf("请选择：");
			scanf("%d", &input);
			//判断玩家选择并作出相应的回应
			//开始游戏或者退出游戏
			switch (input)
			{
			case 1:
				//开始游戏
				game();
				break;
			case 0:
				//退出游戏
				break;
			default:
				printf("选择错误\n");
				break;
			}
		} while (input);
	}
protected:
	void InitChessBoard()
	{
		int i, j;
		for (i = 0; i < g_N + 1; ++i)
		{
			for (j = 0; j < g_N + 1; ++j)
			{
				_ChessBoard[i][j] = g_ChessFlag;
			}
		}
	}
	//判断输赢
	char ISwin(char ChessBoard[g_N][g_N], int row, int col)
	{
		int i = 0;
		//某行三子一样
		for (i = 0; i<row; i++)
		{
			//一行的3个位置的标记一样且不能为初始化设置的空
			if ((ChessBoard[i][0] == ChessBoard[i][1])
				&& (ChessBoard[i][1] == ChessBoard[i][2])
				&& (ChessBoard[i][1] != ' '))
				//返回被标记的值（X或者0）
				return ChessBoard[i][1];
		}
		//某列三子一样
		for (i = 0; i<col; i++)
		{
			//一列的3个位置的标记一样且不能为初始化设置的空
			if ((ChessBoard[0][i] == ChessBoard[1][i])
				&& (ChessBoard[1][i] == ChessBoard[2][i])
				&& (ChessBoard[1][i] != ' '))
				//返回被标记的值（X或者0）
				return ChessBoard[1][i];
		}
		//对角线三子一样(有两条对角线)
		if ((ChessBoard[0][0] == ChessBoard[1][1])
			&& (ChessBoard[1][1] == ChessBoard[2][2])
			&& (ChessBoard[1][1] != ' '))
			//返回被标记的值（X或者0）
			return ChessBoard[1][1];
		if ((ChessBoard[0][2] == ChessBoard[1][1])
			&& (ChessBoard[1][1] == ChessBoard[2][0])
			&& (ChessBoard[1][1] != ' '))
			//返回被标记的值（X或者0）
			return ChessBoard[1][1];
		//走到这里说明没有人赢，但有可能达成了平局
		//此时就需要判断一下棋盘是否满了
		//如果满了而又没有人赢了说明达成了平局
		if (ISfull(ChessBoard, row, col))
		{
			//棋盘满了，返回q表示平局
			return 'q';
		}
		//走到这里说明没有人赢也没有平局则返回一个初始化设置的空
		//来代表这种情况，游戏继续往下进行
		return ' ';
	}
	//判断棋盘是否下满，未满返回0 满了返回1
	static int ISfull(char ChessBoard[g_N][g_N], int row, int col)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i<row; i++)
		{
			for (j = 0; j<col; j++)
			{
				if (ChessBoard[i][j] == ' ')
					return 0;
			}
		}
		return 1;
	}
	//玩家落子
	void player_move(char ChessBoard[g_N][g_N], int row, int col)
	{
		int x = 0;
		int y = 0;
		while (1)
		{
			printf("玩家走\n");
			printf("请输入坐标:如1 2\n");
			scanf("%d%d", &x, &y);
			//数组下标从零开始，而人的习惯是从1开始，因此读入数据以后减一
			x--;
			y--;
			//判断下标是否有效
			if (((x >= 0) && (x <= 2)) && ((y >= 0) && (y <= 2)))
			{
				//如果该位置没有被走过
				if (ChessBoard[x][y] == ' ')
				{
					//则可以落子，将其标记为X代表被玩家走过
					ChessBoard[x][y] = 'X';
					break;
				}
				else
				{
					//否则不能落子
					printf("下标有误, 重新输入！");
				}
			}
			else
			{
				//下标不合法
				printf("下标有误, 重新输入！");
			}
		}
	}
	//电脑落子
	void computer_move(char ChessBoard[g_N][g_N], int row, int col)
	{
		printf("电脑走\n");
		while (1)
		{
			//随机产生横纵左边的值
			int x = rand() % 3;
			int y = rand() % 3;
			//如果该位置没有被走过
			if (ChessBoard[x][y] == ' ')
			{
				//将其标记为0代表电脑走过
				ChessBoard[x][y] = '0';
				break;
			}
		}
	}
private:
	char _ChessBoard[g_N + 1][g_N + 1];
};