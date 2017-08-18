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


//返回属性
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


//以下为MapList
int MapList::SetPointer()//设置地图关系
{
	list<Map>::iterator it_i;
	list<Map>::iterator it_j;
	int posxi;
	int posyi;
	int posxj;
	int posyj;

	for (it_i = _maplist.begin(); it_i != _maplist.end(); ++it_i)
	{
		for (it_j = _maplist.begin(); it_j != _maplist.end(); ++it_j)
		{
			if (it_i->GetID() == it_j->GetID())
			{
				continue;
			}
			posxi = it_i->GetPosX();
			posxj = it_j->GetPosX();
			posyi = it_i->GetPosY();
			posyj = it_j->GetPosY();

			//根据坐标位置，进行方位连接
			// i  j
			if ((posyi == posyj) && ((posxj - posxi) == 1))
			{
				it_i->SetEast(&(*it_j));
				it_j->SetWest(&(*it_i));
			}
			// j  i
			else if ((posyi == posyj) && ((posxi - posxj) == 1))
			{
				it_j->SetEast(&(*it_i));
				it_i->SetWest(&(*it_j));
			}
			// i 
			// j
			else if ((posxi == posxj) && ((posyi - posyj) == 1))
			{
				it_i->SetSouth(&(*it_j));
				it_j->SetNorth(&(*it_i));
			}
			// j
			// i
			else if ((posxi == posxj) && ((posyj - posyi) == 1))
			{
				it_i->SetNorth(&(*it_j));
				it_j->SetSouth(&(*it_i));
			}
		}//it_j
	}//it_i

	return 0;
}

int MapList::SetCurMap()//设置开始位置的所在的地图
{
	_curMap = &(*_maplist.begin());
	return 1;
}

int MapList::PushMap(Map& map)//添加一个新地图
{
	_maplist.push_back(map);
	return 1;
}

int MapList::ChangeMap(int pos)//走下一图
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
	cout << "[" << _curMap->GetName() << "]你遇到了：" << endl;
	//打印怪物或人

	if (_curMap->GetNorth() != NULL)
	{
		cout << "[w北]--[" << _curMap->GetNorth()->GetName() << "]" << endl;
	}
	if (_curMap->GetSouth() != NULL)
	{
		cout << "[s南]--[" << _curMap->GetSouth()->GetName() << "]" << endl;
	}
	if (_curMap->GetWest() != NULL)
	{
		cout << "[a西]--[" << _curMap->GetWest()->GetName() << "]" << endl;
	}
	if (_curMap->GetEast() != NULL)
	{
		cout << "[d东]--[" << _curMap->GetEast()->GetName() << "]" << endl;
	}

	return 1;
}