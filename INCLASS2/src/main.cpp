#include <iostream>

int main()
{
	//Variable for how many lines user will enter
	int numLines = 0;


	std::cout << "Please enter a positive number of lines you want constructed in the shape: " << std::endl;
	std::cin  >> numLines;


	for (int i=0; i<=numLines; i++)
	{
		for (int j=1; j<=i; j++)
		{
			std::cout << "*";			
		} 
		std::cout << std::endl;
	}

	return 0;
}