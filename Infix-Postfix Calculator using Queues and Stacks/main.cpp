#include <iostream>
#include <sstream>
#include <string>
#include "Calculator.h"

using namespace std;


int main() 
{
	Calculator obj;
	string input;
	bool check = false;
	cout << "This is a calculator program. Please enter a mathmatical expression!" << endl;
	cout << "*Note: Program only accepts (+,-,*,/,%), the parentheses and positive integers. There must be space between characters." << endl;
	cout << "Here's an example of a valid expression: ( 1 + 25 ) / 15 * 8" << endl;
	do
	{
		cout << "Enter your expression: ";
		getline(cin, input);
		check = obj.checkLegit(input);
		if (check == true)
			cout << "Expression is valid!" << endl;
		else
			cout << "Expression is invalid! Please enter again!" << endl;
	} while (!check);
	
	string word = "";
	Queue<string> inputQueue;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] != ' ')
			word += input[i];
		else
		{
			inputQueue.enqueue(word);
			word = "";
		}

		if (i + 1 == input.length())
			inputQueue.enqueue(word);
	}
	
	/*inputQueue.enqueue("(");
	inputQueue.enqueue("1");
	inputQueue.enqueue("+");
	inputQueue.enqueue("25");
	inputQueue.enqueue(")");
	inputQueue.enqueue("/");
	inputQueue.enqueue("15");
	inputQueue.enqueue("*");
	inputQueue.enqueue("8");*/
	//Calculator calc = Calculator(inputQueue, 9);
	//cout << calc.infixPostfix();


	//    for (int i = 0; i < 5; i++)
	//    {
	//        cout << parr[i] << endl;
	//    }
	//    cout << parr[1] << endl;
	//    cout << &parr[1] << endl;
	//    
	//    cout << test(parr[0]);

	system("pause");
}
