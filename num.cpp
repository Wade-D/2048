#include "tools.h"
#include "num.h"
#include <iostream>
#include "controller.h"

using namespace std;

/*获取分数*/
int Num::get_score()
{
	return score_;
}

/*增加一个新元素*/
void Num::Add()
{
	if (empty_ > 0)   //仅当棋盘还存在空格子时才执行生成操作
	{
		int randnum = rand() % 100 * 0.01 < 0.75 ? 2 : 4;   //0.75的概率出4；0.25的概率出2
		int x = rand() % 4;   //随机生成新元素的坐标
		int y = rand() % 4;
		int count = 0;   //记录随机生成新元素坐标发生的冲突次数
		while (num_[x][y] != 0 && count < 50)   //发生冲突时重新生成坐标，并让冲突次数自增
		{
			x = rand() % 4;
			y = rand() % 4;
			++count;
		}
		if (num_[x][y] != 0 && count == 50)   //当发生50次冲突还没找到空格子时，说明棋盘较慢，此时按行顺序查找第一个可用的空格子作为新元素的坐标
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (num_[i][j] == 0)
					{
						num_[i][j] = randnum;
						--empty_;
						DrawNum(i, j);
					}
				}
			}
		}
		else   //否则将当前随机生成的坐标作为新元素的坐标
		{
			num_[x][y] = randnum;
			--empty_;
			DrawNum(x, y);
		}
	}
}

/*在棋盘上绘制数字*/
bool Num::DrawNum(int i, int j)
{
	if (num_[i][j] == 0)   //0代表格子为空，不应该绘制出来
		return false;
	int offset = 0;
	WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;   //2和4为白色
	
	/*为不同的数字设置不同的颜色和偏移量*/
	if (num_[i][j] < 100)
	{
		offset = 1;
		if (num_[i][j] >= 8 && num_[i][j] <= 16)
		{
			color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;   //8和16为绿色
		}
		else if (num_[i][j] >= 32 && num_[i][j] <= 64)
		{
			color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;   //32和64为黄色
		}
	}
	else if (num_[i][j] > 100 && num_[i][j] < 10000)
	{
		offset = 0;
		if (num_[i][j] >= 128 && num_[i][j] <= 256)
		{
			color = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;   //128和256为洋红色
		}
		else if (num_[i][j] == 512)
		{
			color = FOREGROUND_BLUE | FOREGROUND_INTENSITY;   //512为蓝色
		}
	}
	else if (num_[i][j] > 10000 && num_[i][j] < 1000000)
	{
		offset = -1;
		if (num_[i][j] == 1024)
		{
			color = FOREGROUND_BLUE | FOREGROUND_INTENSITY;   //1024为蓝色
		}
		else if (num_[i][j] >= 2048)
		{
			color = FOREGROUND_RED | FOREGROUND_INTENSITY;   //2048及以上为红色
		}
	}
	else if (num_[i][j] > 1000000)
	{
		offset = -2;
		color = FOREGROUND_RED | FOREGROUND_INTENSITY;   //2048及以上为红色
	}
	SetCursorPosition_n(i, j, offset);
	SetColor(color);
	cout << num_[i][j];
	return true;
}

/*在棋盘上删除数字*/
void Num::DeleteNum(int i, int j)
{
	int offset = -2;
	SetCursorPosition_n(i, j, offset);
	cout << "        ";
}

/*游戏操作：向上移动*/
void Num::Up()
{
	bool flag = false;   //记录本列的处理中是否发生数字合并或移动

	/*每一列从上到下依次检查下方相邻的数字（①是否可以向上合并；②是否可以向上移动一格）*/
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (num_[i][j] == num_[i + 1][j] && num_[i][j] != 0)   //检查是否可以和下方相邻的数字合并
			{
				num_[i][j] *= 2;
				num_[i + 1][j] = 0;
				score_ += num_[i][j];
				flag = true;
				++empty_;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i + 1, j);
			}
			else if (num_[i][j] == 0 && num_[i + 1][j] != 0)   //检查下方相邻的数字是否可以向上移动一格
			{
				num_[i][j] = num_[i + 1][j];
				num_[i + 1][j] = 0;
				flag = true;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i + 1, j);
			}
		}
		/*检查本列的处理中是否发生数字合并或移动，若发生，则本列应再进行检查，直到没有数字合并或移动发生*/
		if (flag == true)
		{
			--j;
			flag = false;
		}
	}
}

/*游戏操作：向下移动*/
void Num::Down()
{
	bool flag = false;   //记录本列的处理中是否发生数字合并或移动

	/*每一列从下到上依次检查上方相邻的数字（①是否可以向下合并；②是否可以向下移动一格）*/
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 3; i > 0; --i)
		{
			if (num_[i][j] == num_[i - 1][j] && num_[i][j] != 0)   //检查上方相邻的数字是否可以向下合并
			{
				num_[i][j] *= 2;
				num_[i - 1][j] = 0;
				score_ += num_[i][j];
				flag = true;
				++empty_;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i - 1, j);
			}
			else if (num_[i][j] == 0 && num_[i - 1][j] != 0)   //检查上方相邻的数字是否可以向下移动一格
			{
				num_[i][j] = num_[i - 1][j];
				num_[i - 1][j] = 0;
				flag = true;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i - 1, j);

			}
		}
		/*检查本列的处理中是否发生数字合并或移动，若发生，则本列应再进行检查，直到没有数字合并或移动发生*/
		if (flag == true)
		{
			--j;
			flag = false;
		}
	}
}

/*游戏操作：向左移动*/
void Num::Left()
{
	bool flag = false;   //记录本行的处理中是否发生数字合并或移动

	/*每一行从左到右依次检查右方相邻的数字（①是否可以向左合并；②是否可以向左移动一格）*/
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (num_[i][j] == num_[i][j + 1] && num_[i][j] != 0)   //检查右方相邻的数字是否可以向左合并
			{
				num_[i][j] *= 2;
				num_[i][j + 1] = 0;
				score_ += num_[i][j];
				flag = true;
				++empty_;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i, j + 1);
			}
			else if (num_[i][j] == 0 && num_[i][j + 1] != 0)   //检查右方相邻的数字是否可以向左移动一格
			{
				num_[i][j] = num_[i][j + 1];
				num_[i][j + 1] = 0;
				flag = true;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i, j + 1);
			}
		}
		/*检查本行的处理中是否发生数字合并或移动，若发生，则本行应再进行检查，直到没有数字合并或移动发生*/
		if (flag == true)
		{
			--i;
			flag = false;
		}
	}
}

/*游戏操作：向右移动*/
void Num::Right()
{
	bool flag = false;   //记录本行的处理中是否发生数字合并或移动

	/*每一行从右到左依次检查左方相邻的数字（①是否可以向右合并；②是否可以向右移动一格）*/
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j > 0; --j)
		{
			if (num_[i][j] == num_[i][j - 1] && num_[i][j] != 0)   //检查左方相邻的数字是否可以向右合并
			{
				num_[i][j] *= 2;
				num_[i][j - 1] = 0;
				score_ += num_[i][j];
				flag = true;
				++empty_;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i, j - 1);
			}
			else if (num_[i][j] == 0 && num_[i][j - 1] != 0)   //检查左方相邻的数字是否可以向右移动一格
			{
				num_[i][j] = num_[i][j - 1];
				num_[i][j - 1] = 0;
				flag = true;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i, j - 1);
			}
		}
		/*检查本行的处理中是否发生数字合并或移动，若发生，则本行应再进行检查，直到没有数字合并或移动发生*/
		if (flag == true)
		{
			--i;
			flag = false;
		}
	}
}

/*检查游戏是否结束*/
bool Num::CheekFinish()
{
	bool flag = false;   //表示是否还存在可以合并的数字
	/*检测是否出现2048*/
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (num_[i][j] == 2048)
			{
				SetCursorPosition_p(24, 11);
				SetColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "恭喜你！";
				SetCursorPosition_p(24, 13);
				cout << "成功合成2048！";
				SetCursorPosition_p(24, 15);
				cout << "你可以继续游戏";
				SetCursorPosition_p(24, 17);
				cout << "也可以按Enter键结束";
				SetCursorPosition_p(0, 19);
			}
		}
	}

	/*检测是否还存在可以横向合并的数字*/
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (num_[i][j] == num_[i][j + 1])
			{
				flag = true;
			}
		}
	}

	/*检测是否还存在可以纵向合并的数字*/
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (num_[i][j] == num_[i + 1][j])
			{
				flag = true;
			}
		}
	}

	/*当棋盘已满并且没有可以合并的数字时，返回true表示游戏结束*/
	if (flag == false && empty_ == 0)
	{
		return true;
	}
	return false;
}

/*寻找最大合成数*/
int Num::SearchMax()
{
	int maxnum = 2;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (num_[i][j] > maxnum)
			{
				maxnum = num_[i][j];
			}
		}
	}
	return maxnum;
}
