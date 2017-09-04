#pragma once
#include "role.h"

//设置信息
int Role::SetName(string n)
{
	_name = n;
	return 1;
}
int Role::SetMoney(int m)
{
	_money = m;
	return m;
}
int Role::SetHP(int hp)
{
	_HP = hp;
	return _HP;
}
int Role::SetHPmax(int hpm)
{
	_HPmax = hpm;
	return _HPmax;
}
int Role::SetMP(int mp)
{
	_MP = mp;
	return _MP;
}
int Role::SetMPmax(int mpm)
{
	_MPmax = mpm;
	return _MPmax;
}
int Role::SetExp(int exp)
{
	_exp = exp;
	return _exp;
}
int Role::SetExpMax(int expm)
{
	_expMax = expm;
	return _expMax;
}
int Role::SetLevel(int l)
{
	_level = l;
	return l;
}
int Role::SetAttackPoint(int attack)
{
	_attackPoint = attack;
	return _attackPoint;
}
int Role::SetDefendPoint(int defend)
{
	_defendPoint = defend;
	return _defendPoint;
}

//设置背包
bool Role::InitUsingItr()
{
	_itr_using = _usingList.begin();
	return true;
}
bool Role::NextUsingItr()
{
	if (_itr_using != _usingList.end())
	{
		++_itr_using;
		return true;
	}
	return false;
}
bool Role::EndUsingItr()
{
	return _itr_using == _usingList.end();
}
Using Role::GetCurUsing()
{
	return *_itr_using;
}

//放入东西
int Role::PickUp(Using& use)
{
	int usingid = use.GetID();
	for (_itr_using = _usingList.begin(); _itr_using != _usingList.end(); ++_itr_using)
	if (_itr_using->GetID() == usingid)/* have*/
	{
		_itr_using->AddNumber(1);
		return 1;
	}
	_usingList.push_back(use);
	_usingList.back().AddNumber(1);
	return 1;
}
int Role::PickUp(Using& use, int num)
{
	int usingid = use.GetID();
	for (_itr_using = _usingList.begin(); _itr_using != _usingList.end(); ++_itr_using)
	if (_itr_using->GetID() == usingid)/* have*/
	{
		_itr_using->AddNumber(num,1);
		return 1;
	}
	_usingList.push_back(use);
	_usingList.back().AddNumber(num,1);
	return 1;
}
int Role::PickUp(Weapon)
{
	return 1;
}


//出售东西(尚未完善)
int Role::Sell()
{
	return 1;
}
//返回基本信息
string Role::GetName()
{
	return _name;
}
int Role::GetMoney()
{
	return _money;
}
int Role::GetHP()
{
	return _HP;
}
int Role::GetHPmax()
{
	return _HPmax;
}
int Role::GetMP()
{
	return _MP;
}
int Role::GetMPmax()
{
	return _MPmax;
}
int Role::GetExp()
{
	return _exp;
}
int Role::GetExpMax()
{
	return _expMax;
}
int Role::GetLevel()
{
	return _level;
}
int Role::GetAttackPoint()
{
	return _attackPoint;
}
int Role::GetDefendPoint()
{
	return _defendPoint;
}

//改变属性,再设定一个参数，1打印，0不打印
int Role::ChangeMoney(const int& changemoney)
{
	_money += changemoney;
	cout << "你获得了:" << changemoney << "银两" << endl;
	return changemoney;
}
int Role::ChangeName(const string changename)
{
	_name = changename;
	return 1;
}
int Role::ChangeHP(const int& hp,const int& tag)
{
	int tmp = hp;
	if (tmp >= _HPmax - _HP)
	{
		tmp = _HPmax - _HP;
	}
	_HP += tmp;
	if (tag && hp > 0)
	{
		cout << "你回复了" << tmp << "点生命" << endl;
		Sleep(SLEEPTIME);
	}

	return _HP;
}
int Role::ChangeHPmax(const int& hpm)
{
	_HPmax += hpm;
	return _HPmax;
}
//失败返回-1,因为有可能刚好使用完之后剩0MP
int Role::ChangeMP(const int& mp, const int& tag)
{
	int tmp = mp;
	if((tmp + _MP) < 0)
	{
		return -1;
	}
	if (tmp >= (_MPmax - _MP))
	{
		tmp = _MPmax - _MP;
	}
	_MP += tmp;
	if (tag)
	{
		cout << "你回复了" << tmp << "点魔法值" << endl;
		Sleep(SLEEPTIME);
	}

	return _MP;
}

int Role::ChangeExpMax(const int& exp)
{
	_expMax += exp;
	return _expMax;
}

int Role::ChangeExp(const int& exp, const int& tag)
{
	int tmp = exp;
	if (tag)
	{
		cout << "你获得了" << exp << "点经验" << endl;
		Sleep(SLEEPTIME);
	}
	while (tmp > (_expMax - _exp))
	{
		tmp -= (_expMax - _exp);
		LevelUp();
	}
	_exp += tmp;
	return 1;
}

//打印角色基本信息
int Role::PrintHead()
{
	int pointlength = 40;//头部长度
	int temp;
	system("cls");
	cout << _name << "   等级: " << _level << "   银两: " << _money << endl;
	cout << "HP: ";
	temp = int(float(_HP)/float(_HPmax)*pointlength);
	for (int i = 0; i < pointlength;i++)
	{
		if (i < temp)
		{
			cout << "|";
		}
		else
		{
			cout << ".";
		}
	}
	cout << endl;
	//mp
	cout << "MP: ";
	temp = int(float(_MP) / float(_MPmax)*pointlength);
	for (int i = 0; i < pointlength; i++)
	{
		if (i < temp)
		{
			cout << "|";
		}
		else
		{
			cout << ".";
		}
	}
	cout << endl;

	cout << "EXP: "<<_exp<<"/"<<_expMax<<endl;
	
	for (int i = 0; i < pointlength + 10; i++)
		cout << "-";
	cout << endl;

	return 1;
}

//升级
int Role::LevelUp()
{
	_expMax = (20 * _level + 40);
	//属性升级
	_HPmax += 20;
	_HP = _HPmax;
	_MPmax += 10;
	_MP = _MPmax;
	_attackPoint += 3;
	_defendPoint += 1;
	_level++;
	cout << _name << "升到了" << _level << "级！" << endl;

	Sleep(SLEEPTIME);
	return _level;
}
//判断死亡
bool Role::Dead()
{
	if (_HP <= 0)
		return true;
	else
		return false;
}
//新开始
int Role::NewLife()
{
	int temp = _expMax / 10;
	if (temp < _exp)
	{
		_exp -= temp;
	}
	else
	{
		temp = _exp;
		_exp = 0;
	}
	_HP = _HPmax;
	cout << "    " << _name << "已经挂掉！损失经验：" << temp << "点" << endl;
	Sleep(SLEEPTIME);
	
	return 1;
}

//打印背包,同时也牵扯使用
int PrintBeg(int battleOrNot = 0)
{
	int battle;
	return 1;
}

int Role::Initialize()
{
	_name = "yjk";
	_money = 30;
	_HPmax = 40;
	_HP = _HPmax;
	_MPmax = 20;
	_MP = _MPmax;
	_expMax = 20;
	_exp = 0;
	_level = 1;
	_attackPoint = 8;
	_defendPoint = 2;
	posX = 0;
	posY = 0;
	return 1;
}