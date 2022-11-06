#include "bankApplication.h"

void BankApplication::showMenu() {
    cout << "Welcome to our Banking Application "<< endl
        << "1. Create a New Account" << endl
        << "2. List Clients and Accounts" << endl
        <<" 3. Withdraw Money" << endl
        << "4. Deposit Money" << endl << endl;

    int choice;
    cin >> choice;

    if(choice == 1) {
        createAccount();
    } else if(choice == 2) {
        listClientsAndAccounts();
    } else if(choice == 3) {
        withdrawMoney();
    } else if(choice == 4) {
        depositMoney();
    }

}

void BankApplication::createAccount() {
    
}

void BankApplication::listClientsAndAccounts(){

}

void BankApplication::withdrawMoney() {

}

void BankApplication::depositMoney() {

}