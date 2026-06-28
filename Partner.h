#ifndef PARTNER_H
#define PARTNER_H

#include "LoginAccount.h"
using namespace std;

class Partner : public LoginAccount {
private:
    string companyName;
    string businessTaxID;
    double commissionRate; 

public:
    Partner();
    Partner(int id, string user, string pass, string company, string taxID);

    void displayInfo() const override;

    void setCompanyName(string name);
    string getCompanyName() const;

    void verifyPartnership();
};

#endif
