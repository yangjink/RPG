#pragma once
#include "define.h"

//NPC����
class UsingMap;
class Role;
class MapList;

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

	//��ѡ��npcʱ�ĶԻ�
	int Talk(Role&, UsingMap&, MapList&, MonsterMap&);
	//��npc������ʱ���������ӿ���Ч
	int SellUsing(Role&,UsingMap&);
	//�̵���۵Ķ��ǰ�װ���������Ի�������仯���Ҽ۸�������
	int SellWeapon(Role&);
	//����ɫ������Ʒʱ
	int RoleSell(Role&);
	//��npc��������ʱ��npc�ĶԻ�����������Ҳ�ǴӴκ����н���
	int Speak();
	//��ӡnpc��Ϣ
	int PrintNpcInfo();
};
 
class NPCMap
{
private:
	map<int,NPC> _npcMap;
	map<int,NPC>::iterator _itr_npc;
public:
	//NPC��Ŀ
	int GetNPCNum();
	//NPC�Ŀ���
	NPC GetNPC(int id);
	//NPC��ָ��
	NPC* GetNPCPtr(int id);
	//���һ��NPC
	bool PushNPC(NPC);

	//_itr_npc
	bool InitItr();
	bool Next();
	bool End();

	NPC* GetCurNPC();
};
