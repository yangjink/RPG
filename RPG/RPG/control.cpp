#include "control.h"

int Control::game_control(MapList& maplist)
{
	int num_in_map = 0;
	string userinput;
	maplist.SetCurMap();

	while (1)
	{
		maplist.PrintMap();
		print_line_sep();
		num_in_map;
		cout << "1~" << num_in_map << "选择   0: 菜单" << endl;
		print_line_sep();

		while (1)
		{
			cin >> userinput;
			if (userinput[0] == '0')
				break;
			if (userinput[0] - '0' >= 1 && userinput[0] - '0' <= num_in_map)
				break;
			if (userinput[0] == 'w' || userinput[0] == 'W')/* change map*/
				break;
			if (userinput[0] == 's' || userinput[0] == 'S')/* change map*/
				break;
			if (userinput[0] == 'a' || userinput[0] == 'A')/* change map*/
				break;
			if (userinput[0] == 'd' || userinput[0] == 'D')/* change map*/
				break;
		}
		if (userinput[0] == '0')
		{
			//回到菜单
		}
		else if (userinput[0] - '0' >= 1 && userinput[0] - '0' <= num_in_map)
		{
			//怪物或者NPC
		}
		else if (userinput[0] == 'w' || userinput[0] == 'W')
		{
			if (maplist.ChangeMap(MAP_NORTH))
			{
				//生成npc或者怪物
			}
		}
		else if (userinput[0] == 's' || userinput[0] == 'S')
		{
			if (maplist.ChangeMap(MAP_SOUTH))
			{
				//生成npc或者怪物
			}
		}
		else if (userinput[0] == 'a' || userinput[0] == 'A')
		{
			if (maplist.ChangeMap(MAP_WEST))
			{
				//生成npc或者怪物
			}
		}
		else if (userinput[0] == 'd' || userinput[0] == 'D')
		{
			if (maplist.ChangeMap(MAP_EAST))
			{
				//生成npc或者怪物
			}
		}
	}

	return 1;
}

int Control::game_init(MapList& maplist)
{
	init_map(maplist);

	return 1;
}

int Control::init_map(MapList& maplist)
{
	Map tmp;

	struct StMap
	{
		string name;
		int ID;
		int x;
		int y;
		int lock;
		int level;

		int arr_npc[10];
		int arr_monster[10];
		int arr_boss[3];
	};

	StMap st_map[]=
	{
		/* name  |id|   x,y|  lock |  lev  | arr_npc --arr_monster---arr_must_monster*/
		{ "河望镇", 601, 0, 0, 1, 0, { 300, 301, 302, 303, 304, 305, 306, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "泥泞小道", 602, 0, -1, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "后山（一）", 603, 0, -2, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "后山（二）", 604, 1, -2, 0, 0, { 307, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "山谷", 605, 0, -3, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "山腰", 606, 0, -4, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, 803, 804, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "空山穴", 607, 2, -2, 0, 4, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 801, 802, 803, 804, -1, -1, -1, -1, -1, -1 },
		{ 851, -1, -1 } },
		{ "东部平原（一）", 608, 1, 0, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, 803, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "东部平原（二）", 609, 1, -1, 0, 5, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 804, 801, 802, 803, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "平原丘陵", 610, 0, -1, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 803, 804, 805, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "东方小路", 611, 2, 0, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 803, 804, 805, 806, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "北方小路", 612, 2, 1, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 803, 804, 805, 806, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "鬼泣崖", 613, 3, 1, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 806, 805, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 852, -1, -1 } },
		{ "洛阳城西", 614, 4, 1, 1, 0, { 312, 314, 301, -1, -1, -1, -1, -1, -1, -1 },
		{ 804, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "洛阳", 615, 5, 1, 1, 0, { 310, 302, 309, 311, 313, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "森林小路", 616, 5, 2, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 806, 807, 808, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "河边", 617, 5, 3, 0, 10, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 806, 807, 808, 809, -1, -1, -1, -1, -1, -1 },
		{ 853, -1, -1 } },
		{ "森林深处", 618, 4, 3, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 807, 808, 809, 810, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "林中之城", 619, 4, 2, 0, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 807, 808, 809, 810, -1, -1, -1, -1, -1, -1 },
		{ 854, -1, -1 } }
	};
	
	int num_map = sizeof(st_map) / sizeof(st_map[0]);
	Map map;
	for (int i = 0; i < num_map;++i)
	{
		map.SetName(st_map[i].name);
		map.SetID(st_map[i].ID);
		map.SetPosX(st_map[i].x);
		map.SetPosY(st_map[i].y);
		map.SetLevel(st_map[i].level);
		maplist.PushMap(map);
	}
	maplist.SetPointer();
	return 1;
}


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

int Control::game_laod()
{
	return -1;
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
		cout << endl << "    未命名        ver 1.0" << endl;
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