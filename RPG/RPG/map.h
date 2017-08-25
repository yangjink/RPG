#pragma once
#include "define.h"
//这个类将对地图进行描述
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
	int _ID;//唯一标识
	int _pos_x;
	int _pos_y;
	int _level;

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
};

//整个地图的一个链表

class MapList
{
private:
	list<Map> _maplist;
	list<Map>::iterator _it_map;
	Map* _curMap;//当前所在的位置
	int _curMapID;
public:
	int SetPointer();//设置地图之间关系
	int SetCurMap();
	int PushMap(Map& map);
	int ChangeMap(int pos);
	int PrintMap();//打印当前地图
	int ShowMap();//展示整个地图
};

