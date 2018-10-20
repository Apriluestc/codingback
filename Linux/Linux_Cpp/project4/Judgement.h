#pragma once
#include<iomanip>
#include"Snake.h"
//边界
const int confineX = 20;
const int confineY = 10;
//等级坐标
const Coordinate _score(confineX + 5, 4);
const Coordinate _level(confineY + 5, 7);

const int Level[6] = {0, 400, 300, 200, 100, 50};//每个等级对应的时间间隔单位(毛秒)
const int Score[6] = {0, 10, 30, 60, 100, 150};//每个等级对应的分数值

class Judgement
{
public:
    //构造函数
    Judgement(int l, int u, int r, int d)
        :level(1)
         ,score(0)
         ,left(1)
         ,up(u)
         ,right(r)
         ,down(d)
    {}

    int direction;
    int level;
    int score;
    int left, up, right, down;
    //~Judgement() {}

bool::Judge Death(Snake& snake)
{
    ChangeNext(snake);
    if(snake.next.x > =confineX || snake.next.x < 0)
    {
        return true;
    }
    else if(snake.next.y >=confineY || snake.next.y < 0)
    {
        return true;
    }
    else
    {
        for(list<Coordinate>::iterator i = snake.snakebody.begin(); i != snake.snakebody.cend(); i++)
        {
            if((*i) == snake.next)
            {
                return true;
            }
        }
    }
    return false;

}

bool Judge::ChangeSorce()
{
    score += level;
    gotoxy(_score);
    cout<<setw(5)<<score;

    if(score >= Score[level])
    {
        level++;
        if(level > 5)
        {
            return true;
        }
        gotoxy(_level);
        cout<<setw(5)<<level;
    }
    return false;
}
void Judge::ChangeDriection(Snake& snake)
{
    if(direction == left || direction == right)
    {
        if(GetAsyncKeyState(up))
        {
            direction = up;
        }
        else if(GetAsyncKeyState(down))
        {
            direction = down;
        }
    }
    else
    {
        if(GetAsyncKeyState(left))
        {
            direction = left;
        }
        else if(GetAsyncKeyState(right))
        {
            direction = right;
        }
    }
}
void Judge::ChangeNext(Snake& snake)
{
    ChangeDriction(snake);
    if(direction == up)
    {
        snake.next.y--;
    }
    else if(direction == left)
    {
        snake.next.x--;
    }
    else if(direction == down)
    {
        snake.next.y++;
    }
    else if(direction == right)
    {
        snake.next.x++;
    }
}
