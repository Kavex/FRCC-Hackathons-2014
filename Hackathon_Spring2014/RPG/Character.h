/*hackathon April 2014*/

#pragma once
#include <string>
#include "InventoryList.h"

using namespace std;


const double MAXHP = 100;	//can't exceed 100%
const double MAXAP = 100;	//can't exceed 100%
const int MAXSTATUS = 5;	//different status effects
const int MAPWIDTH = 100;	//temp max values
const int MAPHEIGHT= 100;	//temp max values

class Character
{
public:
	double HP;		//hitpoints-> in %
	double AP;		//ability points -> in %

	double speed;	//movement speed
	
	int location[MAPWIDTH][MAPHEIGHT];		//X COORDINATE, Y COORDINATE

	bool status[MAXSTATUS];		//status ailments. T\F

	//Base Damage???
	//Equipment/item list

	//Ability List/Magic spells
	//Basic attack is only one shared accross all player classtypes

	


	Character(void);
	~Character(void);

	/*STR setters and getters*/
	void setStr(int strNum);
	int getStr();

	//accuracy setters and getters
	void setAcc(int accNum);
	int getAcc();

	//defense setters and getters
	void setDef(double defNum);
	double getDef();
	void setGainDef(double gainDef);
	void setLossDef(double lossDef);

	//luck setters and getters
	void setLuck(int luckNum);
	int getLuck();

	//level setters/getters
	void setLevel(int levelNum);
	int getLevel();

	//race setters and getters
	void setRace(string inputRace);
	string getRace();

	//class setters and getters
	void setClass(string inputType);
	string getClass();

	//name setters/getters
	void setName(string inputName);
	string getName();

	//add an item to linked list in alphabetical order
	void addItem(Item currentItem);

	bool checkItem(Item input);
	
	void outputBackpack();

protected:
	string name;
	string className;	//warrior, mage, etc.
	string race;		//fantasy race: Goblin, human, elf, etc.

	int level;		//player level
	int str;		//strength
	int acc;		//accuracy
	double def;		//defense
	int luck;		//luck for crits?

	InventoryList *head;		//front of the inventory list

};

