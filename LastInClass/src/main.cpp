#include <iostream>
#include<deque>
#include<algorithm>
#include<numeric>
#include<iterator>


using namespace std;

int main()
{

	deque<int> deq;

	//1. Insert numbers into the deque
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(6);
	deq.push_back(2);
	deq.push_back(9);
	deq.push_back(1);
	deq.push_back(5);
	deq.push_back(0);
	deq.push_back(7);
	deq.push_back(8);


	cout << "1. The elements of the deque are: " << endl;
	for (int i = 0; i < deq.size(); ++i)
	{
		cout << deq[i] << " ";
	}
	cout << endl;
	cout << endl;


	//2. Remove value of 7
	deq.erase(remove(deq.begin(), deq.end(), 7), deq.end());
	

	cout << "2. The deque is now: (after removing 7)" << endl;
	for (int i = 0; i < deq.size(); ++i)
	{
		cout << deq[i] << " ";
	}
	cout << endl;
	cout << endl;

	//3
	replace_if(deq.begin(), deq.end(), [&](int x){return x > 6;}, 10);

	cout << "3. The deque is now: (replacing values greater than 6 with 10)" << endl;
	for (int i = 0; i < deq.size(); ++i)
	{
		cout << deq[i] << " ";
	}
	cout << endl;
	cout << endl;


	//4
	int sum = accumulate(deq.begin(), deq.end(), 0);
	cout << "4. The sum of the numbers 0 to 9 is: " << sum << endl << endl;
	deq.push_front(sum);


	//5
	int countGreaterThan6 = count_if(deq.begin(), deq.end(), [&](int x){return x > 6;});
	cout << "5. The number of elements greater than 6 is: " << countGreaterThan6 << endl << endl;

	//6
	deque<int>::iterator half;
	cout << "6. The half of every elment in the deque is: ";
	for_each(deq.begin(), deq.end(), [&](int x){cout << x/2 << " ";});
	cout << endl << endl;

	//7
	sort(deq.begin(), deq.end());
	cout << "7. The sorted deque: " << endl;
	for (int i = 0; i < deq.size(); ++i)
	{
		cout << deq[i] << " ";
	}
	cout << endl;
	cout << endl;


	//8
	deque<int>::iterator findIndex;
	findIndex = find(deq.begin(), deq.end(), 6);
	if (findIndex == deq.end()) 
	{
		cout << "6 was not found in the deque." << endl << endl;
	}
	
	else 
	{
		int pos = findIndex - deq.begin();
		cout << "8. The location of 6 in the sorted deque is index: " << pos << endl << endl;
	}
	

	//9
	cout << "9. The items in the deque are: (using ostream iterator and copy): ";
	copy(deq.begin(), deq.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	return 0;

}