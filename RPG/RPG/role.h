#pragma once
#include "define.h"
//����ģ��
//
class Using;
class Weapon;
class Role
{
private:
	string _name;
	int _money;
	int _HP;
	int _HPmax;
	int _MP;
	int _MPmax;
	int _expMax;
	int _exp;
	int _level;
	int _attackPoint;
	int _defendPoint;

	int posX;//��ǰλ��
	int posY;

	//��ɫ�ı���
	list<Using> _usingList;
	list<Using>::iterator _itr_using;
	//���ϵ�װ��
	//����
public:
	//������Ϣ
	int SetName(string);
	int SetMoney(int);
	int SetHP(int);
	int SetHPmax(int);
	int SetMP(int);
	int SetMPmax(int);
	int SetExp(int);
	int SetExpMax(int);
	int SetLevel(int);
	int SetAttackPoint(int);
	int SetDefendPoint(int);

	//���ñ���
	bool InitUsingItr();
	bool NextUsingItr();
	bool EndUsingItr();
	Using GetCurUsing();
	//���붫��
	int PickUp(Using&);
	int PickUp(Using&, int);
	int PickUp(Weapon);
    //ʹ����Ʒ ����1�ɹ�ʹ�� ����0��ʹ����Ʒ
	int UseUsing(Using&);
	int LoseUsing(int, int);
	//���۶���
	int Sell();
	//�õ�������Ϣ
	string GetName();
	int GetMoney();
	int GetHP();
	int GetHPmax();
	int GetMP();
	int GetMPmax();
	int GetExp();
	int GetExpMax();
	int GetLevel();
	int GetAttackPoint();
	int GetDefendPoint();
	//�ı�����,���趨һ��������1��ӡ��0����ӡ
	int ChangeName(const string);
	int ChangeMoney(const int& );
	int ChangeHP(const int&, const int& tag = 0);
	int ChangeHPmax(const int& );
	int ChangeMP(const int&, const int& tag = 0);
	int ChangeMPmax(const int& );
	int ChangeExp(const int&,const int& tag = 0 );//ͬʱ��������������
	int ChangeExpMax(const int& );
	//��ӡ������ɫ��Ϣ
	int PrintHead();
	//��ӡ������Ϣ
	int PrintInfo();
	//��ɫ����
	int LevelUp();
	//�жϽ�ɫ�Ƿ����
	bool Dead();
	//�����������ʼ�µ����̣���ʵֻ�Ǽ���һЩexp
	int NewLife();
	//��Ϸ��ʼ����ʼ��
	int Initialize();
	//��ӡ������ͬʱҲǣ��ʹ��
	int PrintBeg(int battleOrNot = 0);
};
