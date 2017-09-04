#pragma once
#include "role.h"

//������Ϣ
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

//���ñ���
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

//���붫��
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


//���۶���(��δ����)
int Role::Sell()
{
	return 1;
}
//���ػ�����Ϣ
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

//�ı�����,���趨һ��������1��ӡ��0����ӡ
int Role::ChangeMoney(const int& changemoney)
{
	_money += changemoney;
	cout << "������:" << changemoney << "����" << endl;
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
		cout << "��ظ���" << tmp << "������" << endl;
		Sleep(SLEEPTIME);
	}

	return _HP;
}
int Role::ChangeHPmax(const int& hpm)
{
	_HPmax += hpm;
	return _HPmax;
}
//ʧ�ܷ���-1,��Ϊ�п��ܸպ�ʹ����֮��ʣ0MP
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
		cout << "��ظ���" << tmp << "��ħ��ֵ" << endl;
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
		cout << "������" << exp << "�㾭��" << endl;
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

//��ӡ��ɫ������Ϣ
int Role::PrintHead()
{
	int pointlength = 40;//ͷ������
	int temp;
	system("cls");
	cout << _name << "   �ȼ�: " << _level << "   ����: " << _money << endl;
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

//����
int Role::LevelUp()
{
	_expMax = (20 * _level + 40);
	//��������
	_HPmax += 20;
	_HP = _HPmax;
	_MPmax += 10;
	_MP = _MPmax;
	_attackPoint += 3;
	_defendPoint += 1;
	_level++;
	cout << _name << "������" << _level << "����" << endl;

	Sleep(SLEEPTIME);
	return _level;
}
//�ж�����
bool Role::Dead()
{
	if (_HP <= 0)
		return true;
	else
		return false;
}
//�¿�ʼ
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
	cout << "    " << _name << "�Ѿ��ҵ�����ʧ���飺" << temp << "��" << endl;
	Sleep(SLEEPTIME);
	
	return 1;
}

//��ӡ����,ͬʱҲǣ��ʹ��
int Role::PrintBeg(int battleOrNot)
{
	//int battle;
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