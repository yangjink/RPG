#pragma once
#include "define.h"
//����ཫ�Ե�ͼ��������
class Master;
class Role;

enum {
	MAP_EAST,
	MAP_WEST,
	MAP_NORTH,
	MAP_SOUTH
};
class Map
{
private:
	string _name;
	int _ID;//Ψһ��ʶ
	int _pos_x;
	int _pos_y;
	int _level;

	//�����б�
	list<int> _monsterIDList;
	list<int>::iterator _itr_monsterID;
	list<int> _monsterIDBosslist;

	Map* _east;
	Map* _west;
	Map* _north;
	Map* _south;
public:
	Map();
	//��������
	void SetName(string);
	int SetID(int);
	int SetLevel(int);
	int SetPosX(int);
	int SetPosY(int);
	Map* SetEast(Map*);
	Map* SetWest(Map*);
	Map* SetNorth(Map*);
	Map* SetSouth(Map*);

	int AddMonster(int);
	int AddMonsterBoss(int);

	int Clear();
	//�ṩ����
	string GetName();
	int GetID();
	int GetLevel();
	int GetPosX();
	int GetPosY();
	Map* GetEast();
	Map* GetWest();
	Map* GetNorth();
	Map* GetSouth();

	int GetMonsterID(const int&);
	//���Ｏ�ϵĲ���
	bool InitMonsterID();
	int GetCurMonsterID();
	bool NextMonsterID();
	bool EndMonsterID();
	bool InitItrMonsterIDBoss();
	int GetCurMonsterIDBoss();
	bool NextItrMonsterIDBoss();
	bool EndMonsterIDBoss();

};

//������ͼ��һ������
class Monster;
class MonsterMap;
class MapList
{
private:
	list<Map> _maplist;
	list<Map>::iterator _it_map;
	Map* _curMap;//��ǰ���ڵ�λ��
	int _curMapID;

	//��������
	list<Monster> _monster;
	list<Monster>::iterator _itr_monster;
public:
	int SetPointer();//���õ�ͼ֮���ϵ
	int SetCurMap();
	int MapClear();
	int PushMap(Map& map);
	int ChangeMap(int pos);
	int GetMonsterNum();
	Monster GetMonster(const int&);
	bool DeleteMonster(const int&);
	//����NPC�͹���
	int Generate(Role&,MonsterMap&);
	int PrintMap();//��ӡ��ǰ��ͼ
	int ShowMap();//չʾ������ͼ
};

