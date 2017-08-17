#include "map.h"

Map::Map()
{
	_east = NULL;
	_west = NULL;
	_north = NULL;
	_south = NULL;
}

void Map::SetName(string n)
{
	_name = n;
}

int Map::SetID(int id)
{
	_ID = id;
	return _ID;
}

int Map::SetLevel(int l)
{
	_level = l;
	return _level;
}

int Map::SetPosX(int x)
{
	_pos_x = x;
	return _pos_x;
}

int Map::SetPosY(int y)
{
	_pos_y = y;
	return _pos_y;
}

Map* Map::SetEast(Map* east)
{
	_east = east;
	return _east;
}

Map* Map::SetWest(Map* west)
{
	_west = west;
	return _west;
}

Map* Map::SetNorth(Map* north)
{
	_north = north;
	return _north;
}

Map* Map::SetSouth(Map* south)
{
	_south = south;
	return _south;
}


//��������
string Map::GetName()
{
	return _name;
}

int Map::GetID()
{
	return _ID;
}

int Map::GetLevel()
{
	return _level;
}

int Map::GetPosX()
{
	return _pos_x;
}

int Map::GetPosY()
{
	return _pos_y;
}

Map* Map::GetNorth()
{
	return _north;
}

Map* Map::GetSouth()
{
	return _south;
}

Map* Map::GetWest()
{
	return _west;
}

Map* Map::GetEast()
{
	return _east;
}


//����ΪMapList
int MapList::SetCurMap()//���ÿ�ʼλ�õ����ڵĵ�ͼ
{
	_curMap = &(*_maplist.begin());
	return 1;
}

int MapList::PushMap(Map& map)//���һ���µ�ͼ
{
	_maplist.push_back(map);
	return 1;
}

int MapList::ChangeMap(int pos)//����һͼ
{
	switch (pos)
	{
	case MAP_EAST:
		if (_curMap->GetEast() == NULL)
			return 0;
		
		_curMap = _curMap->GetEast();
		return 1;
		break;
	case MAP_NORTH:
		if (_curMap->GetNorth() == NULL)
			return 0;

		_curMap = _curMap->GetNorth();
		return 1;
		break;
	case MAP_SOUTH:
		if (_curMap->GetSouth() == NULL)
			return 0;

		_curMap = _curMap->GetSouth();
		break;
	case MAP_WEST:
		if (_curMap->GetWest() == NULL)
			return 0;

		_curMap = _curMap->GetWest();
		return 1;
		break;
	default:
		return 0;
	}
	return 0;
}

int MapList::PrintMap()
{
	cout << "[" << _curMap->GetName() << "]�������ˣ�" << endl;
	//��ӡ�������

	if (_curMap->GetNorth() != NULL)
	{
		cout << "[w��]--[" << _curMap->GetNorth()->GetName() << "]" << endl;
	}
	if (_curMap->GetSouth() != NULL)
	{
		cout << "[s��]--[" << _curMap->GetSouth()->GetName() << "]" << endl;
	}
	if (_curMap->GetWest() != NULL)
	{
		cout << "[a��]--[" << _curMap->GetWest()->GetName() << "]" << endl;
	}
	if (_curMap->GetEast() != NULL)
	{
		cout << "[d��]--[" << _curMap->GetEast()->GetName() << "]" << endl;
	}

	return 1;
}