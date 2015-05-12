#include "Zubat.h"


Zubat::Zubat(int level)
{
	name = "Zubat";
	HP = 30 + (level*.6);
	AP = 20 + (level*.6);
	setStr(10);
	setDef(8 + (level*.6));
	setAcc(14 + (level*.6));
	setLuck(5 + (level*.6));
	speed = 1.2;
	expGain = 15 * (level*.6);
	goldLooted = 10 * (level*.4);
	head->deleteList();
}


Zubat::~Zubat()
{
}



//Apply one turn str buff for an attack
int Zubat::fireball()
{
	//cout << "The wizard summons a fiery inferno and throws a fireball.\n";
	setStr(getStr() + 4);
	return 4;
}

//3 turn defense buff
double Zubat::stoneWall()
{
	//cout << "A Stone wall is erected between the wizard and their attacker.\n";
	setDef(getDef() + 3);
	return 3;
}

int Zubat::phaseShift()
{
	//cout << "The Wizard steps between planes, enhancing their accuracy\n";
	setAcc(getAcc() + 2);
	return 2;
}

void Zubat::specialAbilities(int input)
{
	int strBuff = 0;
	double defBuff = 0;
	int accBuff = 0;
	int luckBuff = 0;

	static int strBuffTurn = 0;
	static int defBuffTurn = 0;
	static int accBuffTurn = 0;
	static int luckBuffTurn = 0;

	decrementTurnBuff(strBuffTurn, 'S', strBuff);
	decrementTurnBuff(defBuffTurn, 'D', defBuff);
	decrementTurnBuff(accBuffTurn, 'A', accBuff);
	decrementTurnBuff(luckBuffTurn, 'L', luckBuff);

	switch (input)
	{
	case 1:
		if (AP > 10)
		{
			strBuff = fireball();
			strBuffTurn = 1;
			AP = AP - 10;
		}
		else
		{
			//cout << "not enough AP";
		}

		break;
	case 2:
		if (AP > 10)
		{
			defBuff = stoneWall();
			defBuffTurn = 3;
			AP = AP - 10;
		}
		else
		{
			//cout << "Not enough AP";
		}

		break;
	case 3:

		if (AP > 10)
		{
			accBuff = phaseShift();
			accBuffTurn = 3;
			AP = AP - 10;
		}
		else
		{
			//cout << "Not enough AP";
		}

		break;

	default:
		//cout << "Invalid special\n";
		;
	}
}

/*************
when buff has expired, revert stat to previous value
Parameters: length of buff, current stat value, size of buff
***************/
void Zubat::decrementTurnBuff(int &num, char stat, double buffSize)
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
		;
	}
}

/**************
revert buff.
Parameters: current stat value, buff applied
returns: debuffed stat
***************/
double Zubat::revertBuff(double current, double buffSize)
{
	return (current - buffSize);
}