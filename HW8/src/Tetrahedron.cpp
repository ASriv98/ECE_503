#include "Tetrahedron.h"
#include <math.h> 
#include <iostream>

Tetrahedron::Tetrahedron()
{
	setX(0); setY(0); setZ(0); setSide(0); 
}

void Tetrahedron::setSide(double val)
{
	side = val;
}

double Tetrahedron::getSide()
{
	return side;
}

double Tetrahedron::getArea()
{
	return 1.0 * sqrt(3) * side * side;
}

double Tetrahedron::getVolume()
{
	return 1.0/12.0 * sqrt(2) * side * side * side;
}

void Tetrahedron::print()
{
	std::cout << "The Tetrahedron with side length " << side << " that is located at (" << x << ", " << y << ", " << z << ") has:" <<std::endl;
	std::cout << "Area of " << getArea() << std::endl;
	std::cout << "Volume of " << getVolume() << std::endl;

}