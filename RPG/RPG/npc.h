#pragma once
#include "define.h"

//NPC种类
enum kind{
	SELLNOTHING,//一般npc
	SELLUSING,//商人
	SELLWEAPON//铁匠
};
class NPC
{
private:
	string _name;
	int _ID;
	//npc的对话
	string _talk;
	int _sell;

public:
	//清理
	bool NpcClear();
	//增加任务
	bool AddMission(int);
	//get
	string GetName();
	int GetSell();
	string GetTalk();
	//set
	bool SetName(string);
	bool SetSell(int);
	bool SetID(int);
	bool SetTalk(string);
};