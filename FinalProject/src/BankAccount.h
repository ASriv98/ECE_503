#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
using namespace std;

#include "Account.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <time.h>

class BankAccount : public Account 
{

public:
	BankAccount();

	void setCashBalance(double balance);
	double getCashBalance();

	void deposit(double money);
	double withdraw(double money);

	void trackPortfolio();
	void printHistory();


protected:


private:
	double cashBalance;
};


#endif