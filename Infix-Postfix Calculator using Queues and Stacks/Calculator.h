/** 
 * @authors Steven Dea, Darlene Pham
 * Version 1.0 
 */
#pragma once
#include "Stack.h"
#include "Queue.h"
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
private:
    Queue<std::string>input;
    std::string output;
    Stack<std::string> charStack;
    int size;
public:
    Calculator(); // default constructor
    Calculator(Queue<std::string>input, int size); // constructor given a string input
    bool isOperator(std::string x); // determine if a character is an operator or not
    int opPriority(std::string x); // determine the priority of a given operator
    std::string infixPostfix(); // return a postfix converted string 
    std::string infixPrefix(); // return a prefix converted string 
    int evaluate(); // return an integer evaulation of a prefix expression
    void printStack(); // print what is currently in the stack
    void printQueue(); // print what is currently in the queue
};

#endif // !CALCULATOR_H