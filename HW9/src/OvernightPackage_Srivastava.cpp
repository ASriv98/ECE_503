#include "OvernightPackage.h"

OvernightPackage::OvernightPackage(Person sender, Person receiver, double weight, double costPerOunce, double newFee)
:Package(sender, receiver, weight, costPerOunce)
{
	setFee(newFee);
}

double OvernightPackage::calculateCost()
{
	return (getWeight() * (fee + getCostPerOunce()));
}

void OvernightPackage::setFee(double newFee)
{
	if (newFee > 0)
	{
		fee = newFee;
	}

	else
	{
		newFee = 0;
		std::cout << "The flat fee must be positive!" << std::endl;
	}
}

double OvernightPackage::getFee()
{
	return fee;
}

std::string OvernightPackage::getName()
{
	return "Overnight Package";
}