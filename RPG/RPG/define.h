#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <list>
#include <set>
#include <map>
#include <fstream>
#include <windows.h>
#include <math.h>
using namespace std ;

#include "battle.h"
#include "map.h"
#include "misssion.h"
#include "monster.h"
#include "npc.h"
#include "role.h"
#include "using.h"
#include "weapon.h"
#include "skill.h"
#include "control.h"

#define SLEEPTIME 1000

class Role;
class Monster;
class MonsterMap;
class Mission;
class Skill;
class Using;
class Weapon;
class NPC;
class Map;
class MapList;
class Control;

inline void print_line_sep()
{
	for (int i = 0; i<55; ++i)
		cout << '-';
	cout << endl;
}
