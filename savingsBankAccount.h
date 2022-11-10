#ifndef SAVINGSBANKACCOUNT_H
#define SAVINGSBANKACCOUNT_H

#include <iostream>
#include "bankAccount.h"
using namespace std;

class SavingsBankAccount : public BankAccount {
    private:
    double minimumBalance;
    bool savings = true;
    public:
    SavingsBankAccount(string accountID, double balance, double minBalance = 1000);
    SavingsBankAccount();
    void setMinimumBalance(double minimumBalance);
    double getMinimumBalance();
    int withdraw(double amount);
    int deposit(double amount);
    bool isSaving();
};

#endif
