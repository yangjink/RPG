#pragma once
#include "define.h"
//������ʹ����Ʒ���������
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
	//�Ƿ񻹿���ʹ��
	bool UseUp();
};