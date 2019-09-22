#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>


int main()
{
	//initialize random number generator
	srand(time(0));
	int numIterations = 0;

	//Prompt user for number of iterations of monte carlo simulations 
	std::cout << "Please enter the number of iterations you would like to use in the Monte Carlo simulation: ";
	std::cin >> numIterations;

	//Check to see if it is a valid input for number of iterations
	if(!(numIterations > 0))
	{
		std::cout << "Please enter a positive number of iterations";
		std::cin >> numIterations;
	}

	//initialize text file that we will write our x,y points to
	std::ofstream resultsFile;
	resultsFile.open("results.txt");

	//init of variables for x,y coordinates
	double x,y = 0.0;
	//init of circleCount, will track whether point is inside circle or not
	double circleCount = 0.0;

	//control loop using specified number of iterations
	for (int i=0; i<numIterations; i++)
	{
		//generating random points of x and y
		x = static_cast<double>(rand() * 1.0 / RAND_MAX);
		y = static_cast<double>(rand() * 1.0 / RAND_MAX);		

		//std::cout << x << std::endl;
		//std::cout << y << std::endl;

		//recording values of x and y to file
		resultsFile << x << ',' << y << std::endl;

		//checking to see if points x,y are within the circle or not
		if((pow(x,2) + pow(y,2)) <= 1)
		{
			circleCount+=1.0;
		}
	}

	//std::cout << circleCount;
	//std::cout << numIterations;
	double pi = (circleCount/static_cast<double>(numIterations))*4.0;

	std::cout << "The monte carlo approximation for pi using specified amount of iterations is: " << pi << std::endl;
	return 0; 
}
