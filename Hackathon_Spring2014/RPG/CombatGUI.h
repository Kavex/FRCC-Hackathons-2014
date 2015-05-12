#ifndef combatGUI_h
#define combatGUI_h

#include "All.h"
using namespace std;

const string specialsarray[] = { "fireBBALL", "Kick shin", "Flick booger", "Throw shoe", "Slap" };

const int STATSLENGTH = 25;		//constant for stats box length
const int ACTIONSLENGTH = 27;	//constant for actions box length
void solidline(int numStars);	//creates a solid line of stars
void statsline();				//creates the lines for player and enemey hp and ap
void actionsline();				//creates the box for the main screen combat with main choices
void itemsline();				//creates the box for the items in inventory
void specialsline(const string specialsarray[]);			//creates the box for the special abilities
void maincombatscreen(Character *player, Character *enemy);		//displays the UI for main battle screen
void itemsscreen();				//displays the UI for the selection of the items menu in the main screen
void specialsscreen();			//displays the UI for the selection of the specials menu in the main screen

void combat(Character *player, Character *enemy, bool &playerIsAlive, bool &playersTurn, bool &enemyIsAlive);
void playerDefend(Character *player);
void playerAttack(Character *player, Character *enemy);
int getChoice();

#endif 