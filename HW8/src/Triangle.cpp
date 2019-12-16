#include "Triangle.h"
#include <math.h> 
#include <iostream>

Triangle::Triangle()
{
	setX(0); setY(0); setSide(0);
}

void Triangle::setSide(double val)
{
	side = val;
}

double Triangle::getSide()
{
	return side;
}

double Triangle::getArea()
{
	return (sqrt(3)/4)*side*side;
}

void Triangle::print()
{
	std::cout << "The triangle with side length " << side << " that is located at (" << x << ", " << y << ") has:" <<std::endl;
	std::cout << "Area of " << getArea() << std::endl;

}