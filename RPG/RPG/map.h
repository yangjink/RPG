#pragma once
#include "define.h"
//这个类将对地图进行描述
class Master;
class Role;
class NPCmap;

enum direction{
	MAP_EAST,
	MAP_WEST,
	MAP_NORTH,
	MAP_SOUTH
};
class Map
{
private:
	string _name;
	int _ID;//唯一标识
	int _pos_x;
	int _pos_y;
	int _level;

	//npc列表
	list<int> _NPCIDList;
	list<int>::iterator _itr_npcid;
	//怪物列表
	list<int> _monsterIDList;
	list<int>::iterator _itr_monsterID;
	list<int> _monsterIDBosslist;

	Map* _east;
	Map* _west;
	Map* _north;
	Map* _south;
public:
	Map();
	//设置属性
	void SetName(string);
	int SetID(int);
	int SetLevel(int);
	int SetPosX(int);
	int SetPosY(int);
	Map* SetEast(Map*);
	Map* SetWest(Map*);
	Map* SetNorth(Map*);
	Map* SetSouth(Map*);

	int AddNPC(int);
	int AddMonster(int);
	int AddMonsterBoss(int);

	int Clear();
	//提供属性
	string GetName();
	int GetID();
	int GetLevel();
	int GetPosX();
	int GetPosY();
	Map* GetEast();
	Map* GetWest();
	Map* GetNorth();
	Map* GetSouth();

	//npc集合
	bool InitItrNPCID();
	int GetCurNPCID();
	bool NextItrNPC();
	bool EndNPCID();
	int GetMonsterID(const int&);
	//怪物集合的操作
	bool InitMonsterID();
	int GetCurMonsterID();
	bool NextMonsterID();
	bool EndMonsterID();
	bool InitItrMonsterIDBoss();
	int GetCurMonsterIDBoss();
	bool NextItrMonsterIDBoss();
	bool EndMonsterIDBoss();

};

//整个地图的一个链表
class Monster;
class MonsterMap;
class NPCMap;
class MapList
{
private:
	list<Map> _maplist;
	list<Map>::iterator _it_map;
	Map* _curMap;//当前所在的位置
	int _curMapID;
	//npc
	vector<int> _npc;
	vector<int>::iterator _itr_npc;
	//怪物链表
	list<Monster> _monster;
	list<Monster>::iterator _itr_monster;
public:
	int SetPointer();//设置地图之间关系
	int SetCurMap();
	int MapClear();
	int PushMap(Map& map);
	int ChangeMap(int pos);

	int GetNPCNum();
	int GetNPCID(const int&);
	int GetMonsterNum();
	Monster GetMonster(const int&);
	bool DeleteMonster(const int&);
	//生成NPC和怪物
	int Generate(Role&,MonsterMap&);
	int PrintMap(NPCMap&,MonsterMap&);//打印当前地图
	int ShowMap();//展示整个地图
};

