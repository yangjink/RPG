#pragma once
#include "define.h"
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
	int print_game();
	int game_info();
	int game_my();
	int print_txt(char* filename);
};