#include "Currency.h"
#include <string>

//explicit constructor
Currency::Currency() {};
Currency::Currency(std::string note, int whole, int fraction, std::string coin) :
	m_note(note), m_whole(whole), m_fraction(fraction), m_coin(coin) {}

//Getters for all member variables
std::string Currency::getNote() {
	return this->m_note;
}
int Currency::getWhole() {
	return this->m_whole;
}
int Currency::getFraction() {
	return this->m_fraction;
}
std::string Currency::getCoin() {
	return this->m_coin;
}

//Setters for only integer member variables
void Currency::setWhole(int whole) {
	this->m_whole = whole;
}
void Currency::setFraction(int fraction) {
	this->m_fraction = fraction;
}

//overloaded operators implemented in Currency because 
//each derived class constructor is creating a polymorphic Currency class
//Add operator with built in check for if currency is of the same type
void Currency::operator+(Currency &currency) {
	//cout error if two currencies not of the same type are added
	if (this->m_note != currency.m_note) {
		std::cout << "Can only add currencies of the same type!" << std::endl;
	}
	//add together currencies, if m_fractions go above 100, roll over the amount of times into whole
	else {
		this->m_fraction += currency.m_fraction;
		this->m_whole += currency.m_whole;
		if (this->m_fraction > 99) {
			this->m_whole += (this->m_fraction / 100);
			this->m_fraction = (this->m_fraction % 100);
		}
	}
}
//Subtract operator
void Currency::operator-(Currency &currency) {
	if (this->m_note != currency.m_note) {
		std::cout << "Can only subtract currencies of the same type!" << std::endl;
	}
	else {
		this->m_fraction -= currency.m_fraction;
		this->m_whole -= currency.m_whole;
		if (this->m_fraction < 0) {
			this->m_whole -= 1;
			this->m_fraction = abs(this->m_fraction % 100);
		}
	}
}
//Greater than compare operator
bool Currency::operator>(Currency &currency) {
	if (this->m_note != currency.m_note) {
		std::cout << "Can only compare currencies of the same type!" << std::endl;
	}
	else {
		//first compare the wholes to see if LH is > RH
		if (this->m_whole > currency.m_whole) {
			return true;
		}
		//if wholes are ==, compare fractions
		else if (this->m_whole == currency.m_whole) {
			if (this->m_fraction > currency.m_fraction) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return false;
}
//Less than compare operator
bool Currency::operator<(Currency &currency) {
	if (this->m_note != currency.m_note) {
		std::cout << "Can only compare currencies of the same type!" << std::endl;
	}
	else {
		if (this->m_whole < currency.m_whole) {
			return true;
		}
		else if (this->m_whole == currency.m_whole) {
			if (this->m_fraction < currency.m_fraction) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return false;
}

//input/output operator overloads
//input, take in any reference to a currency object
std::istream& operator>>(std::istream &in, Currency &currency) {
	if (!in) {
		return in;
	}

	std::string note, coin;
	std::string whole, fraction;
	//    char comma;
    //eat white space before the dollar type
    std::cin >> std::ws;
	std::getline(in, note, ',');
	std::getline(in, whole, ',');
	std::getline(in, fraction, ',');
	//eat white space before the coin type
	std::cin >> std::ws;
	std::getline(in, coin);

	currency.m_note = note;
	currency.m_whole = std::stoi(whole);
	currency.m_fraction = std::stoi(fraction);
	currency.m_coin = coin;

	return in;
}
//output should write out the values of any currency
//left hand is the ostream object and the right is a reference to the currency being put into the stream
std::ostream& operator<<(std::ostream &out, Currency &currency) {
	out << currency.getNote() << ", " << currency.getWhole() << ", "
		<< currency.getFraction() << ", " << currency.getCoin();

	return out;
}

//virtual destructor
Currency::~Currency() {};



//polymorphic constructors for different monetary types
Dollar::Dollar() : Currency("Dollar", 0, 0, "cent") {};
Dollar::Dollar(std::string note, int whole, int fraction, std::string coin) :
	Currency("Dollar", whole, fraction, "cent") {}
Dollar::~Dollar() {
//	std::cout << "Dollar Destroyed" << std::endl;
}

Euro::Euro() : Currency("Euro", 0, 0, "cent") {};
Euro::Euro(std::string note, int whole, int fraction, std::string coin) :
	Currency("Euro", whole, fraction, "cent") {}
Euro::~Euro() {
	std::cout << "Euro Destroyed" << std::endl;
}

Yen::Yen() : Currency("Yen", 0, 0, "sen") {};
Yen::Yen(std::string note, int whole, int fraction, std::string coin) :
	Currency("Yen", whole, fraction, "sen") {}
Yen::~Yen() {
	std::cout << "Yen Destroyed" << std::endl;
}

Rupee::Rupee() : Currency("Rupee", 0, 0, "paise") {}
Rupee::Rupee(std::string note, int whole, int fraction, std::string coin) :
	Currency("Rupee", whole, fraction, "paise") {}
Rupee::~Rupee() {
	std::cout << "Rupee Destroyed" << std::endl;
}

Yuan::Yuan() : Currency("Yuan", 0, 0, "fen") {}
Yuan::Yuan(std::string note, int whole, int fraction, std::string coin) :
	Currency("Yuan", whole, fraction, "fen") {}
Yuan::~Yuan() {
	std::cout << "Yuan Destroyed" << std::endl;
}



