#ifndef BANKER_H
#define BANKER_H

#include "LoginAccount.h"
#include "Transaction.h"
#include "Queue.h"
template <typename T> class Queue;
using namespace std;

class Banker : public LoginAccount {
private:
    string bankBranch;
    string employeeID;
    double performanceScore; 

    string bankerName;

public:
    Banker();
    Banker(string name);
    Banker(int id, string user, string pass, string branch, string empID);

    void displayInfo() const override;

    void setBranch(string branch);
    string getBranch() const;

    void approveTransaction(int transactionID);


    void processNextTransaction(Queue<Transaction>& bankQueue);
};

#endif
