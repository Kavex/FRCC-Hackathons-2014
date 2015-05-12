#include <string>
#include <iostream>
#include "InventoryList.h"

using namespace std;

const int MAXSTATUS = 5;
const int MAPWIDTH = 100;
const int MAPHEIGHT = 100;
const double MAXAP = 100;
const double MAXHP = 100;

class Character
{
protected:
	int level;
	int str;
	int acc;
	int luck;
	double def;
	string name;
	string className;
	string race;
	InventoryList *head;		//front of the inventory list


public:

	double AP;
	double HP;
	double speed;
	int location [MAPWIDTH][MAPHEIGHT];

	int getLevel(void);
	void setLevel(int newLevel);

	int getStr(void);
	void setStr(int newStr);

	int getAcc(void);
	void setAcc(int newAcc);

	int getLuck(void);
	void setLuck(int newLuck);

	int getDef(void);
	void setGainDef(double gainDef);
	void setLossDef(double lossDef);

	string getName(void);
	void setName(string newName);

	string getClassName(void);
	void setClassName(string newClassName);

	string getRace(void);
	void setRace(string newRaceName);

	double getHP(void);
	void setHP(double gainHP, double lossHP);

	Character(void);
	~Character(void);

		//add an item to linked list in alphabetical order
	void addItem(Item currentItem);

	bool checkItem(Item input);
	
	void outputBackpack();



	
};