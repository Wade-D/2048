#include "point.h"
#include "tools.h"
#include <iostream>

/*�ڵ�λ��ӡ�����ַ�*/
void Point::Print()
{
    SetCursorPosition_p(x_, y_);
    std::cout << "��";
}

/*�ڵ�λ��ӡԲ���ַ�*/
void Point::PrintCircular()
{
    SetCursorPosition_p(x_, y_);
    std::cout << "��";
}

/*�����λ��Ӧ���ַ�*/
void Point::Clear()
{
    SetCursorPosition_p(x_, y_);
    std::cout << "  ";
}

/*�ı��λ����*/
void Point::ChangePosition(int x, int y)
{
    this->x_ = x;
    this->y_ = y;
}