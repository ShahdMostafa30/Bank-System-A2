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
    string name;
    string address;
    string phone;
    double balance;
    double minBalance;
    int type;
    cout << "please Enter Client name " << endl;
    cin >> name;

    cout << "please Enter Client address " << endl;
    cin >> address;

    cout << "please Enter Client phone number " << endl;
    cin >> phone;

    cout << "What Type of Account Do You Like? (1) Basic (2) Saving" << endl;
    cin >> type;

    cout << "Enter the Starting Balance" << endl;
    cin >> balance;

    if(type == 1) {
        Client client(name, address, phone, BankAccount(accId, balance));
    } else if (type == 2) {
        cout << "Enter the minimum Balance" << endl;
        cin >> minBalance;
        // Client client(name, address, phone, SavingsBankAccount());
    } else {
        cout << "wrong choice" << endl;
        exit(0);
    } 
    
}

void BankApplication::listClientsAndAccounts(){
    for(int i = 0; i < clients.size(); i++) {
        cout << "name : " << clients[i].getName() << endl;
        cout << "Address : " << clients[i].getAddress() << endl;
        cout << "Phone : " << clients[i].getPhoneNum() << endl;
    }
}

void BankApplication::withdrawMoney() {
    
}

void BankApplication::depositMoney() {

}