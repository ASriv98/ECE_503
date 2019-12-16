#include "Node.h"

Node::Node(string name, double stockPrice, int num)
	:company(name), shares(num), price(stockPrice)
{
	this->next = nullptr;
	this->prev = nullptr;
}


string Node::getName()
{
	return company;
}

int Node::getShares()
{
	return shares;
}

double Node::getPrice()
{
	return price;
}

double Node::getValue()
{
	return price*shares;
}

void Node::increaseShares(int amount)
{
	shares += amount;
}

void Node::decreaseShares(int amount)
{
	shares -= amount;
}