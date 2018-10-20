#pragma once
#include"Coordinate.h"
#include<windows.h>

void gotoxy(Coordinate a)
{
    COORD local;
    local.X = a.x;
    local.Y = a.y;
    SetConsoleCursorPosition(GetStdHandle(SID_OUTPUT_HANDLE), local);
}
