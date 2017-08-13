#include "define.h"


int main()
{
	Control control;
	int main_menu;
	while (1)
	{
		main_menu = control.print_game();
		switch (main_menu)
		{
		case GAME_NEW:
			break;
		case GAME_LOAD:
			break;
		case GAME_MY:
			control.game_my();
			break;
		case GAME_INFO:
			control.game_info();
			break;
		case GAME_EXIT:
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}