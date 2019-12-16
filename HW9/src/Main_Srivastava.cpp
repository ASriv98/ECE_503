#include <iostream>
#include <vector>
#include "Person.h"
#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"

int main()
{
	Person person1("Atul Srivastava", "4 Eamonn Court", "Kendall Park", "NJ", "08824");
	Person person2("Yusra Khan", "75 Easton Ave", "New Brunswick", "NJ", "08854");

	Person person3("John Smith", "1 Frelinghyson Road", "Piscataway", "NJ", "08854");
	Person person4("John Doe", "123 ABC Way", "ABC Town", "CA", "90023");

	Person person5("Peter Parker", "1 Spiderman Way", "NYC", "NY", "12345");
	Person person6("Bruce Wayne", "1007 Mountain Drive", "Gotham", "PA", "53540");

	double ouncecost = 0.5;
	double twodayfee = 2.00;
	double overnightfee = 5.00;

	Package package1(person1, person2, 10, ouncecost);
	TwoDayPackage package2(person3, person4, 5, ouncecost, twodayfee);
	OvernightPackage package3(person5, person6, 2, ouncecost, overnightfee);

	std::vector<Package *> packageVector;
	packageVector.push_back(&package1);
	packageVector.push_back(&package2);
	packageVector.push_back(&package3);

	std::cout << "Package delivery services program " << std::endl;
	std::cout << std::endl;

	std::cout << "Cost per ounce for a package: $" << ouncecost << "/ounce" << std::endl;
	std::cout << "Additional cost for two day delivery: $" << twodayfee << "/ounce" << std::endl;
	std::cout << "Additional cost for overnight delivery: $" << overnightfee << "/ounce" << std::endl;


	int packageNum = 1;
	double totalPackageCost = 0.0;

	for (std::vector<Package*>::iterator pack = packageVector.begin(); pack != packageVector.end(); pack++)
	{
		std::cout << "Package " << packageNum++ << ":" << std::endl;
		std::cout << std::endl;

		(*pack)->print();
		if ((*pack)->calculateCost() <= 0)
		{
			std::cout << std::endl;
			std::cout << "Error processing package request" << std::endl;
		}

		else
		{
			totalPackageCost += (*pack)->calculateCost();
		}

	}	

	std::cout << std::endl;
	std::cout << "Total cost of all the packages: $" << totalPackageCost << std::endl;

	return 0;

}