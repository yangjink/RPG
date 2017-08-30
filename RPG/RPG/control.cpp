#include "control.h"

int Control::game_control(Role& role,MapList& maplist,MonsterMap& monstermap)
{
	int num_in_map = 0;
	string userinput;
	maplist.SetCurMap();
	maplist.Generate(role,monstermap);
	while (1)
	{
		role.PrintHead();
		maplist.PrintMap();
		print_line_sep();
		num_in_map = maplist.GetMonsterNum();//+npc��;
		cout << "1~" << num_in_map << "ѡ��   0: �˵�" << endl;
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
			//�ص��˵�
		}
		else if (userinput[0] - '0' >= 1 && userinput[0] - '0' <= num_in_map)
		{
			//�������NPC
			int tmp_index = userinput[0] - '0';// - npc;
			Monster mon = maplist.GetMonster(tmp_index);
			mon.Generate(role.GetLevel());
			//ս��
		}
		else if (userinput[0] == 'w' || userinput[0] == 'W')
		{
			if (maplist.ChangeMap(MAP_NORTH))
			{
				//����npc���߹���
				maplist.Generate(role, monstermap);
			}
		}
		else if (userinput[0] == 's' || userinput[0] == 'S')
		{
			if (maplist.ChangeMap(MAP_SOUTH))
			{
				//����npc���߹���
				maplist.Generate(role, monstermap);
			}
		}
		else if (userinput[0] == 'a' || userinput[0] == 'A')
		{
			if (maplist.ChangeMap(MAP_WEST))
			{
				//����npc���߹���
				maplist.Generate(role,monstermap);
			}
		}
		else if (userinput[0] == 'd' || userinput[0] == 'D')
		{
			if (maplist.ChangeMap(MAP_EAST))
			{
				//����npc���߹���
				maplist.Generate(role, monstermap);
			}
		}
	}

	return 1;
}

int Control::game_init(Role& role,MapList& maplist,MonsterMap& monsterMap)
{
	init_map(maplist);
	init_role(role);
	init_monster(monsterMap);
	return 1;
}

int Control::init_monster(MonsterMap& monsterMap)
{
	struct StMonster
	{
		string name;
		int ID;
		int money;
		int exp;
		int HPmax;
		int attack;
		int defend;
		int lock;
		int die;
		int level;
		int arr_using[4];
		int arr_weapon[4];
	};
	static StMonster st_monster[] = {
		/*   name      id    money  exp  hp   a/d    lk   die  level  usingList           weaponList*/
		{   "����",    800,    5,    5,  8,  4,1,   1,	  0,    1,{ 1, 4, 16, -1 }, { 105, 100, -1, -1 } },
		{ "������",    801,    8,    7,  10, 6,0,   1,   0,    1,{ 11, 16, 2, 3 }, { 100, 104, -1, -1 } },
		{ "�蹷",      802,   10,    9,  10,   6,2,  1,  0,    1,{ 9, 11, 16, 3 }, { 102, 103, -1, -1 } },
		{ "��ʬ",      803,   10,    9,  12,  8,1,  1,   0,    1,{ 2, 3, 12, 11 }, { 150, 106, 101, -1 } },
		{ "���߽�ʬ",  804,  12,    10, 13,  9,2,   1,   0,    1,{ 2, 5, 8, 9 }, { 104, 110, 130, -1 } },
		{ "����սʿ",  805,  15,    12, 18,  10,2,  1,   0,    1,{ 6, 15, 21, 3 }, { 131, 110, 106, 101 } },
		{ "���÷�ʦ",  806,  18,    12, 13,  11,1,  1,   0,    1,{ 15, 25, 23, 4 }, { 131, 170, 111, 160 } },
		{ "��ħ֮��",  807,  20,    18, 20,  12,3,  1,   0,    1,{ 21, 2, 3, -1 }, { 113, -1, -1, -1 } },
		{ "��Ы��",    808,  24,    22, 24,  13,2,  1,   0,    1,{ 17, 14, 11, 4 }, { 151, 111, 170, 141 } },
		{ "������",    809,  30,    28, 25,  14,8,  1,   0,    1,{ 8, 9, 2, 4 }, { 171, 132, 112, 160 } },
		{ "���۸�ʬ",  810,  35,    32, 30,  17,2,  1,   0,    1,{ 3, 4, 6, 14 }, { 161, 112, 141, -1 } },
		{ "а���ɽ��", 851, 100,  100, 50,  18,2,  0,   0,    3,{ 2, 3, 4, 25 }, { 150, 160, 171, -1 } },
		{ "����ͺ��",  852,  400,  220, 160, 35,6,  0,   0,    5,{ 3, 6, 14, 21 }, { 132, 111, 141, -1 } },
		{ "�κ�ˮ��",  853,  600,  300, 260, 40,10, 0,   0,    8,{ 3, 6, 21, 25 }, { 161, 107, 171, 113 } },
		{ "ħ������",  854, 1000,  550, 380, 60,15, 0,   0,   10,{ 3, 6, 1, 25 }, { 113, 171, -1, -1 } }
	};

	Monster mon_tmp;
	int num_of_monster = sizeof(st_monster) / sizeof(st_monster[0]);
	for (int i = 0; i < num_of_monster; ++i)
	{
		mon_tmp.MonsterClear();
		mon_tmp.SetName(st_monster[i].name);
		mon_tmp.SetID(st_monster[i].ID);
		mon_tmp.SetMoney(st_monster[i].money);
		mon_tmp.SetExpPoint(st_monster[i].exp);
		mon_tmp.SetHPmax(st_monster[i].HPmax);
		mon_tmp.SetAttackPoint(st_monster[i].attack);
		mon_tmp.SetDefendPoint(st_monster[i].defend);
		mon_tmp.SetLock(st_monster[i].lock);
		mon_tmp.SetDie(st_monster[i].die);
		mon_tmp.SetLevel(st_monster[i].level);
		//��ʼ��װ��
		//��ʼ��������Ʒ

		monsterMap.AddMonster(mon_tmp);
	}
	return 0;
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

	static StMap st_map[]=
	{
		/* name  |id|   x,y|  lock |  lev  | arr_npc --arr_monster---arr_must_monster*/
		{ "������", 601, 0, 0, 1, 0, { 300, 301, 302, 303, 304, 305, 306, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "��ŢС��", 602, 0, -1, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "��ɽ��һ��", 603, 0, -2, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "��ɽ������", 604, 1, -2, 0, 0, { 307, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "ɽ��", 605, 0, -3, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "ɽ��", 606, 0, -4, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, 803, 804, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "��ɽѨ", 607, 2, -2, 0, 4, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 801, 802, 803, 804, -1, -1, -1, -1, -1, -1 },
		{ 851, -1, -1 } },
		{ "����ƽԭ��һ��", 608, 1, 0, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 800, 801, 802, 803, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "����ƽԭ������", 609, 1, -1, 0, 5, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 804, 801, 802, 803, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "ƽԭ����", 610, 0, -1, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 803, 804, 805, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "����С·", 611, 2, 0, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 803, 804, 805, 806, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "����С·", 612, 2, 1, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 803, 804, 805, 806, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "������", 613, 3, 1, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 806, 805, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 852, -1, -1 } },
		{ "��������", 614, 4, 1, 1, 0, { 312, 314, 301, -1, -1, -1, -1, -1, -1, -1 },
		{ 804, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "����", 615, 5, 1, 1, 0, { 310, 302, 309, 311, 313, -1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "ɭ��С·", 616, 5, 2, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 806, 807, 808, -1, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "�ӱ�", 617, 5, 3, 0, 10, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 806, 807, 808, 809, -1, -1, -1, -1, -1, -1 },
		{ 853, -1, -1 } },
		{ "ɭ���", 618, 4, 3, 1, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 807, 808, 809, 810, -1, -1, -1, -1, -1, -1 },
		{ -1, -1, -1 } },
		{ "����֮��", 619, 4, 2, 0, 0, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
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
		for (int j = 0; j < 10; j++)
		{
			if (st_map[i].arr_monster[j] >= 0)
			{
				map.AddMonster(st_map[i].arr_monster[j]);
			}
			else
			{
				break;
			}
		}
		for (int j = 0; j < 3; j++)
		{
			if (st_map[i].arr_boss[j] >= 0)
			{
				map.AddMonsterBoss(st_map[i].arr_boss[j]);
			}
			else
			{
				break;
			}
		}
		maplist.PushMap(map);
	}
	maplist.SetPointer();
	return 1;
}

int Control::init_role(Role& role)
{
	role.Initialize();
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
	cout << "1:ȷ��" << endl;
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
	//��ӡ���˵�
	string select_menu;
	while (1)
	{
		system("cls");
		/* to print the game menu */
		cout << endl << "    δ����        ver 1.0" << endl;
		cout << endl << "1: ����Ϸ" << endl << "2: ������Ϸ����δ��ӣ�" << endl <<
			"3: ��Ϸ����" << endl << "4: ������Ϣ" << endl << "5: �˳�" << endl;
		cout << endl << "��ѡ��1~5��:" << endl;
		cin >> select_menu;
		if (select_menu[0] == '1') return GAME_NEW;
		else if (select_menu[0] == '2') return GAME_LOAD;
		else if (select_menu[0] == '3') return GAME_INFO;
		else if (select_menu[0] == '4') return GAME_MY;
		else if (select_menu[0] == '5') return GAME_EXIT;
	}
	return 0;
}