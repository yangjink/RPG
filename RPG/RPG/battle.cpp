#include "battle.h"
//战斗开始
int Battle::InBattle(Role& role,Monster& monster,MonsterMap& monsterMap)
{
	_whosAttack = ROLEATTACK;
	int temp;
	//怪物重置
	monster.NEW();
	while (true)
	{
		role.PrintHead();
		cout << "战斗中. . . ." << endl;
		cout << "    " << role.GetName() << ":";
		//打印玩家的血
		temp = (role.GetHP() / role.GetHPmax()) * 40;
		for (int i_hit = 0; i_hit<40; ++i_hit)
		if (i_hit<temp)
			cout << '|';
		else
			cout << '.';
		cout << '(' << role.GetHP<< ')';
		//打印怪物的血
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
				int m_money = monster.GetMoney()*((float)(rand() % 10 + 95) / 100);
				role.ChangeMoney(m_money);
				break;
			}
		}
		else//没有死亡的话，就是怪物攻击
		{
			_monstertoRole = GetDemagePoint2(monster, role, GetAttackPoint(monster));
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

int Battle::Fight(Role& role, Monster& monster)
{
	string userInput;
	int temp1, temp2;
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
		temp1 = role.PrintBeg(1);
		if (temp1 != 0)
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
		temp1 = ;
		return temp2;
	}
}