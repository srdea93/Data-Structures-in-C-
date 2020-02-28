#pragma once

#ifndef BST_H

#define BST_H

#include "Person.h"
#include "Node.h"
#include "Queue.h"

class BST

{

public:

	BST();

	template <typename T>
	Node<T>* insert(Node<T>* node, Person key);

	template <typename T>
	void printInOrder(Node<T>* node);

	template <typename T>
	void printPostOrder(Node<T>* node);

	template <typename T>
	void printPreOrder(Node<T>* node);

	template <typename T>
	void printBreadthFirst(Node<T>* node);
    
	template <typename T>
    bool compare (Person key, Node<T>* node);


};


BST::BST() {}

template <typename T>
Node<T>* BST::insert(Node<T>* node, Person key)
{

	// If BST is empty create a new node as root

	// or if 

	if (node == NULL)
	{
		node = new Node<T>;
		node->setData(key);
		node->setLeft(NULL);
		node->setRight(NULL);
	}
	else if (compare(key, node))  // Compare function added here
	{
		node->setLeft(insert(node->getLeft(), key));
	}
	else if (!compare(key, node))  // Compare function added here
	{
		node->setRight(insert(node->getRight(), key));
	}

	return node;

}

template <typename T>
void BST::printInOrder(Node<T>* node)

{

	// Stop printing if no node found

	if (node == NULL)

		return;



	// First recurse on left child

	printInOrder(node->getLeft());



	// Print data of node

	std::string name = node->getData().getWholeName();
	std::string birthday = node->getData().getBirthday();
	std::cout << "Name: " << name << ", Birthday: " << birthday << std::endl;



	// Then recurse on right child

	printInOrder(node->getRight());

}

template <typename T>
void BST::printPostOrder(Node<T>* node)

{

	// Stop printing if no node found

	if (node == NULL)

		return;



	// First recurse on left subtree

	printPostOrder(node->getLeft());



	// Then recurse on right subtree

	printPostOrder(node->getRight());



	// Print data of node

	std::string name = node->getData().getWholeName();
	std::string birthday = node->getData().getBirthday();
	std::cout << "Name: " << name << ", Birthday: " << birthday << std::endl;

}

template <typename T>
void BST::printPreOrder(Node<T>* node)

{

	// Stop printing if no node found

	if (node == NULL)

		return;



	// Print data of node

	std::string name = node->getData().getWholeName();
	std::string birthday = node->getData().getBirthday();
	std::cout << "Name: " << name << ", Birthday: " << birthday << std::endl;



	// Recurse on left tree

	printPreOrder(node->getLeft());



	// Then recurse on right tree

	printPreOrder(node->getRight());

}

template <typename T>
void BST::printBreadthFirst(Node<T>* node)

{

	// Stop printing if no node found

	if (node == NULL)

		return;



	// Create empty queue

	Queue<Node<T>*> queue;



	// Enqueue node

	queue.enqueue(node);



	while (queue.checkEmpty() == false)

	{

		// Print front of queue then remove it

		Node<T>* obj = queue.peekFront();

		std::string name = obj->getData().getWholeName();
		std::string birthday = obj->getData().getBirthday();
		std::cout << "Name: " << name << ", Birthday: " << birthday << std::endl;

		queue.dequeue();



		// Enqueue left child

		if (node->left != NULL)

			queue.enqueue(node->getLeft());



		// Enqueue right child

		if (node->right != NULL)

			queue.enqueue(node->getRight());

	}

}

template <typename T>
bool BST::compare (Person key, Node<T>* node)
{
	std::string str1 = key.getWholeName();
	std::string str2 = node->getData().getWholeName();
    if (str2 > str1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // !BST_H

