#include "Skeleton.h"


SkeletonWarrior:: SkeletonWarrior(int level)
{
	name = "Skeleton";
	HP = 50 + (level*.8);
	AP = 25 + (level*.7);
	setStr(11 + (level*.6));
	setDef(11 + (level*.6));
	setAcc(9 + (level*.6));
	setLuck(15 + (level*.6));
	speed = .9;
	expGain = 20 * (level*.9);
	goldLooted = 5;
	head->deleteList();
}


SkeletonWarrior::~SkeletonWarrior()
{
}

 
bool SkeletonWarrior::checkItem(Item input)
{
	if (input.getSubtype() != "Sword" || input.getSubtype() != "Metal")
	{
		return false;
	}
	return true;
}

//attack buffed attack
int SkeletonWarrior::strongSlash()
{
	setStr(getStr() + 2);
	return 2;
}

//def buff attack
double SkeletonWarrior::ironSkin()
{
	setDef(getDef() + 2);
	return 2;
}

//acc buff
int SkeletonWarrior::clearSight()
{
	setAcc(getAcc() + 2);
	return 2;
}

//selects the ability 
bool SkeletonWarrior::specialAbilities(int input)
{
	bool success;
	int strBuff;
	double defBuff;
	int accBuff;
	// doesn't use this: int luckBuff;

	int temp;
	static int strBuffTurn = 0;
	static int defBuffTurn = 0;
	static int accBuffTurn = 0;
	static int luckBuffTurn = 0;


	switch (input)
	{
	case 1:
		if (AP > 8)
		{
			strBuff = strongSlash();
			strBuffTurn = 4;
			AP = AP - 8;
			success = true;
		}
		else
		{
			cout << "Not enough AP";
			success = false;
		}

		break;
	case 2:
		if (AP > 8)
		{
			defBuff = ironSkin();
			defBuffTurn = 4;
			AP = AP - 8;
			success = true;
		}
		else
		{
			cout << "Not enough AP";
			success = false;
		}
		success = true;
		break;
	case 3:
		if (AP > 8)
		{
			accBuff = clearSight();
			accBuffTurn = 4;
			AP = AP - 8;
			success = true;
		}
		else
		{
			cout << "not enough AP";
			success = false;
		}
		break;
	default:
		success = false;
	}

	decrementTurnBuff(strBuffTurn, 'S', strBuff);
	decrementTurnBuff(defBuffTurn, 'D', defBuff);
	decrementTurnBuff(accBuffTurn, 'A', accBuff);
	// doesn't use this: decrementTurnBuff(luckBuffTurn, 'L', luckBuff);
	return success;
}

void SkeletonWarrior::decrementTurnBuff(int num, char stat, double buffSize)
{
	if (num > 0)
	{
		num--;
	}
	switch (stat)
	{
	case 'S':
		setStr(revertBuff(getStr(), buffSize));
		break;
	case 'D':
		setDef(revertBuff(getDef(), buffSize));
		break;
	case 'A':
		setAcc(revertBuff(getAcc(), buffSize));
		break;
	case 'L':
		setLuck(revertBuff(getLuck(), buffSize));
		break;
	default:
		cout << "Invalid special\n";
	}
}

double SkeletonWarrior::revertBuff(double current, double buffSize)
{
	return (current - buffSize);
}

