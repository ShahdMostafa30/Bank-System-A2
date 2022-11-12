#include "bankApplication.h"

void BankApplication::readFromFile() {
    fstream file;
    file.open("clients.txt", ios::in);
    string line;
    string name;
    string address;
    string phone;
    double balance;
    double minBalance;
    int type;
    int counter = 0;
    string numId = to_string(clients.size()+1);
    while(numId.length() < 3) {
        numId.insert(0, "0");
    }
    
    if(file.is_open()) {
        while(getline(file, line)) {
            counter++;
            if(counter == 1) {
                name = line;
            } else if (counter == 2) {
                address = line;
            } else if (counter == 3) {
                phone = line;
            } else if (counter == 4) {
                type = stoi(line);
            } else if (counter == 5) {
                balance = stoi(line);
            } else if (counter == 6) {
                if(line != "-") {
                    minBalance = stoi(line);
                }
            } else if (counter == 7) {
                accId = "FCAI-" + numId;
                if(type == 1) {
                    clients.push_back(new Client(name, address, phone, new BankAccount(accId, balance)));
                    accounts.push_back(new BankAccount(accId, balance));
                } else if (type == 2) {
                    clients.push_back(new Client(name, address, phone, new SavingsBankAccount(accId, balance, minBalance)));
                    accounts.push_back(new SavingsBankAccount(accId, balance, minBalance)); 
                }
                counter = 0;
                
                numId = to_string(stoi(numId) + 1);
                while(numId.length() < 3) {
                    numId.insert(0, "0");
                }

                
            }
        }
    }

    file.close();
}

void BankApplication::writeToFile() {
    fstream file;
    file.open("clients.txt", ios::out);

    for(int i = 0; i < clients.size(); i++) {
        file << clients[i]->getName() << endl;
        file << clients[i]->getAddress() << endl;
        file << clients[i]->getPhoneNum() << endl;
        accounts[i]->isSaving() ? file << 2 << endl : file << 1 << endl;
        file << accounts[i]->getBalance() << endl;
        if(accounts[i]->isSaving()) {
            SavingsBankAccount* acc = static_cast<SavingsBankAccount*>(accounts[i]);
            file << acc->getMinimumBalance() << endl << endl;
        } else {
            file << "-" << endl << endl;
        }

    }

    file.close();

}

void BankApplication::showMenu() {
    readFromFile();
    while(true) {
        cout << "Welcome to our Banking Application "<< endl
        << "1. Create a New Account" << endl
        << "2. List Clients and Accounts" << endl
        << "3. Withdraw Money" << endl
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
            writeToFile();
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
        cout << "Enter (0) to keep the default minimum balance = 1000" << endl;
        cin >> minBalance;

        if(balance >= minBalance && minBalance != 0) {
            clients.push_back(new Client(name, address, phone, new SavingsBankAccount(accId, balance, minBalance)));
            accounts.push_back(new SavingsBankAccount(accId, balance, minBalance));
        } else if (balance >= 1000 && minBalance == 0) {
            clients.push_back(new Client(name, address, phone, new SavingsBankAccount(accId, balance)));
            accounts.push_back(new SavingsBankAccount(accId, balance));
        } else {
            cout << "balance should be greater than or equal minimum balance" << endl;
            exit(0);
        }
        
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
        cout << "Balance : " << accounts[i]->getBalance() << endl << endl; 
    }
}

void BankApplication::withdrawMoney() {
    int amount;
    cout << "Please Enter Account ID (e.g., FCAI-015)" << endl;
    cin >> accId;
    bool validId;
    
    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i]->getAccountID() == accId) {
            validId = true;
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
    
    if(!validId) {
        cout << "Id not found " << endl;
    }
}

void BankApplication::depositMoney() {
    int amount;
    cout << "Please Enter Account ID (e.g., FCAI-015)" << endl;
    cin >> accId;
    bool validId;
    
    for(int i = 0; i < accounts.size(); i++) {
        if(accounts[i]->getAccountID() == accId) {
            validId = true;
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

    if(!validId) {
        cout << "Id not found " << endl;
    }
}