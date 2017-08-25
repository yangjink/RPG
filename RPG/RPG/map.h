#pragma once
#include "define.h"
//����ཫ�Ե�ͼ��������
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
};

//������ͼ��һ������

class MapList
{
private:
	list<Map> _maplist;
	list<Map>::iterator _it_map;
	Map* _curMap;//��ǰ���ڵ�λ��
	int _curMapID;
public:
	int SetPointer();//���õ�ͼ֮���ϵ
	int SetCurMap();
	int PushMap(Map& map);
	int ChangeMap(int pos);
	int PrintMap();//��ӡ��ǰ��ͼ
	int ShowMap();//չʾ������ͼ
};

