#include "Boss.h"


Boss::Boss()
{
	name = "Vicki";
	race = "Professor";
	className = "Computer Scientist";
	
	HP = 130;
	AP = 70;
	setStr(20);
	setDef(20);
	setAcc(20);
	setLuck(3);
	speed = 1.3;
	
}


Boss::~Boss()
{
}
