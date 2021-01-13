#include <iostream>
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
using namespace std;

int main()
{
	SetWindowSize(33, 20);
	Controller game;
	game.Start();
	return 0;
}