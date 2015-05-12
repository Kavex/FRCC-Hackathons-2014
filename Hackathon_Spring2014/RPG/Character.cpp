/*hackathon April 2014*/

#include "Character.h"

Character::Character(void)
{
	Item HPpot, APpot;
	HPpot.setName("Health Potion");
	HPpot.setQuant(2);
	HPpot.setType("Potion");
	HPpot.setSubtype("Health");
	HPpot.setValue(25);

	APpot.setName("Ability Potion");
	APpot.setQuant(2);
	APpot.setType("Potion");
	APpot.setSubtype("Ability");
	APpot.setValue(25);

	addItem(HPpot);
	addItem(APpot);
}


Character::~Character(void)
{
}

/**********************
Setter and getters
*********************/

void Character:: setStr(int strNum)
{
	str = strNum;
}
int Character::getStr()
{
	return str;
}

void Character::setAcc(int accNum)
{
	acc = accNum;
}
int Character::getAcc()
{
	return acc;
}

void Character::setDef(double defNum)
{
	def = defNum;
}
double Character::getDef()
{
	return def;
}

void Character::setLossDef(double lossDef)
{
	def = def - (def / lossDef);
}

void Character::setGainDef(double gainDef)
{
	def = (def * gainDef) + def;
}


void Character::setLuck(int luckNum)
{
	luck = luckNum;
}
int Character::getLuck()
{
	return luck;
}

void Character::setLevel(int levelNum)
{
	level = levelNum;
}
int Character::getLevel()
{
	return level;
}

void Character::setRace(string inputRace)
{
	race = inputRace;
}
string Character::getRace()
{
	return race;
}

void Character::setClass(string inputType)
{
	className = inputType;
}
string Character::getClass()
{
	return className;
}

void Character::setName(string inputName)
{
	name = inputName;
}
string Character::getName()
{
	return name;
}

/*****************
add item in parameter to the weight linklist
****************/
void Character::addItem(Item currentItem)
{
	head = head->addFront(currentItem);
}

/*output backpack linklist*/
void Character:: outputBackpack()
{
	head->output();
}