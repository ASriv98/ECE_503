#include "BankAccount.h"

BankAccount::BankAccount()
{
	ifstream input("cashbalance.txt");
	if (!input.is_open())
	{
		setCashBalance(10000);
		ofstream file;
		file.open("cashbalance.txt");
		file << 10000 << "\n";
		file.close();

		file.open("bankAccountHistory.txt");
		file << std::left << setw(20) << "Event" << std::left << setw(20) << "Amount" << std::left << setw(20) << "Date" << std::left << setw(20) << "Balance" << "\n";
		file.close();
	}
	
	//set the cash balance to what is reflected in the textfile
	else
	{
		double cash;
		ifstream OpenFile("cashbalance.txt");
		OpenFile >> cash;
		setCashBalance(cash);
		OpenFile.close();
	}

}

void BankAccount::setCashBalance(double balance)
{
	cashBalance = balance;
}


double BankAccount::getCashBalance()
{
	return cashBalance;
}

void BankAccount::deposit(double amount)
{
	ofstream file;
	cashBalance += amount;

	//update cash balance by amount 
	file.open("cashbalance.txt");
	file << cashBalance << "\n";
	file.close();

	//add to bank account history
	file.open("bankAccountHistory.txt", fstream::app);

    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    char buf[100] = {0};
    strftime(buf, sizeof(buf), "%Y-%m-%d", localtime(&now));

	file << std::left << setw(20) << "Deposit" << std::left << setw(1) << "$" << std::left << setw(19) << amount << std::left << setw(20) << buf << std::left << setw(20) << cashBalance << "\n";
	
	file.close();


}

double BankAccount::withdraw(double amount)
{
	if(amount > cashBalance)
	{
		cout << "Not enough money in account to withdraw specified amount!" << endl;
		return -1;
	}

	else
	{
		ofstream file;
		cashBalance -= amount;
		file.open("cashbalance.txt");
		file << cashBalance << "\n";
		file.close();

		//add to bank account history
		file.open("bankAccountHistory.txt", fstream::app);

		time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
		char date[100] = {0};
		strftime(date, sizeof(date), "%Y-%m-%d", localtime(&now));

		file << std::left << setw(20) << "Withdraw" << std::left << setw(1) << "$" << std::left << setw(19) << amount << std::left << setw(20) << date << std::left << setw(20) << cashBalance << "\n";
		file.close();

		return amount;
	}

}

void BankAccount::printHistory()
{

	char line[10];
	ifstream file("cashbalance.txt");

	//Extract last line of file
	file.getline(line, 10);
	file.close();

	cout << "The cash balance of this account is: " << line << "." << endl;
	cout << endl;

	ifstream input("bankAccountHistory.txt");

	char lines[100];
	while(!input.eof())
	{
		input.getline(lines,100);
		cout << lines << endl;
	}

	input.close();
}
