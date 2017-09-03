#include "define.h"


int main()
{
	Role role;
	Control control;
	MapList map_list;
	MonsterMap monster_map;
	UsingMap using_map;
	NPCMap npc_map;
	int main_menu;
	srand(unsigned(time(NULL)));
	control.game_init(role,map_list,monster_map,using_map,npc_map);
	while (1)
	{
		main_menu = control.print_game();
		switch (main_menu)
		{
		case GAME_NEW:
			control.game_control(role,map_list,monster_map,using_map,npc_map);
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