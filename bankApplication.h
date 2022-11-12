#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H

#include <iostream>
#include "bankAccount.cpp"
#include "savingsBankAccount.cpp"
#include "client.cpp"
#include <vector>
#include <fstream>
using namespace std;

class BankApplication {
    private:
    vector<BankAccount*> accounts;
    vector<Client*> clients;
    string accId;
    void readFromFile();
    void writeToFile();
    public:
    BankApplication(){}
    void showMenu();
    void createAccount();
    void listClientsAndAccounts();
    void withdrawMoney();
    void depositMoney();
};

#endif
