#pragma once
#include "npc.h"

//NPC
//清理
bool NPC::NpcClear()
{
	//任务的清理
	return true;
}
//增加任务
bool NPC::AddMission(int)
{
	return true;
}

//set
bool NPC::SetName(string name)
{
	_name = name;
	return true;
}
int NPC::SetSell(int sell)
{
	_sell = sell;
	return _sell;
}
int NPC::SetID(int id)
{
	_ID = id;
	return _ID;
}
bool NPC::SetTalk(string talk)
{
	_talk = talk;
	return true;
}

//get
int NPC::GetID()
{
	return _ID;
}
string NPC::GetName()
{
	return _name;
}
int NPC::GetSell()
{
	return _sell;
}
string NPC::GetTalk()
{
	return _talk;
}

//当选中npc时的对话
int NPC::Talk(Role& role, UsingMap& usingMap, MapList& mapList, MonsterMap& monsterMap)
{
	string userinput;
	while (true)
	{
		role.PrintHead();
		switch (_sell)
		{
		case SELLNOTHING:
			Speak();
			break;
			return 1;	

		case SELLUSING:

			cout << "[药店]" << _name << ":" << endl;
		    cout << "  1:买物品  2:卖物品  0:退出" << endl;
			for (int i = 0; i < 55; ++i)
				cout << '-';
			cout << endl;
			while (true)
			{
				cin >> userinput;
				if (userinput[0] == '1')
				{
					SellUsing(role, usingMap);
					break;
				}
				if (userinput[0] == '2')
				{
					RoleSell(role);
					break;
				}if (userinput[0] == '0')
					return 1; 
			} 
			break;
		case SELLWEAPON:
			cout << "[装备店]" << _name << ":" << endl;
			cout << "  1:买装备  2:卖装备  0:退出" << endl;
			for (int i = 0; i < 55; ++i)
				cout << '-';
			cout << endl;
			while (true)
			{
				cin >> userinput;
				if (userinput[0] == '1')
				{
					SellWeapon(role);//不完善
					break;
				}
				if (userinput[0] == '2')
				{
					RoleSell(role);
					break;
				}
				if (userinput[0] == '0')
					return 1;
			}
			break;
		}
		
	}
}
//当npc是商人时下面两个接口有效
int NPC::SellUsing(Role& role, UsingMap& usingMap)
{
	//一页最多打印9个
	int maxPrint = 9;
	//当前页
	int page = 0;
	//当前页面物品需要被打印的值，不能超过最大打印
	int num_in_cur_page = 0;
	string userinput;
	while (true)
	{
		role.PrintHead();
		//当前页打印的数量
		num_in_cur_page = usingMap.GetSize() - page*maxPrint;
		if (num_in_cur_page > 9)
			num_in_cur_page = 9;
		usingMap.InitItr();
		for (int i = 0; i < num_in_cur_page; i++)
		{
			cout << "   " << i + 1 << ":";
			usingMap.GetCurUsing().PringUsingInfo();
			usingMap.Next();
		}
		for (int i = 0; i < 55; i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "1~" << num_in_cur_page << "：选择购买";
		if (page > 0)
		{
			cout << "Z";
		}
		cout << "/";
		if ((page + 1)*maxPrint <= usingMap.GetSize())
		{
			cout << "X";
		}
		cout << ":翻页  0：退出" << endl;
		for (int i = 0; i < 55; i++)
		{
			cout << "-";
		}
		cout << endl;

		//用户输入
		while (true)
		{
			cin >> userinput;
			if (userinput[0] == '0')
				return 0;
			if ((userinput[0] == 'X' || userinput[0] == 'x') && (page + 1)*maxPrint<=usingMap.GetSize())
			{
				++page;
				break;
			}
			if ((userinput[0] == 'Z' || userinput[0] == 'z') && page>0)
			{
				--page;
				break;
			}
			if (userinput[0] - '0' >= 1 && userinput[0] - '0' <= num_in_cur_page)
				break;
		}
		if (userinput[0] - '0' >= 1 && userinput[0] - '0' <= num_in_cur_page)
		{
			usingMap.InitItr();
			for (int i = 1; i < page*maxPrint + (userinput[0] - '0'); ++i)
			{
				usingMap.Next();
			}
			role.PrintHead();
			if ()
		}


	}
}
//商店出售的都是白装，但是属性会有随机变化，且价格是两倍
int NPC::SellWeapon(Role&);
//当角色出售物品时
int NPC::RoleSell(Role&);
//当npc不是商人时，npc的对话，并且任务也是从次函数中接受
int NPC::Speak();
//打印npc信息
int NPC::PrintNpcInfo();

//NPCMap
//NPC数目
int NPCMap::GetNPCNum();
//NPC的拷贝
NPC NPCMap::GetNPC(int id);
//NPC的指针
NPC* NPCMap::GetNPCPtr(int id);
//添加一个NPC
int NPCMap::PushNPC(NPC);

//_itr_npc
bool NPCMap::InitItr();
bool NPCMap::Next();
bool NPCMap::End();

NPC* NPCMap::GetCurNPC();