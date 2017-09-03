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
	int game_init(Role& role,MapList& maplist,MonsterMap& monsterMap,UsingMap& usingMap,NPCMap& npcMap);
	int game_save();
	int game_laod();

	int game_control(Role&, MapList&,MonsterMap& monsterMap,UsingMap& usingMap,NPCMap& npcMap);
	int print_game();
	int game_info();
	int game_my();
	int print_txt(char* filename);
private:
	/*	Using : 1~99;
		weapon 100~199
		skill 200~299
		npc 300~399
		mission 400~599
		map 600~799
		monster 800~999   850~870
	*/
	int init_map(MapList&);
	int init_role(Role&);
	int init_monster(MonsterMap&);
	int init_using(UsingMap&);
	bool init_npc(NPCMap&);
};
