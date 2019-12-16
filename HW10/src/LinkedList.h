#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList {

public:
	LinkedList();
	~LinkedList();
	int size() const; 
	void addToStart(Node *); 
	void addToEnd(Node *); 
	void printList();
	void removeFromStart(); 
	void removeFromEnd(); 
	void removeNodeFromList(int);
	void removeNodeFromList(std::string);

private:
	Node *myHead; 
	Node *myTail; 
	int mySize; 
};



#endif
