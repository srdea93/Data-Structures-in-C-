/**
 * @brief This program prompts a user to enter the size of an array that they wish to sort.
 * The array size can't be larger than 16 and larger than 0. If it is not, then the user receives
 * a message telling them that their size is out of bounds.
 * Once the user has entered a size, the user is the prompted to select what type of array they
 * wish to create: int, string, or Dollar. They are then prompted to enter their data index by index
 * and once they have filled the array, the array is then sorted using a recursive selection sort function.
 * The user is then prompted to continue or quit the program.
 * @authors Steven Dea, Darlene Pham
 * Version 1.0 10/24/19
 */
#include <iostream>
#include <string>
#include "Array.h"
#include "Currency.h"

using namespace std;
/**
 * @pre inputArr a non-empty array of type int, string, or Dollar
 * startIndex is always set to 0
 * size a positive integer between 1 and 16 (inclusive)
 * @post
 * @return void return, but cout string of the sorted array after each recursive call
 */
template <typename T>
void RecurSelectionSort(T inputArr, int startIndex, int size);

/**
 * @pre val1 a reference to an int, string, or Dollar
 * val2 a reference to an int, string or Dollar
 * val1 and val2 must be of the same data type
 * @post
 * @return void return, but swaps the 2 references at their respective indeces
 */
template <typename T>
void arrSwap(T &val1, T &val2);

int main() 
{
    const int SORT_MAX_SIZE = 16;
    bool exit = false;

    int size, choice;
    cout << "This program ask user to input an array and sort the elements in descending order." << endl;

    while (exit == false)
    {
        do
        {

            cout << "Please enter the size of the array: ";
            cin >> size;
            if (size < 0 || size > SORT_MAX_SIZE)
                cout << "Array's size must less than 16 and bigger than 0!" << endl;
        } while (size < 0 || size > SORT_MAX_SIZE);

        do
        {
            cout << "Select a Data Type to Sort:" << endl;
            cout << "1. Int" << endl;
            cout << "2. String" << endl;
            cout << "3. Dollar" << endl;
            cin >> choice;

            if (choice < 1 || choice > 3)
                cout << "Please only choose from 1 to 3!" << endl;
        } while (choice < 1 || choice > 3);

        if (choice == 1)
        {
            Array<int> obj(size);
            RecurSelectionSort(obj, 0, size);
            obj.~Array<int>();

        }
        else if (choice == 2)
        {
            Array<string> obj(size);
            RecurSelectionSort(obj, 0, size);
            obj.~Array<string>();
        }
        else
        {
            Array<Dollar> obj(size);
            RecurSelectionSort(obj, 0, size);
            obj.~Array<Dollar>();
        }
        char temp;
        cout << "Do you want to exit program? Type Y to exit, type 'N' to continue: ";
        cin >> temp;
        if (temp == 'Y')
            exit = true;
    }
}
template <typename T>
void RecurSelectionSort(T inputArr, int startIndex, int size){
    //check if we've reached the end of the array, if so, return
    if (startIndex == size-1){
        cout << "Final sorted array:" << endl; 
        ofstream outputfile;
        outputfile.open("outputfile.txt");
        outputfile << "Steven Dea and Darlene Pham output:" << endl;
        for (int k = 0; k < size; k++){
            cout << inputArr[k] << " ";
            outputfile << inputArr[k] << " ";
        } 
        cout << "\nArray written to output file: 'outputfile.txt'" << endl;
        outputfile.close();
        
        return;
    }
    //function to check the index containing the max is greater than all others
    else{
        int maxIndex = startIndex;
        int i=startIndex+1;
        
        //if an index contains a greater value, make max index the new index
        for(i; i < size; i++){
            
            if(inputArr[maxIndex] < inputArr[i]){
                maxIndex = i;
            }
        }
        //std lib swap function
        arrSwap(inputArr[maxIndex], inputArr[startIndex]);
        
        //print out the newly sorted array after each recursive call
        if (startIndex + 1 < size)
        {
            cout << "Recursion Selection #" << startIndex + 1 << endl;
            for(int l = 0; l < size; l++){
                cout << inputArr[l] << " ";
            }
            cout << endl;
            RecurSelectionSort(inputArr, startIndex + 1, size);
        }
    }
}

template <typename T>
void arrSwap(T &val1, T &val2){
    T temp;
    temp = val1;
    val1 = val2;
    val2 = temp;
}