#ifndef CIRCLE
#define CIRCLE
#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape
{
public:
	Circle();

	void setR(double);
	double getR();

	virtual double getArea();
	virtual void print();

private:
	double r;
};

#endif