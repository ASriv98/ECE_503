#include <iostream>
#include <stdexcept>
#include <iomanip>

static int getUserChoice();
static void getUserInput(int*, int*, double[]);
static void display();

double* Addition(int, int, int, int, double[], double[], double[]);
static void Subtraction(int, int, int, int, double[], double[], double[]);
static void Multiplication();

double Determinant();
static void Transpose();
static void Inverse();


int getUserChoice()
{
	int choice = 0;

	std::cout << "Menu" 				     << std::endl;
	std::cout << " Choice 1: Addition"       << std::endl;
	std::cout << " Choice 2: Subtraction"    << std::endl;
	std::cout << " Choice 3: Multiplication" << std::endl;
	std::cout << " Choice 4: Transpose"      << std::endl;
	std::cout << " Choice 5: Determinant"    << std::endl;
	std::cout << " Choice 6: Inverse"        << std::endl;
	std::cout << " Choice 7: Quit"           << std::endl;
	std::cout << " Enter your Choice"        << std::endl;
	std::cin  >> choice;
	std::cin.ignore(1024, '\n');

	if((choice < 1) || (choice > 7))
	{
		throw std::invalid_argument("received invalid menu choice");
	}

	return choice;
}

void getUserInput(int* row, int* col, double matrix[])
{
	std::cout << "Please enter the number of the row(1-10): " << std::endl;
	std::cin  >> *row;

	if((*row < 1) || (*row > 10))
	{
		throw std::invalid_argument("received invalid row choice");
	}

	std::cout << "Please enter the number of the column(1-10): " << std::endl;
	std::cin  >> *col;

	if((*col < 1) || (*col > 10))
	{
		throw std::invalid_argument("received invalid row choice");
	}

	std::cout << "Please enter the value of elements" << std::endl;

	for(int i = 0; i < (*row)*(*col); i++)
	{
		std::cin >> matrix[i];
		std::cin.clear();
	}
}

static void printMatrix(bool result, int* row, int* col, double matrix[])
{
	if(result) std::cout << "The result is: " << std::endl;
	else std::cout << "Your input is: " << std::endl;
	
	for(int i=0; i < *row; i++)
	{
		for(int j=0; j < *col; j++)
		{
			std::cout << std::setw(7) << matrix[j + i*(*col)];
		}
		std::cout << std::endl;
	}
}

double* Addition(int *rowA, int *colA, int *rowB, int *colB, double matrixA[], double matrixB[], double result[])
{

	if((*rowA != *rowB) || (*colA != *colB))
	{
		throw std::invalid_argument("the two specified matrices are different sizes, it is mathematically impossible to add them.");
	}

	for(int i=0; i < (*rowA)*(*colA); i++)
	{
		result[i] = matrixA[i]+matrixB[i];
	}

}

double* Subtraction(int *rowA, int *colA, int *rowB, int *colB, double matrixA[], double matrixB[], double result[])
{

	if((*rowA != *rowB) || (*colA != *colB))
	{
		throw std::invalid_argument("the two specified matrices are different sizes, it is mathematically impossible to add them.");
	}

	for(int i=0; i < (*rowA)*(*colA); i++)
	{
		result[i] = matrixA[i]+matrixB[i];
	}

}



int main()
{
	bool exitStatus = false;

	while(true)
	{
		int choice = getUserChoice();

		int rowA, rowB, colA, colB = 0;
		//Max size of the array is 10x10 (100 elements)
		double matrixA[100] = {};	
		double matrixB[100] = {};
		double result [100] = {};

		//Choices 1-3 require the input of 2 matrices
		if((choice == 1) || (choice == 2) || (choice == 3))
		{
			getUserInput(&rowA, &colA, matrixA); printMatrix(false, &rowA, &colA, matrixA);
			getUserInput(&rowB, &colB, matrixB); printMatrix(false, &rowB, &colB, matrixB);
		}

		if((choice == 4) || (choice == 5) || (choice == 6))
		{	
			getUserInput(&rowA, &colA, matrixA); printMatrix(false, &rowA, &colA, matrixA);
		}

		switch(choice)
		{
			case 1:
				Addition(&rowA, &colA, &rowB, &colB, matrixA, matrixB, result);
				printMatrix(true, &rowA, &colA, result);
				break;

			case 2: 
				Subtraction(&rowA, &colA, &rowB, &colB, matrixA, matrixB, result);
				printMatrix(true, &rowA, &colA, result);
				break;
			
			case 3: 
				break;

			case 4: 
				break;

			case 5: 
				break;

			case 6: 
				break;

			case 7: 
				exitStatus = true;
				break;

			default:
				std::cout << "Please enter a valid choice! " << std::endl;



		}
	}

	return 0;
}