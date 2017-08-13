#include "control.h"


int Control::print_txt(char* filename)
{
	fstream file(filename);
	char read[1024];
	system("cls");
	while (!file.eof())
	{
		file >> read;
		cout << read << endl;
	}
	file.close();
	print_line_sep();
	cout << "1:确定" << endl;
	char c;
	while (1)
	{
		cin >> c;
		if (c == '1')
			break;
	}
	return 0;
}

int Control::game_info()
{
	return print_txt("game_info.txt");
}

int Control::game_my()
{
	return print_txt("game_my.txt");
}

int Control::print_game()
{
	//打印主菜单
	string select_menu;
	while (1)
	{
		system("cls");
		/* to print the game menu */
		cout << endl << "    人魔之战        ver 1.0" << endl;
		cout << endl << "1: 新游戏" << endl << "2: 载入游戏（尚未添加）" << endl <<
			"3: 游戏帮助" << endl << "4: 制作信息" << endl << "5: 退出" << endl;
		cout << endl << "请选择（1~5）:" << endl;
		cin >> select_menu;
		if (select_menu[0] == '1') return GAME_NEW;
		else if (select_menu[0] == '2') return GAME_LOAD;
		else if (select_menu[0] == '3') return GAME_INFO;
		else if (select_menu[0] == '4') return GAME_MY;
		else if (select_menu[0] == '5') return GAME_EXIT;
	}
	return 0;
}