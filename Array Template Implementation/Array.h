/** This file defines a template class object of Array which behaves like
 * a normal array. It has two member variables, a int size and any data type
 * pointer to data. It has the basic functionality of a normal array as well:
 * overloaded subscript operator [], print, add, remove, find, count, checkEmpty, 
 * and empty.
 * @authors Steven Dea, Darlene Pham
 * Version 1.0 10/24/19
 */
#pragma once

#ifndef ARRAY_H

#define ARRAY_H



template<typename T>



class Array

{

private:

	int size;

	T *data;

public:

    Array();            

    Array(int s);   
    
/**
 * @pre int a integer that signifies the index of the Array we wish to return
 * @post
 * @return returns a reference to the data located at that particular index of the Array
 */
    T& operator[] (int);   // Get array item

/**
 * @pre 
 * @post
 * @return void, but prints out every data item in the array
 */
    void print();          // Print out the array

/**
 * @pre T& is a reference to a piece of data of any data type to be inserted into the Array
 * @post
 * @return void, but adds a new item at the end of the array
 */
    void add(T&);   // Add item to the end of array

/**
 * @pre int is the index at which the data in the Array is removed
 * @post
 * @return void, but removes the data at the specified index of the Array
 */
    void remove(int);   // Remove array item

/**
 * @pre T& is a reference to a piece of data of any data type that is being
 * searched for in the Array
 * @post
 * @return void, but prints out every data item in the array
 */
    void find(T&);      // Find an element in the array

/**
 * @pre T& is a reference to a piece of data of any data type that is being
 * counted in the Array. The number of counts is the amount of times that
 * data appears in the Array.
 * @post
 * @return int count is returned
 */
    int count(T&);      // Count how many times an item appears in the array

/**
 * @pre 
 * @post
 * @return True/False if the array is empty or not
 */
    bool checkEmpty();  // Check if the array is empty

/**
 * @pre 
 * @post
 * @return void, but removes all values from an Array
 */
    void empty();

    ~Array() {};

};



template<typename T>

Array<T>::Array()

{

    size = 0;

}



template<typename T>

Array<T>::Array(int s)

{

    size = s;

    data = new T[size];    // Allocate array



    // Input elements into the array

    for (int i = 0; i < size; i++)

    {
        try
        {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> data[i]; 
        if (std::cin.fail())
            {
                std::cin.clear();
                throw -1;
            }
        }
        catch (int x)
        {
            std::cout << "Invalid input";
            std::exit(x);
        }
    }

}



template<typename T>
T& Array<T>::operator [](int index) 
{
    return data[index];
}



template<typename T>

void Array<T>::print()

{

    for (int i = 0; i < size; i++)

        std::cout << data[i] << " ";

    std::cout << std::endl;

}



template<typename T>

void Array<T>::add(T& item)

{

    size++;   // Increase size

    T *temp = new T[size];   // Create a temporary array



    for (int i = 0; i < size; i++)

    {

        temp[i] = data[i];

    }



    // Add item to the end of the temp array

    temp[size - 1] = item;



    // Delete data array

    delete[] data;



    // Assign data to temp

    data = temp;

}



template<typename T>

void Array<T>::remove(int pos)

{

    if (checkEmpty())

    {

        // Print only if array is empty

        std::cout << "Array is empty, there's nothing to remove!" << std::endl;

    }

    else

    {

        // Move every element after pos back 

        for (int i = pos; i < size - 1; i++)

            data[i] = data[i + 1];



        // Decrease size

        size--;

    }

}



template<typename T>

void Array<T>::find(T& item)

{

    bool check = false;      // Check if there's item in the array



    for (int i = 0; i < size; i++)

    {

        if (data[i] == item)

        {

            // Print position of item

            std::cout << item << " is in position " << i + 1 << std::endl;

            check = true;

            break;

        }

    }



	// Print announcement if there's no such item in the array

	if (check == false)

		std::cout << "There's no " << item << " in the array." << std::endl;

}



template<typename T>

int Array<T>::count(T& item)

{

	int count = 0;



	// Count the numbers of appearance of an item in the array

	for (int i = 0; i < size; i++)

	{

		if (data[i] == item)

			count++;

	}



	// Print result

	std::cout << item << " appears " << count << " times in the array." << std::endl;
    return count;

}



template<typename T>

bool Array<T>::checkEmpty()

{

	if (size == 0)

		return true;

	else

		return false;

}



template<typename T>

void Array<T>::empty()

{

	size = 0;

	delete[] data;

}



#endif // !ARRAY_H

