#pragma once
#ifndef TOOLS_H
#define TOOLS_H
#include <windows.h>

void SetWindowSize(int cols, int lines);   //���ô��ڴ�С
void SetCursorPosition_p(const int x, const int y);   //���û�ͼ����λ��
void SetCursorPosition_n(const int x, const int y, int offset);   //�������ֹ��λ��
void SetColor(WORD color);   //�����ı���ɫ
void SetBackColor();   //�����ı�����ɫ

#endif // TOOLS_H