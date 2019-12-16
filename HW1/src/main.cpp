#include <iostream>
#include <string>
using namespace std;

int f (int);
int main ()
 {
 f(3);
 return 0;
 }

int f(int n)
 {
	 static int x = 1;
	 if (n <=1) return 0;
	 f (n-1);
	 x++;
	 f (n-2);
	 x++;
	 cout << "x = " << x << " n = " << n << endl;

 return 0;
 } 