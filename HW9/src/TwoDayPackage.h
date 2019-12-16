#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(Person, Person, double, double, double);

	void setFee(double);
	double getFee();

	virtual double calculateCost();
	virtual std::string getName();

private:
	double fee;






};








#endif