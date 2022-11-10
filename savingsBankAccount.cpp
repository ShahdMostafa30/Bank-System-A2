#include "savingsBankAccount.h"

    SavingsBankAccount::SavingsBankAccount(string accountID, double balance, double minBalance = 1000) {
        if (balance >= minBalance) {
            BankAccount(accountID, balance);
            this->minimumBalance = minBalance;
        } else {
            cout << "balance should be greater than or equal minimum balance";
        }
    }

    SavingsBankAccount::SavingsBankAccount() : BankAccount() {
        this->minimumBalance = 1000;
    }

    // setters
    void SavingsBankAccount::setMinimumBalance(double minimumBalance) {
        this->minimumBalance = minimumBalance;
    }

    // getters
    double SavingsBankAccount::getMinimumBalance() {
        return this->minimumBalance;
    }

    // withdraw
    int SavingsBankAccount::withdraw(double amount) {
        if (BankAccount::balance - amount >= minimumBalance) {
            BankAccount::balance -= amount;
            return 1;
        } else {
            return 0;
        }
    }

    // deposit
    int SavingsBankAccount::deposit(double amount) {
        if (amount >= 100) {
            balance += amount;
            return 1;
        } else {
            return 0;
        }
    }