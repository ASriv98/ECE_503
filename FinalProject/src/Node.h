#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using namespace std;

class Node
{
	friend class DLinkedList;

public:

	//Constructor
	Node(string, double, int);

	string getName();
	int getShares();
	double getPrice();
	double getValue();

	void increaseShares(int amount);
	void decreaseShares(int amount);

private:
	Node* prev;
	Node* next;

	string company;
	double price;
	int shares;

};








#endif