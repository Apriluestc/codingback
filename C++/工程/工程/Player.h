#pragma once
#include "ServeOneClient.h"
#include <iostream>
#include <string>
using namespace std;

class Player
{
	string self = nullptr;
	ServeOneClient selfSocket;
	bool setting = false;
	int color = 1;
public:
	Player()
	{}
};