#pragma once
#include "Monster.h"

class Zubat :
	public Monster
{
public:
	Zubat(int level);
	~Zubat();

	/******
	CODE FROM WIZARD
	******/
	bool checkItem(Item input);
	//Apply one turn str buff for an attack
	int fireball();

	//3 turn defense buff
	double stoneWall();

	//3 turn acc buff
	int phaseShift();

	void specialAbilities(int input);

	/*************
	when buff has expired, revert stat to previous value
	Parameters: length of buff, current stat value, size of buff
	***************/
	void decrementTurnBuff(int &num, char stat, double buffSize);

	/**************
	revert buff.
	Parameters: current stat value, buff applied
	returns: debuffed stat
	***************/
	double revertBuff(double current, double buffSize);
	
};

