#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>


int main()
{
	srand(time(0));
	int numIterations = 0;

	std::cout << "Please enter the number of iterations you would like to use in the Monte Carlo simulation: ";

	std::cin >> numIterations;

	if(!(numIterations > 0))
	{
		std::cout << "Please enter a positive number of iterations";
		std::cin >> numIterations;
	}

	std::ofstream file;

	file.open("results.txt");

	double x,y = 0.0;
	double circleCount = 0.0;


	for (int i=0; i<numIterations; i++)
	{
		x = rand() * 1.0 / RAND_MAX;
		y = rand() * 1.0 / RAND_MAX;		

		//std::cout << x << std::endl;
		//std::cout << y << std::endl;

		file << x << ',' << y << std::endl;

		if((pow(x,2) + pow(y,2)) <= 1)
		{
			circleCount+=1.0;
		}
	}

	std::cout << circleCount;
	std::cout << numIterations;
	double pi = (circleCount/static_cast<double>(numIterations))*4.0;

	std::cout << "The monte carlo approximation for pi using specified amount of iterations is: " << pi << std::endl;
	return 0; 
}
