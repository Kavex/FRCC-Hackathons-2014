/*hackathon April 2014*/

#pragma once
#include "Item.h"
#include <iostream>
using namespace std;

/******************
Inventory list stores an object
and its location in regards to the
relevant sorting methods. (through multiple links)
*********************/

class InventoryList
{
private:
	InventoryList * nextItem;				//weight sorted list
	Item object;							//object/item being stored in the list
public:
	InventoryList();
	~InventoryList();

	InventoryList * addFront(Item newItem);			//adds to front of weight list

	
	void output();							//output weight in a numbered list

	void deleteList();								//deletes linklist
};

