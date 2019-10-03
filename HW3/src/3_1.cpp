#include <iostream>
#include <stdexcept>
#include <iomanip>

//Inputting functions for matrix, choice, printing
static int getUserChoice();
static void getUserInput(int*, int*, double[]);
static void printMatrix(bool, int*, int*, double[]);

//Computational Functions for specified matrix calculations
void Add(int*, int*, int*, int*, double[], double[], double[]);
void Subtract(int*, int*, int*, int*, double[], double[], double[]);
void Multiply(int*, int*, int*, int*, double[], double[], double[]);
double Determinant(int*, int*, double[]);
static void Transpose(int*, int*, double[], double[]);
static void Inverse(int*, int*, double[], double[]);

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

void Add(int *rowA, int *colA, int *rowB, int *colB, double matrixA[], double matrixB[], double result[])
{
	if((*rowA != *rowB) || (*colA != *colB))
	{
		throw std::invalid_argument("the two specified matrices are different sizes, it is mathematically impossible to add them.");
	}

	for(int i=0; i < (*rowA)*(*colA); i++)
	{
		result[i] = matrixA[i] + matrixB[i];
	}
}

void Subtract(int *rowA, int *colA, int *rowB, int *colB, double matrixA[], double matrixB[], double result[])
{

	if((*rowA != *rowB) || (*colA != *colB))
	{
		throw std::invalid_argument("the two specified matrices are different sizes, it is mathematically impossible to subtract them.");
	}

	for(int i=0; i < (*rowA)*(*colA); i++)
	{
		result[i] = matrixA[i] - matrixB[i];
	}
}

void Multiply(int *rowA, int *colA, int *rowB, int *colB, double matrixA[], double matrixB[], double result[])
{
	if(*colA != *rowB)
	{
		throw std::invalid_argument("Invalid matrix dimensions for multiplication.");
	}

	for(int i=0; i < *rowA; i++)
	{
		for(int j=0; j < *colB; j++)
		{
			for (int k=0; k < *colA; k++)
			{
				//std::cout << i * (*colB) + j << " : " << matrixA[i * (*colA) + k] + matrixB[k * (*colB) + j] << std::endl;
				result[i * (*colB) + j] += (matrixA[i * (*colA) + k] * matrixB[k * (*colB) + j]);
			}
		}
	}
}


double Determinant(int* rowA, int* colA, double matrixA[])
{
	if((*rowA != 3) || (*colA != 3))
	{
		throw std::invalid_argument("Determinant operations not supported for non 3x3 matrices");
	}

	//hardcoded formula for calculation of determinant of a 3x3 matrix
	double determinant = matrixA[0]*(matrixA[4]*matrixA[8]-matrixA[5]*matrixA[7])-matrixA[1]*(matrixA[3]*matrixA[8]-matrixA[5]*matrixA[6])+matrixA[2]*(matrixA[3]*matrixA[7]-matrixA[4]*matrixA[6]);
	return determinant;
}

void Transpose(int* rowA, int* colA, double matrixA[], double result[])
{
	for(int i = 0; i < (*rowA); i++)
	{
		for(int j = 0; j < (*colA); j++)
		{
			result[j*(*rowA)+ i] = matrixA[i*(*colA)+ j];
		}
	}
}

void Inverse(int* rowA, int* colA, double matrixA[], double inverse[])
{
	double determinant = Determinant(&(*rowA), &(*colA), matrixA);

	if(determinant == 0)
	{
		throw std::invalid_argument("Determinant = 0-Inverse does not exist.");
	}	

	//hardcoded formula for inverse of a 3x3 matrix
	 inverse[0] = (matrixA[4] * matrixA[8] - matrixA[7] * matrixA[5])*(1/determinant);
	 inverse[1] = (matrixA[7] * matrixA[2] - matrixA[1] * matrixA[8])*(1/determinant);
	 inverse[2] = (matrixA[1] * matrixA[5] - matrixA[2] * matrixA[4])*(1/determinant);
	 inverse[3] = (matrixA[5] * matrixA[6] - matrixA[8] * matrixA[3])*(1/determinant);
	 inverse[4] = (matrixA[8] * matrixA[0] - matrixA[2] * matrixA[6])*(1/determinant);
	 inverse[5] = (matrixA[2] * matrixA[3] - matrixA[0] * matrixA[5])*(1/determinant);
	 inverse[6] = (matrixA[3] * matrixA[7] - matrixA[6] * matrixA[4])*(1/determinant);
	 inverse[7] = (matrixA[6] * matrixA[1] - matrixA[0] * matrixA[7])*(1/determinant);
	 inverse[8] = (matrixA[0] * matrixA[4] - matrixA[1] * matrixA[3])*(1/determinant);

}

int main()
{

	//used to exit program upon menu item 7 being selected
	bool exitStatus = true;

	while(exitStatus)
	{
		int choice = getUserChoice();

		//initialization of all arrays that are used as matrices 
		//matrixA, matrixB, result, inverse
		//size of 10 by 10 vector (max 100 elements)
		int rowA, rowB, colA, colB = 0;
		double determinant = 0;
		//Max size of the array is 10x10 (100 elements)
		double matrixA[100] = {};	
		double matrixB[100] = {};
		double result [100] = {};
		double inverse[9]   = {};

		//Choices 1-3 require the input of 2 matrices
		if((choice == 1) || (choice == 2) || (choice == 3))
		{
			getUserInput(&rowA, &colA, matrixA); printMatrix(false, &rowA, &colA, matrixA);
			getUserInput(&rowB, &colB, matrixB); printMatrix(false, &rowB, &colB, matrixB);
		}

		//Choices 4-6 require only input of 1 matrix
		if((choice == 4) || (choice == 5) || (choice == 6))
		{	
			getUserInput(&rowA, &colA, matrixA); printMatrix(false, &rowA, &colA, matrixA);
		}

		//switch cases going through menu choices
		switch(choice)
		{
			case 1:
				Add(&rowA, &colA, &rowB, &colB, matrixA, matrixB, result);
				printMatrix(true, &rowA, &colA, result);
				break;

			case 2: 
				Subtract(&rowA, &colA, &rowB, &colB, matrixA, matrixB, result);
				printMatrix(true, &rowA, &colA, result);
				break;
			
			case 3: 
				Multiply(&rowA, &colA, &rowB, &colB, matrixA, matrixB, result);
				printMatrix(true, &rowA, &colA, result);
				break;

			case 4: 
				Transpose(&rowA, &colA, matrixA, result);
				printMatrix(true, &rowA, &colA, result);
				break;

			case 5: 
				determinant = Determinant(&rowA, &colA, matrixA);
				std::cout << "The determinant of the this 3x3 matrix is: " << determinant << std::endl;
				break;

			case 6: 
				Inverse(&rowA, &colA, matrixA, inverse);
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