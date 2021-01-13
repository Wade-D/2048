#include <iostream>
#include <time.h>
#include "conio.h"
#include "controller.h"
#include "tools.h"
#include "startinterface.h"
#include "num.h"
#include <windows.h>
using namespace std;

/*��������*/
void Controller::DrawChessboard()
{
	system("cls");
	//����1
	/*
	for (int y = 1; y <= 17; ++y)
	{
		if (y == 1 || y == 5 || y == 9 || y == 13 || y == 17)
		{
			for (int x = 1; x <= 21; ++x)
			{
				SetCursorPosition_p(x, y);
				SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "��";
				Sleep(10);
			}
		}
		else
		{
			for (int x = 1; x <= 21; x += 5)
			{
				SetCursorPosition_p(x, y);
				SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << "��";
				Sleep(10);
			}
		}
	}
	*/

	//����2
	/*
	for (int y = 1; y <= 17; y += 4)
	{
		for (int x = 1; x <= 21; ++x)
		{
			SetCursorPosition_p(x, y);
			SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "��";
			Sleep(10);
		}
	}
	for (int x = 1; x <= 21; ++x)
	{
		for (int y = 1; y <= 17; y += 4)
		{
			SetCursorPosition_p(x, y);
			SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "��";
			Sleep(10);
		}
	}
	*/
	
	//����3
	/*��ӡ������*/
	for (int x = 1; x <= 21; ++x)
	{
		int y = 1;
		for (int n = 1; n <= 5; ++n)
		{
			SetCursorPosition_p(x, y);
			SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "��";
			y += 4;
		}
		Sleep(30);
	}
	/*��ӡ������*/
	for (int y = 1; y <= 17; ++y)
	{
		int x = 1;
		for (int n = 1; n <= 5; ++n)
		{
			SetCursorPosition_p(x, y);
			SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << "��";
			x += 5;
		}
		Sleep(30);
	}
	Sleep(100);
	/*��ӡ��Ϸ�����ҷ�˵��*/
	SetCursorPosition_p(24, 1);
	SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "2 0 4 8";
	SetCursorPosition_p(24, 4);
	cout << "�÷֣�0";
	SetCursorPosition_p(24, 7);
	cout << "����������ƶ�";
	SetCursorPosition_p(24, 9);
	cout << "Enter��������Ϸ";
	Sleep(100);
}

/*��Ϸ����ѡ����*/
int Controller::GameOver(Num num)
{
	/*������Ϸ��������*/
	Sleep(100);
	SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	SetCursorPosition_p(6, 5);
	cout << "��������������������������������������������������������������������������������������";
	Sleep(10);
	SetCursorPosition_p(5, 6);
	cout << " ��             -  Game  Over  -             �� ";
	Sleep(10);
	SetCursorPosition_p(5, 7);
	cout << " ��                                          �� ";
	Sleep(10);
	SetCursorPosition_p(5, 8);
	cout << " ��                 �÷�:                    �� ";
	SetCursorPosition_p(18, 8);
	cout << num.get_score();
	Sleep(10);
	SetCursorPosition_p(5, 9);
	cout << " ��             ���ϳ���:                  �� ";
	SetCursorPosition_p(19, 9);
	cout << num.SearchMax();
	Sleep(10);
	SetCursorPosition_p(5, 10);
	cout << " ��                                          �� ";
	Sleep(10);
	SetCursorPosition_p(5, 11);
	cout << " ��        ���¿�ʼ          ������Ϸ        �� ";
	Sleep(10);
	SetCursorPosition_p(5, 12);
	cout << " ��                                          �� ";
	Sleep(10);
	SetCursorPosition_p(6, 13);
	cout << "��������������������������������������������������������������������������������������";
	Sleep(10);
	SetCursorPosition_p(10, 11);
	SetBackColor();
	cout << "���¿�ʼ";
	SetCursorPosition_p(0, 19);
	SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	/*ѡ��������˳�*/
	int ch;
	int tmp_key = 1;   //��¼��ǰ��ѡ��1�������¿�ʼ��2���������Ϸ��
	bool flag = false;   //��¼�Ƿ��»س�ѡ��
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75:   //���¡������
			if (tmp_key > 1)
			{
				SetCursorPosition_p(10, 11);
				SetBackColor();
				cout << "���¿�ʼ";
				SetCursorPosition_p(19, 11);
				SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "������Ϸ";
				--tmp_key;
			}
			break;

		case 77:   //���¡������
			if (tmp_key < 2)
			{
				SetCursorPosition_p(19, 11);
				SetBackColor();
				cout << "������Ϸ";
				SetCursorPosition_p(10, 11);
				SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "���¿�ʼ";
				++tmp_key;
			}
			break;

		case 13:   //����Enter��
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
		return 1;   //���¿�ʼ
	case 2:
		return 2;   //�˳���Ϸ
	default:
		return 1;
	}
	
}

/*��������*/
void Controller::Animation()
{
	StartInterface start;
	start.Action();
}

/*��Ϸһ��ѭ��*/
void Controller::Start()
{
	Animation();   //��������
	while (true)   //��Ϸһ��ѭ��
	{
		Num num;
		DrawChessboard();
		num.Add();
		num.Add();
		SetCursorPosition_p(0, 19);
		int flag = Game(num);   //������Ϸ����ѭ��
		if (flag == 1)   //����ֵΪ1ʱ���¿�ʼ��Ϸ
		{
			continue;
		}
		else   //����ֵΪ2ʱ������Ϸ
		{
			break;
		}
	}
}

/*��Ϸ����ѭ��*/
int Controller::Game(Num num)
{
	int ch;
	bool flag = false;
	while ((ch = _getch()))   //��Ϸ����ѭ��
	{
		switch (ch)
		{
		case 72:    //���¡������
			num.Up();
			num.Add();
			break;
		case 80:    //���¡������
			num.Down();
			num.Add();
			break;
		case 75:    //���¡������
			num.Left();
			num.Add();
			break;
		case 77:    //���¡������
			num.Right();
			num.Add();
			break;
		case 13:   //���»س���������Ϸ
			flag = true;
			break;
		default:
			break;
		}

		SetCursorPosition_p(24, 4);
		SetColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "�÷֣�" << num.get_score();   //�������ϸ��µ÷�
		SetCursorPosition_p(0, 19);
		if (flag == true)   //���»س���������Ϸ
		{
			return 2;
		}
		if (num.CheekFinish() == true)   //������������û�п��Ժϲ�������ʱ����GameOver����
		{
			return GameOver(num);
		}
	}
}