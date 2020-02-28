#pragma once
#ifndef NODE_H
#define NODE_H

#include "Person.h"

template<typename T>
class Node
{
private:
	T data;
	Node *left, *right;
public:
	Node();
	T getData();
	Node<T>* getLeft();
	Node<T>* getRight();
	void setData(T input);
	void setLeft(Node* input);
	void setRight(Node* input);
};

template<typename T>
Node<T>::Node()
{
	left = NULL;
	right = NULL;
}

template<typename T>
T Node<T>::getData()
{
	return this->data;
}

template<typename T>
Node<T>* Node<T>::getLeft()
{
	return this->left;
}

template<typename T>
Node<T>* Node<T>::getRight()
{
	return this->right;
}

template<typename T>
void Node<T>::setData(T input)
{
	this->data = input;
}

template<typename T>
void Node<T>::setLeft(Node* input)
{
	this->left = input;
}

template<typename T>
void Node<T>::setRight(Node* input)
{
	this->right = input;
}

#endif // !NODE_H