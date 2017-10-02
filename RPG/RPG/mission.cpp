#pragma once
#include "misssion.h"

Mission::Mission()
{
	_ID = 0;
	_name = " no string ";
	_info = " no string ";
	_state = 0;
	_lock = 0;
	_circle = 1;
	_level = 0;
	_unlockmap = -1;
}
//…Ë÷√ Ù–‘
int Mission::SetTalkBefore(string& talk)
{
	_talkbefore = talk;
	return 1;
}
int Mission::SetTalkBeing(string& talk)
{
	_talkbeing = talk;
	return 1;
}
int Mission::SetTalkDone(string& talk)
{
	_talkdone = talk;
	return 1;
}
int Mission::SetMsnInfo(string& info)
{
	_info = info;
	return 1;
}
int Mission::PushGiftList(int id)
{
	_giftList.push_back(id);
	return 1;
}
int Mission::ClearGiftList()
{
	_giftList.clear();
	return 1;
}
int Mission::SetLock(int lk)
{
	_lock = lk;
	return _lock;
}
int Mission::SetUnlockMap(int id)
{
	_unlockmap = id;
	return id;
}
int Mission::SetState(int ss)
{
	_state = ss;
	return ss;
}
int Mission::SetLevel(int le)
{
	_level = le;
	return le;
}
int Mission::SetID(int id)
{
	_ID = id;
	return id;
}
int Mission::SetName(string name)
{
	_name = name;
	return 1;
}
int Mission::SetCircle(int cir)
{
	_circle = cir;
	return 1;
}
int Mission::GetID()
{
	return _ID;
}
string Mission::GetName()
{
	return _name;
}
int Mission::GetState()
{
	return _state;
}

list<int> Mission::GetGiftList()
{
	return _giftList;
}

string Mission::GetTalkBefore()	
{
	return _talkbefore;
}

string Mission::GetTalkBeing()
{
	return _talkbeing;
}

string Mission::GetTalkDone()	
{
	return _talkdone;
}

string Mission::GetInfo()
{
	return _info;
}

int Mission::GetCircle()
{
	return _circle;
}

int Mission::GetLock()
{
	return _lock;
}

int Mission::GetUnlockMap()
{
	return _unlockmap;
}

int Mission::GetLevel()
{
	return _level;
}