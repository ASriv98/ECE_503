#ifndef SPHERE
#define SPHERE
#include "ThreeDimensionalShape.h"

class Sphere : public ThreeDimensionalShape
{
public:
	Sphere();

	void setR(double);
	double getR();

	virtual double getArea();
	virtual double getVolume();
	virtual void print();

private:
	double r;
};

#endif