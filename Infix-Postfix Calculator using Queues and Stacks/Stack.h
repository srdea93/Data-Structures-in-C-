/** This file defines a template class object of Stack which behaves like
 * a normal Stack. It has two member variables, a Node pointer of top and
 * an int of count It has the basic functionality of a normal Stack as well:
 * push, pop, checkEmpty, countItem, print, deleteStack.
 * @authors Steven Dea, Darlene Pham
 * Version 1.0 11/2/19
 */
#pragma once

#ifndef STACK_H

#define STACK_H

#include "LinkedList.h"



template<typename T>

class Stack : private List<T>
{
public:

	Stack();


    /**
     * @pre a value of any data type to be contained within the new Node
     * @post
     * @return void, but adds a new node to the Top of the Stack
     */
	void push(T val);             // Push new node into stack


    /**
     * @pre 
     * @post
     * @return void, but deletes a node off the Top of the Stack
     */
	void pop();                   // Pop node from stack

	/**
	 * @pre
	 * @post
	 * @return void, but deletes a node off the Top of the Stack
	*/
	Node<T>* peek();                  // Print the peek of the stack


    /**
     * @pre 
     * @post
     * @return void, but prints out the number of Nodes currently in the Stack
     */
	void countItem();                 // Count number of items in stack


    /**
     * @pre 
     * @post
     * @return void, but prints out every Node in the Stack
     */
	void print();                 // Print result


    /**
     * @pre 
     * @post
     * @return void, but deletes all of the Nodes located within the Stack
     */
	void deleteStack();           // Delete stack

};



template<typename T>

Stack<T>::Stack()

{

	std::cout << "Empty stack created!" << std::endl;

}



template<typename T>

void Stack<T>::push(T value)

{

	List<T>::insertNode(value);
	
}



template<typename T>

void Stack<T>::pop()

{

	List<T>::deleteNodeFront();

}

template<typename T>

Node<T>* Stack<T>::peek()
{
    if(List<T>::getHead() == NULL)
    {
        std::cout << "The Stack is empty." << std::endl;
        return List<T>::getHead();
    }
	else
    {
//        std::cout << "The top item is:" << List<T>::getHead()->data << std::endl;
        return List<T>::getHead();
    }
}

template<typename T>

void Stack<T>::countItem()

{

	List<T>::countData();

}



template<typename T>

void Stack<T>::print()

{
	List<T>::print();
    std::cout << std::endl;
}



template<typename T>

void Stack<T>::deleteStack()

{

	List<T>::deleteList();
    std::cout << "Stack deleted!" << std::endl;

}

#endif // !STACK_H

