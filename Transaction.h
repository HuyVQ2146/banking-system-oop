#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
private:
    int transactionId;
    string username;
    string type;
    double amount;

public:
    Transaction();
    Transaction(int id, string name, string t, double amt);

    void display() const;

    int getId() const { return transactionId; }
    string getUsername() const { return username; }
    string getType() const { return type; }
    double getAmount() const { return amount; }
};
#endif 
