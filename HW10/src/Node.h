#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node{
friend class LinkedList;

public:
	Node(std::string& name, int no)
		:itemName(name), itemNo(no)
	{
		this->next = NULL;
	}
private:
	std::string itemName;
	int itemNo;
	Node *next;

};

#endif
