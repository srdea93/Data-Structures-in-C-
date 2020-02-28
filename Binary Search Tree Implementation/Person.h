#pragma once
#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>
#include <sstream>

class Person
{
private:
    std::string wholeName;
    std::string birthday;
public:
    Person();
    Person(std::string inputName, std::string inputBirthday);
    void setWholeName(std::string inputWholeName);
    void setBirthday(std::string inputBirthday);
    std::string getWholeName();
    std::string getBirthday();
    
    //input, take in any Person object
    friend std::istream& operator>>(std::istream &in, Person &person);
    //output should write out the name and birthday of a Person object
    friend std::ostream& operator<<(std::ostream &out, Person &person);
};








#endif // !STACK_H