#pragma once
#include "define.h"
class MapList;
class Role;
class MonsterMap;
enum game_menu
{
	GAME_SAVE,
	GAME_LOAD,
	GAME_EXIT,
	GMAE_INIT,
	GAME_NEW,
	GAME_MY,
	GAME_INFO,
};
class Control
{
public:
	int game_init(Role& role,MapList& maplist,MonsterMap& monsterMap,UsingMap& usingMap);
	int game_save();
	int game_laod();

	int game_control(Role&, MapList&,MonsterMap& monsterMap,UsingMap& usingMap);
	int print_game();
	int game_info();
	int game_my();
	int print_txt(char* filename);
private:
	int init_map(MapList&);
	int init_role(Role&);
	int init_monster(MonsterMap&);
	int init_using(UsingMap&);
};
