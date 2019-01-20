#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 15;	//棋盘大小 15 * 15
const char ChessBoardFlag = ' ';
const char flag1 = 'o';	//玩家1
const char flag2 = 'x';	//玩家2

typedef struct Coordinate	//坐标类
{
	int x;	//行
	int y;	//列
}Coordinate;

class GoBang	//五子棋类
{
public:
	GoBang()	//构造函数对棋盘进行初始化
	{
		InitChessBoard();
	}
	void Play()	//下棋
	{
		Coordinate pos1;	//玩家1
		Coordinate pos2;	//玩家2
		int n = 0; 
		while (1)
		{
			int mode = ChoiceMode();
			while (1)
			{
				if (mode == 1)	//电脑 vs 玩家
				{
					ComputerChess(pos1, flag1);
					if (GetVictory(pos1, 0, flag1) == 1)
						break;
					PlayChess(pos2, 2, flag2);
					if (GetVictory(pos2, 2, flag2))
						break;
				}
				else    //玩家1vs玩家2
				{
					PlayChess(pos1, 1, flag1);
					if (GetVictory(pos1, 1, flag1))
						break;

					PlayChess(pos2, 2, flag2);
					if (GetVictory(pos2, 2, flag2))
						break;
				}
			}
			cout << "***再来一局***" << endl;
			cout << "y or n :";
			char c = 'y';
			cin >> c;
			if (c == 'n')
				break;
		}
	}
protected:
	int ChoiceMode()	//选择模式
	{
		int i = 0;
		system("cls");
		InitChessBoard();
		cout << "***0、退出  1、电脑vs玩家  2、玩家vs玩家***" << endl;
		while (1)
		{
			cout << "请选择：";
			cin >> i;
			if (i == 0)
				exit(1);
			if (i == 1 || i == 2)
				return i;
			cout << "输入不合法" << endl;
		}
	}
	void InitChessBoard()	//初始化棋盘
	{
		int i, j;
		for (i = 0; i < N + 1; ++i)
		{
			for (j = 0; j < N + 1; ++j)
			{
				_ChessBoard[i][j] = ChessBoardFlag;
			}
		}
	}
	void PrintChessBoard()	//打印棋盘
	{
		system("cls");
		for (int i = 0; i < N + 1; ++i)
		{
			for (int j = 0; j < N + 1; ++j)
			{
				if (i == 0)
				{
					if (j != 0)
						printf("%d  ", j);
					else
						printf("   ");
				}
				else if (j == 0)
					printf("%2d ", i);
				else
				{
					if (i < N + 1)
					{
						printf("%c |", _ChessBoard[i][j]);
					}
				}
			}
			cout << endl;
			cout << "   ";
			for (int m = 0; m < N; m++)
			{
				printf("--|");
			}
			cout << endl;
		}
	}
	void PlayChess(Coordinate& pos, int player, int flag)//玩家走
	{
		PrintChessBoard();
		while (1)
		{
			printf("玩家%d输入坐标：", player);
			cin >> pos.x >> pos.y;
			if (JudgeValue(pos) == 1)
				break;
			cout << "坐标不合法，重新输入" << endl;
		}
		_ChessBoard[pos.x][pos.y] = flag;
	}
	void ComputerChess(Coordinate& pos, char flag)	//电脑走
	{
		PrintChessBoard();
		int x = 0;
		int y = 0;
		while (1)
		{
			x = (rand() % N) + 1;
			srand((unsigned int)time(NULL));
			y = (rand() % N) + 1;
			srand((unsigned int)time(NULL));
			if (_ChessBoard[x][y] == ChessBoardFlag)
				break;
		}
		pos.x = x;
		pos.y = y;
		_ChessBoard[pos.x][pos.y] = flag;
	}
	int JudgeValue(const Coordinate& pos)	//判断坐标是否合法
	{
		if (pos.x > 0 && pos.x <= N&&pos.y > 0 && pos.y <= N)
		{
			if (_ChessBoard[pos.x][pos.y] == ChessBoardFlag)
			{
				return 1;
			}
		}
		return 0;
	}
	int JudgeVictory(Coordinate& pos, char flag)	//判断胜负(底层判断）
	{
		int begin = 0;
		int end = 0;

		int begin1 = 0;
		int end1 = 0;

		//判断行是否满足条件
		(pos.y - 4) > 0 ? begin = (pos.y - 4) : begin = 1;
		(pos.y + 4) >N ? end = N : end = (pos.y + 4);

		for (int i = pos.x, j = begin; j + 4 <= end; j++)
		{
			if (_ChessBoard[i][j] == flag&&_ChessBoard[i][j + 1] == flag&&
				_ChessBoard[i][j + 2] == flag&&_ChessBoard[i][j + 3] == flag&&
				_ChessBoard[i][j + 4] == flag)
				return 1;
		}

		//判断列是否满足条件
		(pos.x - 4) > 0 ? begin = (pos.x - 4) : begin = 1;
		(pos.x + 4) > N ? end = N : end = (pos.x + 4);

		for (int j = pos.y, i = begin; i + 4 <= end; i++)
		{
			if (_ChessBoard[i][j] == flag&&_ChessBoard[i + 1][j] == flag&&
				_ChessBoard[i + 2][j] == flag&&_ChessBoard[i + 3][j] == flag&&
				_ChessBoard[i + 4][j] == flag)
				return 1;
		}

		int len = 0;

		//判断主对角线是否满足条件
		pos.x > pos.y ? len = pos.y - 1 : len = pos.x - 1;
		if (len > 4)
			len = 4;
		begin = pos.x - len;       //横坐标的起始位置
		begin1 = pos.y - len;      //纵坐标的起始位置

		pos.x > pos.y ? len = (N - pos.x) : len = (N - pos.y);
		if (len>4)
			len = 4;
		end = pos.x + len;       //横坐标的结束位置
		end1 = pos.y + len;      //纵坐标的结束位置

		for (int i = begin, j = begin1; (i + 4 <= end) && (j + 4 <= end1); ++i, ++j)
		{
			if (_ChessBoard[i][j] == flag&&_ChessBoard[i + 1][j + 1] == flag&&
				_ChessBoard[i + 2][j + 2] == flag&&_ChessBoard[i + 3][j + 3] == flag&&
				_ChessBoard[i + 4][j + 4] == flag)
				return 1;
		}


		//判断副对角线是否满足条件
		(pos.x - 1) >(N - pos.y) ? len = (N - pos.y) : len = pos.x - 1;
		if (len > 4)
			len = 4;
		begin = pos.x - len;//横坐标的起始位置
		begin1 = pos.y + len;//纵坐标的起始位置

		(N - pos.x) > (pos.y - 1) ? len = (pos.y - 1) : len = (N - pos.x);
		if (len>4)
			len = 4;
		end = pos.x + len;//横坐标的结束位置
		end1 = pos.y - len;//纵坐标的结束位置

		for (int i = begin, j = begin1; (i + 4 <= end) && (j - 4 >= end1); ++i, --j)
		{
			if (_ChessBoard[i][j] == flag&&_ChessBoard[i + 1][j - 1] == flag&&
				_ChessBoard[i + 2][j - 2] == flag&&_ChessBoard[i + 3][j - 3] == flag&&
				_ChessBoard[i + 4][j - 4] == flag)
				return 1;
		}


		for (int i = 1; i < N + 1; ++i)//棋盘有没有下满
		{
			for (int j = 1; j < N + 1; ++j)
			{
				if (_ChessBoard[i][j] == ChessBoardFlag)
					return 0;//0表示棋盘没满
			}
		}

		return -1;      //和棋
	}
	bool GetVictory(Coordinate& pos, int player, int flag)	//判断胜负，具体哪个玩家赢
	{
		int n = JudgeVictory(pos, flag);//判断有没有人获胜
		if (n != 0)//有人获胜，0表示没有人获胜
		{
			PrintChessBoard();
			if (n == 1)//有玩家赢棋
			{
				if (player == 0)//0表示电脑获胜，1表示玩家1,2表示玩家2
					printf("***电脑获胜***\n");
				else
					printf("***恭喜玩家%d获胜***\n", player);
			}
			else
				printf("***双方和棋***\n");

			return true;//已经有人获胜
		}
		return false;//没有人获胜
	}
private:
	char _ChessBoard[N + 1][N + 1];
};