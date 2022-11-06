#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "bankAccount.h"
#include "savingsBankAccount.h"
using namespace std;

class Client{
    private:
    string name;
    string address;
    string phoneNum;
    BankAccount *bankAcc;
    SavingsBankAccount *savingAcc;
    public:
    Client(string n, string a, string p, BankAccount _bankAcc);
    Client(string n, string a, string p, SavingsBankAccount _bankAcc);
    string getName();
    string getAddress();
    string getPhoneNum();
};

#endif
