#pragma once
#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point() {}
    Point(const int x, const int y) : x_(x), y_(y) {}
    void Print();   //在点位打印方块字符
    void PrintCircular();   //在点位打印圆形字符
    void Clear();   //清除点位对应的字符
    void ChangePosition(int x, int y);   //改变点位坐标
    bool operator== (const Point& point) { return (point.x_ == this->x_) && (point.y_ == this->y_); }
    int GetX() { return this->x_; }   //获得点位x值
    int GetY() { return this->y_; }   //获得点位y值
private:
    int x_, y_;
};
#endif // POINT_H