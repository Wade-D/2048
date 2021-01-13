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
	int get_score();   //��ȡ����
	void Add();   //����һ����Ԫ��
	bool DrawNum(int i, int j);   //�������ϻ�������
	void DeleteNum(int i, int j);   //��������ɾ������
	void Up();   //��Ϸ�����������ƶ�
	void Down();   //��Ϸ�����������ƶ�
	void Left();   //��Ϸ�����������ƶ�
	void Right();   //��Ϸ�����������ƶ�
	bool CheekFinish();   //�����Ϸ�Ƿ����
	int SearchMax();   //Ѱ�����ϳ���
private:
	int num_[4][4];   //�洢�����ϵ�����
	int empty_;   //��¼�����Ͽո��ӵ�����
	int score_;   //��¼�÷�
};
#endif //NUM_H