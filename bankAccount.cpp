#include "bankAccount.h"

//Defualt constructor
BankAccount :: BankAccount ()
{
    accountID = "" ;
    balance = 0;
}


//constructor
BankAccount :: BankAccount(string accountID , double balance)
{
    this->accountID = accountID;
    this->balance = balance;
}


//setters
void BankAccount :: setAccountID(string accountID)
    {
        this->accountID = accountID;
    }

void BankAccount :: setBalance(double balance)
    {
        this->balance = balance;
    }


//getters
string BankAccount :: getAccountID()
    {
        return accountID;
    }

double BankAccount :: getBalance()
    {
        return balance;
    }


//withdraw
int BankAccount :: withdraw(double amount)
    {
        if(balance >= amount)
        {
            balance -= amount;
            return 1;
        }
        else
        {
            return 0;
        }
    }


//deposit
int BankAccount :: deposit(double amount)
    {
        if(amount > 0)
        {
            balance += amount;
            return 1;
        }
        else
        {
            return 0;
        }
    }