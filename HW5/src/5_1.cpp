#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <typeinfo>

std::string square(int n)
{
	if(!(n >= 0))
	{
		throw std::invalid_argument("this function is expecting a positive integer");
	}

	//convert integer to string after squaring
	std::string returnStatement;
	std::string squared = std::to_string(n*n);

	//std::cout << squared << std::endl;
	if(n == 1)
	{
		returnStatement = squared;
	}

	else
	{
		//add to beginning if even, else add to end
		if(n % 2 == 0)
		{
			returnStatement = square(n-1) + ", " + squared;
		}
		else
		{
			returnStatement = squared + ", " + square(n-1);
		}
	}

	return returnStatement;
}

int main()
{
	int input = 0;
	std::cout << "Please enter a positive number that you would like to run in recursive function: ";
	std::cin  >> input;


	std::string result = square(input);
	std::cout << result << std::endl;

	return 0;
}