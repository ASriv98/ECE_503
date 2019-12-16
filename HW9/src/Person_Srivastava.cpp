#include "Person.h"

Person::Person()
{
	name = "";
	address = "";
	city = "";
	state = "";
	zipcode = "";
}

Person::Person(std::string inputname, std::string inputaddress, std::string inputcity, std::string inputstate, std::string inputzipcode)
{
	name = inputname;
	address = inputaddress;
	city = inputcity;
	state = inputstate;
	zipcode = inputzipcode;
}

void Person::setName(std::string input)
{
	name = input;
}

void Person::setAddress(std::string input)
{
	address = input;
}

void Person::setCity(std::string input)
{
	city = input;
}

void Person::setState(std::string input)
{
	state = input;
}

void Person::setZipcode(std::string input)
{
	zipcode = input;
}


std::string Person::getName() 
{
	return name;
}
std::string Person::getAddress()
{ 
	return address;
}
std::string Person::getCity() 
{
	return city;
}
std::string Person::getState() 
{
	return state;
}
std::string Person::getZipcode()
{
	return zipcode;
}

void Person::print()
{
	std::cout << name << std::endl;
	std::cout << address << std::endl;
	std::cout << city << ", " << state << " " << zipcode << std::endl;
}