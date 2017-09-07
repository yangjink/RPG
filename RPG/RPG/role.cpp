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
int Role::PrintBeg(int battleOrNot)
{
	int battle = battleOrNot;
	
	string userinput;
	list<Using>::iterator uitr;
	//装备
	//数量
	int count = 0;
	//什么东西 1 物品 2装备
	int which;
	int page = 0;
	int maxPrint = 9;
	int nextPage;
	int num = 0;

	int change = 0;
	while (true)
	{
		PrintHead();
		nextPage = 1;
		for (int i = 0; i < 45; ++i)
		if (i == 22)
			cout << "背包信息";
		else
			cout << '-';
		cout << endl;
		cout << "1: 物品" << "        " << "2:  装备" << endl;
		while (1)
		{
			cin >> userinput;
			if (userinput[0] == '1' || userinput[0] == '2')
			{
				break;
			}
		}
		which = userinput[0] - '0';
		int k = 0;
		int i = 0;
		if (which == 1)
		{
			for (_itr_using = _usingList.begin(), i = 0; i<page*maxPrint; ++i)
				++_itr_using;
			k = int(_usingList.size()) - page*maxPrint;
			for ( i = 0; i < maxPrint; ++i)
			{
				cout << "   " << i + 1 << ":";
				_itr_using->PringUsingInfo();
				++_itr_using;
			}
		}
		else//打印装备
		{

		}

		if (which == 1 && !_usingList.empty())
		{
			print_line_sep();
			num = _usingList.size() - page*maxPrint;
			if (num > 9)
			{
				num = 9;
			}
			cout << "1~" << num << "选择   ";
			if (page > 0) cout << "Z";
			cout << "/";
			if ((page + 1)*maxPrint < (int)_usingList.size())
			{
				cout << "X";
			}
			cout << ":翻页    0：推出" << endl;
			print_line_sep();
			while (1)
			{
				cin >> userinput;
				if (userinput[0]-'0' >= 1  && userinput[0]-'0' <= num )
					break;
				if ((userinput[0] == 'x' || userinput[0] == 'X') && ((page + 1)*maxPrint< (int)_usingList.size()))
					break;
				if ((userinput[0] == 'z' || userinput[0] == 'Z') && page>0)
					break;
				if (userinput[0] == '0')
				{
					if (change == 0)
						return 0;
					else
						return 1;
				}
			}
			if (userinput[0] - '0' >= 1 && userinput[0] - '0' <= num)
			{
				int temp;
				int i = userinput[0] - '0' + page*maxPrint;
				_itr_using = _usingList.begin();
				for (int j = 1; j<i; ++j)
					++_itr_using;
				
				PrintHead();
				temp = _itr_using->PrintInfo();
				if (temp != 0)
				{
					if (temp == 1)
						UseUsing(*_itr_using);
					if (temp == -1)
						_usingList.erase(_itr_using);
					change = 1;
					if (battle == 1)
						return 1;
				}
			}
			if ((userinput[0] == 'x' || userinput[0] == 'X') && ((page + 1)*maxPrint< (int)_usingList.size()))
				++page;
			if ((userinput[0] == 'z' || userinput[0] == 'Z') && page>0)
				--page;
		}
		//装备的显示使用
		else if (which == 2 && 0)
		{
		}
		else
		{
			cout << "  你的背包是空的！" << endl;
			print_line_sep();
			cout << "  0: 返回" << endl;
			print_line_sep();
			while (1)
			{
				cin >> userinput;
				if (userinput[0] == '0')
					break;
			}
			if (userinput[0] == '0')
				return 0;
		}
	}
	return 1;
}
//使用物品 返回1成功使用 返回0非使用物品
int Role::UseUsing(Using& us)
{
	int usingid = us.GetID();
	list<Using>::iterator itr;
	for (itr = _usingList.begin(); itr != _usingList.end();++itr)
	{
		if (itr->GetID() == usingid)
		{
			itr->DecreaseNumber(1);
			break;
		}
	}
	//如果数量小于等于0 删掉它
	if (itr->GetNumber() <= 0)
		_usingList.erase(itr);

	if (itr->GetAddHP() > 0)
	{
		int add = 0;
		/* percent or not */
		if ( itr->GetPercentOrNo() == 1)
		{
			add = int(float(itr->GetAddHP()) / 100 * (GetHPmax()));
		}
		else
		{
			add = itr->GetAddHP();
		}
		ChangeHP(add,1);
		return 1;
	}
	if (itr->GetAddMP() > 0)
	{
		int add = 0;
		/* percent or not */
		if (itr->GetPercentOrNo() == 1)
		{
			add = int(float(itr->GetAddMP()) / 100 * (GetMPmax()));
		}
		else
		{
			add = itr->GetAddMP();
		}
		ChangeMP(add, 1);
		return 1;
	}

	return 0;
}
int Role::LoseUsing(int id, int num)
{
	for (_itr_using = _usingList.begin(); _itr_using != _usingList.end(); ++_itr_using)
	{
		if (_itr_using->GetID() == id)
		{
			
			_itr_using->DecreaseNumber(num, 1);
			
			if (_itr_using->GetNumber() <= 0)
			{
				_usingList.erase(_itr_using);
				break;
			}
		}
	}

	return 1;
}
//打印更多信息
int Role::PrintInfo()
{
	//list<Weapon*>::iterator itr_weapon_t;
	string userinput;
	PrintHead();
	cout << "  角色名: " << _name << endl;
	cout << "  等级: " << _level << endl;
	cout << "  银两: " << _money << endl;
	cout << "  HP: " << _HP << " / " << _HPmax << endl;
	cout << "  MP: " << _MP << " / " << _MPmax << endl;
	cout << "  EXP: " << _exp << " / " << _expMax << endl;
	cout << "  攻击力: " << _attackPoint << endl;
	cout << "  防御力: " << _defendPoint << endl;
	cout << "装备: " << endl;
	//装备

	cout << "1: 确定 " << endl;
	while (true)
	{
		cin >> userinput;
		if (userinput[0] == '1')
			break;
	}
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