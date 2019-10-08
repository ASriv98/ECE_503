#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>


//Inputting functions for matrix, choice, printing
static int getUserChoice();
static void getUserInput(int*, int*, std::vector<std::vector<double>>&);
static void printMatrix(bool, int*, int*, std::vector<std::vector<double>>&);

//Computational Functions for specified matrix calculations
void Add(int*, int*, int*, int*, std::vector<std::vector<double>>&, std::vector<std::vector<double>>&, std::vector<std::vector<double>>&);
void Subtract(int*, int*, int*, int*, std::vector<std::vector<double>>&, std::vector<std::vector<double>>&, std::vector<std::vector<double>>&);
void Multiply(int*, int*, int*, int*, std::vector<std::vector<double>>&, std::vector<std::vector<double>>&, std::vector<std::vector<double>>&);
double Determinant(int*, int*, std::vector<std::vector<double>>&);
static void Transpose(int*, int*, std::vector<std::vector<double>>&, std::vector<std::vector<double>>&);
static void Inverse(int*, int*, std::vector<std::vector<double>>&, std::vector<std::vector<double>>&);

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

	if((choice < 1) || (choice > 7))
	{
		throw std::invalid_argument("received invalid menu choice");
	}

	return choice;
}

void getUserInput(int* row, int* col, std::vector<std::vector<double>> & vector)
{
	std::cout << "Please enter the number of the row: " << std::endl;
	std::cin  >> *row;

	if((*row < 1) || (*row > 10))
	{
		throw std::invalid_argument("received invalid row choice");
	}

	std::cout << "Please enter the number of the column: " << std::endl;
	std::cin  >> *col;

	if((*col < 1) || (*col > 10))
	{
		throw std::invalid_argument("received invalid row choice");
	}

	std::cout << "Please enter the value of elements" << std::endl;

	for(int i = 0; i < (*row); i++)
	{
		for(int j=0; j < (*col); j++)
		{
			double input;
			std::cin >> input;
			vector[i][j] = input;
		}

	}
}

static void printMatrix(bool result, int* row, int* col, std::vector<std::vector<double>> & vector)
{
	if(result) std::cout << "The result is: " << std::endl;
	else std::cout << "Your input is: " << std::endl;
	
	for(int i=0; i < *row; i++)
	{
		for(int j=0; j < *col; j++)
		{
			std::cout << std::setw(7) << vector[i][j];
		}

		//hardcoded formula for calculation of determinant of a 3x3 matrix
		std::cout << std::endl;
	}
}

void Add(int *rowA, int *colA, int *rowB, int *colB, std::vector<std::vector<double>> & vectorA, std::vector<std::vector<double>> & vectorB, std::vector<std::vector<double>> & result)
{
	if((*rowA != *rowB) || (*colA != *colB))
	{
		throw std::invalid_argument("the two specified matrices are different sizes, it is mathematically impossible to add them.");
	}

	for(int i=0; i < (*rowA); i++)
	{
		for(int j=0; j < (*rowB); j++)
		{
			std::cout << vectorA[i][j];
			std::cout << vectorB[i][j];
			result[i][j] = vectorA[i][j] + vectorB[i][j];
		}
	}
}

void Subtract(int *rowA, int *colA, int *rowB, int *colB, std::vector<std::vector<double>> & vectorA, std::vector<std::vector<double>> & vectorB, std::vector<std::vector<double>> & result)
{
	if((*rowA != *rowB) || (*colA != *colB))
	{
		throw std::invalid_argument("the two specified matrices are different sizes, it is mathematically impossible to add them.");
	}

	for(int i=0; i < (*rowA); i++)
	{
		for(int j=0; j < (*rowB); j++)
		{
			std::cout << vectorA[i][j];
			std::cout << vectorB[i][j];
			result[i][j] = vectorA[i][j] - vectorB[i][j];
		}
	}
}

void Multiply(int *rowA, int *colA, int *rowB, int *colB, std::vector<std::vector<double>> & vectorA, std::vector<std::vector<double>> & vectorB, std::vector<std::vector<double>> & result)
{
	if(*colA != *rowB)
	{
		throw std::invalid_argument("Invalid matrix dimensions for multiplication.");
	}

	for(int i=0; i < *rowA; i++)
	{
		for(int j=0; j <= *colB; j++)
		{
			for (int k=0; k < *colA; k++)
			{
				result[i][j] += vectorA[i][k] * vectorB[k][j]; 
			}
		}
	}
}

double Determinant(int* rowA, int* colA, std::vector<std::vector<double>> & vector)
{
	if((*rowA != 3) || (*colA != 3))
	{
		throw std::invalid_argument("Determinant operations not supported for non 3x3 matrices");
	}
	

	//hardcoded formula for a 3x3 determinant
	double determinant = vector[0][0] * (vector[1][1] * vector[2][2] - vector[1][2] * vector[2][1]) - vector[0][1] * (vector[1][0] * vector[2][2] - vector[1][2] * vector[2][0]) + vector[0][2] * (vector[1][0] * vector[2][1] - vector[1][1] * vector[2][0]);

	return determinant;
}

void Transpose(int* rowA, int* colA, std::vector<std::vector<double>> & vectorA, std::vector<std::vector<double>> & result)
{
	for(int i = 0; i < (*rowA); i++)
	{
		for(int j = 0; j < (*colA); j++)
		{
			result[i][j] = vectorA[j][i];
		}
	}
}

void Inverse(int* rowA, int* colA, std::vector<std::vector<double>> & vectorA, std::vector<std::vector<double>> & inverse)
{
	double determinant = Determinant(&(*rowA), &(*colA), vectorA);

	if(determinant == 0)
	{
		throw std::invalid_argument("Determinant = 0-Inverse does not exist.");
	}	

	//hardcoded formula for inverse of a 3x3 matrix
	inverse[0][0] = (vectorA[1][1] * vectorA[2][2] - vectorA[2][1] * vectorA[1][2])*(1/determinant);
	inverse[0][1] = (vectorA[2][1] * vectorA[0][2] - vectorA[0][1] * vectorA[2][2])*(1/determinant);
	inverse[0][2] = (vectorA[0][1] * vectorA[1][2] - vectorA[0][2] * vectorA[1][1])*(1/determinant);	  
	inverse[1][0] = (vectorA[1][2] * vectorA[2][0] - vectorA[2][2] * vectorA[1][0])*(1/determinant);
	inverse[1][1] = (vectorA[2][2] * vectorA[0][0] - vectorA[0][2] * vectorA[2][0])*(1/determinant);
	inverse[1][2] = (vectorA[0][2] * vectorA[1][0] - vectorA[0][0] * vectorA[1][2])*(1/determinant);
	inverse[2][0] = (vectorA[1][0] * vectorA[2][1] - vectorA[2][0] * vectorA[1][1])*(1/determinant);
	inverse[2][1] = (vectorA[2][0] * vectorA[0][1] - vectorA[0][0] * vectorA[2][1])*(1/determinant);
	inverse[2][2] = (vectorA[0][0] * vectorA[1][1] - vectorA[0][1] * vectorA[1][0])*(1/determinant);

}

int main()
{
	//used to exit program upon menu item 7 being selected
	bool exitStatus = true;

	while(exitStatus)
	{

		//initialization of all vectors that are used as matrices 
		//vectorA, vectorB, result, inverse
		//size of 10 by 10 vector (max 100 elements)
		int choice = getUserChoice();
		std::vector<std::vector<double> >vA(10, std::vector<double>(10));
		std::vector <std::vector<double>> vectorA(10, std::vector<double>(10));
		std::vector <std::vector<double>> vectorB(10, std::vector<double>(10));
		std::vector <std::vector<double>> result(10, std::vector<double>(10));
		std::vector <std::vector<double>> inverse(3, std::vector<double>(3));

		int rowA, rowB, colA, colB = 0;
		double determinant = 0;
		//Max size of the array is 10x10 (100 elements)

		//Choices 1-3 require the input of 2 matrices
		if((choice == 1) || (choice == 2) || (choice == 3))
		{
			getUserInput(&rowA, &colA, vectorA); printMatrix(false, &rowA, &colA, vectorA);
			getUserInput(&rowB, &colB, vectorB); printMatrix(false, &rowB, &colB, vectorB);
		}

		//Choices 4-6 require only input of 1 matrix
		if((choice == 4) || (choice == 5) || (choice == 6))
		{	
			getUserInput(&rowA, &colA, vectorA); printMatrix(false, &rowA, &colA, vectorA);
		}

		//switch cases going through menu choices
		switch(choice)
		{
			case 1:
				Add(&rowA, &colA, &rowB, &colB, vectorA, vectorB, result);
				printMatrix(true, &rowA, &colA, result);
				break;

			case 2: 
				Subtract(&rowA, &colA, &rowB, &colB, vectorA, vectorB, result);
				printMatrix(true, &rowA, &colA, result);
				break;
			
			case 3: 
				Multiply(&rowA, &colA, &rowB, &colB, vectorA, vectorB, result);
				printMatrix(true, &rowA, &colA, result);
				break;

			case 4: 
				Transpose(&rowA, &colA, vectorA, result);
				printMatrix(true, &rowA, &colA, result);
				break;

			case 5: 
				determinant = Determinant(&rowA, &colA, vectorA);
				std::cout << "The determinant of the this 3x3 matrix is: " << determinant << std::endl;
				break;

			case 6: 
				Inverse(&rowA, &colA, vectorA, inverse);
				printMatrix(true, &rowA, &colA, inverse);
				break;

			case 7: 
				exitStatus = false;
				break;

			default:
				std::cout << "Please enter a valid choice! " << std::endl;
		}
	}

	return 0;
}