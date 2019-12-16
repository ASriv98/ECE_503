#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>


class Shape
{
public:
	void setX(double);
	void setY(double);
	double getX() const;
	double getY() const;

	virtual void print() = 0;

protected:
	double x;
	double y;

};


#endif