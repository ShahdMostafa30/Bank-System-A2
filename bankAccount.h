#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
using namespace std;

class BankAccount {
    protected:
    string accountID;
    double balance;
    public:
    BankAccount();
    BankAccount(string accountID , double balance);
    void setBalance(double balance);
    void setAccountID (string accountID);
    string getAccountID ();
    double getBalance();
    virtual int withdraw(double amount);
    virtual int deposit(double amount);
    virtual bool isSaving();
};

#endif
