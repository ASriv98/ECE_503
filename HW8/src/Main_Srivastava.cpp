#include <iostream>
#include "Circle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Tetrahedron.h"

void circle();
void triangle();
void sphere();
void tetrahedron();


int main()
{
	bool exitStatus = false;
	int choice = -0;

	while(!(exitStatus))
	{
		std::cout << "Please choose a shape or 0 to exit: " << std::endl;
		std::cout << "1. Circle" << std::endl;
		std::cout << "2. Triangle" << std::endl;
		std::cout << "3. Sphere" << std::endl;
		std::cout << "4. Regular Tetrahedron" << std::endl;
		std::cout << "0. Exit" << std::endl;

		std::cin  >> choice;

		switch(choice)
		{
			case 0:
				std::cout << "Quitting Program"; 
				exitStatus = true;
			break;

			case 1:
				circle();
				break;

			case 2:
				triangle();
				break;	

			case 3:
				sphere();
				break;

			case 4: 
				tetrahedron();
				break;
		}

	}


	return 0;
}

void circle()
{
	double x, y, r;
	std::cout << "You have chosen circle." << std::endl;
	std::cout << "Please enter the center of the circle (x-coordinate and y-coordinate)" << std::endl;
	std::cin  >> x >> y;

	std::cout << "Please enter the radius of the circle" << std::endl;
	std::cin >> r;
	
	Circle circ;
	circ.setX(x);
	circ.setY(y);

	if(r > 0)
	{
		circ.setR(r);
		circ.print();

	}
	else 
	{
		std::cout << "Invalid radius value" << std::endl;
	}

}

void triangle()
{
	double x, y, side;
	std::cout << "You have chosen triangle." << std::endl;
	std::cout << "Please enter the center of the triangle (x-coordinate and y-coordinate)" << std::endl;
	std::cin  >> x >> y;
	std::cout << "Please enter the side length of the triangle" << std::endl;
	std::cin >> side;
	
	Triangle tri;
	tri.setX(x);
	tri.setY(y);	
	
	if(side >= 0)
	{
		tri.setSide(side);
		tri.print();

	}
	
	else 
	{
		std::cout << "Invalid side value" << std::endl;
	}
}

void sphere()
{
	double x, y, z, r;
	std::cout << "You have chosen sphere." << std::endl;
	std::cout << "Please enter the center of the sphere (x-coordinate, y-coordinate, and z-coordinate)" << std::endl;
	std::cin  >> x >> y >> z;
	std::cout << "Please enter the side length of the sphere" << std::endl;
	std::cin >> r;
	
	Sphere sp;
	sp.setX(x);
	sp.setY(y);	
	sp.setZ(z);
	
	if(r > 0)
	{
		sp.setR(r);
		sp.print();

	}
	else 
	{
		std::cout << "Invalid radius value" << std::endl;
	}
}

void tetrahedron()
{
	double x, y, z, side;
	std::cout << "You have chosen tetrahedron." << std::endl;
	std::cout << "Please enter the center of the tetrahedron (x-coordinate, y-coordinate, and z-coordinate)" << std::endl;
	std::cin  >> x >> y >> z;
	std::cout << "Please enter the side length of the tetrahedron" << std::endl;
	std::cin >> side;
	
	Tetrahedron tet;
	tet.setX(x);
	tet.setY(y);	
	tet.setZ(z);
	
	if(side > 0)
	{
		tet.setSide(side);
		tet.print();

	}
	else 
	{
		std::cout << "Invalid radius value" << std::endl;
	}
}
