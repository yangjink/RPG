#include "battle.h"
//战斗开始
int Battle::InBattle(Role& role,Monster& monster,MonsterMap& monsterMap)
{
	_whosAttack = ROLEATTACK;
	int tmp;
	//怪物重置
	monster.NEW();
	while (true)
	{
		role.PrintHead();
		cout << "战斗中. . . ." << endl;
		cout << "    " << role.GetName() << ":";
		//打印玩家的血
		tmp = (role.GetHP() / role.GetHPmax()) * 40;
		for (int i_hit = 0; i_hit<40; ++i_hit)
		if (i_hit<tmp)
			cout << '|';
		else
			cout << '.';
		cout << '(' << role.GetHP()<< ')';
		//打印怪物的血
		cout << endl << "   " << monster.GetName() << ":";
		tmp = (monster.GetHP() / monster.GetHPmax()) * 40;
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
				cout << "你对" << monster.GetName() << "造成了" << _roletoMonster << "伤害" << endl;
			}
			Sleep(SLEEPTIME);
			//转换攻击
			_whosAttack = MONSTERATTACK;
			//判断怪物死亡了没
			if (monster.Dead())
			{
				//如果其死亡了就要做善后工作，首先要在怪物列表里面声明其死亡了
				Monster* itr_monster_set;
				for (monsterMap.InitMonsterItr(); monsterMap.EndMonsterItr(); monsterMap.NextMonsterItr())
				{
					itr_monster_set = monsterMap.GerCurMonsterRef();
					if (itr_monster_set->GetID() == monster.GetID())
					{
						//找到了之后将其设置为死亡 0死亡
						itr_monster_set->SetDie(0);
						break;
					}
					if (itr_monster_set == NULL)
					{
						break;
					}
		
				}
				//获得的钱要是一个随机数
				int m_money = (int)monster.GetMoney()*((float)(rand() % 10 + 95) / 100);
				role.ChangeMoney(m_money);
				break;
			}
		}
		else//没有死亡的话，就是怪物攻击
		{
			_monstertoRole = GetDamagePoint(monster, role, GetAttackPoint(monster));
			if (_monstertoRole<0){ 
				cout << monster.GetName() << "打空了！" << endl;
			}
			else{
				role.ChangeHP(-_monstertoRole);
				cout << monster.GetName() << "对你造成了" << _monstertoRole << "伤害" << endl;
			}
			Sleep(SLEEPTIME);
			_whosAttack = ROLEATTACK;
			//如果玩家死亡
			if (role.Dead())
			{
				break;
			}

		}//end of else 
	}//end of while
	return 1;
}

//当战斗结束后
int Battle::AfterBattle(Role& role, Monster& monster, UsingMap& usingmap)//装备技能
{
	string userInput;
	if (monster.Dead())
	{
		monster.PrintDead();
		role.ChangeExp(monster.GetExpPoint(),1);
		GenerateDroped(monster,usingmap);
		cout << "1:确认   0:继续 " << endl;
		while (1)
		{
			cin >> userInput;
			//决定捡东西
			if (userInput[0] == '1')
			{
				break;
			}
			//不捡东西
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

//战斗结束后生成的物品时随机的
int Battle::GenerateDroped(Monster& monster, UsingMap& usingmap)//装备
{
	_usingDropList.clear();
	_weaponDropList.clear();
	//物品数量
	int num_d = monster.GetUsingNum();
	int index = 0;
	if (num_d > 0)
	{
		//掉落数量
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
	//装备数量
	num_d = monster.GetWeaponNum();
	index = 0;
	if (num_d > 0)
	{
		index = rand() % num_d + 1;
		//掉落装备
	}//if

	return 1;
}

//拿起什么物品
int Battle::PickUp(Role&)
{
	string userInpur;
	
	while (1)
	{

	}
}
//攻击需要是随机数
//又分为人和怪物的
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
//实际的伤害值，要miss要由级别差来决定
//人对怪物
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
//怪物对人
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
	cout << "1:普通攻击  k:使用技能   b:查看物品  " << endl;
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
		//打印背包
		tmp1 = role.PrintBeg(1);
		if (tmp1 != 0)
		{
			return 0;
		}
	}
	else if (select == 'K' || select == 'k')
	{
		//使用技能
	}
	else
	{
		tmp1 = GetAttackPoint(role);
		tmp2 = GetDamagePoint(role, monster, tmp1);
		return tmp2;
	}
	return 0;
}