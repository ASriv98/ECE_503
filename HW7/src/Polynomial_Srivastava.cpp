#include <iostream>
#include "Polynomial_Srivastava.h"
#include <stdexcept>



Polynomial::Polynomial()
{
	for(int i = 0; i < 13; i++)
		polyTerms[i] = 0;
	
	numTerms = 0;
}

Polynomial::~Polynomial()
{
	//Destructor
}

void Polynomial::setPolynomial()
{
	std::cout << "Please specify how many terms you want to include in the polynomial (1 to 7)" << std::endl;
	std::cin  >> numTerms;

	if((numTerms < 0) || (numTerms > 7))
	{
		throw std::invalid_argument("Invalid number of terms");
	}

	for(int i=0; i < numTerms; i++)
	{
		int coefficient = 0;
		int exponent 	= -10;

		while((exponent > 6) || (exponent < 0))
		{
			std::cout << "Enter cofficient and exponent: " << std::endl;
			std::cin  >> coefficient >> exponent;

			if((exponent < 0) || (exponent > 6))
			{
				std::cout << "Invalid exponent. Number should be from 0 to 6" << std::endl;
				exponent = -10;
			}

			else if(polyTerms[exponent] != 0)
			{
				std::cout << "Cannot set the same exponent twice!" << std::endl;
				exponent = -10;
			}

			else if(coefficient == 0)
			{
				std::cout << "Cofficient must not be set to 0" << std::endl;
				exponent = -10;
			}
			
			else 
			{
				polyTerms[exponent] = coefficient;
			}
			
		}
	}
}

double * Polynomial::getPolynomial()
{
	return polyTerms;
}

Polynomial Polynomial::operator+(const Polynomial &poly)
{
	Polynomial returnPoly;
	for (int i = 0; i < 7; i++)
	{
		//Adding the like exponent terms of the two polynomials
		returnPoly.polyTerms[i] = poly.polyTerms[i] + polyTerms[i];
		//updating the number of terms in the new polynomial
		if(returnPoly.polyTerms[i] != 0)
		{
			returnPoly.numTerms += 1;
		}
	}
	return returnPoly;
}

Polynomial Polynomial::operator-(const Polynomial &poly)
{
	Polynomial returnPoly;
	for (int i = 0; i < 7; i++)
	{
		//Adding the like exponent terms of the two polynomials
		returnPoly.polyTerms[i] = polyTerms[i] - poly.polyTerms[i];
		//updating the number of terms in the new polynomial
		if(returnPoly.polyTerms[i] != 0)
		{
			returnPoly.numTerms += 1;
		}
	}
	return returnPoly;
}

void Polynomial::operator=(const Polynomial &poly)
{
	numTerms = poly.numTerms;
	for(int i = 0; i < 7; i++)
	{
		polyTerms[i] = poly.polyTerms[i];
	}
}

Polynomial Polynomial::operator*(const Polynomial &poly)
{
	Polynomial returnPoly;
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if((polyTerms[i]*poly.polyTerms[j] != 0) && (i+j > 12))
			{
				throw std::invalid_argument("The multiplication went out of range");
			}
			else
			{
				returnPoly.polyTerms[i+j] = returnPoly.polyTerms[i+j] + polyTerms[i] * poly.polyTerms[j]; 
			}
		}
	}

	for (int i = 0; i < 13; i++)
	{
		if(returnPoly.polyTerms[i] != 0)
			returnPoly.numTerms += 1;
	}
	return returnPoly;
}

Polynomial Polynomial::operator+=(const Polynomial &poly)
{
	*this = *this + poly;
	return *this;
}

Polynomial Polynomial::operator-=(const Polynomial &poly)
{
	*this = *this - poly;
	return *this;
}

Polynomial Polynomial::operator*=(const Polynomial &poly)
{
	*this = *this * poly;
	return *this;
}

std::ostream & operator<<(std::ostream &output, const Polynomial &poly)
{
	if(poly.numTerms < 0)
	{
		output << "Invalid polynomial";
		return output;
	}

	else if(poly.numTerms == 0)
	{
		output << "0";
		return output;
	}

	bool firstTerm = false;
	//iterate through possible length of the polynomial
	for(int i = 0; i < 13; i++)
	{
		if(poly.polyTerms[i] != 0)
		{
			if (i == 0)
			{
				output << poly.polyTerms[i];
				firstTerm = true;
			}

			else
			{
				if(poly.polyTerms[i] > 0)
					if(firstTerm == true)
					{
						output << "+";
					}

				else if(poly.polyTerms[i] < 0)
				{
					output << "-";
				}

				output << poly.polyTerms[i] << "x";
				firstTerm = true;
			}

			if(i > 1)
			{
				output << "^" << i;
			}

		}

	}
	return output;
}