#pragma once
//#include "character.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <Tchar.h>
#include <stdlib.h>


using namespace std;

const int ROOM_SIZE = 64;
const int SCREEN_WIDTH =100;
const int SCREEN_HEIGHT = 70;
const int MAX_DOORS = 16;
class Tile
{
public:
	Tile();
	~Tile();

	void setAppearance(char app);
	void setDoorLoc(int x, int y);
	void setSolid(bool sol);
	void setDoor(bool d);
	void setDestRoom(int x, int y);
	void setEncounterChance(int chance);

	char getAppearance();
	bool getSolid();
	bool isDoor();
	COORD getDoorLoc();
	COORD getDestRoomDoor();
	int getEncounterChance();

	void setBoss(bool b);
	bool isBoss();

private:
	char appearance;
	bool solid;

	COORD destRoomDoor;
	COORD doorLoc;
	bool door;
	bool boss;


	int encounterChance;
	//more later
};


class Room
{
public:

	Room(void);

	bool loadRoom(ifstream &ifs);

	void draw();
	bool tryMove(int dx, int dy);

	void setPlayerLoc(COORD loc);
	COORD getDoorLoc(int door);

	void doAction();

	bool needsChangeRoom();
	COORD getDestinationRoom();

	~Room(void);

private:
	Tile room[ROOM_SIZE][ROOM_SIZE];

	char screenBuffer[SCREEN_WIDTH][SCREEN_HEIGHT];

	string roomName;


	int encounterLvl;

	int roomWidth;
	int roomHeight;

	int numDoors;
	Tile* doors[MAX_DOORS];


	//thanks to http://www.benryves.com/tutorials/winconsole/
	// for the win console stuff
	HANDLE wHnd;
	HANDLE rHnd;

	bool needsChange;
	COORD destRoomDoor;

	COORD playerLoc;
};

