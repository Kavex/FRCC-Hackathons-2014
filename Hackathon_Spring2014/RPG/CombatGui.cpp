
#include "All.h"
using namespace std;

void solidline(int numStars);
void statsline();
void actionsline();
void itemsline();

//int main()
//{
//	maincombatscreen();
//	
//	system("pause");
//
//}

void solidline(int numStars)
{

	for (int count = 0; count<numStars; count++)
	{
		cout << "*";
	}
	cout << endl;
}

void statsline(Character *player)
{
	cout << "*";
	cout << setw(10);
	cout << "Player"; //number should be hp variable
	cout << setw(9);
	cout << "*";
	cout << endl;

	cout << "*";
	cout << setw(7);
	cout << "HP:" << player->HP; //number should be hp variable
	cout << setw(10);
	cout << "*";
	cout << endl;

	cout << "*";
	cout << setw(7);
	cout << "AP:" << player->AP;	//number should be ap variable
	cout << setw(10);
	cout << "*";
	cout << endl;
}

void actionsline()
{
	string optionsarray[5] = { "Attack", "Defend", "Specials", "Items", "Flee" };
	
	for (int i = 0; i < 5; i++)
	{
	cout << "*";
	cout << setw(4);
	cout << (i + 1) << ". " << setw(10) << optionsarray[i];
	cout << setw(5);
	cout << "*";
	cout << endl;
	}
	
}

void itemsline()
{
	//string itemsarray[];

	for (int i = 0; i < 5; i++)
	{
		cout << "*";
		cout << setw(4);
		//cout << (i + 1) << ". " << setw(10) << optionsarray[i];
		cout << (i + 1) << ". " << setw(10) << "Meed things in itemsLine";
		cout << setw(5);
		cout << "*";
		cout << endl;
	}

}

void specialsline(const string specialsarray[])
{
	

	for (int i = 0; i < 5; i++)
	{
		cout << "*";
		cout << setw(4);
		cout << (i + 1) << ". " << setw(12) << specialsarray[i];
		
		cout << setw(8);
		cout << "*";
		cout << endl;
	}

}


void maincombatscreen(Character *player, Character *enemy)
{
	solidline(STATSLENGTH);
	cout<<"Enemy stats";
	statsline(enemy);
	solidline(STATSLENGTH);
	cout << endl;
	solidline(STATSLENGTH);
	cout<<"Player stats";
	statsline(player);
	solidline(STATSLENGTH);
	cout << endl;
	solidline(ACTIONSLENGTH);
	actionsline();
	solidline(ACTIONSLENGTH);
}

void itemsscreen()
{
	cout << endl;
	solidline(ACTIONSLENGTH);
	itemsline();
	solidline(ACTIONSLENGTH);
	cout << endl;
}

void specialsscreen()
{
	cout << endl;
	solidline(ACTIONSLENGTH);
	specialsline(specialsarray);
	solidline(ACTIONSLENGTH);
	cout << endl;
}

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

void playerAttack(Character *player, Character *enemy)
{
	if ( player->getStr() > enemy->getDef() )
	{
		double damage = player->getStr() - enemy->getDef();
		enemy->HP = enemy->HP-damage;
	}
}

void playerDefend(Character *player)
{
	player->setLossDef(1.2);
}

void combat(Character *player, Character *enemy, bool &playerIsAlive, bool &playersTurn, bool &enemyIsAlive)
{
	if ( player->getLuck() > enemy->getLuck() )
	{
		playersTurn = true;
	}

	while( ( (playerIsAlive==true) && (enemyIsAlive == true) ) ) 
	{
		if( playersTurn == true )
		{
			maincombatscreen(player, enemy);
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
			int choice = 1;
			switch(choice)
			{
				//Attack
			case 1:
					playerAttack(enemy, player);
					break;
				
				//Defend
				case 2:
					playerDefend(enemy);
					break;

				//Special abilities
				case 3:
					specialsscreen();
					break;

				//Should never happen
				default:
					cerr<<"Error contact support->";
					break;
			}
			playersTurn = true;
		}

		if(enemy->HP < 1)
		{
			enemyIsAlive = false;
		}

		if(player->HP <1)
		{
			playerIsAlive = false;
		}
	}
}