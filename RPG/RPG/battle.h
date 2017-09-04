#pragma once
#include "define.h"

enum AttackObject
{
	ROLEATTACK,
	MONSTERATTACK
};

class Battle
{
private:
	
	//����˭���ڹ���
	int _whosAttack;
	int _roletoMonster;
	int _monstertoRole;
	//������������Ʒ
	list<Using> _usingDropList;
	list<Using>::iterator _itr_using;
	//����������װ��
	list<Weapon> _weaponDropList;
	list<Weapon>::iterator _itr_weapon;
public:
	Battle()
	{};

	//��ս�������ֱ��ս������
	int InBattle(Role&,Monster&,MonsterMap&);
	//��ս��������
	int AfterBattle(Role& , Monster&, UsingMap&);//װ������


	int GenerateDroped(Monster&,UsingMap&);//װ��
	//�Ƿ�������Ʒ
	int PickUp(Role&);
	//ս������ҵĲ���
	//����ֵ< 0 ��ζ�� miss
	//== 0 ʲôҲû��
	// > 0 �Թ�����˺�
	//��¼�������ܹ��ܡ�������
	int Fight(Role&,Monster&);
};