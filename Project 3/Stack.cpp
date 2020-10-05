#include "Stack.h"


//Constructor
template<typename T>
Stack<T>::Stack()
{
	list = new SLList<T>;//Creates a new empty list
}

//Destructor
template<typename T>
Stack<T>::~Stack()
{
}

//Public Member Functions
template<typename T>
void Stack<T>::push(T element) //Used to insert an element at the top of the stack
{
	list->insert(element); //Uses SLList's insert(element) function to insert an element at the top of the stack
}

template<typename T>
void Stack<T>::pop() //Pops off the top of the stack if the stack isn't already empty
{
	if (isEmpty())
		cout << "The stack is already empty" << endl;
	else
		list->pop_back(); //Uses SLList's pop_back function to pop off the top of the stack
}

template<typename T>
bool Stack<T>::isEmpty() //Checks if the stack is empty
{
	if (list->isEmpty()) //If the singly linked list of elements is empty then the stack is empty
		return true;
	else
		return false;
}

template<typename T>
void Stack<T>::clear() //Used to completely clear the stack
{
	list->clearList(); //Uses SLList's clearList function to clear the stack
}

template<typename T>
T* Stack<T>::topEl() //Retutns the data stored at the top of the stack
{
	if (isEmpty())
		return nullptr;
	else
		return list->back(); //Uses SLList's back function to obtain the value stored at the top of the stack
}