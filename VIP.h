#ifndef VIP_H
#define VIP_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class VIP {
protected:
    int vipLevel;
    double cashbackRate;
    string specialBenefit;

public:
    VIP();
    VIP(int level, double rate, string benefit);
    virtual ~VIP();

    void setVipLevel(int level);
    int getVipLevel() const;
    
    virtual void displayVipBenefits() const;
    
    double calculateDiscount(double amount) const;
};

#endif
