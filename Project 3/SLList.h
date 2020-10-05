//Single Linked List Class
#ifndef SLLIST_H
#define SLLIST_H

#include "Node.h"
#include <iostream>

using namespace std;

template<typename T>
class SLList
{
public:
	//Constructor
	SLList<T>();
	//Destructor
	~SLList();

	//Public Member Functions
	bool insert(const T& new_Data); //Used to insert a node into the list
	bool isEmpty(); //Checks if a list is empty
	bool pop_back(); //Removes last element in the list
	void clearList(); //Removes all nodes from the list
	T* back(); //Returns the value stored in the tail of the list
private:
	//Private Member Variables
	Node<T>* head;
	Node<T>* tail;
	Node<T>* iterator;
};

#endif