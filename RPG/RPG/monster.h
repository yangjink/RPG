#pragma once
#include "define.h"

enum MON_LOCK{
	MON_LOCK,
	MON_UNLOCK
};
class Monster
{
private:
	//��������
	int _ID;
	string _name;
	int _attackPoint;
	int _defendPoint;
	int _HP;
	int _HPmax;
	int _level;
	//ɱ��������õ�exp
	int _expPoint;
	//ɱ��������õĽ�Ǯ
	int _money;
	//�������жϹ����ǲ��ǿɼ���
	//MON_LOCK  MON_UNLOCK
	int _lock;
	//����״̬��0��������1�����ţ�
	int _die;
	//��������ʹ����Ʒ
	//��������װ��
public:
	//��������
	int SetID(int id);
	int SetName(string name);
	int SetAttackPoint(int attack);
	int SetDefendPoint(int defend);
	int SetHP(int hp);
	int SetHPmax(int hpmax);
	int SetExpPoint(int exp);
	int SetMoney(int money);
	int SetLock(int tag);
	int SetLevel(int level);
	int SetDie(int die);
	//��ʼ��������Ʒ
	int MonsterClear();
	//���õ�����Ʒ
	//���õ���װ��
	//�õ�����
	int GetDie();
	string GetName();
	int GetID();
	int GetAttackPoint();
	int GetDefendPoint();
	int GetHP();
	int GetHPmax();
	int GetExpPoint();
	int GetMoney();
	int GetLock();
	int GetLevel();

	//�ı�Ѫ��
	int ChangeHP(const int& chp);
	//�ж��Ƿ�����
	bool Dead();
	//�������ϢӦ���Ǹ����Ｖ���йصģ�
	//����Ļ�����Ϸ����л�ܲ�,��������᷵�ظı��ĸ�����
	Monster Generate(const int& level = 0);
	//��ӡ������Ϣ
	int NEW();
	int PrintDead();
};
//�޸�֮�����map
//����set�й���ıȽ�ʵ��id�����бȽ�
//class com{
//public:
//	bool operator()(Monster& m1, Monster& m2) const
//	{
//		return m1.GetID() > m2.GetID();
//	}
//};
//����map
class MonsterMap
{
private:
	//��������
	map<int,Monster> _monsterMap;
	map<int,Monster>::iterator _itr_monster;
public:
	//�Թ�������ĵ�������ʼ��
	int InitMonsterItr();
	int NextMonsterItr();
	int EndMonsterItr();
	//���ӹ������Ѿ����ڣ��Ͳ�����ӣ�
	bool AddMonster(Monster&);
	//���ڵ�ǰ����ĸ���
	Monster GetCurMonster();
	//��ǰ�����ָ��
	Monster* GerCurMonsterRef();
	
	//�����ض�����Ŀ���
	Monster GetMonster(const int&);
	//���ù������
	int SetLock(const int&, const int&);

};
