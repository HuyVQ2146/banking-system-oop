#ifndef VIPUSER_H
#define VIPUSER_H

#include "User.h"
#include "VIP.h"
using namespace std;


class VIPUser : public User, public VIP {
private:
    double loyaltyPoints;

public:
    VIPUser();
    VIPUser(int id, string user, string pass, string name, string mail, 
            int vLevel, double vRate, string vBenefit);

    void displayInfo() const override;

    void accumulatePoints(double transactionAmount);
    
    double getLoyaltyPoints() const;
};

#endif
