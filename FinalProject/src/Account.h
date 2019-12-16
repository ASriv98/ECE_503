#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

using namespace std;

class Account
{
public:
	Account();

	virtual void setCashBalance(double) = 0;
	double getBalance();

	virtual void printHistory() {};
private:
	double cashBalance;


};

#endif