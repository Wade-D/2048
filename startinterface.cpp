#include "startinterface.h"
#include "tools.h"
#include <windows.h>

/*Step1����0��4�����ƶ�*/
void StartInterface::move_0_4()
{
    MoveNum(num_0_, 0, -11);   //�Ƚ��ַ�0�ƶ��������ϱ�Ե
    MoveNum(num_4_, 0, -11);   //�Ƚ��ַ�4�ƶ��������ϱ�Ե
    while (num_0_.back().GetY() < 10 && num_4_.back().GetY() < 10)   //�ַ�0��4û�е���ָ��λ��ʱ��ͣ�ƶ�
    {
        /*���ԭ����0�������ƶ�һ�񲢴�ӡ�µ�0*/
        ClearNum(num_0_);
        MoveNum(num_0_, 0, 1);
        SetColor(FOREGROUND_BLUE);
        PrintNum(num_0_);

        /*���ԭ����4�������ƶ�һ�񲢴�ӡ�µ�4*/
        ClearNum(num_4_);
        MoveNum(num_4_, 0, 1);
        SetColor(FOREGROUND_RED | FOREGROUND_GREEN);
        PrintNum(num_4_);

        Sleep(speed_);
    }
}

/*Step2����2��8���м��ƶ�*/
void StartInterface::move_2_8()
{
    MoveNum(num_2_, -11, 0);   //�Ƚ��ַ�2�ƶ����������Ե
    MoveNum(num_8_, 11, 0);   //�Ƚ��ַ�8�ƶ��������ұ�Ե
    while (num_2_.back().GetX() < 10 && num_8_.back().GetX() > 25)   //�ַ�2��8û�е���ָ��λ��ʱ��ͣ�ƶ�
    {
        /*���ԭ����2�������ƶ�һ�񲢴�ӡ�µ�2*/
        ClearNum(num_2_);
        MoveNum(num_2_, 1, 0);
        SetColor(FOREGROUND_GREEN);
        PrintNum(num_2_);

        /*���ԭ����8�������ƶ�һ�񲢴�ӡ�µ�8*/
        ClearNum(num_8_);
        MoveNum(num_8_, -1, 0);
        SetColor(FOREGROUND_RED);
        PrintNum(num_8_);

        Sleep(speed_);
    }
}

/*Step3����2048ˢ�£�����Ϊ������ɫ��*/
void StartInterface::Refresh()
{
    Sleep(300);

    /*ˢ���ַ�2*/
    SetColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (auto& point : num_2_)
    {
        point.PrintCircular();
        SetCursorPosition_p(0, 19);
        Sleep(speed_);
    }

    /*ˢ���ַ�0*/
    SetColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    for (auto& point : num_0_)
    {
        point.PrintCircular();
        SetCursorPosition_p(0, 19);
        Sleep(speed_);
    }

    /*ˢ���ַ�4*/
    SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    for (auto& point : num_4_)
    {
        point.PrintCircular();
        SetCursorPosition_p(0, 19);
        Sleep(speed_);
    }

    /*ˢ���ַ�8*/
    SetColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
    for (auto& point : num_8_)
    {
        point.PrintCircular();
        SetCursorPosition_p(0, 19);
        Sleep(speed_);
    }
}

/*Step4����2048���������ƶ�*/
void StartInterface::move_2048()
{
    while (num_2_.front().GetX() < 33)   //����ߵ��ַ�2û����ȫ��ʧ�ڴ����ұ�Եʱ��2048��ͣ�����ƶ�
    {
        /*���ԭ����2�������ƶ�һ�񲢴�ӡ�µ�2*/
        ClearNum(num_2_);
        MoveNum(num_2_, 1, 0);
        SetColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        PrintNum(num_2_);

        /*���ԭ����0�������ƶ�һ�񲢴�ӡ�µ�0*/
        ClearNum(num_0_);
        MoveNum(num_0_, 1, 0);
        SetColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        PrintNum(num_0_);

        /*���ԭ����4�������ƶ�һ�񲢴�ӡ�µ�4*/
        ClearNum(num_4_);
        MoveNum(num_4_, 1, 0);
        SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        PrintNum(num_4_);

        /*���ԭ����8�������ƶ�һ�񲢴�ӡ�µ�8*/
        ClearNum(num_8_);
        MoveNum(num_8_, 1, 0);
        SetColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        PrintNum(num_8_);

        Sleep(speed_);
    }
}

/*�ڿ���̨�ϴ�ӡһ���ַ�����*/
void StartInterface::PrintNum(vector<Point> num)
{
    for (auto& point : num)
    {
        if (point.GetX() >= 0 && point.GetX() <= 32 && point.GetY() >= 0 && point.GetY() <= 19)   //��λλ�ڴ����ڲ�ʱ�Ŵ�ӡ
        {
           point.PrintCircular();
           SetCursorPosition_p(0, 19);
        }
    }
}

/*�ڿ���̨�����һ���ַ�����*/
void StartInterface::ClearNum(vector<Point> num)
{
    for (auto& point : num)
    {
        if (point.GetX() >= 0 && point.GetX() <= 32 && point.GetY() >= 0 && point.GetY() <= 19)   //��λλ�ڴ����ڲ�ʱ�����
        {
            point.Clear();
            SetCursorPosition_p(0, 19);
        }
    }
}

/*�ı�һ���ַ����ֵĵ�λ��Ϣ*/
void StartInterface::MoveNum(vector<Point>& num, int x, int y)
{
    for (auto& point : num)
    {
        point.ChangePosition(point.GetX() + x, point.GetY() + y);
    }
}

/*ִ�ж���*/
void StartInterface::Action()
{
    move_0_4();   //Step1
    move_2_8();   //Step2
    Refresh();   //Step3

    SetCursorPosition_p(12, 17);
    SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("pause");   //�ȴ��û���Ӧ

    move_2048();   //Step4

    SetCursorPosition_p(0, 19);
}
