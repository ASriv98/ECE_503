#ifndef TRIANGE
#define TRIANGLE
#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape
{
public:
	Triangle();

	void setSide(double);
	double getSide();

	virtual double getArea();
	virtual void print();

private:
	double side;
};

#endif