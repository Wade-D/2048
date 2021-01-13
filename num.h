#pragma once
#ifndef NUM_H
#define NUM_H

class Num
{
public:
	Num()
	{
		empty_ = 4 * 4;
		score_ = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				num_[i][j] = 0;
			}
		}
	}
	int get_score();   //获取分数
	void Add();   //增加一个新元素
	bool DrawNum(int i, int j);   //在棋盘上绘制数字
	void DeleteNum(int i, int j);   //在棋盘上删除数字
	void Up();   //游戏操作：向上移动
	void Down();   //游戏操作：向下移动
	void Left();   //游戏操作：向左移动
	void Right();   //游戏操作：向右移动
	bool CheekFinish();   //检查游戏是否结束
	int SearchMax();   //寻找最大合成数
private:
	int num_[4][4];   //存储棋盘上的数字
	int empty_;   //记录棋盘上空格子的数量
	int score_;   //记录得分
};
#endif //NUM_H