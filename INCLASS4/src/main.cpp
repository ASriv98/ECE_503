#include <iostream>
#include <string>


int main()
{
	 for(int i = 0; i < 100; i++)
	 {
	 	std::cout << ((1 + rand()%7) * 3)%10 << std::endl;
	 }
}


