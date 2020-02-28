#include "Array.h"
#include <iostream>
#include <string>

template<typename T>

Array<T>::Array(int s){
    size = s;
    data = new T[size];
    
    for (int i = 0; i < size; i++){
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> data[i];
    }
	//print();   // Testing
}
template<typename T>
void Array<T>::print(){
    for (int i = 0; i < size; i++){
        std::cout << data[i];
    }
}
//Return reference when indexing
template<typename T>
T& Array<T>::operator [](int index){
    return (data[index]);
}
