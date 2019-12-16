#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage(Person sender, Person receiver, double weight, double costPerOunce, double newFee)
:Package(sender, receiver, weight, costPerOunce)
{
	setFee(newFee);
}

double TwoDayPackage::calculateCost()
{
	return (getCostPerOunce() + fee) * getWeight();
}

void TwoDayPackage::setFee(double newFee)
{
	if (newFee > 0)
	{
		fee = newFee;
	}

	else
	{
		fee = 0;
		std::cout << "The flat fee must be positive!" << std::endl;
	}
}

double TwoDayPackage::getFee()
{
	return fee;
}

std::string TwoDayPackage::getName()
{
	return "Two Day Package";
}