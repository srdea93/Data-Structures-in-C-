/** This file defines a template class object of Queue which behaves like
 * a normal queue. It has 3 member variables, a Node pointer to head, a Node
 * pointer to tail, and an int of count. It contains the basic functionality
 * of a Queue with member functions of enqueue, dequeue, peekFront, peekBack,
 * deleteList, print, and checkEmpty.
 * @authors Steven Dea, Darlene Pham
 * Version 1.0 11/2/19
 */
#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

template<typename T>
class Queue : private List<T>
{
public:
    Queue();
    
    /**
    * @pre a value of any data type to be contained within the new Node
    * @post
    * @return void, but inserts a new Node at the end of the Queue
    */
    //Add new node to the back - Enqueue
    void enqueue(T value);
    
    /**
     * @pre 
     * @post
     * @return void, but deletes a node from the front of the Queue
     */
    //Remove node from the head - Dequeue
    void dequeue();
    
    /**
     * @pre 
     * @post
     * @return void, but prints out the value of the head node if it is not NULL, otherwise
     * prints out that the head is NULL
     */
    //See the node at the head
    void peekFront();
    
    /**
     * @pre 
     * @post
     * @return void, but prints out the value of the tail node if it is not NULL, otherwise
     * prints out that the head is NULL
     */
    //See the node at the tail
    void peekBack();
    
    /**
     * @pre 
     * @post
     * @return void, but deletes every Node located within a Queue
     */
    //Delete the list
    void deleteList();
    
    /**
     * @pre 
     * @post
     * @return void, but prints out every Node located within a Queue. If the Queue is 
     * empty, prints out that Queue is empty.
     */
    //Print the queue
    void print();
    
    /**
     * @pre 
     * @post
     * @return void, but prints out if a Queue is empty or not.
     */
    //Check if empty
    void checkEmpty();
};

template<typename T>
Queue<T>::Queue()
{    
    std::cout << "Empty queue created!" << std::endl;
}

template<typename T>
void Queue<T>::enqueue(T value)
{
    Node<T>* pNew = new Node<T>;
    pNew->data = value;
    pNew->next = NULL;
    if(List<T>::getHead() == NULL)
    {
        List<T>::setHead(pNew);
        List<T>::setTail(pNew);
    }
    else
    {
        List<T>::getTail()->next= pNew;
        List<T>::setTail(pNew);
    }
    std::cout << "Enqueue: " << pNew->data << std::endl;
    List<T>::setCount(List<T>::getCount() + 1);
}

template<typename T>
void Queue<T>::dequeue()
{
    std::cout << "Dequeuing: " << List<T>::getHead()->data << std::endl;
    List<T>::deleteNodeFront();
}

template<typename T>
void Queue<T>::peekFront()
{
    if(List<T>::getHead() == NULL)
    {
        std::cout << "Head is empty." << std::endl;
    }
    else
    {
        std::cout << "Head is: " << List<T>::getHead()->data << std::endl;
    }
}

template<typename T>
void Queue<T>::peekBack()
{
    if(List<T>::getTail() == NULL)
    {
        std::cout << "Tail is empty." << std::endl;
    }
    else
    {
        std::cout << "Tail is: " << List<T>::getTail()->data << std::endl;
    }
}

template<typename T>
void Queue<T>::deleteList()
{
    List<T>::deleteList();
    std::cout << "Queue deleted!" << std::endl;
}

template<typename T>
void Queue<T>::print()
{
    List<T>::print();
    std::cout << std::endl;
}

template<typename T>
void Queue<T>::checkEmpty()
{
    if (List<T>::getHead() == NULL)
    {
        std::cout << "Queue is empty." << std::endl;
    }
}

#endif // QUEUE_H
