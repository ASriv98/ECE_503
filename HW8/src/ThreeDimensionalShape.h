#ifndef THREE_DIM
#define THREE_DIM

#include "Shape.h"

class ThreeDimensionalShape : public Shape
{
	public:
		void setZ(double);
		double getZ();

		virtual double getArea() = 0;
		virtual double getVolume() = 0;
		virtual void print() = 0;

	protected:
		double z;
};


#endif