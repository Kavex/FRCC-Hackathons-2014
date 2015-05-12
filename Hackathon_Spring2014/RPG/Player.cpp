#include "Player.h"



int Character::getLevel()
	{
		return level;
	}
	
void Character::setLevel(int newLevel)
	{
		level = newLevel;
	}

int Character::getStr(void)
	{
		return str;
	}

void Character::setStr(int newStr)
	{
		str = newStr;
	}

int Character::getAcc(void)
	{
		return acc;
	}

void Character::setAcc(int newAcc)
	{
		acc = newAcc;
	}

int Character::getLuck(void)
	{
		return luck;
	}

void Character::setLuck(int newLuck)
	{
		luck = newLuck;
	}

int Character::getDef(void)
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

string Character::getName(void)
	{
		return name;
	}

void Character::setName(string newName)
	{
		name = newName;
	}

string Character::getClassName(void)
	{
		return className;
	}

void Character::setClassName(string newClassName)
	{
		className = newClassName;
	}

string Character::getRace(void)
	{
		return race;
	}

void Character::setRace(string newRaceName)
	{
		race = newRaceName;
	}

double Character::getHP(void)
{
	return HP;
}

//If player loses HP or gains HP
void Character::setHP(double lossHP, double gainHP)
{
	HP -= lossHP;

	HP += gainHP;

}