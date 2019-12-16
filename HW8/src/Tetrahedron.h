#ifndef TETRAHEDRON
#define TETRAHEDRON
#include "ThreeDimensionalShape.h"

class Tetrahedron : public ThreeDimensionalShape
{
public:
	Tetrahedron();

	void setSide(double);
	double getSide();

	virtual double getArea();
	virtual double getVolume();
	virtual void print();

private:
	double side;
};

#endif