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

int Map::AddMonster(int monsterID)
{
	for (_itr_monsterID = _monsterIDList.begin(); _itr_monsterID != _monsterIDList.end(); ++_itr_monsterID)
	{
		if (*_itr_monsterID == monsterID)
		{
			return 0;
		}
	}
	_monsterIDList.push_back(monsterID);
	return monsterID;
}
int Map::AddMonsterBoss(int monsterid)
{
	for (_itr_monsterID = _monsterIDBosslist.begin();
		_itr_monsterID != _monsterIDBosslist.end();
		++_itr_monsterID)
	if ((*_itr_monsterID) == monsterid)
		return 0;
	_monsterIDBosslist.push_back(monsterid);
	return monsterid;
}

int Map::Clear()
{
	_monsterIDList.clear();
	_monsterIDBosslist.clear();
	return 0;
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

int Map::GetMonsterID(const int& num)
{
	_itr_monsterID = _monsterIDList.begin();
	for (int i = 1; i < num; ++i)
		++_itr_monsterID;

	return (*_itr_monsterID);
}
//���Ｏ�ϵĲ���
bool Map::InitMonsterID()
{
	_itr_monsterID = _monsterIDList.begin();
	return true;
}
int Map::GetCurMonsterID()
{
	return *_itr_monsterID;
}
bool Map::NextMonsterID()
{
	if (_itr_monsterID != _monsterIDList.end())
		++_itr_monsterID;
	return true;
}
bool Map::EndMonsterID()
{
	if (_itr_monsterID == _monsterIDList.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Map::InitItrMonsterIDBoss()
{
	_itr_monsterID = _monsterIDBosslist.begin();
	return true;
}
int Map::GetCurMonsterIDBoss()
{
	return *_itr_monsterID;
}
bool Map::NextItrMonsterIDBoss()
{
	if (_itr_monsterID != _monsterIDBosslist.end())
	{
		++_itr_monsterID;
		return true;
	}
	return false;
}
bool Map::EndMonsterIDBoss()
{
	if (_itr_monsterID == _monsterIDBosslist.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//����ΪMapList
int MapList::SetPointer()//���õ�ͼ��ϵ
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

			//��������λ�ã����з�λ����
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

int MapList::SetCurMap()//���ÿ�ʼλ�õ����ڵĵ�ͼ
{
	_curMap = &(*_maplist.begin());
	return 1;
}
int MapList::MapClear()
{
	_monster.clear();
	return 0;
}
int MapList::PushMap(Map& map)//���һ���µ�ͼ
{
	_maplist.push_back(map);
	return 1;
}
//�õ����������
int MapList::GetMonsterNum()
{
	return _monster.size();

}
Monster MapList::GetMonster(const int& num)
{
	_itr_monster = _monster.begin();
	for (int i = 1; i<num; ++i)
		++_itr_monster;
	return (*_itr_monster);
}
//ս�������󽫹�����б���ɾ��
bool MapList::DeleteMonster(const int& num)
{
	_itr_monster = _monster.begin();
	for (int i = 1; i<num; ++i)
		++_itr_monster;
	_monster.erase(_itr_monster);
	return true;
}
//����NPC�͹���
int MapList::Generate(Role& role, MonsterMap& monsterMap)
{
	//���
	_monster.clear();

	//���ɹ����б�Ҫ�����Ｖ��ı���ı�
	_curMap->InitItrMonsterIDBoss();
	while (!_curMap->EndMonsterIDBoss())
	{
		if (monsterMap.GetMonster(_curMap->GetCurMonsterIDBoss()).GetLock() == MON_UNLOCK)
		{
			_monster.push_back(monsterMap.GetMonster(_curMap->GetCurMonsterIDBoss()).Generate());
		}
		_curMap->NextItrMonsterIDBoss();
	}
	//Ȼ�����ɹ����б�����������Ӧ�ô��9�����й��ﱻɱ���ʹ���ɾ��
	//ʣ�»����еĹ�������
	int most_mon = 9 - _monster.size();
	int num_monster = 0;//ʵ�ʹ�������

	if (most_mon > 6)
	{
		num_monster = 6 - rand() % 3;//4~6
	}
	else
	{
		num_monster = most_mon - rand() % 3;
		if (num_monster < 0)
		{
			num_monster = 0;
		}
	}

	//Ȼ�����ɹ���
	//���������Ҫ�漶��仯
	int all_monster = 0;
	int rand_monster[10];
	for (int i = 0; i < sizeof(rand_monster) / sizeof(rand_monster[0]); ++i)
	{
		rand_monster[i] = -1;
	}
	for (_curMap->InitMonsterID();!_curMap->EndMonsterID();_curMap->NextMonsterID())
	{
		++all_monster;
	}
	if (all_monster != 0)
	{
		for (int i = 0; i < num_monster; ++i)
		{
			int tmp = rand() % all_monster;
			_curMap->InitMonsterID();
			for (int j = 0; j < tmp; j++)
			{
				_curMap->NextMonsterID();
			}
			if (monsterMap.GetMonster(_curMap->GetCurMonsterID()).GetLock() == MON_UNLOCK)
			{
				_monster.push_back(monsterMap.GetMonster(_curMap->GetCurMonsterID()).Generate(role.GetLevel()));
			}
		}
	}

	return 0;
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
	int index = 1;
	for (_itr_monster = _monster.begin(); _itr_monster != _monster.end();++_itr_monster)
	{
		cout << "   " << index++ << " :";
		cout << _itr_monster->GetName() << endl;
	}
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