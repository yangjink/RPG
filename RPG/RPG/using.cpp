#pragma once
#include "using.h"

//Set
bool Using::SetName(string name)
{
	_name = name;
	return true;
}
int Using::SetID(int id)
{
	_ID = id;
	return id;
}
int Using::SetNumber(int num)
{
	_number = num;
	return _number;
}
bool Using::SetPercentOrNo(bool per)
{
	_percentOrNo = per;
	return per;
}
int Using::SetAddHP(int addhp)
{
	_addHP = addhp;
	return _addHP;
}
int Using::SetMoney(int money)
{
	_money = money;
	return _money;
}
int Using::SetAddMP(int addmp)
{
	_addMP = addmp;
	return _addMP;
}
//get
int Using::GetID()
{
	return _ID;
}
string Using::GetName()
{
	return _name;
}
int Using::GetNumber()
{
	return _number;
}
bool Using::GetPercentOrNo()
{
	return _percentOrNo;
}
int Using::GetAddHP()
{
	return _addHP;
}
int Using::GetAddMP()
{
	return _addMP;
}
int Using::GetMoney()
{
	return _money;
}
//��û���ʧȥ��Ʒ
int Using::AddNumber(int tag)
{
	++_number;
	cout << "��õ��ˣ�" << _name << "*1" << endl;
	if (tag == 1)
	{
		Sleep(SLEEPTIME);
	}
	return _number;
}
int Using::AddNumber(int& num, int tag)
{
	_number+=num;
	cout << "��õ��ˣ�" << _name << "*" <<num<< endl;
	if (tag == 1)
	{
		Sleep(SLEEPTIME);
	}
	return _number;
}
int Using::DecreaseNumber(int tag)
{
	if (_number > 0)
	{
		--_number;
	}
	cout << "��ʧȥ�ˣ�" << _name << "*1" << endl;
	if (tag == 1)
	{
		Sleep(SLEEPTIME);
	}
	return _number;
}
//��ʹ�ò���Ҫ�������ʱ���Ὣʣ���ȫ��ʹ����
int Using::DecreaseNumber(int& num, int tag)
{
	if (_number - num >= 0)
	{
		_number -= num;
	}
	else
	{
		num = _number;
		_number = 0;
	}
	cout << "��ʧȥ�ˣ�" << _name << "*" << num << endl;
	if (tag == 1)
	{
		Sleep(SLEEPTIME);
	}
	return _number;
}
//�Ƿ���ʹ�õ���Ʒ
bool Using::UseUp()
{
	if (_number <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}