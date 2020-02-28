#include <iostream>
#include <string>
#include "Calculator.h"

Calculator::Calculator() : input(), output(), charStack(), size(){}    

Calculator::Calculator(Queue<std::string> strInput, int size) : input(strInput), output(""), charStack(), size(size){}    

bool Calculator::isOperator(std::string x)
{
    if (x == "+" or x == "-" or x == "*" or x == "/" or x == "^")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Calculator::opPriority(std::string x)
{
    if (x == "-" or x == "+")
    {
        return 1;
    }
    else if (x == "*" or x == "/")
    {
        return 2;
    }
    else if (x == "^")
    {
        return 3;
    }
}

std::string Calculator::infixPostfix()
{
    int stringSize = size;
    for (int i = 0; i < stringSize; i++)
    {
        // check if the next character is an operand or an operator. If operand, add to output
        if (!isOperator(input.peekFront()->data))
        {
            output += input.peekFront()->data;
            output += " ";
            input.dequeue();
        }
        // if char is ( push to stack
        else if (input.peekFront()->data == "(")
        {
            charStack.push(input.peekFront()->data);
            input.dequeue();
        }
        // if char is ), keep popping stack and adding to output until you reach (
        else if (input.peekFront()->data == ")")
        {
            while(charStack.peek()->data != "(")
            {
                output = output + charStack.peek()->data;
                output = output + " ";
                charStack.pop();
            }
            // remove the ( from the stack
            charStack.pop();
        }
        // if char is an operator
        else
        {
            // check if the stack is empty first, if so, then push the operator on
            if (charStack.peek() == NULL)
            {
                charStack.push(input.peekFront()->data);
                input.dequeue();
            }
            else if (isOperator(charStack.peek()->data))
            {
                while(opPriority(input.peekFront()->data) <= opPriority(charStack.peek()->data))
                {
                    output += charStack.peek()->data;
                    output += " ";
                    charStack.pop();
                }
                // push the operator onto the stack if priority is >
                charStack.push(input.peekFront()->data);
                input.dequeue();
            }
        }
    }
    // Once we reach the end of a input string, pop the remaining operators off and add to output
    while(charStack.peek() != NULL)
    {
        output += charStack.peek()->data;
        output += " ";
        charStack.pop();
    }
    
    return output;
}

std::string Calculator::infixPrefix()
{
    
}

int Calculator::evaluate()
{
    
}

void Calculator::printStack()
{
    charStack.print();
}

void Calculator::printQueue()
{
    input.print();
}
