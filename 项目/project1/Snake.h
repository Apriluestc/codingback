#pragma once
//蛇类
#include<iostream>
#include<list>
using namespace std;

class Snake
{
public:
    Snake();
    void AddHead();
    void SubtractTail();
    Coordinate next;
    list<Coordinate> snakebody;

    //~Snake() {}

//private:

};
Snake::Snake()
{
    next = Coordinate(3, 0);
    for(int n = 0, m = 0; n < 4;n++)
    {
        snakebody.push_front(Coordinate(n, m));
    }
}

void Snake::AddHead()
{
    gotoxy(next);
    cout<<"#";
    snakebody.push_front(next);

}

void Snake::SubtractTail()
{
    gotoxy(snakebody.back());
    cout<<" ";
    snakebody.pop_back();
}
