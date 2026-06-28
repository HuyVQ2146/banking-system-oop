#include "LoginAccount.h"
using namespace std;

LoginAccount::LoginAccount() {
    accountID = 0;
    username = "";
    password = "";
    isActive = true;
}

LoginAccount::LoginAccount(int id, string user, string pass) {
    this->accountID = id;
    this->username = user;
    this->password = pass;
    this->isActive = true;
}

LoginAccount::~LoginAccount() {
}

void LoginAccount::setUsername(string user) {
    this->username = user;
}

string LoginAccount::getUsername() const {
    return this->username;
}

void LoginAccount::setPassword(string pass) {
    this->password = pass;
}


bool LoginAccount::authenticate(string user, string pass) {
    return (this->username == user && this->password == pass && this->isActive);
}

void LoginAccount::displayInfo() const {
    cout << "Account ID: " << accountID << " | Username: " << username;
    cout << " | Status: " << (isActive ? "Active" : "Locked") << endl;
}
