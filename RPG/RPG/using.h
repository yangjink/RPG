#pragma once
#include "define.h"
//代表了使用物品及任务材料
enum percent{
	NOPERCENT = 0,
	PERCENT = 1
};
class Using
{
private:
	int _ID;//全局标识
	string _name;
	int _money;//所值钱数
	int _number;//存在的数量
	//回血蓝
	int _addHP;
	int _addMP;

	bool _percentOrNo;//是否百分比回血
public:
	//Set
	bool SetName(string);
	int SetID(int);
	int SetNumber(int);
	bool SetPercentOrNo(bool);
	int SetAddHP(int);
	int SetMoney(int);
	int SetAddMP(int);
	//get
	int GetID();
	string GetName();
	int GetNumber();
	bool GetPercentOrNo();
	int GetAddHP();
	int GetAddMP();
	int GetMoney();
	//获得或者失去物品
	int AddNumber(int);
	int AddNumber(int&, int);
	int DecreaseNumber(int);
	int DecreaseNumber(int&, int);
	//物品信息
	/*同时 return 1 决定使用  -1 丢弃  0 什么也不干*/
	int PrintInfo(int in_npc = 0);
	//使用物品的信息
	bool PringUsingInfo();
	
	//是否还可以使用
	bool UseUp();
};
//全局仅一份
class UsingMap
{
private:
	map<int,Using> _usingMap;
	map<int, Using>::iterator _itr_using;
public:
	//通过id找到对应的物品信息
	Using GetUsing(const int&);
	//往map中插入一个新物品
	bool PushUsing(Using&);
	//总共的数量
	int GetSize();
	//初始化
	bool InitItr();
	//next
	bool Next();
	//end
	bool End();
	//当前物品的信息
	Using GetCurUsing();
};