#include "User.h"
using namespace std;


User::User() : LoginAccount() {
    fullName = "Unknown";
    email = "N/A";
}

User::User(string name) : LoginAccount() {
    fullName = name;
    email = "N/A";
}

User::User(int id, string user, string pass, string name, string mail) 
    : LoginAccount(id, user, pass) {
    this->fullName = name;
    this->email = mail;
}


void User::displayInfo() const {
    LoginAccount::displayInfo();
    cout << "Full Name: " << fullName << " | Email: " << email << endl;
}

void User::setFullName(string name) {
    this->fullName = name;
}

string User::getFullName() const {
    return this->fullName;
}

void User::makeTransaction(Queue<Transaction>& bankQueue, int id, string type, double amount) {
    Transaction newTrans(id, fullName, type, amount);
    
    if (!bankQueue.isFull()) {
        bankQueue.enqueue(newTrans);
        cout << "[User] " << fullName << " created transaction " << type << ": " << amount << "$\n";
    } else {
        cout << "[System] Hang on today, please come back later!\n";
    }
}
