#pragma once 
#include "monster.h"

//设置属性
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

//初始化掉落物品和装备
int Monster::MonsterClear()
{
	return 0;
}
//设置掉落物品
//设置掉落装备
//得到属性
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

//改变血量
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

//判断是否死亡
bool Monster::Dead()
{
	if (_HP <= 0)
	{
		_die = 0;
		return 0;
	}
	else
	{
		return 1;
	}
}

//怪物的信息应该是跟人物级别有关的，
//否则的话，游戏体验感会很差,这个函数会返回改变后的副本；
Monster Monster::Generate(const int& level)
{
	if (level - _level > 3)
	{
		//增加怪物属性 HP10%,attack 20%,defend 20%,exp 10%
		_HPmax = int(float(_HPmax)*((level - _level) * 10 / 100 + 1));
		_attackPoint = int(float(_attackPoint)*((level - _level) * 20 / 100 + 1));
		_defendPoint = int(float(_defendPoint)*((level - _level) * 20 / 100 + 1));
		_expPoint = int(float(_expPoint)*((level - _level) * 10 / 100 + 1));
	}
	_HP = _HPmax;
	return (*this);
}

//打印怪物信息
int Monster::NEW()
{
	_HP = _HPmax;
	return _HP;
}

int Monster::PrintDead()
{
	cout << "   " << _name << "被你杀死了" << endl;
	return 1;
}


//---------------------------------------
//class MonsterList
//---------------------------------------

//对怪物链表的迭代器初始化
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

//增加怪物，如果已经存在，就不在添加；
bool MonsterMap::AddMonster(Monster& monster)
{
	return _monsterMap.insert(make_pair(monster.GetID(), monster)).second;
}

//对于当前怪物的复制
Monster MonsterMap::GetCurMonster()
{
	return _itr_monster->second;
}

//当前怪物的引用
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

//对于特定怪物的拷贝
Monster MonsterMap::GetMonster(const int& id)
{
	return _monsterMap.find(id)->second;
}

//设置怪物的锁
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