#include "point.h"
#include "tools.h"
#include <iostream>

/*在点位打印方块字符*/
void Point::Print()
{
    SetCursorPosition_p(x_, y_);
    std::cout << "■";
}

/*在点位打印圆形字符*/
void Point::PrintCircular()
{
    SetCursorPosition_p(x_, y_);
    std::cout << "●";
}

/*清除点位对应的字符*/
void Point::Clear()
{
    SetCursorPosition_p(x_, y_);
    std::cout << "  ";
}

/*改变点位坐标*/
void Point::ChangePosition(int x, int y)
{
    this->x_ = x;
    this->y_ = y;
}