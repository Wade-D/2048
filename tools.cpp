#include "tools.h"
#include <windows.h>
#include <stdio.h>

/*���ô��ڴ�С*/
void SetWindowSize(int cols, int lines)
{
    system("title 2048");//���ô��ڱ���
    char cmd[30];
    sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);   //һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
    system(cmd);   //system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

/*���û�ͼ����λ��*/
void SetCursorPosition_p(const int x, const int y)
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

/*�������ֹ��λ��*/
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

/*�����ı���ɫ*/
void SetColor(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*�����ı�����ɫ*/
void SetBackColor()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_BLUE |
        BACKGROUND_BLUE |
        BACKGROUND_GREEN |
        BACKGROUND_RED);
}