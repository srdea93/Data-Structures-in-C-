#pragma once

/** This file defines a template class object of Linked List which behaves like

* a normal linked list. It has 4 members' variables: an int variable count of number

* of elements inside the linked list, an int variable sorted if the linked list

* is sorted in ascending orders or decending order or neither, two Node data

* type pointers that behave as the head and tail pointer of the linked list. It has

* the basic functionality of a linked list as well: create new list, add data, 

* delete data, find data, count of data items in the list, empty the list, print

* all data items in a list etc.

*

* @authors Steven Dea, Darlene Pham

* Version 1.0 10/29/19

*/

#pragma once

#include "Node.h"



#ifndef LINKED_LIST_H

#define LINKED_LIST_H



template <typename T>

class List

{

private:

	Node<T> *head;

    Node<T> *tail;

	int count;

	int sorted;

public:

	List();

    

    void setHead(Node<T> *newHead);     // This function set the head pointers

	                                    /* 

										   Pre: newHead - the address assign to head pointer



										   Post: None

										*/

    

    void setTail(Node<T> *newTail);     // This function set the tail pointers

										/*

										   Pre: newTail - the address assign to tail pointer



										   Post: None

										*/

    

    void setCount(int number);          // This function set the count variable

										/*

										   Pre: number - the value assign to count variable



										   Post: None

										*/

    

    void setSorted(int sortNum);        // This function set the sorted variable

										/*

										   Pre: sortNum - value telling the function to sort in ascending, descending or neither



										   Post: None



										   Description: Assign sorted variable equal to the variable received. The function will

										                print a message announce if the list is sorted in asending, descending or

														neither orders.

										*/

    Node<T>* getHead();
    
    Node<T>* getTail();
    
    int getCount();
    

	void insertNode(T value);           // Insert new node at correct location depending on sorted value

	                                    /*

										   Pre: value - the value of the new node inserted



										   Post: None



										   Description: If the list is unsorted, this function insert a new node at the head of the linked list.

										                If the list is sorted, this function insert a new node depends on the ascending or descending orders.

										*/



    void deleteNodeFront();             // Delete first node

									    /*

										   Pre: None



										   Post: None



										   Description: This function deletes the firt node of the linked list.

									    */

    

    void deleteNodeBack();              // Delete last node

										/*

										   Pre: None



										   Post: None



										   Description: This function deletes the last node of the linked list.

										*/

    

	void deleteNode(T value);           // Delete a node given particular data

										/*

										   Pre: value - the particular data user want to delete from the list



										   Post: None



										   Description: This function deletes the node given particular data received from parameter. If

										                there's no node storing such data, it will print out a message inform the user.

										*/

    

	void findData(T value);            // Find a data's position in a linked list

									   /*

										   Pre: value - the particular data user want to find position



										   Post: None



										   Description: This function finds and prints the node's positions given particular data received from 

										                parameter. If there's no node storing such data, it will print out nothing.

										*/



	void countData();                  // Count numbers of data in the list

									   /*

										   Pre: None



										   Post: None



										   Description: This function counts the number of data (node) inside a linked list and prints the result

										                for the user.

										*/



	void print();                      // Print out everything of the linked list

									   /*

										   Pre: None



										   Post: None



										   Description: This function prints out everything inside the list.

										*/



	void deleteList();                 // Delete the linked list

									   /*

										   Pre: None



										   Post: None



										   Description: This function deletes every nodes inside the list.

										*/

};



template<typename T>

List<T>::List()

{

	head = NULL;

    tail = NULL;

	count = 0;

	sorted = 0;

    std::cout << "Creating a new empty List object." << std::endl;

}



template<typename T>

void List<T>::setHead(Node<T> *newNode)

{

    head = newNode;

}



template<typename T>

void List<T>::setTail(Node<T> *newNode)

{

    tail = newNode;

}



template<typename T>

void List<T>::setCount(int number)

{

    count = number;

}



template<typename T>

void List<T>::setSorted(int sortNum)

{

    sorted = sortNum;

    switch (sortNum)

    {

        case 0:

            std::cout << "Sort is set to unsorted." << std::endl;

            break;

        case 1:

            std::cout << "Sort is set to ascending sort." << std::endl;

            break;

        case 2:

            std::cout << "Sort is set to descending sort." << std::endl;

            break;

    }

}

template<typename T>
Node<T>* List<T>::getHead()
{
    return head;
}

template<typename T>
Node<T>* List<T>::getTail()
{
    return tail;
}

template<typename T>
int List<T>::getCount()
{
    return count;
}


template<typename T>

void List<T>::insertNode(T value)

{

    Node<T>* pNew = new Node<T>;

    pNew->data = value;

    pNew->next = NULL;

    

    std::cout << "Inserting new Node with data value of: " << value << std::endl;

    

    // new value is the head if the head pointer is NULL

    if (head == NULL)

    {

        head = pNew;

        pNew = NULL;

    }

    

    else

    {

        Node<T>* pCur = new Node<T>;

        pCur = head;



        Node<T>* pPre = new Node<T>;

        pPre = NULL;

        

        // if the array is unsorted, insert at the head for efficiency

        if(sorted == 0)

        {

            pNew->next = pCur;

            head = pNew;

        }

        

        // if the array is sorted in ascending fashion

        else if (sorted == 1)

        {

            // check if head->next is null

            if(pCur->next == NULL)

            {

                //if head < new, head -> new

                if (pCur->data < pNew->data)

                {

                    pCur->next = pNew;

                }

                // if head > new, add new as head 

                else

                {

                    pNew->next = pCur;

                    head = pNew;

                }

            }

            else

            {

                // if head > new, new becomes head

                if(pCur->data > pNew->data)

                {

                    pNew->next = pCur;

                    head = pNew;

                }

                

                else

                {

                       // if head is not > new, search for the correct insertion position

                    while (pCur->data < pNew->data && pCur->next != NULL)

                    {

                        pPre = pCur;

                        pCur = pCur->next;

                    }

                    

                    //insert at the end of the linked list if head < new

                    if(pCur->data < pNew->data)

                    {

                        pCur->next = pNew;

                    }

                    //insert in between pCur and pPre

                    else

                    {

                        pPre->next = pNew;

                        pNew->next = pCur;

                    } 

                }

            }

        }

        

        // if the array is sorted in descending fashion

        else

        {

            // check if head->next is null

            if(pCur->next == NULL)

            {

                //if head > new, head -> new

                if (pCur->data > pNew->data)

                {

                    pCur->next = pNew;

                }

                // if head > new, add new as head 

                else

                {

                    pNew->next = pCur;

                    head = pNew;

                }

            }

            else

            {

                // if head < new, new becomes head

                if(pCur->data < pNew->data)

                {

                    pNew->next = pCur;

                    head = pNew;

                }

                

                else

                {

                       // if head is not < new, search for the correct insertion position

                    while (pCur->data > pNew->data && pCur->next != NULL)

                    {

                        pPre = pCur;

                        pCur = pCur->next;

                    }

                    

                    //insert at the end of the linked list if head > new

                    if(pCur->data > pNew->data)

                    {

                        pCur->next = pNew;

                    }

                    //insert in between pCur and pPre

                    else

                    {

                        pPre->next = pNew;

                        pNew->next = pCur;

                    } 

                }

            }

        }

    }

    count++;

}



template<typename T>

void List<T>::deleteNodeFront()

{

	// Create a new node pointer and assign it to head

    Node<T>* pCur = new Node<T>;

    pCur = head;

    

	// Move head to next node and delete the first one

    head = head->next;

    delete pCur;

    count--;

}



template<typename T>

void List<T>::deleteNodeBack()

{

	// Create a new node pointer and assign it to head

    Node<T>* pCur = new Node<T>;

    pCur = head;

    

	// Loop until the last node

    while (pCur->next != NULL)

    {

        pCur = pCur->next;

    }

    delete pCur;   // Delete the last node

    count--;

}



template<typename T>

void List<T>::deleteNode(T valueToRemove)

{

    Node<T>* pCur = new Node<T>;

    pCur = head;         // Create a current node and set to head

	Node<T>* pPre = NULL;         // Create a orevious node and set to null



    while(pCur->data != valueToRemove && pCur->next != NULL)

    {

        pPre = pCur;

        pCur = pCur->next;

    }

    if(pCur->next == NULL && pCur->data != valueToRemove)

    {

        std::cout << "Error, data not found in linked list.";

    }

    else

    {

        pPre->next = pCur->next;

        delete pCur;

        count--;

    }

}



template<typename T>

void List<T>::findData(T value)

{

	// Create a new node pointer and assign it to head

    Node<T>* pCur = new Node<T>;

    pCur = head;



	// Position of the node

	int pos = 1;



	// Loop until reach the last node

	while (pCur != NULL)

	{

		// If data stored in node equal to value then print out

		// the position of the node

		if (pCur->data == value)

			std::cout << value << " is at node " << pos << std::endl;

		pCur = pCur->next;      // Move to the next node

		pos++;

	}

}



template<typename T>

void List<T>::countData()

{

	// Create a new node

    Node<T>* pCur = new Node<T>;

    pCur = head;

    

    int num = 0;



	// Loop until reach the last node

	while (pCur != NULL)

	{

		num++;    

		pCur = pCur->next;        // Move to the next node

	}



	// Print the result

	std::cout << "There are " << num << " data items in the list.\n";

}



template<typename T>

void List<T>::print()

{

        if (head == NULL)

    {

        std::cout << "List is empty!" << std::endl;

    }

    else

    {

         // Create a new node

        Node<T>* pCur = new Node<T>;

        pCur = head;

        // Loop until reach the last node

        while (pCur != NULL)

        {

            std::cout << pCur->data << " ";     // Print out data stored in that node

            pCur = pCur->next;                  // Move to the next node

        }

    }

}



template<typename T>

void List<T>::deleteList()

{

	// Create a new pointer and assign it at the head node

    Node<T>* pCur = new Node<T>;

    pCur = head;     



	// Loop until reach the last node

	while (pCur != NULL)

	{

		head = pCur->next;            // Head become the next node

		delete pCur;                  // The current node is deleted

		pCur = head;                  // Temp now become head

	}



	std::cout << "Linked list deleted!\n";

}



#endif // !LINKED_LIST_H



