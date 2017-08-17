#pragma once
#include "define.h"
class MapList;
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
	int game_init(MapList& maplist);
	int game_save();
	int game_laod();

	int game_control(MapList&);
	int print_game();
	int game_info();
	int game_my();
	int print_txt(char* filename);
private:
	int init_map(MapList&);
};
