#include "savingsBankAccount.h"

    SavingsBankAccount::SavingsBankAccount(string accountID, double balance, double minBalance) {
        this->accountID = accountID;
        this->balance = balance;
        this->minimumBalance = minBalance;
    }

    SavingsBankAccount::SavingsBankAccount() : BankAccount() {
        this->minimumBalance = 1000;
    }

    // setters
    void SavingsBankAccount::setMinimumBalance(double minBalance) {
        this->minimumBalance = minBalance;
    }

    // getters
    double SavingsBankAccount::getMinimumBalance() {
        return this->minimumBalance;
    }

    // withdraw
    int SavingsBankAccount::withdraw(double amount) {
        if (this->balance - amount >= minimumBalance) {
            this->balance -= amount;
            return 1;
        } else {
            return 0;
        }
    }

    // deposit
    int SavingsBankAccount::deposit(double amount) {
        if (amount >= 100) {
            this->balance += amount;
            return 1;
        } else {
            return 0;
        }
    }

    bool SavingsBankAccount::isSaving() {
        return true;
    }