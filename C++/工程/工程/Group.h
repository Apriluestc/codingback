#include "ServeOneClient.h"

#include <iostream>
#include <string>
using namespace std;
#include <malloc.h>

#define ROW 25
#define COL 25
class Group
{
public:
	Group()
	{
		int (*board)[COL] = (int(*)[COL])malloc(sizeof(int)*ROW*COL);
	}
	~Group()
	{
		free(board);
	}
public:
	string self = nullptr;
	ServeOneClient selfSocket;
	string player = nullptr;
	ServeOneClient playerSocket;
	int selfColor = 0;
	int playerColor = 0;
	bool Setting = false;
private:
	int board[ROW][COL];
};