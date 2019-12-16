#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
public:	
	Person();
	Person(std::string, std::string, std::string, std::string, std::string);

	void setName(std::string);
	void setAddress(std::string);
	void setCity(std::string);
	void setState(std::string);
	void setZipcode(std::string);

	std::string getName();
	std::string getAddress();
	std::string getCity();
	std::string getState();
	std::string getZipcode();

	void print();

private:
	std::string name;
	std::string address;
	std::string city; 
	std::string state;
	std::string zipcode;
};



#endif