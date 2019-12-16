#include "LinkedList.h"
#include <string>
#include <iostream>
#include <iomanip>



LinkedList::LinkedList()
{
	myHead = nullptr;
	myTail = nullptr;
	mySize = 0;
}

LinkedList::~LinkedList()
{
	Node * cur = myHead;
	Node * tmp;

	while (cur != nullptr)
	{
		tmp = cur;
		cur = cur->next;
		delete tmp;
	}
}

int LinkedList::size() const
{
	return mySize;
}

void LinkedList::addToStart(Node * ptr)
{
	if(size() == 0)
	{
		myHead = ptr;
		myTail = ptr;
	}

	else
	{
		ptr->next = myHead;
		myHead = ptr;
	}

	mySize += 1;
}

void LinkedList::addToEnd(Node * ptr)
{
	if(size() == 0)
	{
		myHead = ptr;
		myTail = ptr;
	}
	else
	{
		myTail->next = ptr;
		myTail = ptr;
	}
}

void LinkedList::printList()
{
	if(size() == 0)
	{
		std::cout << "Empty shopping list." << std::endl;
		std::cout << std::endl;
	}

	Node * cur = myHead;
	std::cout << std::setw(10) << "Item No" << std::setw(10) << "Item Name" << std::endl;

	while(cur != nullptr)
	{
		std::cout << std::setw(10) << cur->itemNo << std::setw(10) << cur->itemName << std::endl;
		cur = cur->next;
	}
		std::cout << std::endl;
}

void LinkedList::removeFromStart()
{
	if(size() == 0)
	{
		std::cout << "Emtpy shopping list." << std::endl;
		std::cout << std::endl;
	}

	else
	{
		Node * temp = myHead;
		myHead = myHead->next;
		delete temp;
		mySize -= 1;
	}
}

void LinkedList::removeFromEnd()
{
	if(size() == 0)
	{
		std::cout << "Emtpy shopping list." << std::endl;
		std::cout << std::endl;
	}

	else if(size() == 1)
	{
		myHead = nullptr;
		myTail = nullptr;
		mySize -= 1;
	}

	else
	{
		Node * cur = myHead;
		while(cur->next != myTail)
		{
			cur = cur->next;
		}

		myTail = cur;
		Node * tmp = myTail->next;
		myTail->next = nullptr;
		delete tmp;
		mySize -= 1;
	}
}

void LinkedList::removeNodeFromList(int number)
{
	if(size() == 0)
	{
		std::cout << "Emtpy shopping list." << std::endl;
		std::cout << std::endl;
	}

	else if(number == myHead->itemNo)
	{
		removeFromStart();
	}
	else if(number == myTail->itemNo)
	{
		removeFromEnd();
	}
	else
	{
		Node * cur = myHead;
		while(cur->next != nullptr && cur->next->itemNo != number)
		{
			cur = cur->next;
		}

		if(cur->next == nullptr)
		{
			std::cout << "Error. Item not found." << std::endl;
		}

		else
		{
			Node * tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
			mySize-= 1;
		}
	}
}

void LinkedList::removeNodeFromList(std::string name)
{
	if(size() == 0)
	{
		std::cout << "Emtpy shopping list." << std::endl;
		std::cout << std::endl;
	}

	else if(name == myHead->itemName)
	{
		removeFromStart();
	}
	else if(name == myTail->itemName)
	{
		removeFromEnd();
	}
	else
	{
		Node * cur = myHead;
		while(cur->next != nullptr && cur->next->itemName != name)
		{
			cur = cur->next;
		}

		if(cur->next == nullptr)
		{
			std::cout << "Error. Item not found." << std::endl;
		}

		else
		{
			Node * tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
			mySize-= 1;
		}
	}
}


