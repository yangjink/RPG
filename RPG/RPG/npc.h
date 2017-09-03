#pragma once
#include "define.h"

//NPC种类
class UsingMap;
class Role;
class MapList;

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
	//set
	bool SetName(string);
	int SetSell(int);
	int SetID(int);
	bool SetTalk(string);
	//get
	int GetID();
	string GetName();
	int GetSell();
	string GetTalk();

	//当选中npc时的对话
	int Talk(Role&, UsingMap&, MapList&, MonsterMap&);
	//当npc是商人时下面两个接口有效
	int SellUsing(Role&,UsingMap&);
	//商店出售的都是白装，但是属性会有随机变化，且价格是两倍
	int SellWeapon(Role&);
	//当角色出售物品时
	int RoleSell(Role&);
	//当npc不是商人时，npc的对话，并且任务也是从次函数中接受
	int Speak();
	//打印npc信息
	int PrintNpcInfo();
};
 
class NPCMap
{
private:
	map<int,NPC> _npcMap;
	map<int,NPC>::iterator _itr_npc;
public:
	//NPC数目
	int GetNPCNum();
	//NPC的拷贝
	NPC GetNPC(int id);
	//NPC的指针
	NPC* GetNPCPtr(int id);
	//添加一个NPC
	bool PushNPC(NPC);

	//_itr_npc
	bool InitItr();
	bool Next();
	bool End();

	NPC* GetCurNPC();
};
