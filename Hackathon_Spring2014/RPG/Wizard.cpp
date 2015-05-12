#include "Wizard.h"


Wizard::Wizard()
{
	HP = 50;
	AP = 50;
	className = "Wizard";
	acc = 20;		//high base acc
	str = 10;		//min str
	def = 12;		//low def
	luck = 18;		//mid-high luck

	speed = 1.1;

	Item staff, robes;				//generate basic wizard gear
	staff.setName("Basic Staff");
	staff.setType("Weapon");
	staff.setSubtype("Staff");
	staff.setValue(10);

	robes.setName("Worn Robes");
	robes.setType("Armor");
	robes.setSubtype("Cloth");
	robes.setValue(20);

	addItem(staff);
	addItem(robes);
}


Wizard::~Wizard()
{
	;
}

bool Wizard::checkItem(Item input)
{
	if (input.getSubtype() != "Staff" || input.getSubtype() != "Cloth")
	{
		return false;
	}
	return true;
}

//Apply one turn str buff for an attack
int Wizard::fireball()
{
	//cout << "The wizard summons a fiery inferno and throws a fireball.\n";
	setStr(getStr() + 4);
	return 4;
}

//3 turn defense buff
int Wizard::stoneWall()
{
	//cout << "A Stone wall is erected between the wizard and their attacker.\n";
	setDef(getDef() + 3);
	return 3;
}

int Wizard::phaseShift()
{
	//cout << "The Wizard steps between planes, enhancing their accuracy\n";
	setAcc(getAcc() + 2);
	return 2;
}

void Wizard::specialAbilities(int input)
{
	int strBuff = 0;
	int defBuff = 0;
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
void Wizard::decrementTurnBuff(int &num, char stat, int buffSize)
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
int Wizard::revertBuff(int current, int buffSize)
{
	return (current - buffSize);
}