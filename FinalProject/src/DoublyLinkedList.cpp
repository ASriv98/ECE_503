#include "DoublyLinkedList.h"
#include "StockAccount.h"
#include "Node.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

DLinkedList::DLinkedList()
{
	fstream file("stocks.txt");


	cout << "Constructor D Linked List" << endl;

	tail = new Node("", 0, 0);
	tail->next = tail;
	tail->prev = tail;

	numElements = 0;
	totalPortfolioValue = 0.0;


}

DLinkedList::~DLinkedList()
{
	cout << "Destructing DLinkedList" << endl;
	
	ofstream file("stocks.txt");

	Node * temp = tail->next;

	while (temp != tail)
	{
		//cout << temp->getName() << " " << temp->getShares() << " " << temp->getPrice() << " " << "\n";
		file << temp->getName() << " " << temp->getShares() << " " << temp->getPrice() << " " << "\n";
		temp = temp->next;
	}
	file.close();
}

int DLinkedList::size()
{
	return numElements;

}

Node * DLinkedList::returnTail()
{
	return tail;
}

void DLinkedList::insert(Node * node)
{
	node->prev = tail->prev;
	node->next = tail;
	tail->prev->next = node;
	tail->prev = node;

	numElements += 1;
	totalPortfolioValue += node->getValue();

}

void DLinkedList::deleteNode(string stockName)
{
	Node * temp = tail->next;

	if(temp->getName() == stockName)
	{
		Node * remove = temp;
		tail->next = temp->next;
		tail->next->prev = tail;
		totalPortfolioValue -= (remove->getValue());
		remove = NULL;
		numElements -= 1;
		return;
	}

	Node * remove = new Node("tempRemove", -1, -1);
	
	while (temp != tail)
	{
		if (temp->next->getName() == stockName)
		{
			Node * remove = temp->next;
			temp->next = temp->next->next;
			temp->next->prev = temp;
			totalPortfolioValue -= remove->getValue();
			remove = NULL;
			numElements -= 1;
			return;
		}
	}

	cout << "ERROR: This stock was not found and does not exist in the linked list." << endl;
	

}

double DLinkedList::portfolioValue()
{
	return totalPortfolioValue;
}

void DLinkedList::printDLL()
{
	Node* cur = tail->next;

	while(cur != tail)
	{
		cout << cur->company << ", " << cur->shares << ", " << cur->getValue() << endl;
		cur = cur->next;
	}
}

void DLinkedList::bubbleSort()
{
	Node * temp = tail->prev;

	for(int i = 0; i < numElements - 1; i++)
	{
		for(int j = 0; j < numElements - i - 1; j++)
		{
			if(temp->getValue() > temp->prev->getValue())
			{
				string tempCompany = temp->company;
				double tempPrice   = temp->price;
				int    tempShares  = temp->shares;

				temp->company = temp->prev->company;
				temp->price   = temp->prev->price;
				temp->shares  = temp->prev->shares;

				temp->prev->company = tempCompany;
				temp->prev->price   = tempPrice;
				temp->prev->shares  = tempShares;
			}
			temp = temp->prev;
		}

		temp = tail->prev;
	}
}

int DLinkedList::getShares(string company)
{
	Node * temp = tail->next;

	while(temp != tail)
	{
		if (temp->next->getName() == company)
		{
			return temp->next->getShares();
		}
		temp = temp->next;
	}

	return 0;
}

bool DLinkedList::increaseShareNum(string company, int shares)
{	
	Node * temp = tail->next;
	while (temp != tail)
	{
		if (temp->getName() == company)
		{
			totalPortfolioValue += temp->getPrice() * shares;
			temp->increaseShares(shares);
			return true;
		}
		temp = temp->next;
	}

	return false;
}

bool DLinkedList::decreaseShareNum(string company, int shares)
{
	Node * temp = tail->next;

	while(temp != tail)
	{
		if (temp->getName() == company)
		{
			
			if(temp->getShares() > shares)
			{
				totalPortfolioValue -= temp->getPrice() * shares;
				temp->decreaseShares(shares);
				return true;
			}

			else if(shares == temp->getShares())
			{
				deleteNode(company);
				return true;
			}

			else
			{
				cout << "Error. Requesting to delete more stocks than owned. Total amount of owned stocks is: " << temp->getShares() << endl;
				return false;
			}


		}

		else
		{
			temp = temp->next;
		}

		}
}


void DLinkedList::writePortfolio()
{

	fstream file("portfolio.txt");

	file << std::left << setw(20) << "CompanySymbol" << std::left << setw(10) << "Number" << std::left << setw(20) << "PricePerShare" << std::left << setw(10) << "Total value" << "\n";

	Node * temp = tail->next;

	while (temp != tail)
	{
		// cout << temp->getName() << endl;
		// cout << temp->getShares() << endl;
		// cout << temp->getPrice() << endl;

		file << std::left << setw(20) << temp->getName() << std::left << setw(10) << temp->getShares() <<  std::left << setw(20) << temp->getPrice() << std::left << setw(20) << temp->getValue() << "\n";
		temp = temp->next;
	}

	file.close();
}