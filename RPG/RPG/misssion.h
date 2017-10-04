#pragma once
#include "define.h"

enum msn_state
{
	//任务状态
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
//是否是循环任务
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
	//根据任务的状态不同，对话的内容
	string _talkbefore;
	string _talkbeing;
	string _talkdone;
public:
	//设置属性
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
	virtual int HandOnMsn();//交付
	virtual int DoneMsn();
	virtual int CanSeeMsn();
};