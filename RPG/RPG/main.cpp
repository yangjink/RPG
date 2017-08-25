#include "define.h"


int main()
{
	Role role;
	Control control;
	MapList map_list;
	int main_menu;

	control.game_init(role,map_list);
	while (1)
	{
		main_menu = control.print_game();
		switch (main_menu)
		{
		case GAME_NEW:
			control.game_control(role,map_list);
			break;
		case GAME_LOAD:
			if (control.game_laod() == -1)
			{
				cout << "û�н��ȿ��Զ�ȡ!!!" << endl;
				Sleep(1000);
				continue;
			}
			else
			{
				//��ȡ�浵
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