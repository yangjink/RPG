#include "control.h"

int Control::game_control(Role& role,MapList& maplist,MonsterMap& monstermap,UsingMap& usingmap,NPCMap& npcMap,Battle& battle)
{
	int num_in_map = 0;
	string userinput;
	maplist.SetCurMap();
	maplist.Generate(role,monstermap);
	while (1)
	{
		role.PrintHead();
		maplist.PrintMap(npcMap,monstermap);
		print_line_sep();
		num_in_map = maplist.GetMonsterNum()+maplist.GetNPCNum();
		cout << "1~" << num_in_map << "选择   0: 菜单" << endl;
		print_line_sep();
		cout << "b：背包    c：账号信息" << endl;
		print_line_sep();

		while (1)
		{
			cin >> userinput;
			if (userinput[0] == '0')
				break;
			if (userinput[0] - '0' >= 1 && userinput[0] - '0' <= num_in_map)
				break;
			if (userinput[0] == 'w' || userinput[0] == 'W')//北
				break;
			if (userinput[0] == 's' || userinput[0] == 'S')//南
				break;
			if (userinput[0] == 'a' || userinput[0] == 'A')//西
				break;
			if (userinput[0] == 'd' || userinput[0] == 'D')//东
				break;
			if (userinput[0] == 'b' || userinput[0] == 'B')//背包
				break;
			if (userinput[0] == 'c' || userinput[0] == 'C')//背包
				break;
		}
		if (userinput[0] == '0')
		{
			//回到菜单
		}
		else if (userinput[0] - '0' >= 1 && userinput[0] - '0' <= num_in_map)
		{
			//怪物或者NPC
			if (userinput[0] - '0' <= maplist.GetNPCNum())
			{
				//对话 任务
			}
			else
			{
				int tmp_index = userinput[0] - '0';// - npc;
				Monster mon = maplist.GetMonster(tmp_index);
				mon.Generate(role.GetLevel());

				//战斗
				battle.InBattle(role,mon,monstermap);
				battle.AfterBattle(role,mon,usingmap);
			}

		}
		else if (userinput[0] == 'w' || userinput[0] == 'W')
		{
			if (maplist.ChangeMap(MAP_NORTH))
			{
				//生成npc或者怪物
				maplist.Generate(role, monstermap);
			}
		}
		else if (userinput[0] == 's' || userinput[0] == 'S')
		{
			if (maplist.ChangeMap(MAP_SOUTH))
			{
				//生成npc或者怪物
				maplist.Generate(role, monstermap);
			}
		}
		else if (userinput[0] == 'a' || userinput[0] == 'A')
		{
			if (maplist.ChangeMap(MAP_WEST))
			{
				//生成npc或者怪物
				maplist.Generate(role,monstermap);
			}
		}
		else if (userinput[0] == 'd' || userinput[0] == 'D')
		{
			if (maplist.ChangeMap(MAP_EAST))
			{
				//生成npc或者怪物
				maplist.Generate(role, monstermap);
			}
		}
		else if (userinput[0] == 'b' || userinput[0] == 'B')
		{
			role.PrintBeg();
		}
		else if (userinput[0] == 'c' || userinput[0] == 'C')
		{
			role.PrintInfo();
		}
	}

	return 1;
}

int Control::game_init(Role& role,MapList& maplist,MonsterMap& monsterMap,UsingMap& usingMap,NPCMap& npcMap,Battle& battle)
{
	init_map(maplist);
	init_role(role);
	init_monster(monsterMap);
	init_using(usingMap);
	init_npc(npcMap);
	return 1;
}

bool Control::init_npc(NPCMap& npcMap)
{
	struct StNpc{
		string name;
		string talk;
		int ID;
		int sell;
		//一个npc有5个任务
		int arr_mission[5];
	};
	StNpc st_npc[] = {
		{ "沈万山", "哎，村子里的村民受妖怪折磨太久了.....",
		300, 0, { 401, -1, -1, -1, -1 } },
		{ "赵大娘", "看看有什么需要的，这里卖的很便宜啊。",
		301, 1, { -1, -1, -1, -1, -1 } },
		{ "欧阳铁匠", "我这可以打造天下最好的武器。",
		302, 2, { -1, -1, -1, -1, -1 } },
		{ "孟三", "哥哥去后山很久了，不知到发现了什么还不回来...",
		303, 0, { 400, 402, 405, -1, -1 } },
		{ "秦女", "我相公去山穴采药，不慎被山妖抓住，至今了无音讯，我该如何是好啊...5555555",
		304, 0, { -1, -1, -1, -1, -1 } },
		{ "娄知县", "只有彻底消灭了魔怪，天下方能安生啊....",
		305, 0, { 404, -1, -1, -1, -1 } },
		{ "程伯伯", "老了...身体都快动不了了...哎......",
		306, 0, { 403, -1, -1, -1, -1 } },
		{ "张先生", "啊！后山的确有很多不知到的秘密呢！",
		307, 0, { 402, 405, -1, -1, -1 } },
		{ "太白仙人", "呵呵，世人的污浊真是可笑啊，哈哈哈....",
		308, 0, { 410, -1, -1, -1, -1 } },
		{ "王捕头", "我是洛阳的捕头总管，这里的治安都是我负责。",
		309, 0, { 404, 411, -1, -1, -1 } },
		{ "景阳", "稀奇古怪的东西总是能令人兴奋。",
		310, 0, { 406, 407, -1, -1, -1 } },
		{ "宋书生", "苦读十几年，总该要有个结果吧.....",
		311, 0, { 410, -1, -1, -1, -1 } },
		{ "梦", "人妖之争何时了.....为什么总要有战争.....",
		312, 0, { 408, -1, -1, -1, -1 } },
		{ "总督", "现在的年轻人可真不得了，应该刮目先看了。",
		313, 0, { 409, -1, -1, -1, -1 } },
		{ "路人", "啊，我是出来打酱油的........",
		314, 0, { -1, -1, -1, -1, -1 } }
	};
	NPC npc;
	int num_npc = sizeof(st_npc) / (sizeof(st_npc[0]));
	for (int i = 0; i < num_npc; ++i)
	{
		npc.NpcClear();
		npc.SetName(st_npc[i].name);
		npc.SetTalk(st_npc[i].talk);
		npc.SetID(st_npc[i].ID);
		npc.SetSell(st_npc[i].sell);
		for (int j = 0; j < 5; ++j)
		if (st_npc[i].arr_mission[j] >= 0)
			npc.AddMission(st_npc[i].arr_mission[j]);
		else
			break;
		npcMap.PushNPC(npc);
	}
	return 0;
}
int Control::init_using(UsingMap& usingmap)
{
	struct StUsing{
		string name;
		int ID;
		int money;
		int number;
		int addHP;
		int addMP;
		int percent;
	};
	static StUsing st_using[] = {
		/* name  id   money  num  +HP   +MP   per_or_n   */
		{ "止血草", 1, 15,    0,   10,   0, 0 },
		{ "药瓶", 2,   50,    0,   25,   0, 1 },
		{ "补血药", 3, 40,    0,   25,   0, 0 },
		{ "小补气瓶",4,10,    0,    0,  15, 0 },
		{ "补气瓶", 5, 40,    0,    0,  40, 0 },
		{ "回魔药", 6, 80,    0,    0,  40, 1 },
		{ "狼皮", 7,   80,    0,    0,  0, 0 },
		{ "矿石", 9,   50,    0,    0,  0, 0 },
		{ "铁粉", 8,   23,    0,    0,  0, 0 },
		{ "水晶", 15, 150,    0,    0,  0, 0 },
		{ "虎牙", 17,  90,    0,    0,  0, 0 },
		{ "铁矿", 12,   0,    0,    0,  0, 0 },
		{ "兽皮", 11, 100,    0,    0,  0, 0 },
		{ "怪脚", 14, 160,    0,    0,  0, 0 },
		{ "戒指", 21, 200,    0,    0,  0, 0 },
		{ "金属", 16, 220,    0,    0,  0, 0 },
		{ "木炭", 23, 190,    0,    0,  0, 0 },
		{ "恶魔的碎片", 24, 400,0,  0,  0, 0 },
		{ "天使之翼", 25, 360, 0,   0,  0, 0 }
	};
	Using tmp;
	int num = sizeof(st_using) / sizeof(st_using[0]);
	for (int i = 0; i < num; ++i)
	{
		tmp.SetName(st_using[i].name);
		tmp.SetMoney(st_using[i].money);
		tmp.SetID(st_using[i].ID);
		tmp.SetAddHP(st_using[i].addHP);
		tmp.SetAddMP(st_using[i].addMP);
		tmp.SetPercentOrNo(st_using[i].percent);
		tmp.SetNumber(st_using[i].number);
		usingmap.PushUsing(tmp);
	}
	return true;
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
		{   "恶狼",    800,    5,    5,  8,  4,1,   1,	  0,    1,{ 1, 4, 16, -1 }, { 105, 100, -1, -1 } },
		{ "仓眼狼",    801,    8,    7,  10, 6,0,   1,   0,    1,{ 11, 16, 2, 3 }, { 100, 104, -1, -1 } },
		{ "疯狗",      802,   10,    9,  10,   6,2,  1,  0,    1,{ 9, 11, 16, 3 }, { 102, 103, -1, -1 } },
		{ "僵尸",      803,   10,    9,  12,  8,1,  1,   0,    1,{ 2, 3, 12, 11 }, { 150, 106, 101, -1 } },
		{ "瘟疫僵尸",  804,  12,    10, 13,  9,2,   1,   0,    1,{ 2, 5, 8, 9 }, { 104, 110, 130, -1 } },
		{ "骷髅战士",  805,  15,    12, 18,  10,2,  1,   0,    1,{ 6, 15, 21, 3 }, { 131, 110, 106, 101 } },
		{ "骷髅法师",  806,  18,    12, 13,  11,1,  1,   0,    1,{ 15, 25, 23, 4 }, { 131, 170, 111, 160 } },
		{ "恶魔之虫",  807,  20,    18, 20,  12,3,  1,   0,    1,{ 21, 2, 3, -1 }, { 113, -1, -1, -1 } },
		{ "毒蝎虎",    808,  24,    22, 24,  13,2,  1,   0,    1,{ 17, 14, 11, 4 }, { 151, 111, 170, 141 } },
		{ "铁甲猪",    809,  30,    28, 25,  14,8,  1,   0,    1,{ 8, 9, 2, 4 }, { 171, 132, 112, 160 } },
		{ "独眼腐尸",  810,  35,    32, 30,  17,2,  1,   0,    1,{ 3, 4, 6, 14 }, { 161, 112, 141, -1 } },
		{ "邪恶的山妖", 851, 100,  100, 50,  18,2,  0,   0,    3,{ 2, 3, 4, 25 }, { 150, 160, 171, -1 } },
		{ "独眼秃鹫",  852,  400,  220, 160, 35,6,  0,   0,    5,{ 3, 6, 14, 21 }, { 132, 111, 141, -1 } },
		{ "盐湖水怪",  853,  600,  300, 260, 40,10, 0,   0,    8,{ 3, 6, 21, 25 }, { 161, 107, 171, 113 } },
		{ "魔界首领",  854, 1000,  550, 380, 60,15, 0,   0,   10,{ 3, 6, 1, 25 }, { 113, 171, -1, -1 } }
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
		//初始化装备
		//初始化掉落用品
		for (int j = 0; j < 4; ++j)
		if (st_monster[i].arr_using[j] >= 0)
			mon_tmp.AddUsingList(st_monster[i].arr_using[j]);
		else
			break;
		for (int j = 0; j < 4; ++j)
		if (st_monster[i].arr_weapon[j] >= 0)
			mon_tmp.AddWeaponList(st_monster[i].arr_weapon[j]);
		else
			break;
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
		map.Clear();
		map.SetName(st_map[i].name);
		map.SetID(st_map[i].ID);
		map.SetPosX(st_map[i].x);
		map.SetPosY(st_map[i].y);
		map.SetLevel(st_map[i].level);
		for (int j = 0; j < 10; j++)
		{
			if (st_map[i].arr_npc[j] >= 0)
			{
				map.AddNPC(st_map[i].arr_npc[j]);
			}
			else
			{
				break;
			}
		}
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
		cout << endl << "    修行之路        ver 1.0" << endl;
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