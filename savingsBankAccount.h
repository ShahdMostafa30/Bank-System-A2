#ifndef SAVINGSBANKACCOUNT_H
#define SAVINGSBANKACCOUNT_H

#include <iostream>
#include "bankAccount.h"
using namespace std;

class SavingsBankAccount : public BankAccount {
    private:
    double minimunBalance;
    public:
    SavingsBankAccount();
};

#endif
