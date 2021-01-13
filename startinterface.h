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
        /*数字2*/
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

        /*数字0*/
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

        /*数字4*/
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

        /*数字8*/
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
    void move_0_4();   //Step1：将0和4向下移动
    void move_2_8();   //Step2：将2和8向中间移动
    void Refresh();   //Step3：将2048刷新（更换为高亮颜色）
    void move_2048();   //Step4：将2048整体向右移动
    void PrintNum(vector<Point> num);   //在控制台上打印一个字符数字
    void ClearNum(vector<Point> num);   //在控制台上清除一个字符数字
    void MoveNum(vector<Point>& num, int x, int y);   //改变一个字符数字的点位信息
    void Action();   //执行动画
private:
    vector<Point> num_2_;   //存储字符数字2的点位
    vector<Point> num_0_;   //存储字符数字0的点位
    vector<Point> num_4_;   //存储字符数字4的点位
    vector<Point> num_8_;   //存储字符数字8的点位
    int speed_;   //动画的速度
};
#endif // STRATINTERFACE_H