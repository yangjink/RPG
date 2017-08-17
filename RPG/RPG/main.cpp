#include "define.h"


int main()
{
	Control control;
	MapList map_list;
	int main_menu;

	control.game_init(map_list);
	while (1)
	{
		main_menu = control.print_game();
		switch (main_menu)
		{
		case GAME_NEW:
			control.game_control(map_list);
			break;
		case GAME_LOAD:
			if (control.game_laod() == -1)
			{
				cout << "没有进度可以读取!!!" << endl;
				Sleep(1000);
				continue;
			}
			else
			{
				//读取存档
			}
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