#include "partner.h"
using namespace std;

Partner::Partner() : LoginAccount() {
    companyName = "General Partner";
    businessTaxID = "000-000-000";
    commissionRate = 0.05; 
}

Partner::Partner(int id, string user, string pass, string company, string taxID)
    : LoginAccount(id, user, pass) {
    this->companyName = company;
    this->businessTaxID = taxID;
    this->commissionRate = 0.05;
}

void Partner::displayInfo() const {
    cout << "[Partner Profile]" << endl;
    LoginAccount::displayInfo();
    cout << "Company: " << companyName << " | Tax ID: " << businessTaxID << endl;
    cout << "Commission Rate: " << (commissionRate * 100) << "%" << endl;
}

void Partner::setCompanyName(string name) {
    this->companyName = name;
}

string Partner::getCompanyName() const {
    return this->companyName;
}

void Partner::verifyPartnership() {
    cout << "Verifying business credentials for: " << companyName << "..." << endl;
}
