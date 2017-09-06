#include "battle.h"
//ս����ʼ
int Battle::InBattle(Role& role,Monster& monster,MonsterMap& monsterMap)
{
	_whosAttack = ROLEATTACK;
	int tmp;
	//��������
	monster.NEW();
	while (true)
	{
		role.PrintHead();
		cout << "ս����. . . ." << endl;
		cout << "    " << setw(6)<<role.GetName() << ":";
		//��ӡ��ҵ�Ѫ
		tmp = int(float(role.GetHP()) / float(role.GetHPmax())*40);
		for (int i_hit = 0; i_hit<40; ++i_hit)
		if (i_hit<tmp)
			cout << '|';
		else
			cout << '.';
		cout << '(' << role.GetHP()<< ')';
		//��ӡ�����Ѫ
		cout << endl << "    " <<setw(6)<< monster.GetName() << ":";
		tmp = int(float(monster.GetHP()) / float(monster.GetHPmax()) * 40);
		for (int i_hit = 0; i_hit<40; ++i_hit)
		if (i_hit<tmp)
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
				int m_money = (int)monster.GetMoney()*((float)(rand() % 10 + 95) / 100);
				role.ChangeMoney(m_money);
				break;
			}
		}
		else//û�������Ļ������ǹ��﹥��
		{
			_monstertoRole = GetDamagePoint(monster, role, GetAttackPoint(monster));
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

//��ս��������
int Battle::AfterBattle(Role& role, Monster& monster, UsingMap& usingmap)//װ������
{
	string userInput;
	if (monster.Dead())
	{
		monster.PrintDead();
		role.ChangeExp(monster.GetExpPoint(),1);
		GenerateDroped(monster,usingmap);
		print_line_sep();
		cout << "1:ȷ��   0:���� " << endl;
		print_line_sep();
		while (1)
		{
			cin >> userInput;
			//��������
			if (userInput[0] == '1')
			{
				break;
			}
			//������
			if (userInput[0] == '0')
			{
				break;
			}
		}
		if (userInput[0] == '1')
		{
			PickUp(role);
		}
	}
	else if (role.Dead())
	{
		role.NewLife();
	}
	return 1;
}

//ս�����������ɵ���Ʒʱ�����
int Battle::GenerateDroped(Monster& monster, UsingMap& usingmap)//װ��
{
	_usingDropList.clear();
	_weaponDropList.clear();
	//��Ʒ����
	int num_d = monster.GetUsingNum();
	int index = 0;
	if (num_d > 0)
	{
		//��������
		int num = rand()%3;
		while (num--)
		{
			index = rand() % num_d + 1;
			int i = 1;
			for (monster.InitUsingItr(); !monster.EndUsingItr();monster.NextUsingItr(),++i)
			{
				if (i == index)
				{
					_usingDropList.push_back(usingmap.GetUsing(monster.GetCurUsingID()));
					break;
				}
			}
		}//while
	}//if
	//װ������
	num_d = monster.GetWeaponNum();
	index = 0;
	if (num_d > 0)
	{
		index = rand() % num_d + 1;
		//����װ��
	}//if

	return 1;
}

//����ʲô��Ʒ
int Battle::PickUp(Role& role)
{
	string userInpur;
	
	while (1)
	{
		role.PrintHead();
		int num = 1;
		if (_usingDropList.empty() && _weaponDropList.empty())
		{
			break;
		}
		cout << "��������ˣ�" << endl;
		if (!_usingDropList.empty())
		{
			for (_itr_using = _usingDropList.begin(); _itr_using != _usingDropList.end(); ++_itr_using)
			{
				cout << "---" << num++ << ":" << _itr_using->GetName() << endl;
			}
		}
		if (!_weaponDropList.empty())
		{
			for (_itr_weapon = _weaponDropList.begin(); _itr_weapon != _weaponDropList.end(); ++_itr_weapon)
			{
				cout << "---" << num++ << ":";
				//װ����Ϣ
			}
		}
		cout << "--------------------please select--------------------" << endl;
		while (1)
		{
			cin >> userInpur;
			if (userInpur[0]>'0'&&userInpur[0] <= int(_usingDropList.size() + _weaponDropList.size()) + '0')
				break;
			if (userInpur[0] == 'B' || userInpur[0] == 'b')
				break;
			if (userInpur[0] == '0')
				break;
		}
		if (userInpur[0] == 'b' || userInpur[0] == 'B')
		{
			role.PrintBeg();
			break;
		}
		else if (userInpur[0] - '0' <= int(_usingDropList.size()))
		{
			int i = 0;
			for (i = 1, _itr_using = _usingDropList.begin();i<userInpur[0] - '0'; ++_itr_using, ++i);
			role.PickUp(*_itr_using);
			_usingDropList.erase(_itr_using);
		}
		else  //��װ��
		{
	
		}
	}
	return 1;
}
//������Ҫ�������
//�ַ�Ϊ�˺͹����
int Battle::GetAttackPoint(Role& role)
{
	int tmp1, tmp2;
	tmp1 = rand() % (role.GetAttackPoint() * 2 / 5);
	tmp2 = role.GetAttackPoint() * 4 / 5 + tmp1;
	return tmp2;
}
int Battle::GetAttackPoint(Monster& monster)
{
	int tmp1, tmp2;
	tmp1 = rand() % (monster.GetAttackPoint()* 2 / 5);
	tmp2 = monster.GetAttackPoint() * 4 / 5 + tmp1;
	return tmp2;
}
//ʵ�ʵ��˺�ֵ��ҪmissҪ�ɼ����������
//�˶Թ���
int Battle::GetDamagePoint(Role& role, Monster& monster, const int& attackPoint)
{
	int missNum;
	int tmp = 0;
	int missOrno;
	missOrno = rand() % 100;

	missNum = (monster.GetLevel() - role.GetLevel()) * 5;
	missNum = missNum > 30 ? 30 : missNum;
	if (missOrno < missNum)
	{
		return -1;
	}
	else
	{
		tmp = attackPoint;
		tmp = tmp - monster.GetDefendPoint();
		if (tmp <= 0)
		{
			tmp = 1;
		}
		return tmp;
	}
}
//�������
int Battle::GetDamagePoint(Monster& monster, Role& role, const int& attackPoint)
{
	int missNum;
	int tmp = 0;
	int missOrno;
	missOrno = rand() % 100;

	missNum = (role.GetLevel() - monster.GetLevel()) * 5;
	missNum = missNum > 30 ? 30 : missNum;
	if (missOrno < missNum)
	{
		return -1;
	}
	else
	{
		tmp = attackPoint;
		tmp = tmp - role.GetDefendPoint();
		if (tmp <= 0)
		{
			tmp = 1;
		}
		return tmp;
	}
}
int Battle::Fight(Role& role, Monster& monster)
{
	string userInput;
	int tmp1, tmp2;
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
		tmp1 = role.PrintBeg(1);
		if (tmp1 != 0)
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
		tmp1 = GetAttackPoint(role);
		tmp2 = GetDamagePoint(role, monster, tmp1);
		return tmp2;
	}
	return 0;
}