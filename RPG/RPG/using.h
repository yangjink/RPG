#pragma once
#include "define.h"
//代表了使用物品及任务材料
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
	//是否还可以使用
	bool UseUp();
};