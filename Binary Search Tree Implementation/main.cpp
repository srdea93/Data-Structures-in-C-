#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"
#include "BST.h"

using namespace std;

int main() 
{
	ifstream inFile;
	ofstream outFile;
	string filePath;
	bool check;

	do
	{
		cout << "Enter the file's path to open: ";
		cin >> filePath;

		inFile.open(filePath.c_str());

		if (!inFile)
		{
			cout << "Cannot open file! Please try again!" << endl;
			check = false;
		}
		else
		{
			cout << "File open success!" << endl;
			check = true;
		}
	} while (check == false);

	Person person;
	BST bst;
	Node<Person> *obj = NULL;
	outFile.open("NamesOutput.txt");

	while (inFile >> person)
	{
		obj = bst.insert(obj, person);
	}
    
	bst.printInOrder(obj);
	cout << endl;
	bst.printPostOrder(obj);
	cout << endl;
	bst.printPreOrder(obj);

	system("pause");
	return 0;
}