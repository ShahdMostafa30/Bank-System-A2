#include <iostream>
#include "bankApplication.h"

using namespace std;

int main() {
    SavingsBankAccount account1("99", 5000, 2000);
    cout << account1.getAccountID() << endl;
    cout << account1.getBalance() << endl;
    cout << account1.getMinimumBalance() << endl;


    account1.withdraw(500);
    cout << account1.getBalance() << endl;

    account1.deposit(1000);
    cout << account1.getBalance() << endl;

    // deposit return 1 if done and 0 if not done -- can't deposit less than 100
    account1.deposit(50);
    cout << account1.getBalance() << endl;

    // withdraw return 1 if done and 0 if not done -- can't withdraw if the balance will be less than minimum balance
    account1.withdraw(5000);
    cout << account1.getBalance() << endl;



}