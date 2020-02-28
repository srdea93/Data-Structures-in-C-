#include <string>
#include "Person.h"

    Person::Person(){}
    Person::Person(std::string inputName, std::string inputBirthday):wholeName(inputName), birthday(inputBirthday){}
    void Person::setWholeName(std::string inputWholeName)
    {
        this->wholeName = inputWholeName;
    }
    void Person::setBirthday(std::string inputBirthday)
    {
        this->birthday = inputBirthday;
    }
    std::string Person::getWholeName()
    {
        return this->wholeName;
    }
    std::string Person::getBirthday()
    {
        return this->birthday;
    }
    
    //input, take in any Person object
    std::istream& operator>>(std::istream &in, Person &person)
    {
        std::string fname;
        std::string lname;
        if(!in)
            { 
                return in;
            }
        in >> fname;
        in >> lname;
        in >> person.birthday;
        
        person.wholeName = fname + " " + lname;
        return in;
    }
    //output should write out the name and birthday of a Person object
    std::ostream& operator<<(std::ostream &out, Person &person)
    {
        out << "Name: " << person.getWholeName() << std::endl << "Birthday: " << person.getBirthday() << std::endl;
        return out;
    }