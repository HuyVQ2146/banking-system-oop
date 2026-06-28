#ifndef USER_H
#define USER_H

#include <string>
#include "LoginAccount.h"
#include "Queue.h"
#include "Transaction.h"
using namespace std;

template <typename T> class Queue;

class User : public LoginAccount {
private:
    string fullName;
    string email;

public:
    User();
    User(string name);
    User(int id, string user, string pass, string name, string mail);

    void displayInfo() const override;

    void setFullName(string name);
    string getFullName() const;

    void makeTransaction(Queue<Transaction>& bankQueue, int id, std::string type, double amount);
};

#endif
