#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <ostream>

class Polynomial
{
	friend std::ostream &operator<<(std::ostream &, const Polynomial &);
	
public:
	Polynomial();
	virtual ~Polynomial();
	
	//Setter and getter functions
	void     setPolynomial();
	double * getPolynomial();

	//operator overloaded specified
	Polynomial operator+  (const Polynomial&);
	Polynomial operator-  (const Polynomial&);
	Polynomial operator*  (const Polynomial&);
	Polynomial operator+= (const Polynomial&);
	Polynomial operator-= (const Polynomial&);
	Polynomial operator*= (const Polynomial&);

	void 	   operator=  (const Polynomial&);

private:
	//Since the max size of the polynomial is 6, max size is 6*6 + 1
	double polyTerms[13];
	int numTerms;

};

#endif