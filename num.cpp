#include "tools.h"
#include "num.h"
#include <iostream>
#include "controller.h"

using namespace std;

/*��ȡ����*/
int Num::get_score()
{
	return score_;
}

/*����һ����Ԫ��*/
void Num::Add()
{
	if (empty_ > 0)   //�������̻����ڿո���ʱ��ִ�����ɲ���
	{
		int randnum = rand() % 100 * 0.01 < 0.75 ? 2 : 4;   //0.75�ĸ��ʳ�4��0.25�ĸ��ʳ�2
		int x = rand() % 4;   //���������Ԫ�ص�����
		int y = rand() % 4;
		int count = 0;   //��¼���������Ԫ�����귢���ĳ�ͻ����
		while (num_[x][y] != 0 && count < 50)   //������ͻʱ�����������꣬���ó�ͻ��������
		{
			x = rand() % 4;
			y = rand() % 4;
			++count;
		}
		if (num_[x][y] != 0 && count == 50)   //������50�γ�ͻ��û�ҵ��ո���ʱ��˵�����̽�������ʱ����˳����ҵ�һ�����õĿո�����Ϊ��Ԫ�ص�����
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
		else   //���򽫵�ǰ������ɵ�������Ϊ��Ԫ�ص�����
		{
			num_[x][y] = randnum;
			--empty_;
			DrawNum(x, y);
		}
	}
}

/*�������ϻ�������*/
bool Num::DrawNum(int i, int j)
{
	if (num_[i][j] == 0)   //0�������Ϊ�գ���Ӧ�û��Ƴ���
		return false;
	int offset = 0;
	WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;   //2��4Ϊ��ɫ
	
	/*Ϊ��ͬ���������ò�ͬ����ɫ��ƫ����*/
	if (num_[i][j] < 100)
	{
		offset = 1;
		if (num_[i][j] >= 8 && num_[i][j] <= 16)
		{
			color = FOREGROUND_GREEN | FOREGROUND_INTENSITY;   //8��16Ϊ��ɫ
		}
		else if (num_[i][j] >= 32 && num_[i][j] <= 64)
		{
			color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;   //32��64Ϊ��ɫ
		}
	}
	else if (num_[i][j] > 100 && num_[i][j] < 10000)
	{
		offset = 0;
		if (num_[i][j] >= 128 && num_[i][j] <= 256)
		{
			color = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;   //128��256Ϊ���ɫ
		}
		else if (num_[i][j] == 512)
		{
			color = FOREGROUND_BLUE | FOREGROUND_INTENSITY;   //512Ϊ��ɫ
		}
	}
	else if (num_[i][j] > 10000 && num_[i][j] < 1000000)
	{
		offset = -1;
		if (num_[i][j] == 1024)
		{
			color = FOREGROUND_BLUE | FOREGROUND_INTENSITY;   //1024Ϊ��ɫ
		}
		else if (num_[i][j] >= 2048)
		{
			color = FOREGROUND_RED | FOREGROUND_INTENSITY;   //2048������Ϊ��ɫ
		}
	}
	else if (num_[i][j] > 1000000)
	{
		offset = -2;
		color = FOREGROUND_RED | FOREGROUND_INTENSITY;   //2048������Ϊ��ɫ
	}
	SetCursorPosition_n(i, j, offset);
	SetColor(color);
	cout << num_[i][j];
	return true;
}

/*��������ɾ������*/
void Num::DeleteNum(int i, int j)
{
	int offset = -2;
	SetCursorPosition_n(i, j, offset);
	cout << "        ";
}

/*��Ϸ�����������ƶ�*/
void Num::Up()
{
	bool flag = false;   //��¼���еĴ������Ƿ������ֺϲ����ƶ�

	/*ÿһ�д��ϵ������μ���·����ڵ����֣����Ƿ�������Ϻϲ������Ƿ���������ƶ�һ��*/
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (num_[i][j] == num_[i + 1][j] && num_[i][j] != 0)   //����Ƿ���Ժ��·����ڵ����ֺϲ�
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
			else if (num_[i][j] == 0 && num_[i + 1][j] != 0)   //����·����ڵ������Ƿ���������ƶ�һ��
			{
				num_[i][j] = num_[i + 1][j];
				num_[i + 1][j] = 0;
				flag = true;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i + 1, j);
			}
		}
		/*��鱾�еĴ������Ƿ������ֺϲ����ƶ���������������Ӧ�ٽ��м�飬ֱ��û�����ֺϲ����ƶ�����*/
		if (flag == true)
		{
			--j;
			flag = false;
		}
	}
}

/*��Ϸ�����������ƶ�*/
void Num::Down()
{
	bool flag = false;   //��¼���еĴ������Ƿ������ֺϲ����ƶ�

	/*ÿһ�д��µ������μ���Ϸ����ڵ����֣����Ƿ�������ºϲ������Ƿ���������ƶ�һ��*/
	for (int j = 0; j < 4; ++j)
	{
		for (int i = 3; i > 0; --i)
		{
			if (num_[i][j] == num_[i - 1][j] && num_[i][j] != 0)   //����Ϸ����ڵ������Ƿ�������ºϲ�
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
			else if (num_[i][j] == 0 && num_[i - 1][j] != 0)   //����Ϸ����ڵ������Ƿ���������ƶ�һ��
			{
				num_[i][j] = num_[i - 1][j];
				num_[i - 1][j] = 0;
				flag = true;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i - 1, j);

			}
		}
		/*��鱾�еĴ������Ƿ������ֺϲ����ƶ���������������Ӧ�ٽ��м�飬ֱ��û�����ֺϲ����ƶ�����*/
		if (flag == true)
		{
			--j;
			flag = false;
		}
	}
}

/*��Ϸ�����������ƶ�*/
void Num::Left()
{
	bool flag = false;   //��¼���еĴ������Ƿ������ֺϲ����ƶ�

	/*ÿһ�д��������μ���ҷ����ڵ����֣����Ƿ��������ϲ������Ƿ���������ƶ�һ��*/
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (num_[i][j] == num_[i][j + 1] && num_[i][j] != 0)   //����ҷ����ڵ������Ƿ��������ϲ�
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
			else if (num_[i][j] == 0 && num_[i][j + 1] != 0)   //����ҷ����ڵ������Ƿ���������ƶ�һ��
			{
				num_[i][j] = num_[i][j + 1];
				num_[i][j + 1] = 0;
				flag = true;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i, j + 1);
			}
		}
		/*��鱾�еĴ������Ƿ������ֺϲ����ƶ���������������Ӧ�ٽ��м�飬ֱ��û�����ֺϲ����ƶ�����*/
		if (flag == true)
		{
			--i;
			flag = false;
		}
	}
}

/*��Ϸ�����������ƶ�*/
void Num::Right()
{
	bool flag = false;   //��¼���еĴ������Ƿ������ֺϲ����ƶ�

	/*ÿһ�д��ҵ������μ�������ڵ����֣����Ƿ�������Һϲ������Ƿ���������ƶ�һ��*/
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 3; j > 0; --j)
		{
			if (num_[i][j] == num_[i][j - 1] && num_[i][j] != 0)   //��������ڵ������Ƿ�������Һϲ�
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
			else if (num_[i][j] == 0 && num_[i][j - 1] != 0)   //��������ڵ������Ƿ���������ƶ�һ��
			{
				num_[i][j] = num_[i][j - 1];
				num_[i][j - 1] = 0;
				flag = true;
				DeleteNum(i, j);
				DrawNum(i, j);
				DeleteNum(i, j - 1);
			}
		}
		/*��鱾�еĴ������Ƿ������ֺϲ����ƶ���������������Ӧ�ٽ��м�飬ֱ��û�����ֺϲ����ƶ�����*/
		if (flag == true)
		{
			--i;
			flag = false;
		}
	}
}

/*�����Ϸ�Ƿ����*/
bool Num::CheekFinish()
{
	bool flag = false;   //��ʾ�Ƿ񻹴��ڿ��Ժϲ�������
	/*����Ƿ����2048*/
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (num_[i][j] == 2048)
			{
				SetCursorPosition_p(24, 11);
				SetColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
				cout << "��ϲ�㣡";
				SetCursorPosition_p(24, 13);
				cout << "�ɹ��ϳ�2048��";
				SetCursorPosition_p(24, 15);
				cout << "����Լ�����Ϸ";
				SetCursorPosition_p(24, 17);
				cout << "Ҳ���԰�Enter������";
				SetCursorPosition_p(0, 19);
			}
		}
	}

	/*����Ƿ񻹴��ڿ��Ժ���ϲ�������*/
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

	/*����Ƿ񻹴��ڿ�������ϲ�������*/
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

	/*��������������û�п��Ժϲ�������ʱ������true��ʾ��Ϸ����*/
	if (flag == false && empty_ == 0)
	{
		return true;
	}
	return false;
}

/*Ѱ�����ϳ���*/
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
