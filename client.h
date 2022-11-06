#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "bankAccount.h"
using namespace std;

class Client{
    private:
    string name;
    string address;
    string phoneNum;
    BankAccount *bankAcc;
    public:
    Client(string n, string a, string p, BankAccount _bankAcc);
    string getName();
    string getAddress();
    string getPhoneNum();
};

#endif
