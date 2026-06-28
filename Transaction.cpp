#include "Transaction.h"
#include <iostream>
#include <string>
using namespace std;

Transaction::Transaction() {
    transactionId = 0;
    username = "";
    type = "";
    amount = 0.0;
}

Transaction::Transaction(int id, string name, string t, double amt) 
    : transactionId(id), username(name), type(t), amount(amt) {}

void Transaction::display() const {
    cout << "--- TRANSACTION DETAILS ---" << endl;
    cout << "Transaction ID: " << transactionId << endl;
    cout << "Username:       " << username << endl;
    cout << "Type:           " << type << endl;
    cout << "Amount:         $" << amount << endl;
}
