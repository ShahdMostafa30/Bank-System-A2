#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H

#include <iostream>
#include "bankAccount.cpp"
#include "savingsBankAccount.cpp"
#include "client.cpp"
#include <vector>
using namespace std;

class BankApplication {
    private:
    vector<BankAccount> accounts;
    vector<Client> clients;
    string accId;
    public:
    BankApplication(){}
    void showMenu();
    void createAccount();
    void listClientsAndAccounts();
    void withdrawMoney();
    void depositMoney();


};

#endif
