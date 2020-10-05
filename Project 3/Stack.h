#ifndef STACK_H
#define STACK_H

#include"SLList.h"
#include"SLList.cpp"

template<typename T>
class Stack
{
public:
	//Constructor
	Stack<T>();
	//Destructor
	~Stack();

	//Public Member Functions
	void push(T element); //Inserts an element onto the top of the stack
	void pop(); //Removes the element at the top of the stack
	bool isEmpty(); //Checks if the stack contains any elements
	void clear(); //Removes all elements from the stack
	T* topEl(); //Returns the value stored at the top of the stack
private:
	//Private Member Variables
	SLList<T>* list; //Used to create the stack, each element of the stack is a singly linked node
};

#endif