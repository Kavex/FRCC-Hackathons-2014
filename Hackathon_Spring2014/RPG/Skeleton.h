#pragma once
#include "Monster.h"
class SkeletonWarrior :
	public Monster
{
public:
	SkeletonWarrior(int level);
	~SkeletonWarrior();

	bool checkItem(Item input);	//for the pure virtual


	/****
	To run the special abilities
	*****/
	int strongSlash();
	double ironSkin();
	int clearSight();
	bool specialAbilities(int input);
	void decrementTurnBuff(int num, char stat, double buffSize);
	double SkeletonWarrior::revertBuff(double current, double buffSize);
};

