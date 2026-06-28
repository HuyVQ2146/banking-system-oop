#include "VIP.h"
using namespace std;

VIP::VIP() {
    vipLevel = 1;
    cashbackRate = 0.01;
    specialBenefit = "Standard VIP Support";
}

VIP::VIP(int level, double rate, string benefit) {
    this->vipLevel = level;
    this->cashbackRate = rate;
    this->specialBenefit = benefit;
}

VIP::~VIP() {}

void VIP::setVipLevel(int level) {
    this->vipLevel = level;
    this->cashbackRate = level * 0.02; 
}

int VIP::getVipLevel() const {
    return vipLevel;
}

void VIP::displayVipBenefits() const {
    cout << "[VIP Privileges]" << endl;
    cout << "Level: " << vipLevel << " | Cashback Rate: " << (cashbackRate * 100) << "%" << endl;
    cout << "Special Perk: " << specialBenefit << endl;
}

double VIP::calculateDiscount(double amount) const {
    return amount * cashbackRate;
}
