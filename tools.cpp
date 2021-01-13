#include "tools.h"
#include <windows.h>
#include <stdio.h>

/*设置窗口大小*/
void SetWindowSize(int cols, int lines)
{
    system("title 2048");//设置窗口标题
    char cmd[30];
    sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);   //一个图形■占两个字符，故宽度乘以2
    system(cmd);   //system(mode con cols=88 lines=88)设置窗口宽度和高度
}

/*设置绘图点光标位置*/
void SetCursorPosition_p(const int x, const int y)
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

/*设置数字光标位置*/
void SetCursorPosition_n(const int i, const int j, int offset)
{
    COORD position;
    if (i == 0)
    {
        position.Y = 3;
    }
    else
    {
        position.Y = 3 + i * 4;
    }
    if (j == 0)
    {
        position.X = 6 + offset;
    }
    else
    {
        position.X = 6 + j * 10 + offset;
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

/*设置文本颜色*/
void SetColor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*设置文本背景色*/
void SetBackColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_BLUE |
        BACKGROUND_BLUE |
        BACKGROUND_GREEN |
        BACKGROUND_RED);
}