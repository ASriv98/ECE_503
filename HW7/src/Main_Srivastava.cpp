#include <iostream>
#include "Polynomial_Srivastava.h"


int main()
{
	Polynomial poly1;
	Polynomial poly2;
	Polynomial poly3;
	Polynomial poly4;

	poly1.setPolynomial();
	poly2.setPolynomial();

	std::cout << "Poly 1 is: " << poly1 << std::endl;
	std::cout << std::endl;
	std::cout << "Poly 2 is: " << poly2 << std::endl;
	poly3 = poly1;
	poly4 = poly1;

	std::cout << "Adding the polynomial yields: "       << (poly1 + poly2) << std::endl;
	std::cout << "+= the polynomial yields: "			<< (poly1 += poly2)<< std::endl;

	std::cout << "Subtracting pthe polynomial yields: " << (poly3 - poly2) << std::endl;
	std::cout << "-= the polynomial yields: "			<< (poly3 -= poly2)<< std::endl;

	std::cout << "Multiplying the polynomial yields: "  << (poly4 * poly2) << std::endl;
	std::cout << "*= the polynomial yields: "			<< (poly4 *= poly2)<< std::endl;
 
	return 0;
}