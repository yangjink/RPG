#pragma once
#include "define.h"

enum AttackObject
{
	ROLEATTACK,
	MONSTERATTACK
};

class Battle
{
private:
	
	//决定谁现在攻击
	int _whosAttack;
	int _roletoMonster;
	int _monstertoRole;
	//结束后掉落的物品
	list<Using> _usingDropList;
	list<Using>::iterator _itr_using;
	//结束后掉落的装备
	list<Weapon> _weaponDropList;
	list<Weapon>::iterator _itr_weapon;
public:
	Battle()
	{};

	//当战斗发起后直到战斗结束
	int InBattle(Role&,Monster&,MonsterMap&);
	//当战斗结束后
	int AfterBattle(Role& , Monster&, UsingMap&);//装备技能


	int GenerateDroped(Monster&,UsingMap&);//装备
	//是否拿起物品
	int PickUp(Role&);
	//战斗中玩家的操作
	//返回值< 0 意味着 miss
	//== 0 什么也没做
	// > 0 对怪物的伤害
	//考录加入逃跑功能。。。。
	int Fight(Role&,Monster&);
};