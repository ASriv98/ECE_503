#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <ostream>

class Polynomial
{
	friend std::ostream &operator<<(ostream &, const Polynomial &);
	
public:
	Polynomial();
	virtual ~Polynomial();
	
	//Setter and getter functions
	void setPolynomial();
	double * getPolynomial();

	//operator overloaded specified
	Polynomial operator+  (const Polynomial&);
	Polynomial operator+= (const Polynomial&);
	Polynomial operator-  (const Polynomial&);
	Polynomial operator-= (const Polynomial&);
	Polynomial operator*  (const Polynomial&);
	Polynomial operator*= (const Polynomial&);

	void 	   operator=  (const Polynomial&);

private:
	int maxPolynomial
	double polyTerms[maxPolynomial + 1] = {};
	int numOfTerms;

}

dsafsad
#endif