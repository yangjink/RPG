#pragma once
#include "define.h"
//������ʹ����Ʒ���������
enum percent{
	NOPERCENT = 0,
	PERCENT = 1
};
class Using
{
private:
	int _ID;//ȫ�ֱ�ʶ
	string _name;
	int _money;//��ֵǮ��
	int _number;//���ڵ�����
	//��Ѫ��
	int _addHP;
	int _addMP;

	bool _percentOrNo;//�Ƿ�ٷֱȻ�Ѫ
public:
	//Set
	bool SetName(string);
	int SetID(int);
	int SetNumber(int);
	bool SetPercentOrNo(bool);
	int SetAddHP(int);
	int SetMoney(int);
	int SetAddMP(int);
	//get
	int GetID();
	string GetName();
	int GetNumber();
	bool GetPercentOrNo();
	int GetAddHP();
	int GetAddMP();
	int GetMoney();
	//��û���ʧȥ��Ʒ
	int AddNumber(int);
	int AddNumber(int&, int);
	int DecreaseNumber(int);
	int DecreaseNumber(int&, int);
	//��Ʒ��Ϣ
	/*ͬʱ return 1 ����ʹ��  -1 ����  0 ʲôҲ����*/
	int PrintInfo(int in_npc = 0);
	//ʹ����Ʒ����Ϣ
	bool PringUsingInfo();
	
	//�Ƿ񻹿���ʹ��
	bool UseUp();
};
//ȫ�ֽ�һ��
class UsingMap
{
private:
	map<int,Using> _usingMap;
	map<int, Using>::iterator _itr_using;
public:
	//ͨ��id�ҵ���Ӧ����Ʒ��Ϣ
	Using GetUsing(const int&);
	//��map�в���һ������Ʒ
	bool PushUsing(Using&);
	//�ܹ�������
	int GetSize();
	//��ʼ��
	bool InitItr();
	//next
	bool Next();
	//end
	bool End();
	//��ǰ��Ʒ����Ϣ
	Using GetCurUsing();
};