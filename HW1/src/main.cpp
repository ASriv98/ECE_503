#include <iostream>
using namespace std;


int main()
{
	//Variables used for 5 input numbers, and min/max	
	int a,b,c,d,e = 0;
	int max, min = 0;

	//Taking in 5 numbers as an input
	cout << "Input 5 numbers: " << endl;

	cin >> a >> b >> c >> d >> e;

	min = a;
	max = a;

	//Logic to check if any of the 5 numbers are a min or a max
	if(b < min)	     min = b;
	else if(b > max) max = b;

	if(c < min) min = c;
	else if(c > max) max = c;

	if(d < min) min = d;
	else if(d > max) max = d;

	if(e < min) min = e;
	else if(e > max) max = e;
	
	//Outputting the final results
	std::cout << "Min: " << min << std::endl;
	std::cout << "Max: " << max << std::endl;

	return 0;
}
