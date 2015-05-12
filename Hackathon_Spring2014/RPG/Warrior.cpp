#include "Warrior.h"


Warrior::Warrior()
{
	HP = 80;
	AP = 20;
	className = "Warrior";
	acc = 16;		//mid acc
	str = 20;		//high str
	def = 14;		//mied def
	luck = 10;		//base luck

	speed = .75;

	Item sword, armor;				//generate basic  warrior gear
	sword.setName("Heirloom sword");
	sword.setType("Weapon");
	sword.setSubtype("Sword");
	sword.setValue(10);

	armor.setName("Old suit of Armor");
	armor.setType("Armor");
	armor.setSubtype("Metal");
	armor.setValue(20);

	addItem(sword);
	addItem(armor);
}


Warrior::~Warrior()
{
}
