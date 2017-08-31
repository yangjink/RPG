#pragma once
#include "npc.h"

//NPC
//����
bool NPC::NpcClear()
{
	//���������
	return true;
}
//��������
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

//��ѡ��npcʱ�ĶԻ�
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

			cout << "[ҩ��]" << _name << ":" << endl;
		    cout << "  1:����Ʒ  2:����Ʒ  0:�˳�" << endl;
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
			cout << "[װ����]" << _name << ":" << endl;
			cout << "  1:��װ��  2:��װ��  0:�˳�" << endl;
			for (int i = 0; i < 55; ++i)
				cout << '-';
			cout << endl;
			while (true)
			{
				cin >> userinput;
				if (userinput[0] == '1')
				{
					SellWeapon(role);//������
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
//��npc������ʱ���������ӿ���Ч
int NPC::SellUsing(Role& role, UsingMap& usingMap)
{
	//һҳ����ӡ9��
	int maxPrint = 9;
	//��ǰҳ
	int page = 0;
	//��ǰҳ����Ʒ��Ҫ����ӡ��ֵ�����ܳ�������ӡ
	int num_in_cur_page = 0;
	string userinput;
	while (true)
	{
		role.PrintHead();
		//��ǰҳ��ӡ������
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
		cout << "1~" << num_in_cur_page << "��ѡ����";
		if (page > 0)
		{
			cout << "Z";
		}
		cout << "/";
		if ((page + 1)*maxPrint <= usingMap.GetSize())
		{
			cout << "X";
		}
		cout << ":��ҳ  0���˳�" << endl;
		for (int i = 0; i < 55; i++)
		{
			cout << "-";
		}
		cout << endl;

		//�û�����
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
//�̵���۵Ķ��ǰ�װ���������Ի�������仯���Ҽ۸�������
int NPC::SellWeapon(Role&);
//����ɫ������Ʒʱ
int NPC::RoleSell(Role&);
//��npc��������ʱ��npc�ĶԻ�����������Ҳ�ǴӴκ����н���
int NPC::Speak();
//��ӡnpc��Ϣ
int NPC::PrintNpcInfo();

//NPCMap
//NPC��Ŀ
int NPCMap::GetNPCNum();
//NPC�Ŀ���
NPC NPCMap::GetNPC(int id);
//NPC��ָ��
NPC* NPCMap::GetNPCPtr(int id);
//���һ��NPC
int NPCMap::PushNPC(NPC);

//_itr_npc
bool NPCMap::InitItr();
bool NPCMap::Next();
bool NPCMap::End();

NPC* NPCMap::GetCurNPC();