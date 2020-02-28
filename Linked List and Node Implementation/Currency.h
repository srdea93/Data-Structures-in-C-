/*

Currency base class that contains 4 member variables:

note, whole, fraction, and coin. This base class is used to create

5 derived classes of different types of currencies as well as

define overloaded operators for +, -, >, <, >>, and <<.

Importantly, each derived class has an overloaded constructor

*/

#pragma once

#include <string>

#include <iostream>

#include <fstream>



class Currency {

private:

	std::string m_note;

	int m_whole;

	int m_fraction;

	std::string m_coin;



public:

	Currency();

	Currency(std::string note, int whole, int fraction, std::string coin);

	std::string getNote();

	int getWhole();

	int getFraction();

	std::string getCoin();



	//set operators for the integer values

	void setWhole(int whole);

	void setFraction(int fraction);



	//arithmetic operator overloads

	void operator+(Currency &currency);

	void operator-(Currency &currency);

	bool operator>(Currency &currency);

	bool operator<(Currency &currency);



	//input/output operator overloads

	//input, take in any reference to a currency object

	friend std::istream& operator>>(std::istream &in, Currency &currency);

	//output should write out the values of any currency

	friend std::ostream& operator<<(std::ostream &out, Currency &currency);



	virtual ~Currency();

};



class Dollar :public Currency {

public:

	Dollar();

	Dollar(std::string note, int whole, int fraction, std::string coin);

	~Dollar();

};



class Euro :public Currency {

public:

	Euro();

	Euro(std::string note, int whole, int fraction, std::string coin);

	~Euro();

};



class Yen :public Currency {

public:

	Yen();

	Yen(std::string note, int whole, int fraction, std::string coin);

	~Yen();

};



class Rupee :public Currency {

public:

	Rupee();

	Rupee(std::string note, int whole, int fraction, std::string coin);

	~Rupee();

};



class Yuan :public Currency {

public:

	Yuan();

	Yuan(std::string note, int whole, int fraction, std::string coin);

	~Yuan();

};

