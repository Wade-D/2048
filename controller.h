#pragma once
#include "num.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
	void DrawChessboard();   //绘制棋盘
	int GameOver(Num num);   //游戏结束选择窗体
	void Animation();   //开场动画
	void Start();   //游戏一级循环
	int Game(Num num);   //游戏二级循环
};
#endif // CONTROLLER_H