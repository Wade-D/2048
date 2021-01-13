#pragma once
#ifndef TOOLS_H
#define TOOLS_H
#include <windows.h>

void SetWindowSize(int cols, int lines);   //设置窗口大小
void SetCursorPosition_p(const int x, const int y);   //设置绘图点光标位置
void SetCursorPosition_n(const int x, const int y, int offset);   //设置数字光标位置
void SetColor(WORD color);   //设置文本颜色
void SetBackColor();   //设置文本背景色

#endif // TOOLS_H