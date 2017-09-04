#pragma once
#include "define.h"
//人物模型
//
class Using;
class Weapon;
class Role
{
private:
	string _name;
	int _money;
	int _HP;
	int _HPmax;
	int _MP;
	int _MPmax;
	int _expMax;
	int _exp;
	int _level;
	int _attackPoint;
	int _defendPoint;

	int posX;//当前位置
	int posY;

	//角色的背包
	list<Using> _usingList;
	list<Using>::iterator _itr_using;
	//身上的装备
	//技能
public:
	//设置信息
	int SetName(string);
	int SetMoney(int);
	int SetHP(int);
	int SetHPmax(int);
	int SetMP(int);
	int SetMPmax(int);
	int SetExp(int);
	int SetExpMax(int);
	int SetLevel(int);
	int SetAttackPoint(int);
	int SetDefendPoint(int);

	//设置背包
	bool InitUsingItr();
	bool NextUsingItr();
	bool EndUsingItr();
	Using GetCurUsing();
	//放入东西
	int PickUp(Using&);
	int PickUp(Using&, int);
	int PickUp(Weapon);

	//出售东西
	int Sell();
	//得到基本信息
	string GetName();
	int GetMoney();
	int GetHP();
	int GetHPmax();
	int GetMP();
	int GetMPmax();
	int GetExp();
	int GetExpMax();
	int GetLevel();
	int GetAttackPoint();
	int GetDefendPoint();
	//改变属性,再设定一个参数，1打印，0不打印
	int ChangeName(const string);
	int ChangeMoney(const int& );
	int ChangeHP(const int&, const int& tag = 0);
	int ChangeHPmax(const int& );
	int ChangeMP(const int&, const int& tag = 0);
	int ChangeMPmax(const int& );
	int ChangeExp(const int&,const int& tag = 0 );//同时考虑升级的事情
	int ChangeExpMax(const int& );
	//打印基本角色信息
	int PrintHead();
	//打印更多信息
	int PrintInfo();
	//角色升级
	int LevelUp();
	//判断角色是否活着
	bool Dead();
	//如果死亡，开始新的历程，其实只是减少一些exp
	int NewLife();
	//游戏开始，初始化
	int Initialize();
	//打印背包，同时也牵扯使用
	int PrintBeg(int battleOrNot = 0);
};
