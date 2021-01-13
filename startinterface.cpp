#include "startinterface.h"
#include "tools.h"
#include <windows.h>

/*Step1：将0和4向下移动*/
void StartInterface::move_0_4()
{
    MoveNum(num_0_, 0, -11);   //先将字符0移动到窗口上边缘
    MoveNum(num_4_, 0, -11);   //先将字符4移动到窗口上边缘
    while (num_0_.back().GetY() < 10 && num_4_.back().GetY() < 10)   //字符0和4没有到达指定位置时不停移动
    {
        /*清除原来的0，向下移动一格并打印新的0*/
        ClearNum(num_0_);
        MoveNum(num_0_, 0, 1);
        SetColor(FOREGROUND_BLUE);
        PrintNum(num_0_);

        /*清除原来的4，向下移动一格并打印新的4*/
        ClearNum(num_4_);
        MoveNum(num_4_, 0, 1);
        SetColor(FOREGROUND_RED | FOREGROUND_GREEN);
        PrintNum(num_4_);

        Sleep(speed_);
    }
}

/*Step2：将2和8向中间移动*/
void StartInterface::move_2_8()
{
    MoveNum(num_2_, -11, 0);   //先将字符2移动到窗口左边缘
    MoveNum(num_8_, 11, 0);   //先将字符8移动到窗口右边缘
    while (num_2_.back().GetX() < 10 && num_8_.back().GetX() > 25)   //字符2和8没有到达指定位置时不停移动
    {
        /*清除原来的2，向右移动一格并打印新的2*/
        ClearNum(num_2_);
        MoveNum(num_2_, 1, 0);
        SetColor(FOREGROUND_GREEN);
        PrintNum(num_2_);

        /*清除原来的8，向左移动一格并打印新的8*/
        ClearNum(num_8_);
        MoveNum(num_8_, -1, 0);
        SetColor(FOREGROUND_RED);
        PrintNum(num_8_);

        Sleep(speed_);
    }
}

/*Step3：将2048刷新（更换为高亮颜色）*/
void StartInterface::Refresh()
{
    Sleep(300);

    /*刷新字符2*/
    SetColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (auto& point : num_2_)
    {
        point.PrintCircular();
        SetCursorPosition_p(0, 19);
        Sleep(speed_);
    }

    /*刷新字符0*/
    SetColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for (auto& point : num_0_)
    {
        point.PrintCircular();
        SetCursorPosition_p(0, 19);
        Sleep(speed_);
    }

    /*刷新字符4*/
    SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (auto& point : num_4_)
    {
        point.PrintCircular();
        SetCursorPosition_p(0, 19);
        Sleep(speed_);
    }

    /*刷新字符8*/
    SetColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (auto& point : num_8_)
    {
        point.PrintCircular();
        SetCursorPosition_p(0, 19);
        Sleep(speed_);
    }
}

/*Step4：将2048整体向右移动*/
void StartInterface::move_2048()
{
    while (num_2_.front().GetX() < 33)   //最左边的字符2没有完全消失在窗体右边缘时，2048不停向右移动
    {
        /*清除原来的2，向右移动一格并打印新的2*/
        ClearNum(num_2_);
        MoveNum(num_2_, 1, 0);
        SetColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        PrintNum(num_2_);

        /*清除原来的0，向右移动一格并打印新的0*/
        ClearNum(num_0_);
        MoveNum(num_0_, 1, 0);
        SetColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        PrintNum(num_0_);

        /*清除原来的4，向右移动一格并打印新的4*/
        ClearNum(num_4_);
        MoveNum(num_4_, 1, 0);
        SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        PrintNum(num_4_);

        /*清除原来的8，向右移动一格并打印新的8*/
        ClearNum(num_8_);
        MoveNum(num_8_, 1, 0);
        SetColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        PrintNum(num_8_);

        Sleep(speed_);
    }
}

/*在控制台上打印一个字符数字*/
void StartInterface::PrintNum(vector<Point> num)
{
    for (auto& point : num)
    {
        if (point.GetX() >= 0 && point.GetX() <= 32 && point.GetY() >= 0 && point.GetY() <= 19)   //点位位于窗体内部时才打印
        {
           point.PrintCircular();
           SetCursorPosition_p(0, 19);
        }
    }
}

/*在控制台上清除一个字符数字*/
void StartInterface::ClearNum(vector<Point> num)
{
    for (auto& point : num)
    {
        if (point.GetX() >= 0 && point.GetX() <= 32 && point.GetY() >= 0 && point.GetY() <= 19)   //点位位于窗体内部时才清除
        {
            point.Clear();
            SetCursorPosition_p(0, 19);
        }
    }
}

/*改变一个字符数字的点位信息*/
void StartInterface::MoveNum(vector<Point>& num, int x, int y)
{
    for (auto& point : num)
    {
        point.ChangePosition(point.GetX() + x, point.GetY() + y);
    }
}

/*执行动画*/
void StartInterface::Action()
{
    move_0_4();   //Step1
    move_2_8();   //Step2
    Refresh();   //Step3

    SetCursorPosition_p(12, 17);
    SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("pause");   //等待用户响应

    move_2048();   //Step4

    SetCursorPosition_p(0, 19);
}
