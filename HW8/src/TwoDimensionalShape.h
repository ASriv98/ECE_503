#ifndef TWO_DIM
#define TWO_DIM

#include "Shape.h"

class TwoDimensionalShape : public Shape
{
	//create an abstract base class
	virtual double getArea() = 0;
	virtual void print() = 0;

};

#endif