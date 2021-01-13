#pragma once
#include "num.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
	void DrawChessboard();   //��������
	int GameOver(Num num);   //��Ϸ����ѡ����
	void Animation();   //��������
	void Start();   //��Ϸһ��ѭ��
	int Game(Num num);   //��Ϸ����ѭ��
};
#endif // CONTROLLER_H