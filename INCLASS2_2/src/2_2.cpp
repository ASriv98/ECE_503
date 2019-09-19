#include <iostream>

int main()
{
	//Variable for how many lines user will enter
	int numSpaces = 0;

	//Prompt user for a positive odd number
	std::cout << "Please enter a POSITIVE ODD number max spaces you want to see in the shape: " << std::endl;
	std::cin  >> numSpaces;

	//Re prompt user if an invalid number has been entered
	if((numSpaces < 0) || (numSpaces % 2 == 0))
	{
		std::cout << "Please re-enter a number that is POSITIVE and ODD: ";
		std::cin >> numSpaces;
	}

	for(int i=0; i < (numSpaces/2)+1; i++)
	{
		std::cout << " ";
	}

	std::cout<<"*";
	std::cout<<std::endl;


	//TOP half of the shape
	for(int i=1; i<numSpaces; i+=2)
	{

		for (int j=1; j<=(numSpaces-i)/2; j++)
		{
			std::cout << " ";
		}

		std::cout << "*";

		for (int k=0; k<i; k++)
		{
			std::cout << " ";
		}

		std::cout << "*";
		std::cout << std::endl;
	}

	std::cout << "*";

	for(int i=0; i < numSpaces; i++)
	{
		std::cout << " ";
	} 

	std::cout << "*" << std::endl;

	//Bottom half of the shape

	for(int i=numSpaces-2; i>=1; i-=2)
	{

		for(int j=1; j<=(numSpaces-i)/2; j++)
		{
			std::cout << " ";
		}

		std::cout << "*";

		for (int k=0; k<i; k++)
		{
			std::cout << " ";
		}

		std::cout << "*";
		std::cout << std::endl;
	}

	for(int i=0; i < (numSpaces/2)+1; i++)
	{
		std::cout << " ";
	}

	std::cout << "*" << std::endl;
	return 0;
}