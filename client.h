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
    Client();
    void setName(string n);
    void setAddress(string a);
    void setPhoneNum(string p);
    string getName();
    string getAddress();
    string getPhoneNum();
};

#endif
