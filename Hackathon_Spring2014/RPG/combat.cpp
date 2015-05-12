#include "All.h"

using namespace std;

int getChoice();



int getChoice()
{
	bool good;
	string choice;
	char oneChoice; 
	do
	{
		do
		{
			getline(cin, choice);
		} while (choice.size() < 1);
		good = true;
		oneChoice = choice[0]; 			
		if ( oneChoice < '1' || oneChoice > '5')
		{
			cout<<"Invalid choice";
			good = false;
			//optionsLine
		}
	}while (!good);
	choice = oneChoice;
	return atoi(choice.c_str());
	
}

void playerAttack(Warrior *player, Wizard *enemy)
{
	if ( player->getStr() > enemy->getDef() )
	{
		double damage = player->getStr() - enemy->getDef();
		enemy->HP = enemy->HP-damage;
	}
}

void playerDefend(Warrior *player)
{
	player->setLossDef(1.2);
}

void combat(Warrior *player, Wizard *enemy, bool &playerIsAlive, bool &playersTurn, bool &enemyIsAlive)
{
	if ( player->getLuck() > enemy->getLuck() )
	{
		playersTurn = true;
	}

	while( ( (playerIsAlive==true) && (enemyIsAlive == true) ) ) 
	{
		if( playersTurn == true )
		{
			maincombatscreen();
			int choice = getChoice();
			switch(choice)
			{
				//Attack
			case 1:
					playerAttack(player, enemy);
					break;
				
				//Defend
				case 2:
					playerDefend(player);
					break;

				//Special abilities
				case 3:
					specialsscreen();
					break;
				
				
				case 4:

					break;

				case 5:

					break;

				//Should never happen
				default:
					cerr<<"Error contact support->";
					break;

				

			}

			playersTurn = false;
		}

		if(playersTurn == false)
		{

			playersTurn = true;
		}
	}
}