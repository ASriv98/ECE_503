#include <iostream>
#include <fstream>
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

	ofstream file;

	file.open("results.txt");

	double x,y = 0.0;
	int circleCount = 0;


	for (int i=0; i<numIterations; i++)
	{
		x = static_cast<double>(rand()/RAND_MAX);		
		y = static_cast<double>(rand()/RAND_MAX);

		if(x**2 + y**2 <= 1)
		{
			circleCount++;
		}
	}

	file << x << ',' << y << std::endl;
	double pi = (circleCount/numIterations)*4.0

	std::cout << "The monte carlo approximation for pi using specified amount of iterations is: " << pi << std::endl;

	return 0; 
}
