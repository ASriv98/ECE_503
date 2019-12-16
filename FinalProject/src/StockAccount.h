#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H

#include <iostream>
#include "Account.h"
#include "BankAccount.h"
#include "DoublyLinkedList.h"
#include "Node.h"

class StockAccount : public Account
{


public:
	StockAccount();
	virtual ~StockAccount();

	void   setCashBalance(double);
	double getCashBalance();

	int buy(string, string, double, int);
	int sell(string, string, double, int);

	void printHistory();
	void printPortfolio();

	void graphPortfolio();

	double getStockPrice(string, string);

	double getPortfolioFile();

	void trackPortfolio();


protected:


private:

	DLinkedList stocks;
	double totalValue = 0;
	double cashBalance;


};


#endif