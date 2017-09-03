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
//��ӡ��Ʒ��Ϣ
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
		cout << "(��Ʒ)";
	}
	cout << "*" << _number << endl;
	return true;
}

//��Ʒ��Ϣ
/*ͬʱ return 1 ����ʹ��  -1 ����  0 ʲôҲ����*/
int Using::PrintInfo(int in_npc)
{
	string userinput;
	cout << "-------------------��Ʒ��Ϣ------------------" << endl;
	cout << "����: " << _name << endl;
	cout << "����: " << _number << endl;
	cout << "�۸�: " << _money << endl;
	cout << "��Ϣ: ";
	//����������Ʒ
	if (_addHP != 0 || _addMP != 0)
	{
		cout << "�ظ�";
		if (_addHP != 0)
		{
			cout << "������";
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
			cout << "������";
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
		cout << "ƽ����Ʒ";
	}
	cout << endl;
	print_line_sep();
	if (in_npc == 1)//��
	{
		cout << "1:���� ";
	}
	else if (in_npc == 2)//��
	{
		cout << "1:����";
	}
	else
	{
		cout << "1:����";
		if (_addHP != 0 || _addMP != 0)
		{
			cout << "2:ʹ��";
		}
	}
	cout << "0:����"<<endl;
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

//ͨ��id�ҵ���Ӧ����Ʒ��Ϣ
Using UsingMap::GetUsing(const int& id)
{
	return _usingMap.find(id)->second;
}
//��map�в���һ���µ���Ϣ
bool UsingMap::PushUsing(Using& use)
{
	return _usingMap.insert(make_pair(use.GetID(), use)).second;
}

//�ܹ�������
int UsingMap::GetSize()
{
	return _usingMap.size();
}

//��ʼ��
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
//��ǰ��Ʒ����Ϣ
Using UsingMap::GetCurUsing()
{
	return (_itr_using->second);
}