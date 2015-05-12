#pragma once
#include "Character.h"
class Wizard :
	public Character
{
public:
	Wizard();
	~Wizard();

	bool checkItem(Item input);
	//Apply one turn str buff for an attack
	int fireball();

	//3 turn defense buff
	int stoneWall();

	//3 turn acc buff
	int phaseShift();

	void specialAbilities(int input);

	/*************
	when buff has expired, revert stat to previous value
	Parameters: length of buff, current stat value, size of buff
	***************/
	void decrementTurnBuff(int &num, char stat, int buffSize);

	/**************
	revert buff.
	Parameters: current stat value, buff applied
	returns: debuffed stat
	***************/
	int revertBuff(int current, int buffSize);
};

