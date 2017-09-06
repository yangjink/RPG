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
	int battle = battleOrNot;
	
	string userinput;
	list<Using>::iterator uitr;
	//װ��
	//����
	int count = 0;
	//ʲô���� 1 ��Ʒ 2װ��
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
			cout << "������Ϣ";
		else
			cout << '-';
		cout << endl;
		cout << "1: ��Ʒ" << "        " << "2:  װ��" << endl;
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
		else//��ӡװ��
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
			cout << "1~" << num << "ѡ��   ";
			if (page > 0) cout << "Z";
			cout << "/";
			if ((page + 1)*maxPrint < _usingList.size())
			{
				cout << "X";
			}
			cout << ":��ҳ    0���Ƴ�" << endl;
			print_line_sep();
			while (1)
			{
				cin >> userinput;
				if (userinput[0]-'0' >= 1  && userinput[0]-'0' <= num )
					break;
				if ((userinput[0] == 'x' || userinput[0] == 'X') && ((page + 1)*maxPrint< _usingList.size()))
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
			if ((userinput[0] == 'x' || userinput[0] == 'X') && ((page + 1)*maxPrint< _usingList.size()))
				++page;
			if ((userinput[0] == 'z' || userinput[0] == 'Z') && page>0)
				--page;
		}
		//װ������ʾʹ��
		else if (which == 2 && 0)
		{
		}
		else
		{
			cout << "  ��ı����ǿյģ�" << endl;
			print_line_sep();
			cout << "  0: ����" << endl;
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
//ʹ����Ʒ ����1�ɹ�ʹ�� ����0��ʹ����Ʒ
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
	//�������С�ڵ���0 ɾ����
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
//��ӡ������Ϣ
int Role::PrintInfo()
{
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