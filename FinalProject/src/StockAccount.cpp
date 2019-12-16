#include "StockAccount.h"
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <cmath>

//MATLAB inits
#if(_MSC_VER>=1600)
#define _STDC_utf_16__
#endif

#include "mex.h"
#include <engine.h>
#include <vector>

#pragma comment(lib,"libmx.lib")
#pragma comment(lib,"libmex.lib")
#pragma comment(lib,"libeng.lib")


using namespace std;

StockAccount::StockAccount()
{
	totalValue = 0.0;
	double cash;	

	cout << "Constructing Stock Account" << endl;
	

	ifstream transactionHistory("transactionHistory.txt");
	
	if (!transactionHistory.is_open())
	{
		ofstream file;
		file.open("transactionHistory.txt");
		file << std::left << setw(10) << "Event" << std::left  << setw(20) << "CompSymbol" << std::left << setw(10) << "Number" << std::left << setw(10) << "PricePerShare" << std::left << setw(15) << "Total Value" << std::left << setw(10) << "Time" << "\n";
		file.close();
	}

	else
	{
 		transactionHistory.close();
	}

	ifstream input("cashbalance.txt");

	if (!input.is_open())
	{
		cash = 10000;
		setCashBalance(cash);
		ofstream file; 
		file.open("cashbalance.txt");
		file << cash << "\n";
		file.close();
	}

	else
	{
		ifstream openfile("cashbalance.txt");
		openfile >> cash;
		setCashBalance(cash);
		openfile.close();
	}

	ifstream portfolio("portfolio.txt");

	if (!portfolio.is_open())
	{
		DLinkedList portfolio;
		ofstream file;
		file.open("portfolio.txt");
		file << "Cash balance = " << getCashBalance() << "\n";
		file << std::left << setw(20) << "CompanySymbol" << std::left << setw(10) << "Number" << std::left << setw(20) << "PricePerShare" << std::left << setw(10) << "Total value" << "\n";
		file.close();
	}
	
	ifstream infile("stocks.txt");

	string company;
	int shares;
	double price;

	
	while (infile >> company >> shares >> price)
		{
			stocks.insert(new Node(company, price, shares));
			// cout << "Stocks Available" << endl;
			// cout << "COMPANY: " << company << endl;
			// cout << "Shares: "  << shares << endl;
			// cout << "Price: "   << price << endl;
		}

	totalValue = stocks.portfolioValue();
	trackPortfolio();
}

StockAccount::~StockAccount()
{
	cout << "Stock Account Destructor" << endl;
}

void StockAccount::setCashBalance(double balance)
{
	cashBalance = balance;
}


double StockAccount::getCashBalance()
{
	return cashBalance;
}

double StockAccount::getStockPrice(string fileName, string company)
{
	ifstream file(fileName);
	if(!file.is_open()){
		cout << "Fail: File open error!" << endl;
		return -1;
	}
	string stockSymbol;
	double price;
	while (stockSymbol != company && !file.eof()) {
		file >> stockSymbol;
	}
	if (file.eof()){
		cout << "Fail: There is no such company!" << endl;
		return -1;
	}
	file >> price;
	return price;
}

int StockAccount::buy(string filename, string company, double customerPrice, int shares)
{
	string stockInFile;
	double stockPrice;


	ifstream input(filename);
	while (!input.eof() && stockInFile != company)
	{
		input >> stockInFile;
	}
	input >> stockPrice;

	if(stockInFile != company && input.eof())
	{
		//Stock doesn't exist
		cout << "Error. Stock not found in file" << endl;
		return -1;
	}

	else if (cashBalance >= shares * customerPrice && customerPrice > stockPrice)
	{
		//Valid purchase of stock
		cout << "Stock purchase successful!" << endl;
		stocks.insert(new Node(company, stockPrice, shares));
		stocks.bubbleSort();

	}

	else if (cashBalance < shares*customerPrice  && customerPrice > stockPrice)
	{
		cout << "Invalid funds to purchase requested amount of stocks, and stock Price is too high!" << endl;
		return -1;
	}

	else if (cashBalance > shares*customerPrice && customerPrice < stockPrice)
	{
		cout << "Requested stock price is too low!" << endl;
		return -1;
	}

	else if(cashBalance < shares*customerPrice)
	{
		cout << "Not enough money to purchase stock!" << endl;
		return -1;
	}


	ofstream file;
	file.open("transactionHistory.txt", fstream::app);

    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    char buf[100] = {0};
    strftime(buf, sizeof(buf), "%X", localtime(&now));

	file << std::left << setw(10) << "Buy" << std::left << setw(20) << company << std::left << setw(10) << shares << std::left << setw(1) << "$" << std::left << setw(9) << stockPrice << std::left << setw(1) << "$" << std::left << setw(14) << stockPrice*shares << std::left << setw(10) << buf << "\n";
	file.close();

	trackPortfolio();
	totalValue = stocks.portfolioValue();

	BankAccount bk;
	bk.withdraw(stockPrice*shares);

	ifstream input2;
	input2.open("cashbalance.txt");
	input2 >> cashBalance;
	input2.close();

	return 0;
}

int StockAccount::sell(string filename, string company, double sellPrice, int shares)
{
	ifstream input(filename);

	string stockInFile;
	double stockPrice;

	while (!input.eof() && stockInFile != company)
	{
		input >> stockInFile;
	}


	cout << stockInFile << endl;
	if(input.eof())
	{
		cout << "Error. Could not find stock in file." << endl;
		return -1;
	}

	input >> stockPrice;

	cout << stockPrice << endl;
	
	if(stockPrice > sellPrice)
	{
		cout << "Sell price is less than stock price! The stock price is: " << stockPrice << endl;
		return -1;
	}

	if (stocks.decreaseShareNum(company, shares))
	{
		stocks.bubbleSort();
	
		ofstream file;
		file.open("transactionHistory.txt", fstream::app);

	    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
	    char buf[100] = {0};
	    strftime(buf, sizeof(buf), "%X", localtime(&now));

		file << std::left << setw(10) << "Sell" << std::left << setw(20) << company << std::left << setw(10) << shares << std::left << setw(1) << "$" << std::left << setw(9) << stockPrice << std::left << setw(1) << "$" << std::left << setw(14) << stockPrice*shares << std::left << setw(10) << buf << "\n";
		file.close();

		totalValue = stocks.portfolioValue();

		BankAccount bk;
		bk.deposit(stockPrice*shares);

		ifstream input2;
		input2.open("cashbalance.txt");
		input2 >> cashBalance;
		input2.close();

		trackPortfolio();

		return 0;
	}

	else
	return 0;

}

void StockAccount::printHistory()
{
	char line[10];
	ifstream file("cashbalance.txt");

	//Extract last line of file
	file.getline(line, 10);
	file.close();

	cout << "The cash balance of this account is: " << line << "." << endl;
	cout << endl;

	ifstream input("transactionHistory.txt");

	char lines[100];
	while(!input.eof())
	{
		input.getline(lines,100);
		cout << lines << endl;
	}

	input.close();
}

void StockAccount::printPortfolio()
{
	ifstream in;
	in.open("cashbalance.txt");
	in >> cashBalance;
	in.close();
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << "Cash Balance = $" << cashBalance << endl;
	

	stocks.writePortfolio();
	char line[100];
	ifstream file;
	file.open("portfolio.txt"); 
	
	while (!file .eof()) {
		file.getline(line, 100);
		cout << line << "\n";
	}

	file.close();
	cout << "Total Portfolio Value = $" << cashBalance + totalValue << endl;
	cout << endl;

}

void StockAccount::trackPortfolio()
{
	time_t clock;
	clock = time(NULL);

	fstream file("totalPortfolio.txt", fstream::app);
	double value = cashBalance + totalValue;

	if(!file.is_open())
	{
		ofstream file;
		file.open("totalPortfolio.txt");
		file << std::left << setw(15) << value << std::left << setw(15) << clock << "\n";
		file.close();
	}

	else
	{
		file << setiosflags(ios::fixed) << setprecision(2);
		file << std::left << setw(15) << value << std::left << setw(15) << clock << "\n";
		file.close();
	}
}

void StockAccount::graphPortfolio()
{
	Engine * ep;
	ep = engOpen(NULL);
	
	if(ep == NULL)
	{
		cout << "ERROR: engine open failed" << endl;
		exit(1)
	}
	
	vector<double> time;
	vector<double> value;
	
	ifstream graph("totalPortfolio.txt");
	double val;
	int timeVal;
	int count;
	
	while (!graph)
	{
		if (counter % 2 == 0)
		{
			graph >> val;
			value.push_back(val)
		}
		
		else
		{
			graph >> timeVal;
			time.push_back(timeVal);
		}
		counter++;
	}
	
	double timeIndex[time.size()];
	double valueIndex[value.size()];
	
	for(int i=0; i < time.size(); i++)
	{
		timeIndex[i] = time[i];
	}
	
	for(int i=0; i < value.size(); i++)
	{
		valueIndex[i] = value[i];
	}
	
	mxArray * A;
	mxArray * B;
	
	A = mxCreateDoubleMatrix(1, time.size(), mxREAL);
	B = mxCreateDoubleMatrix(1, value.size(), mxREAL);
	
	engPutVariable(ep, "time", A);
	engPutVariable(ep, "value", B);
	
	engEvalString(ep, "plot(time, value)");
	system("pause");
	
	mxDestroyArray(A);
	engEvalString(ep, "close";);
	engClose(ep);
	
}