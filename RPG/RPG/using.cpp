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

//物品信息
/*同时 return 1 决定使用  -1 丢弃  0 什么也不干*/
int Using::PrintInfo(int in_npc)
{
	string userinput;
	cout << "-------------------物品信息------------------" << endl;
	cout << "名称: " << _name << endl;
	cout << "数量: " << _number << endl;
	cout << "价格: " << _money << endl;
	cout << "信息: ";
	//不是任务物品
	if (_addHP != 0 || _addMP != 0)
	{
		cout << "回复";
		if (_addHP != 0)
		{
			cout << "生命：";
			if (_percentOrNo == PERCENT)
			{
				cout << _addHP << "%";
			}
			else
			{
				cout << _addHP;
			}
		}
		if (_addMP != 0)
		{
			cout << "生命：";
			if (_percentOrNo == PERCENT)
			{
				cout << _addMP << "%";
			}
			else
			{
				cout << _addMP;
			}
		}
	}
	else
	{
		cout << "平常物品";
	}
	cout << endl;
	print_line_sep();
	if (in_npc == 1)//买
	{
		cout << "1:购买 ";
	}
	else if (in_npc == 2)//卖
	{
		cout << "1:卖出";
	}
	else
	{
		cout << "1:丢弃";
		if (_addHP != 0 || _addMP != 0)
		{
			cout << "2:使用";
		}
	}
	cout << "0:返回"<<endl;
	print_line_sep();
	while (1)
	{
		cin >> userinput;
		if (userinput[0] == '0')
		{
			return 0;
		}
		if (userinput[0] == '2' && (_addHP != 0 || _addMP != 0))
		{
			return 1;
		}
		if (userinput[0] == '1')
		{
			return -1;
		}
	}
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