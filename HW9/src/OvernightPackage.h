#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package
{
public:
	OvernightPackage(Person, Person, double, double, double);

	void setFee(double);
	double getFee();

	virtual double calculateCost();
	virtual std::string getName();


private:
	double fee;


};








#endif