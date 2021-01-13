#pragma once
#ifndef STRATINTERFACE_H
#define STARTINTERFACE_H

#include <deque>
#include <vector>
#include "point.h"
using namespace std;

class StartInterface
{
public:
    StartInterface() : speed_(35) {
        /*����2*/
        num_2_.emplace_back(Point(7, 8));
        num_2_.emplace_back(Point(7, 11));
        num_2_.emplace_back(Point(8, 7));
        num_2_.emplace_back(Point(8, 10));
        num_2_.emplace_back(Point(8, 11));
        num_2_.emplace_back(Point(9, 7));
        num_2_.emplace_back(Point(9, 9));
        num_2_.emplace_back(Point(9, 11));
        num_2_.emplace_back(Point(10, 8));
        num_2_.emplace_back(Point(10, 11));

        /*����0*/
        num_0_.emplace_back(Point(12, 8));
        num_0_.emplace_back(Point(12, 9));
        num_0_.emplace_back(Point(12, 10));
        num_0_.emplace_back(Point(13, 7));
        num_0_.emplace_back(Point(13, 11));
        num_0_.emplace_back(Point(14, 7));
        num_0_.emplace_back(Point(14, 11));
        num_0_.emplace_back(Point(15, 8));
        num_0_.emplace_back(Point(15, 9));
        num_0_.emplace_back(Point(15, 10));

        /*����4*/
        num_4_.emplace_back(Point(17, 9));
        num_4_.emplace_back(Point(17, 10));
        num_4_.emplace_back(Point(18, 8));
        num_4_.emplace_back(Point(18, 10));
        num_4_.emplace_back(Point(19, 7));
        num_4_.emplace_back(Point(19, 8));
        num_4_.emplace_back(Point(19, 9));
        num_4_.emplace_back(Point(19, 10));
        num_4_.emplace_back(Point(19, 11));
        num_4_.emplace_back(Point(20, 10));

        /*����8*/
        num_8_.emplace_back(Point(22, 8));
        num_8_.emplace_back(Point(22, 10));
        num_8_.emplace_back(Point(23, 7));
        num_8_.emplace_back(Point(23, 9));
        num_8_.emplace_back(Point(23, 11));
        num_8_.emplace_back(Point(24, 7));
        num_8_.emplace_back(Point(24, 9));
        num_8_.emplace_back(Point(24, 11));
        num_8_.emplace_back(Point(25, 8));
        num_8_.emplace_back(Point(25, 10));
    }
    void move_0_4();   //Step1����0��4�����ƶ�
    void move_2_8();   //Step2����2��8���м��ƶ�
    void Refresh();   //Step3����2048ˢ�£�����Ϊ������ɫ��
    void move_2048();   //Step4����2048���������ƶ�
    void PrintNum(vector<Point> num);   //�ڿ���̨�ϴ�ӡһ���ַ�����
    void ClearNum(vector<Point> num);   //�ڿ���̨�����һ���ַ�����
    void MoveNum(vector<Point>& num, int x, int y);   //�ı�һ���ַ����ֵĵ�λ��Ϣ
    void Action();   //ִ�ж���
private:
    vector<Point> num_2_;   //�洢�ַ�����2�ĵ�λ
    vector<Point> num_0_;   //�洢�ַ�����0�ĵ�λ
    vector<Point> num_4_;   //�洢�ַ�����4�ĵ�λ
    vector<Point> num_8_;   //�洢�ַ�����8�ĵ�λ
    int speed_;   //�������ٶ�
};
#endif // STRATINTERFACE_H