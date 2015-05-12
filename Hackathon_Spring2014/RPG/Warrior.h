#pragma once
#include "Character.h"
class Warrior :
	public Character
{
public:
	Warrior();
	~Warrior();

	bool checkItem(Item input)
	{
		if (input.getSubtype() != "Sword" || input.getSubtype() != "Metal")
		{
			return false;
		}
		return true;
	}

	//attack buffed attack
	int strongSlash()
	{
		setStr(getStr() + 2);
		return 2;
	}

	//def buff attack
	int ironSkin()
	{
		setDef(getDef() + 2);
		return 2;
	}

	//acc buff
	int clearSight()
	{
		setAcc(getAcc() + 2);
		return 2;
	}

	//selects the ability 
	bool specialAbilities(int input)
	{
		bool success;
		int strBuff;
		int defBuff;
		int accBuff;
		int luckBuff;

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
		decrementTurnBuff(luckBuffTurn, 'L', luckBuff);
		return success;
	}

	void decrementTurnBuff(int num, char stat, int buffSize)
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

	int revertBuff(int current, int buffSize)
	{
		return (current - buffSize);
	}
};

