#include "All.h"
using namespace std;


		

int main()
{
	srand(time(NULL));

	ifstream ifs;
	ifs.open("Map.txt");
	

	int numRooms;
	ifs >> numRooms;
	
	Room* level = new Room[numRooms];

	
	for(int i = 0; i < numRooms; i++)
	{
		level[i].loadRoom(ifs);
	}

	ifs.close();
	int curRoom = 0;

	bool playing = true;

	

	while(playing)
	{
		system("cls");
		level[curRoom].draw();
		
			int in = _getch();
			switch(in)
			{
			case 'w':
				level[curRoom].tryMove(0, -1);
				break;
			case 'a':
				level[curRoom].tryMove(-1, 0);
				break;
			case 's':
				level[curRoom].tryMove(0, 1);
				break;
			case 'd':
				level[curRoom].tryMove(1, 0);
				break;
			case 'e':
				level[curRoom].doAction();
				break;
			case 'i':
				//show inv
				break;
			default:
				break;
			}
		
		

		if(level[curRoom].needsChangeRoom())
		{
			COORD newRoom = level[curRoom].getDestinationRoom();
			curRoom = newRoom.X-1;
			level[curRoom].setPlayerLoc(level[curRoom].getDoorLoc(newRoom.Y - 1));
		}

		/*
		if(!player.getHP() <= 0)
		{
			cout << "You died!" << endl;
			playing = false;
		}
		*/
	}

	delete [] level;

	return 0;
}
