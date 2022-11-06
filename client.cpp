#include "client.h"
    Client::Client(string n, string a, string p, BankAccount _bankAcc){
        this->name = n;
        this->address = a;
        this->phoneNum = p;
        this->bankAcc = &_bankAcc;
    }
    string Client::getName(){
        return this->name;
    }
    string Client::getAddress(){
        return this->address;
    }
    string Client::getPhoneNum(){
        return this->phoneNum;
    }