#pragma once
#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point() {}
    Point(const int x, const int y) : x_(x), y_(y) {}
    void Print();   //�ڵ�λ��ӡ�����ַ�
    void PrintCircular();   //�ڵ�λ��ӡԲ���ַ�
    void Clear();   //�����λ��Ӧ���ַ�
    void ChangePosition(int x, int y);   //�ı��λ����
    bool operator== (const Point& point) { return (point.x_ == this->x_) && (point.y_ == this->y_); }
    int GetX() { return this->x_; }   //��õ�λxֵ
    int GetY() { return this->y_; }   //��õ�λyֵ
private:
    int x_, y_;
};
#endif // POINT_H