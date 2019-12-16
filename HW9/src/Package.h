#ifndef PACKAGE_H
#define PACKAGE_H
#include "Person.h"


class Package
{
public:	
	Package(Person, Person, double, double);

	void setSend(Person);
	Person getSend();

	void setReceive(Person);
	Person getReceive();

	void setWeight(double);
	double getWeight();

	void setCostPerOunce(double);
	double getCostPerOunce();

	virtual double calculateCost();
	void print();
	virtual std::string getName();


private:
	Person send;
	Person receive;
	double weight;
	double costPerOunce;

};

#endif