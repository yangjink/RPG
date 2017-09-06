#pragma once 
#include "monster.h"

//��������
int Monster::SetID(int id)
{
	_ID = id;
	return _ID;
}
int Monster::SetName(string name)
{
	_name = name;
	return 1;
}
int Monster::SetAttackPoint(int attack)
{
	_attackPoint = attack;
	return _attackPoint;
}
int Monster::SetDefendPoint(int defend)
{
	_defendPoint = defend;
	return _defendPoint;
}
int Monster::SetHP(int hp)
{
	_HP = hp;
	return _HP;
}
int Monster::SetHPmax(int hpmax)
{
	_HPmax = hpmax;
	return _HPmax;
}
int Monster::SetExpPoint(int exp)
{
	_expPoint = exp;
	return _expPoint;
}
int Monster::SetMoney(int money)
{
	_money = money;
	return _money;
}
int Monster::SetLock(int tag)
{
	_lock = tag;
	return _lock;
}
int Monster::SetLevel(int level)
{
	_level = level;
	return _level;
}

int Monster::SetDie(int die)
{
	_die = die;
	return _die;
}

//��ʼ��������Ʒ��װ��
int Monster::AddUsingList(int id)
{
	list<int>::iterator itr;
	for (itr = _uslist.begin(); itr != _uslist.end(); ++itr)
	{
		if (id == *itr)
		{
			return 0;
		}
	}
	_uslist.push_back(id);
	return 1;
}
int Monster::AddWeaponList(int id)
{
	//
	return 1;
}
int Monster::MonsterClear()
{
	_uslist.clear();
	_wealist.clear();
	return 1;
}
//���õ�����Ʒ
//���õ���װ��

int Monster::InitUsingItr()
{
	_itr_drop = _uslist.begin();
	return 1;
}
int Monster::NextUsingItr()
{
	if (_itr_drop != _uslist.end())
	{
		++_itr_drop;
		return 1;
	}
	return 0;
}
int Monster::EndUsingItr()
{
	if (_itr_drop == _uslist.end())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Monster::GetCurUsingID()
{
	if (_itr_drop != _uslist.end())
	{
		return (*_itr_drop);
	}
	return 0;
}
int Monster::InitWeaponItr()
{
	_itr_drop = _wealist.begin();
	return 1;
}
int Monster::NextWeaponItr()
{
	if (_itr_drop != _wealist.end())
	{
		++_itr_drop;
		return 1;
	}
	return 0;
}
int Monster::EndWeaponItr()
{
	if (_itr_drop == _wealist.end())
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
int Monster::GetCurWeaponID()
{
	if (_itr_drop != _wealist.end())
	{
		return (*_itr_drop);
	}
	return 0;
}

int Monster::GetUsingNum()
{
	return _uslist.size();
}
int Monster::GetWeaponNum()
{
	return _wealist.size();
}
//�õ�����
int Monster::GetDie()
{
	return _die;
}
string Monster::GetName()
{
	return _name;
}
int Monster::GetID()
{
	return _ID;
}
int Monster::GetAttackPoint()
{
	return _attackPoint;
}
int Monster::GetDefendPoint()
{
	return _defendPoint;
}
int Monster::GetHP()
{
	return _HP;
}
int Monster::GetHPmax()
{
	return _HPmax;
}
int Monster::GetExpPoint()
{
	return _expPoint;
}
int Monster::GetMoney()
{
	return _money;
}
int Monster::GetLock()
{
	return _lock;
}
int Monster::GetLevel()
{
	return _level;
}

//�ı�Ѫ��
int Monster::ChangeHP(const int& chp)
{
	_HP += chp;
	if (_HP < 0)
	{
		_HP = 0;
	}
	if (_HP > _HPmax)
	{
		_HP = _HPmax;
	}
	return _HP;
}

//�ж��Ƿ�����
bool Monster::Dead()
{
	if (_HP <= 0)
	{
		_die = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

//�������ϢӦ���Ǹ����Ｖ���йصģ�
//����Ļ�����Ϸ����л�ܲ�,��������᷵�ظı��ĸ�����
Monster Monster::Generate(const int& level)
{
	if (level - _level > 3)
	{
		//���ӹ������� HP10%,attack 20%,defend 20%,exp 10%
		_HPmax = int(float(_HPmax)*((level - _level) * 10 / 100 + 1));
		_attackPoint = int(float(_attackPoint)*((level - _level) * 20 / 100 + 1));
		_defendPoint = int(float(_defendPoint)*((level - _level) * 20 / 100 + 1));
		_expPoint = int(float(_expPoint)*((level - _level) * 10 / 100 + 1));
	}
	_HP = _HPmax;
	return (*this);
}

//��ӡ������Ϣ
int Monster::NEW()
{
	_HP = _HPmax;
	return _HP;
}

int Monster::PrintDead()
{
	cout << "   " << _name << "����ɱ����" << endl;
	return 1;
}


//---------------------------------------
//class MonsterList
//---------------------------------------

//�Թ�������ĵ�������ʼ��
int MonsterMap::InitMonsterItr()
{
	_itr_monster = _monsterMap.begin();
	return 1;
}

int MonsterMap::NextMonsterItr()
{
	if (_itr_monster != _monsterMap.end())
	{
		++_itr_monster;
		return 1;
	}
	return -1;
}

int MonsterMap::EndMonsterItr()
{
	if (_itr_monster == _monsterMap.end())
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

//���ӹ������Ѿ����ڣ��Ͳ�����ӣ�
bool MonsterMap::AddMonster(Monster& monster)
{
	return _monsterMap.insert(make_pair(monster.GetID(), monster)).second;
}

//���ڵ�ǰ����ĸ���
Monster MonsterMap::GetCurMonster()
{
	return _itr_monster->second;
}

//��ǰ���������
Monster* MonsterMap::GerCurMonsterRef()
{
	if (_itr_monster != _monsterMap.end())
	{
		return &(_itr_monster->second);
	}
	else
	{
		return NULL;
	}
}

//�����ض�����Ŀ���
Monster MonsterMap::GetMonster(const int& id)
{
	return _monsterMap.find(id)->second;
}

//���ù������
int MonsterMap::SetLock(const int& id, const int& flag)
{
	if (flag != MON_LOCK && flag != MON_UNLOCK)
	{
		return 0;
	}
	map<int, Monster>::iterator itr;
	if ((itr=_monsterMap.find(id)) != _monsterMap.end())
	{
		itr->second.SetLock(flag);
		return 1;
	}
	else
	{
		return 0;
	}
}