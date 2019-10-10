#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <typeinfo>

int i = 0;	//global size of the
bool puzzleSolver(int[], int);


int main()
{
	int puzzle[1000] = {};
	int startIndex; // arr stores the puzzle
	int input = -1;

	for(int i = 0; i < 1000; i++)
	{	
		puzzle[i] = -1; //-1 signifies an invalid number according to assignment description
	} 
	
	std::cout << "Please input the puzzle, 0 signifies the end. Positive integers only " << std::endl;
	while (input != 0)
	{
		std::cin  >> input;

		if(input < 0)
		{
			throw std::invalid_argument("this function is expecting a positive integer");
		}

		puzzle[i] = input;
		i++;
	}

	//print array to test if input is working
	// for(int j = 0; j < i; j++)
	// {
	// 	std::cout << puzzle[j];
	// }

	std::cout << "Please input the start index: (0 indicates start)" << std::endl;
	std::cin >> startIndex;

	if (puzzleSolver(puzzle, startIndex)) std::cout << "A solution exists" << std::endl;
	else std::cout << "No solution exists." << std::endl;

	return 0;
}

bool puzzleSolver(int puzzle[], int startIndex)
{
	int shiftLeft  		= startIndex - *(puzzle + startIndex);
	int shiftRight 		= startIndex + *(puzzle + startIndex);
	bool shiftLeftTrue  = (*(puzzle + startIndex - *(puzzle + startIndex)) == -1 || shiftLeft < 0);
	bool shiftRightTrue = (*(puzzle + startIndex + *(puzzle + startIndex)) == -1 || shiftRight >= i);
	bool solvable = false;

	if (*(puzzle + startIndex) == 0)  return true;
	if (*(puzzle + startIndex) == -1) return false;

	*(puzzle + startIndex) = -1;

	if(!shiftRightTrue && solvable == false) 
	{
		solvable = puzzleSolver(puzzle, shiftRight);
	}

	if(!shiftLeftTrue && solvable == false)
	{
		solvable = puzzleSolver(puzzle, shiftLeft);
	}
	return solvable;
}


