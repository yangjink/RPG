#pragma once
#include "define.h"

class Using;
class Weapon;
class Monster;
class Role;
class MonsterMap;
class UsingMap;

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
	//������Ҫ�������
	//�ַ�Ϊ�˺͹����
	int GetAttackPoint(Role&);
	int GetAttackPoint(Monster&);
	//ʵ�ʵ��˺�ֵ��ҪmissҪ�ɼ����������
	//�˶Թ���
	int GetDamagePoint(Role&, Monster&,const int&);
	//�������
	int GetDamagePoint(Monster&, Role&, const int&);
	//ս�����������ɵ���Ʒʱ�����
	int GenerateDroped(Monster&,UsingMap&);//װ��
	//����ʲô��Ʒ
	int PickUp(Role&);
	//ս������ҵĲ���
	//����ֵ< 0 ��ζ�� miss
	//== 0 ʲôҲû��
	// > 0 �Թ�����˺�
	//��¼�������ܹ��ܡ�������
	int Fight(Role&,Monster&);
};