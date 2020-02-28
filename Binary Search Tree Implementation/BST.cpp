#pragma once
#include <iostream>
#include "BST.h"

BST::BST() {}

Node* BST::insert(Node* node, Person key)
{
	// If BST is empty create a new node as root
	// or if 
	if (node == NULL)
	{
		node = new Node;
		node->data = key;
		node->left = NULL;
		node->right = NULL;
	}
	else if (key < node->data)  // Compare function added here
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->data)  // Compare function added here
	{
		node->right = insert(node->right, key);
	}

	return node;
}

void BST::printInOrder(Node* node)
{
	// Stop printing if no node found
	if (node == NULL)
		return;

	// First recurse on left child
	printInOrder(node->left);

	// Print data of node
	std::cout << node->data << std::endl;

	// Then recurse on right child
	printInOrder(node->right);
}

void BST::printPostOrder(Node* node)
{
	// Stop printing if no node found
	if (node == NULL)
		return;

	// First recurse on left subtree
	printPostOrder(node->left);

	// Then recurse on right subtree
	printPostOrder(node->right);

	// Print data of node
	std::cout << node->data << std::endl;
}

void BST::printPreOrder(Node* node)
{
	// Stop printing if no node found
	if (node == NULL)
		return;

	// Print data of node
	std::cout << node->data << std::endl;

	// Recurse on left tree
	printPreOrder(node->left);

	// Then recurse on right tree
	printPreOrder(node->right);
}

void BST::printBreadthFirst(Node* node)
{
	// Stop printing if no node found
	if (node == NULL)
		return;

	// Create empty queue
	Queue<Node*> queue;

	// Enqueue node
	queue.enqueue(node);

	while (queue.checkEmpty() == false)
	{
		// Print front of queue then remove it
		Node* temp = queue.peekFront();
		std::cout << temp->data << std::endl;
		queue.dequeue();

		// Enqueue left child
		if (node->left != NULL)
			queue.enqueue(node->left);

		// Enqueue right child
		if (node->right != NULL)
			queue.enqueue(node->right);
	}
}