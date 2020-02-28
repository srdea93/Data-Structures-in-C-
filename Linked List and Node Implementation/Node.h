#pragma once
/** This file defines a template class object of Node which defines
* a single node. The class structure has one data variable accept int,
* string and Rupee will be stored in the node and an any data type pointer
* to the next node.
*
* @authors Steven Dea, Darlene Pham
* Version 1.0 10/29/19
*/
#pragma once

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
	T data;
	Node* next;
};

#endif // !NODE_H