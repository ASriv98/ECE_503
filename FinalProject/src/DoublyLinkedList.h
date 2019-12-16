#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

using namespace std;
#include <iostream>
#include <string>

#include "Node.h"

class DLinkedList
{


public: 
	DLinkedList();
	virtual ~DLinkedList();

	int size();

	Node * returnTail();

	void insert(Node * node);
	void deleteNode(string stockName);

	void bubbleSort();
	void selectionSort();

	double portfolioValue();

	int getShares(string);
	
	bool increaseShareNum(string, int);
	bool decreaseShareNum(string, int);

	void writePortfolio();

	Node* findPos(int position);

	void printDLL();

private:
	Node * tail;

	int numElements;
	double totalPortfolioValue;

};

#endif