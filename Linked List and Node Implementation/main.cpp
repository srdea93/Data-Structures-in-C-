/**
 * @brief This program displays the functionality of a Queue and Stack
 * based on our prior Linked List class template. Both the Queue and Stack 
 * can take in data of int, string, or Rupee and display the common
 * functionality of either a Queue or a Stack
 * @authors Steven Dea, Darlene Pham
 * Version 1.0 11/2/190
 */
#include <iostream>
#include <string>
#include "Currency.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main (){
    //Queue functionality
    Queue<Rupee> rupeeQueue;
    Rupee rupee1("Rupee", 1, 1, "paise");
    Rupee rupee2("Rupee", 2, 2, "paise");
    Rupee rupee3("Rupee", 3, 3, "paise");
    Rupee rupee4("Rupee", 4, 4, "paise");
    Rupee rupee5("Rupee", 5, 5, "paise");
    rupeeQueue.enqueue(rupee1);
    rupeeQueue.enqueue(rupee2);
    rupeeQueue.enqueue(rupee3);
    rupeeQueue.enqueue(rupee4);
    rupeeQueue.enqueue(rupee5);
    rupeeQueue.print();
    rupeeQueue.dequeue();
    rupeeQueue.peekFront();
    rupeeQueue.peekBack();
    rupeeQueue.print();
    rupeeQueue.deleteList();
    
    cout << endl;
    cin.clear();
    
    Queue<string> strQueue;
    strQueue.enqueue("Steven");
    strQueue.enqueue("Bob");
    strQueue.enqueue("Fred");
    strQueue.enqueue("Darlene");
    strQueue.enqueue("Jackie");
    strQueue.print();
    strQueue.dequeue();
    strQueue.dequeue();
    
    strQueue.print();
    strQueue.deleteList();
    
    cout << endl;
    cin.clear();
    
    Queue<int> intQueue;
    for (int i = 0; i < 10; i++)
    {
        intQueue.enqueue(i);
    }
    intQueue.print();
    intQueue.dequeue();
    intQueue.print();
    intQueue.deleteList();
    
    //Stack functionality
    cout << endl;

	Stack<Rupee> rupeeStack;
	rupeeStack.push(rupee1);
	rupeeStack.push(rupee2);
	rupeeStack.push(rupee3);
	rupeeStack.push(rupee4);
	rupeeStack.push(rupee5);
	rupeeStack.print();
	rupeeStack.pop();
	rupeeStack.countItem();
	rupeeStack.print();
	rupeeStack.deleteStack();

	cout << endl;

	Stack<string> strStack;
	strStack.push("Katie");
	strStack.push("John");
	strStack.push("Oliver");
	strStack.push("Alex");
	strStack.push("Joe");
	strStack.print();
	strStack.pop();
	strStack.pop();
	strStack.countItem();
	strStack.print();
	strStack.deleteStack();

	cout << endl;

	Stack<int> intStack;
	for (int i = 0; i < 10; i++)
	{
		intStack.push(i);
	}
	intStack.print();
	intStack.pop();
	intStack.countItem();
	intStack.print();
	intStack.deleteStack();

	system("pause");

    
    return 0;
}
