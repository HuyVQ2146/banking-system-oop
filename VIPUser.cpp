#include "VIPUser.h"
using namespace std;


VIPUser::VIPUser() : User(), VIP() {
    loyaltyPoints = 0.0;
}

VIPUser::VIPUser(int id, string user, string pass, string name, string mail, 
                 int vLevel, double vRate, string vBenefit)
    : User(id, user, pass, name, mail), VIP(vLevel, vRate, vBenefit) {
    this->loyaltyPoints = 0.0;
}

void VIPUser::displayInfo() const {
    cout << "========== [ VIP USER PROFILE ] ==========" << endl;
    User::displayInfo();
    
    VIP::displayVipBenefits();
    
    cout << "Loyalty Points: " << loyaltyPoints << endl;
    cout << "==========================================" << endl;
}

void VIPUser::accumulatePoints(double transactionAmount) {
    double earned = transactionAmount * cashbackRate * 0.1; 
    loyaltyPoints += earned;
    cout << "Transaction successful! Points earned: " << earned << endl;
}

double VIPUser::getLoyaltyPoints() const {
    return loyaltyPoints;
}
