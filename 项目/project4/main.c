#include "game.h"

//初始化棋盘全为空格
void init_board(char board[ROWS][COLS], int row, int col)
{
    memset(board, ' ', col*row*sizeof(char));
}
//棋盘显示
void show_board(char board[ROWS][COLS], int row,int col)
{
    int i = 0;
    for(i=0; i<row; i++)
    {
        printf(" %c | %c | %c \n",
            board[i][0],board[i][1],board[i][2]);
        if(i != 2)
            printf("---|---|---\n");
    }
}
//玩家落子
void player_move(char board[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    while(1)
    {
        printf("玩家走\n");
        printf("请输入坐标:如1 2\n");
        scanf("%d%d", &x, &y);
        //数组下标从零开始，而人的习惯是从1开始，因此读入数据以后减一
        x--;
        y--;
        //判断下标是否有效
        if( ((x>=0)&&(x<=2)) && ((y>=0)&&(y<=2)) )
        {
            //如果该位置没有被走过
            if(board[x][y] == ' ')
            {
                //则可以落子，将其标记为X代表被玩家走过
                board[x][y] = 'X';
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
void computer_move(char board[ROWS][COLS], int row, int col)
{
    printf("电脑走\n");
    while(1)
    {
        //随机产生横纵左边的值
        int x = rand()%3;
        int y = rand()%3;
        //如果该位置没有被走过
        if(board[x][y] == ' ')
        {
            //将其标记为0代表电脑走过
            board[x][y] = '0';
            break;
        }
    }
}
//判断棋盘是否下满，未满返回0 满了返回1
static int ISfull(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}
//判断输赢
char ISwin(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    //某行三子一样
    for(i=0; i<row; i++)
    {
        //一行的3个位置的标记一样且不能为初始化设置的空
        if((board[i][0]==board[i][1])
            &&(board[i][1]==board[i][2])
            &&(board[i][1]!=' '))
            //返回被标记的值（X或者0）
            return board[i][1];
    }
    //某列三子一样
    for(i=0; i<col; i++)
    {
        //一列的3个位置的标记一样且不能为初始化设置的空
        if((board[0][i]==board[1][i])
            &&(board[1][i]==board[2][i])
            &&(board[1][i]!=' '))
            //返回被标记的值（X或者0）
            return board[1][i];
    }
    //对角线三子一样(有两条对角线)
    if((board[0][0]==board[1][1])
        &&(board[1][1]==board[2][2])
        &&(board[1][1]!=' '))
        //返回被标记的值（X或者0）
        return board[1][1];
    if((board[0][2]==board[1][1])
        &&(board[1][1]==board[2][0])
        &&(board[1][1]!=' '))
        //返回被标记的值（X或者0）
        return board[1][1];
    //走到这里说明没有人赢，但有可能达成了平局
    //此时就需要判断一下棋盘是否满了
    //如果满了而又没有人赢了说明达成了平局
    if(ISfull(board, row, col))
    {
        //棋盘满了，返回q表示平局
        return 'q';
    }
    //走到这里说明没有人赢也没有平局则返回一个初始化设置的空
    //来代表这种情况，游戏继续往下进行
    return ' ';
}
