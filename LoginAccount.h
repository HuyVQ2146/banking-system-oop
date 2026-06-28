#ifndef LOGINACCOUNT_H
#define LOGINACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class LoginAccount {
private:
    string username;
    string password;

protected:
    int accountID;
    bool isActive;

public:
    LoginAccount();
    LoginAccount(int id, string user, string pass);

    virtual ~LoginAccount();

    void setUsername(string user);
    string getUsername() const;
    
    void setPassword(string pass);
    
    virtual bool authenticate(string user, string pass);

    virtual void displayInfo() const;
};

#endif
