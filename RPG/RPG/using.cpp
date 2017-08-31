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
//获得或者失去物品
int Using::AddNumber(int tag)
{
	++_number;
	cout << "你得到了：" << _name << "*1" << endl;
	if (tag == 1)
	{
		Sleep(SLEEPTIME);
	}
	return _number;
}
int Using::AddNumber(int& num, int tag)
{
	_number+=num;
	cout << "你得到了：" << _name << "*" <<num<< endl;
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
	cout << "你失去了：" << _name << "*1" << endl;
	if (tag == 1)
	{
		Sleep(SLEEPTIME);
	}
	return _number;
}
//当使用不够要求的数量时，会将剩余的全部使用完
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
	cout << "你失去了：" << _name << "*" << num << endl;
	if (tag == 1)
	{
		Sleep(SLEEPTIME);
	}
	return _number;
}
//打印物品信息
bool Using::PringUsingInfo()
{
	cout << _name;
	if (_addHP != 0 || _addMP != 0)
	{
		cout << "(";
		if (_addHP != 0)
		{
			cout << "HP:";
			if (_percentOrNo == PERCENT)
			{
				cout << _addHP << "%";
			}
			else
			{
				cout << _addHP << " ";
			}
		}
		if (_addMP != 0)
		{
			cout << "MP:";
			if (_percentOrNo == PERCENT)
			{
				cout << _addMP << "%";
			}
			else
			{
				cout << _addMP << " ";
			}
		}
		cout << ")";
	}
	else
	{
		cout << "(物品)";
	}
	cout << "*" << _number << endl;
	return true;
}

//是否是使用的物品
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

//通过id找到对应的物品信息
Using UsingMap::GetUsing(const int& id)
{
	return _usingMap.find(id)->second;
}
//往map中插入一条新的信息
bool UsingMap::PushUsing(Using& use)
{
	return _usingMap.insert(make_pair(use.GetID(), use)).second;
}

//总共的数量
int UsingMap::GetSize()
{
	return _usingMap.size();
}

//初始化
bool UsingMap::InitItr()
{
	_itr_using = _usingMap.begin();
	return true;
}
//next
bool UsingMap::Next()
{
	if (_itr_using != _usingMap.end())
	{
		return false;
	}
	return true;
}
//end
bool UsingMap::End()
{
	if (_itr_using != _usingMap.end())
	{
		return false;
	}
	return true;
}
//当前物品的信息
Using UsingMap::GetCurUsing()
{
	return (_itr_using->second);
}