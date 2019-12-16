#include "Package.h"

Package::Package(Person sender, Person receiver, double weight, double costPerOunce)
{
	setSend(sender);
	setReceive(receiver);	
	setWeight(weight);
	setCostPerOunce(costPerOunce);
}

void Package::setSend(Person sender)
{
	send = sender;
}

Person Package::getSend()
{
	return send;
}

void Package::setReceive(Person receiver)
{
	receive = receiver;
}

Person Package::getReceive()
{
	return receive;
}

void Package::setWeight(double target)
{
	if (target > 0)
	{
		weight = target;
	}
	else
	{
		weight = 0;
		std::cout << "The weight must be a positive value!" << std::endl;
	}
}

double Package::getWeight()
{
	return weight;
}

void Package::setCostPerOunce(double cost)
{
	if (cost > 0)
	{
		costPerOunce = cost;
	}
	else
	{
		costPerOunce = 0;
		std::cout << "The weight must be a positive value!" << std::endl;
	}
}

double Package::getCostPerOunce()
{
	return costPerOunce;
}

double Package::calculateCost()
{
	return costPerOunce * weight;
}

std::string Package::getName()
{
	return "Regular Delivery";
}

void Package::print()
{
	std::cout << "Sender: " << std::endl;
	send.print();
	std::cout << std::endl;
	std::cout << "Receipent: " << std::endl;
	receive.print();

	std::cout << std::endl;
	std::cout << "Weight of package: "  << weight << " ounces" << std::endl;
	std::cout << "Type of delivery: " << getName() << std::endl;
	std::cout << "Cost of package: $" << calculateCost() << std::endl;
	std::cout << std::endl;
}