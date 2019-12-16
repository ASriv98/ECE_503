#include "Sphere.h"
#include <math.h> 
#include <iostream>

Sphere::Sphere()
{
	setX(0); setY(0); setZ(0); setR(0); 
}

void Sphere::setR(double val)
{
	r = val;
}

double Sphere::getR()
{
	return r;
}

double Sphere::getArea()
{
	return 4.0* M_PI * r * r;
}

double Sphere::getVolume()
{
	return 4.0/3.0 * M_PI * r * r * r;
}

void Sphere::print()
{
	std::cout << "The sphere with radius " << r << " that is located at (" << x << ", " << y << ", " << z << ") has:" <<std::endl;
	std::cout << "Area of " << getArea() << std::endl;
	std::cout << "Volume of" << getVolume() << std::endl;

}