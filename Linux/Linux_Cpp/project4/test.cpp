#include <iostream>
using namespace std;
#include"Management.h"

int main()
{
    srand(time(NULL));
    Manage game;
    game.DrawConfine();
    game.Begin();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

