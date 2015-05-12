/*hackathon April 2014*/
#include "InventoryList.h"


InventoryList::InventoryList()
{
	nextItem = nullptr;
}


InventoryList::~InventoryList()
{
	delete nextItem;
	void deleteList();
}

/********************
output weight will output the index location
and weight of the object in this location of the linklist
Parameters: n/a
Returns: n/a
*********************/

void InventoryList:: output()
{
	int index = 1;					//for organization of output
	InventoryList *current;			// pointer for manipulation and output
	current = this;
	while (current != nullptr)
	{
		cout << "\t" << index << ". " << current->object.getName();
		cout<<"\n\t\tQuant:"<<current->object.getQuant()<<endl;
		cout << "\t\t"<< "Gold: "<< current->object.getValue() <<endl;
		current = current->nextItem;
		index++;
	}
}



/***********************
adds a new node to weight list containing the object
passed in as parameter.
Parameter: an Item class object.
Returns: nothing
***********************/
InventoryList* InventoryList::addFront(Item newItem)
{
	/*Set head pointer = to this function's expression*/
	InventoryList * newNode;				//create bag entry
	newNode = new InventoryList;

	newNode->nextItem = this;				//put on front of list
	newNode->object = newItem;				//assign object to the newly created node

	return newNode;
}

/***************
Used to delete the entire set of lists.
called in the destructor.
***************/
void InventoryList::deleteList()
{
	InventoryList *current;			//pointer to help cycle through link nodes
	InventoryList *previous;		//" "
	current = this;

	while (current != nullptr)
	{
		previous = current;
		current = current->nextItem;
		delete previous;
	}
	cout << "\nfinished deleting";
}

