#include "battle.h"
//ս����ʼ
int Battle::InBattle(Role& role,Monster& monster,MonsterMap& monsterMap)
{
	_whosAttack = ROLEATTACK;
	int temp;
	//��������
	monster.NEW();
	while (true)
	{
		role.PrintHead();
		cout << "ս����. . . ." << endl;
		cout << "    " << role.GetName() << ":";
		//��ӡ��ҵ�Ѫ
		temp = (role.GetHP() / role.GetHPmax()) * 40;
		for (int i_hit = 0; i_hit<40; ++i_hit)
		if (i_hit<temp)
			cout << '|';
		else
			cout << '.';
		cout << '(' << role.GetHP<< ')';
		//��ӡ�����Ѫ
		cout << endl << "   " << monster.GetName() << ":";
		temp = (monster.GetHP() / monster.GetHPmax()) * 40;
		for (int i_hit = 0; i_hit<40; ++i_hit)
		if (i_hit<temp)
			cout << '|';
		else
			cout << '.';
		cout << '(' << monster.GetHP() << ')';
		cout << endl;

		
		if (_whosAttack == ROLEATTACK)
		{
			_roletoMonster = Fight(role, monster);
			
			if (_roletoMonster == 0)
			{
				continue;
			}
			if (_roletoMonster<0) 
			{ 
				cout << "you miss!!" << endl;
			}
			else
			{
				monster.ChangeHP(-_roletoMonster);
				cout << "���" << monster.GetName() << "�����" << _roletoMonster << "�˺�" << endl;
			}
			Sleep(SLEEPTIME);
			//ת������
			_whosAttack = MONSTERATTACK;
			//�жϹ���������û
			if (monster.Dead())
			{
				//����������˾�Ҫ���ƺ���������Ҫ�ڹ����б�����������������
				Monster* itr_monster_set;
				for (monsterMap.InitMonsterItr(); monsterMap.EndMonsterItr(); monsterMap.NextMonsterItr())
				{
					itr_monster_set = monsterMap.GerCurMonsterRef();
					if (itr_monster_set->GetID() == monster.GetID())
					{
						//�ҵ���֮��������Ϊ���� 0����
						itr_monster_set->SetDie(0);
						break;
					}
					if (itr_monster_set == NULL)
					{
						break;
					}
		
				}
				//��õ�ǮҪ��һ�������
				int m_money = monster.GetMoney()*((float)(rand() % 10 + 95) / 100);
				role.ChangeMoney(m_money);
				break;
			}
		}
		else//û�������Ļ������ǹ��﹥��
		{
			_monstertoRole = GetDemagePoint2(monster, role, GetAttackPoint(monster));
			if (_monstertoRole<0){ 
				cout << monster.GetName() << "����ˣ�" << endl;
			}
			else{
				role.ChangeHP(-_monstertoRole);
				cout << monster.GetName() << "���������" << _monstertoRole << "�˺�" << endl;
			}
			Sleep(SLEEPTIME);
			_whosAttack = ROLEATTACK;
			//����������
			if (role.Dead())
			{
				break;
			}

		}//end of else 
	}//end of while
	return 1;
}

int Battle::Fight(Role& role, Monster& monster)
{
	string userInput;
	int temp1, temp2;
	char select;
	print_line_sep();
	cout << "1:��ͨ����  k:ʹ�ü���   b:�鿴��Ʒ  " << endl;
	while (1)
	{
		print_line_sep();
		cin >> userInput;
		select = userInput[0];
		if (select == 'B' || select == 'b' || select == '1' || select == 'k' || select == 'K')
		{
			break;
		}
	}
	if (select == 'B' || select == 'b')
	{
		//��ӡ����
		temp1 = role.PrintBeg(1);
		if (temp1 != 0)
		{
			return 0;
		}
	}
	else if (select == 'K' || select == 'k')
	{
		//ʹ�ü���
	}
	else
	{
		temp1 = ;
		return temp2;
	}
}