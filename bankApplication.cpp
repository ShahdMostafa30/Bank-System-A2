#include "bankApplication.h"

void BankApplication::showMenu() {

    while(true) {
        cout << "Welcome to our Banking Application "<< endl
        << "1. Create a New Account" << endl
        << "2. List Clients and Accounts" << endl
        <<" 3. Withdraw Money" << endl
        << "4. Deposit Money" << endl
        << "0. exit " << endl;

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
        } else {
            exit(0);
        }
    }
    

}

void BankApplication::createAccount() {
    string name;
    string address;
    string phone;
    double balance;
    double minBalance;
    int type;
    string numId = to_string(clients.size()+1);
    while(numId.length() < 3) {
        numId.insert(0, "0");
    }
    
    accId = "FCAI-" + numId;
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
        clients.push_back(new Client(name, address, phone, new BankAccount(accId, balance)));
        accounts.push_back(new BankAccount(accId, balance));
    } else if (type == 2) {
        cout << "Enter the minimum Balance" << endl;
        cin >> minBalance;
        clients.push_back(new Client(name, address, phone, new SavingsBankAccount(accId, balance, minBalance)));
        accounts.push_back(new SavingsBankAccount(accId, balance, minBalance));
    } else {
        cout << "wrong choice" << endl;
        exit(0);
    } 
    
    cout << "An account was created with ID " << accId << " and Starting Balance " << balance << endl;
    
}

void BankApplication::listClientsAndAccounts(){
    for(int i = 0; i < clients.size(); i++) {
        cout << "name : " << clients[i]->getName() << endl;
        cout << "Address : " << clients[i]->getAddress() << endl;
        cout << "Phone : " << clients[i]->getPhoneNum() << endl;
        cout << "AccId : " << accounts[i]->getAccountID() << endl;
        cout << "Acc Type : ";
        accounts[i]->isSaving() ? cout << "Saving" << endl : cout << "Basic" << endl;
        cout << "Balance : " << accounts[i]->getBalance() << endl;
    }
}

void BankApplication::withdrawMoney() {
    int amount;
    cout << "Please Enter Account ID (e.g., FCAI-015)" << endl;
    cin >> accId;
    
    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i]->getAccountID() == accId) {
            cout << "Acc Type : ";
            accounts[i]->isSaving() ? cout << "Saving" << endl : cout << "Basic" << endl; 
            cout << "Balance : " << accounts[i]->getBalance() << endl;
            cout << "Please Enter The Amount to Withdraw " << endl;
            cin >> amount;

            if(accounts[i]->withdraw(amount) == 1) {
                cout << "Thank you. " << endl;
                cout << "Account ID: " << accId << endl;
                cout << "New Balance: " << accounts[i]->getBalance() << endl;
            }
            else {
                cout << "Sorry. This is more than what you can withdraw." << endl;
            }
        }
    }
    
}

void BankApplication::depositMoney() {
    int amount;
    cout << "Please Enter Account ID (e.g., FCAI-015)" << endl;
    cin >> accId;
    
    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i]->getAccountID() == accId) {
            cout << "Acc Type : ";
            accounts[i]->isSaving() ? cout << "Saving" << endl : cout << "Basic" << endl; 
            cout << "Balance : " << accounts[i]->getBalance() << endl;
            cout << "Please Enter The Amount to deposit " << endl;
            cin >> amount;

            if(accounts[i]->deposit(amount) == 1) {
                cout << "Thank you. " << endl;
                cout << "Account ID: " << accId << endl;
                cout << "New Balance: " << accounts[i]->getBalance() << endl;
            } else {
                cout << "Sorry. This is less than what you can deposit." << endl;
            }
        }
    }
}