#include <iostream>
#include <string>
using namespace std;

#include "Node.h"
#include "DoublyLinkedList.h"
#include "BankAccount.h"
#include "StockAccount.h"
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

static void mainMenu();
static void bankAccountMenu();
static void StockAccountMenu();
void bankAccount();
void stockAccount();

int main()
{
      mainMenu();
      int userChoice;

      cout << "Option: ";
      cin  >> userChoice;
      cout << endl;

      if (userChoice < 1 || userChoice > 3)
      {
            cout << "Incorrect option entered. Please enter a menu selection of 1, 2, or 3." << endl;
      }

      while(true)
      {
            switch(userChoice)
            {
                  case 1:
                  {
                        stockAccount();
                        return 0;
                  }

                  case 2:
                  {
                        bankAccount();
                        return 0;
                  }

                  case 3:
                  {
                        return 0;
                  }
            }

            return 0;
      }
}

static void mainMenu() {
      cout << "Welcome to the Account Management System." << endl;
      cout << "Please select an account to access: " << endl;
      cout << "1. Stock Portfolio Account" << endl;
      cout << "2. Bank Account" << endl;
      cout << "3. Exit" << endl;
}

static void bankAccountMenu()
{
      cout << "Please select an option" << endl;
    cout << "1. View account balance " << endl;
    cout << "2. Deposit money " << endl;
    cout << "3. Withdraw money " << endl;
    cout << "4. Print out history " << endl;
    cout << "5. Return to previous menu " << endl;
}

static void StockAccountMenu()
{
    cout << "Please select an option:" << endl;
    cout << "1. Display the price of a stock symbol " << endl;
    cout << "2. Display the current portfolio " << endl;
    cout << "3. Buy shares " << endl;
    cout << "4. Sell shares " << endl;
    cout << "5. View a graph for the portfolio value " << endl;
    cout << "6. View transaction history " << endl;
    cout << "7. Return to previous menu " << endl;
}


void bankAccount()
{
    int userChoice;
    BankAccount bk;
      
    while (true) 
    {
        bankAccountMenu();
        cout << "Option: ";
        cin >> userChoice;
        if (userChoice < 1 || userChoice > 5) 
        {
            cout << "The option number is wrong. Please enter a option between 1 and 5." << endl;
            cout << "Option: ";
            cin >> userChoice;
        }
            
        cout << endl;
        switch (userChoice) 
        {
            case 1: 
            {
                  double cash = bk.getCashBalance();
                  cout << setiosflags(ios::fixed) << setprecision(4);
                  cout << "1. You have $" << cash << " in your bank account" << endl;
                  cout << endl;
                  break;
            }
            case 2: 
            {
                  double deposit;
                  cout << "Please select the amount you wish to deposit: $" ;
                  cin >> deposit;
                  bk.deposit(deposit);
                  break;
            }
            case 3: 
            {
                  double withdraw;
                  cout << "Please select the amount you wish to withdraw: $";
                  cin >> withdraw;
                  double tag = bk.withdraw(withdraw);
                  if (tag == -1) 
                  {
                        cout << "Fail: The cash balance is not enough." << endl;
                        cout << endl;
                  }
                  else 
                  {
                        cout << "Withdraw successfully!" << endl;
                        cout << endl;
                  }
                  break;
            }
            case 4: 
            {
                  bk.printHistory();
                  cout << endl;
                  break;
            }
            case 5: 
            {
                  main();
                  return;
            }
            }
      }
}

void stockAccount()
{   
    int userChoice;
    StockAccount sa;

    while (true) {
        srand((unsigned)(time(NULL)));
        int num = rand();

        string fileName;
        if (num % 2 == 1) 
        {
            fileName = "Result_1.txt";
        }
        else 
        {
            fileName = "Result_2.txt";
        }         

        StockAccountMenu();
        cout << "Option: ";
        cin >> userChoice;
        if (userChoice < 1 || userChoice > 7) 
        {
            cout << "The option number is wrong. Please enter a option between 1 and 7." << endl;
            cout << "Option: ";
            cin  >> userChoice;
        }

            cout << endl;
            switch (userChoice) 
            {

            case 1: 
            {
                string company;
                cout << "Please enter the stock symbol: ";
                cin >> company;
                double price = sa.getStockPrice(fileName, company);
                if (price != -1) 
                {
                    cout << "Company symbol price per share" << endl;
                    cout << setiosflags(ios::fixed) << setprecision(2);
                    cout << company << " $" << price << endl;
                }
                cout << endl;
                break;
            }
            case 2: 
            {
                  sa.printPortfolio();
                  break;
            }
            case 3: 
            {
                string company;
                cout << "Please enter the stock symbol you wish to purchase: ";
                cin >> company;
                int shares;
                cout << "Please enter the number of shares: ";
                cin >> shares;
                double price;
                cout << "Please enter the maximum amount you are willing to pay per share: ";
                cin >> price;

                int success = sa.buy(fileName, company, price, shares);                          
                cout << endl;
                break;
            }
            case 4: 
            {
                string company;
                cout << "Please enter the stock symbol you wish to sell: ";
                cin >> company;
                int shares;
                cout << "Please enter the number of shares: ";
                cin >> shares;
                double price;
                cout << "Please enter the maximum amount you are willing to pay per share: ";
                cin >> price;

                int sucess = sa.sell(fileName, company, price, shares);
                cout << endl;
                break;
            }
            case 5: 
            {
                  break;
            }
            case 6: 
            {
                sa.printHistory();
                cout << endl;
                break;
            }
            case 7: 
            {
                //delete(sa);
                main();
                return;
            }
            }
      }
      return;
}