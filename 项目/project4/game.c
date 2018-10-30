#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
void game()
{
    //定义一个棋盘
    char board[ROWS][COLS];
    char ret = 0;
    //初始化棋盘
    init_board(board, ROWS, COLS);
    //展示棋盘
    show_board(board, ROWS, COLS);
    //产生一个随机数种子
    srand((unsigned int)time(NULL));
    while(1)
    {
        //玩家走
        player_move(board, ROWS, COLS);
        //判断玩家是否赢了
        if((ret = ISwin(board, ROWS, COLS)) != ' ')
            break;
        //没有赢就再次展示棋盘
        show_board(board, ROWS, COLS);
        //电脑走
        computer_move(board, ROWS, COLS);
        //判断电脑是否赢了
        if((ret = ISwin(board, ROWS, COLS)) != ' ')
            break;
        //没有赢就再次展示棋盘
        show_board(board, ROWS, COLS);
    }
    //走到这一步说明有人赢了或者平局了
    //那就需要判断谁输谁赢
    if(ret == 'X')
    {
        //玩家赢
        printf("你赢了\n");
    }
    else if(ret == '0')
    {
        //电脑赢
        printf("你输了\n");
    }
    else if(ret == 'q')
    {
        printf("平局！！\n");
    }
    //最后展示棋盘
    show_board(board, ROWS, COLS);
}
//菜单显示
void menu()
{
    printf("*********1.play     0.exit*********\n");
}
int main()
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
        switch(input)
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
    }
    while (input);
    return 0;
}
