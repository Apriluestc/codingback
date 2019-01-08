#pragma once
//坐标类
class Coordinate
{
public:
    Coordinate(int X, int Y)
    {
        x = X;
        y = Y;
    }
    Coordinate()
    {}
    bool operator == (const Coordinate& a)
    {
        return a.x == x && a.y == y;
    }
    bool operator != (const Coordinate& a)
    {
        return !(a.x == x && a.y == y);
    }
    Coordiinate& operator = (const Coordinate& a)
    {
        x = a.x;
        y = a.y;
    }
    int x, y;
    //~Coordinate() {}

//private:

};

