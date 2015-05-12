#pragma once
#include "Character.h"
class Boss :
	public Character
{
public:
	Boss();
	~Boss();

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
				strBuff = strongSlash();
				strBuffTurn = 3;
				AP = AP - 10;
				success = true;
			}
			else
			{
				cout << "Not enough AP";
				success = false;
			}

			break;
		case 2:
			if (AP > 10)
			{
				defBuff = ironSkin();
				defBuffTurn = 3;
				AP = AP - 10;
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
			if (AP > 10)
			{
				accBuff = clearSight();
				accBuffTurn = 3;
				AP = AP - 10;
				success = true;
			}
			else
			{
				cout << "not enough AP";
				success = false;
			}
			break;
		case 4:
			if (HP < 10)
			{
				cout << "YOU HAVE ANGERED THE PROGRAMMING GODS (and Vicki) BY USING GLOBAL VARIABLES!\n\n\t May the internet have mercy on your soul.\n";
				setDef(100);
				setStr(100);
				setAcc(100);
				setLuck(100);
				speed = .75;
				cout << "\n\n\n\n\n\n\n\n\t\tLike a Boss.\n";
				success = true;
				//and death = true :D
			}
			else
			{
				success = specialAbilities(2);
			}
		default:
			success = false;
		}

		
		return success;
	}

	void decrementTurnBuff(int num, char stat, double buffSize)
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

	double revertBuff(double current, double buffSize)
	{
		return (current - buffSize);
	}

};

