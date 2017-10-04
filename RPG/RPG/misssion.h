#pragma once
#include "define.h"

enum msn_state
{
	//����״̬
	MSN_BEFORE,
	MSN_BEING,
	MSN_DONE,
	MSN_NONE
};
enum lock
{
	MSN_LOCK,
	MSN_UNLOCK
};
//�Ƿ���ѭ������
enum msn_cir
{
	MSN_NOCIR,
	MSN_CIRCLE
};
class Mission
{
private:
	int _ID;
	string _name;
	string _info;
	int _state;
	int _lock;
	int _circle;
	int _level;

	int _unlockmap;
	list<int> _giftList;
	list<int>::iterator _itr_gift;
	//���������״̬��ͬ���Ի�������
	string _talkbefore;
	string _talkbeing;
	string _talkdone;
public:
	//��������
	int SetTalkBefore(string&);
	int SetTalkBeing(string&);
	int SetTalkDone(string&);
	int SetMsnInfo(string&);
	int PushGiftList(int);
	int ClearGiftList();
	int SetLock(int);
	int SetUnlockMap(int);
	int SetState(int);
	int SetLevel(int);
	int SetID(int);
	int SetName(string);
	int SetCircle(int);
	
	int GetID();
	string GetName();
	int GetState();

	list<int> GetGiftList();
	string GetTalkBefore();	
	string GetTalkBeing();	
	string GetTalkDone();	
	string GetInfo();	
	int GetCircle(); 
	int GetLock();
	int GetLevel();
	int GetUnlockMap();
	
	virtual int TaliMsn();
	virtual int AcceptMsn();
	virtual int IsMsnCompleted();
	virtual int HandOnMsn();//����
	virtual int DoneMsn();
	virtual int CanSeeMsn();
};