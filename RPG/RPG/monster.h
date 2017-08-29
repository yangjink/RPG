#pragma once
#include "define.h"

enum MON_LOCK{
	MON_LOCK,
	MON_UNLOCK
};
class Monster
{
private:
	//基本属性
	int _ID;
	string _name;
	int _attackPoint;
	int _defendPoint;
	int _HP;
	int _HPmax;
	int _level;
	//杀死怪物后获得的exp
	int _expPoint;
	//杀死怪物后获得的金钱
	int _money;
	//加锁，判断怪物是不是可见的
	//MON_LOCK  MON_UNLOCK
	int _lock;
	//怪物状态，0：死亡；1：活着；
	int _die;
	//怪物掉落的使用物品
	//怪物掉落的装备
public:
	//设置属性
	int SetID(int id);
	int SetName(string name);
	int SetAttackPoint(int attack);
	int SetDefendPoint(int defend);
	int SetHP(int hp);
	int SetHPmax(int hpmax);
	int SetExpPoint(int exp);
	int SetMoney(int money);
	int SetLock(int tag);
	int SetLevel(int level);
	int SetDie(int die);
	//设置掉落物品
	//设置掉落装备
	//得到属性
	int GetDie();
	string GetName();
	int GetID();
	int GetAttackPoint();
	int GetDefendPoint();
	int GetHP();
	int GetHPmax();
	int GetExpPoint();
	int GetMoney();
	int GetLock();
	int GetLevel();

	//改变血量
	int ChangeHP(const int& chp);
	//判断是否死亡
	bool Dead();
	//怪物的信息应该是跟人物级别有关的，
	//否则的话，游戏体验感会很差,这个函数会返回改变后的副本；
	Monster Generate(const int& level = 0);
	//打印怪物信息
	int NEW();
	int PrintDead();
};
//对于map中怪物的比较实用id来进行比较
class com{
public:
	bool operator()(Monster& m1, Monster& m2) const
	{
		return m1.GetID() > m2.GetID();
	}
};
//怪物map
class MonsterMap
{
private:
	//怪物链表
	map<int,Monster,com> _monsterMap;
	map<int,Monster>::iterator _itr_monster;
public:
	//对怪物链表的迭代器初始化
	int InitMonsterItr();
	int NextMonsterItr();
	int EndMonsterItr();
	//增加怪物，如果已经存在，就不在添加；
	bool AddMonster(Monster&);
	//对于当前怪物的复制
	Monster GetCurMonster();
	//当前怪物的指针
	Monster* GerCurMonsterRef();
	
	//对于特定怪物的拷贝
	Monster GetMonster(const int&);
	//设置怪物的锁
	int SetLock(const int&, const int&);

};
