#include "Circle.h"
#include <math.h> 
#include <iostream>

Circle::Circle()
{
	setX(0); setY(0); setR(0);
}

void Circle::setR(double val)
{
	r = val;
}

double Circle::getR()
{
	return r;
}

double Circle::getArea()
{
	return M_PI * r * r;
}

void Circle::print()
{
	std::cout << "The circle with radius " << r << " that is located at (" << x << ", " << y << ") has:" <<std::endl;
	std::cout << "Area of " << getArea() << std::endl;

}