#include <iostream>
#include <time.h>
#include "conio.h"
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "num.h"
#include <windows.h>
using namespace std;

/*绘制棋盘*/
void Controller::DrawChessboard()
{
	system("cls");
	//画法1
	/*
	for (int y = 1; y <= 17; ++y)
	{
		if (y == 1 || y == 5 || y == 9 || y == 13 || y == 17)
		{
			for (int x = 1; x <= 21; ++x)
			{
				SetCursorPosition_p(x, y);
				SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "■";
				Sleep(10);
			}
		}
		else
		{
			for (int x = 1; x <= 21; x += 5)
			{
				SetCursorPosition_p(x, y);
				SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "■";
				Sleep(10);
			}
		}
	}
	*/

	//画法2
	/*
	for (int y = 1; y <= 17; y += 4)
	{
		for (int x = 1; x <= 21; ++x)
		{
			SetCursorPosition_p(x, y);
			SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "●";
			Sleep(10);
		}
	}
	for (int x = 1; x <= 21; ++x)
	{
		for (int y = 1; y <= 17; y += 4)
		{
			SetCursorPosition_p(x, y);
			SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "●";
			Sleep(10);
		}
	}
	*/
	
	//画法3
	/*打印棋盘行*/
	for (int x = 1; x <= 21; ++x)
	{
		int y = 1;
		for (int n = 1; n <= 5; ++n)
		{
			SetCursorPosition_p(x, y);
			SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "●";
			y += 4;
		}
		Sleep(30);
	}
	/*打印棋盘列*/
	for (int y = 1; y <= 17; ++y)
	{
		int x = 1;
		for (int n = 1; n <= 5; ++n)
		{
			SetCursorPosition_p(x, y);
			SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "●";
			x += 5;
		}
		Sleep(30);
	}
	Sleep(100);
	/*打印游戏窗体右方说明*/
	SetCursorPosition_p(24, 1);
	SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "2 0 4 8";
	SetCursorPosition_p(24, 4);
	cout << "得分：0";
	SetCursorPosition_p(24, 7);
	cout << "方向键控制移动";
	SetCursorPosition_p(24, 9);
	cout << "Enter键结束游戏";
	Sleep(100);
}

/*游戏结束选择窗体*/
int Controller::GameOver(Num num)
{
	/*绘制游戏结束窗体*/
	Sleep(100);
	SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetCursorPosition_p(6, 5);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(10);
	SetCursorPosition_p(5, 6);
	cout << " ┃             -  Game  Over  -             ┃ ";
	Sleep(10);
	SetCursorPosition_p(5, 7);
	cout << " ┃                                          ┃ ";
	Sleep(10);
	SetCursorPosition_p(5, 8);
	cout << " ┃                 得分:                    ┃ ";
	SetCursorPosition_p(18, 8);
	cout << num.get_score();
	Sleep(10);
	SetCursorPosition_p(5, 9);
	cout << " ┃             最大合成数:                  ┃ ";
	SetCursorPosition_p(19, 9);
	cout << num.SearchMax();
	Sleep(10);
	SetCursorPosition_p(5, 10);
	cout << " ┃                                          ┃ ";
	Sleep(10);
	SetCursorPosition_p(5, 11);
	cout << " ┃        重新开始          结束游戏        ┃ ";
	Sleep(10);
	SetCursorPosition_p(5, 12);
	cout << " ┃                                          ┃ ";
	Sleep(10);
	SetCursorPosition_p(6, 13);
	cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(10);
	SetCursorPosition_p(10, 11);
	SetBackColor();
	cout << "重新开始";
	SetCursorPosition_p(0, 19);
	SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	/*选择继续或退出*/
	int ch;
	int tmp_key = 1;   //记录当前的选择（1代表重新开始，2代表结束游戏）
	bool flag = false;   //记录是否按下回车选中
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75:   //按下←方向键
			if (tmp_key > 1)
			{
				SetCursorPosition_p(10, 11);
				SetBackColor();
				cout << "重新开始";
				SetCursorPosition_p(19, 11);
				SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "结束游戏";
				--tmp_key;
			}
			break;

		case 77:   //按下→方向键
			if (tmp_key < 2)
			{
				SetCursorPosition_p(19, 11);
				SetBackColor();
				cout << "结束游戏";
				SetCursorPosition_p(10, 11);
				SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "重新开始";
				++tmp_key;
			}
			break;

		case 13:   //按下Enter键
			flag = true;
			break;

		default:
			break;
		}

		SetCursorPosition_p(0, 19);
		if (flag) {
			break;
		}
	}

	SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	switch (tmp_key)
	{
	case 1:
		return 1;   //重新开始
	case 2:
		return 2;   //退出游戏
	default:
		return 1;
	}
	
}

/*开场动画*/
void Controller::Animation()
{
	StartInterface start;
	start.Action();
}

/*游戏一级循环*/
void Controller::Start()
{
	Animation();   //开场动画
	while (true)   //游戏一级循环
	{
		Num num;
		DrawChessboard();
		num.Add();
		num.Add();
		SetCursorPosition_p(0, 19);
		int flag = Game(num);   //进入游戏二级循环
		if (flag == 1)   //返回值为1时重新开始游戏
		{
			continue;
		}
		else   //返回值为2时结束游戏
		{
			break;
		}
	}
}

/*游戏二级循环*/
int Controller::Game(Num num)
{
	int ch;
	bool flag = false;
	while ((ch = _getch()))   //游戏二级循环
	{
		switch (ch)
		{
		case 72:    //按下↑方向键
			num.Up();
			num.Add();
			break;
		case 80:    //按下↓方向键
			num.Down();
			num.Add();
			break;
		case 75:    //按下←方向键
			num.Left();
			num.Add();
			break;
		case 77:    //按下→方向键
			num.Right();
			num.Add();
			break;
		case 13:   //按下回车键结束游戏
			flag = true;
			break;
		default:
			break;
		}

		SetCursorPosition_p(24, 4);
		SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "得分：" << num.get_score();   //在棋盘上更新得分
		SetCursorPosition_p(0, 19);
		if (flag == true)   //按下回车键结束游戏
		{
			return 2;
		}
		if (num.CheekFinish() == true)   //棋盘已满并且没有可以合并的数字时弹出GameOver窗体
		{
			return GameOver(num);
		}
	}
}