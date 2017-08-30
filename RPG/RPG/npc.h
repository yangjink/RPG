#pragma once
#include "define.h"

//NPC����
enum kind{
	SELLNOTHING,//һ��npc
	SELLUSING,//����
	SELLWEAPON//����
};
class NPC
{
private:
	string _name;
	int _ID;
	//npc�ĶԻ�
	string _talk;
	int _sell;

public:
	//����
	bool NpcClear();
	//��������
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