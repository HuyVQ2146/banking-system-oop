#include <iostream>
#include <vector>
#include <iomanip>
#include "LoginAccount.h"
#include "User.h"
#include "Banker.h"
#include "Partner.h"
#include "VIPUser.h"
using namespace std;

// Cách chạy file:
// - Bc1: Chuyển đúng cwd
// - Bc2: Paste "g++ main.cpp LoginAccount.cpp User.cpp Banker.cpp Partner.cpp VIPUser.cpp VIP.cpp -o main; .\main" vào terminal 

int main() {
    cout << "====================================================" << endl;
    cout << "                    Banking System                  " << endl;
    cout << "====================================================\n" << endl;


    cout << ">>> 1. Testing Polymorphism with Account Hierarchy:" << endl;
    
    vector<LoginAccount*> accounts;
    accounts.push_back(new User(101, "huy_quang", "pass123", "Vu Quang Huy", "huy@hust.edu.vn"));
    accounts.push_back(new Banker(202, "staff_01", "banker99", "Hanoi Branch", "EMP_HUST_01"));
    accounts.push_back(new Partner(303, "shopee_pay", "partner456", "Shopee Vietnam", "TAX-987654"));

    for (const auto& acc : accounts) {
        acc->displayInfo(); 
        cout << "-----------------------------------" << endl;
    }



    cout << "\n>>> 2. Testing Multiple Inheritance (VIPUser):" << endl;
    
    VIPUser* vipHuy = new VIPUser(777, "huy_vip", "gold_pass", "Huy Vu (Pro)", "huy.vip@hust.vn", 5, 0.1, "Priority Banking & Free Coffee");
    
    cout << "User Branch: Full Name is " << vipHuy->getFullName() << endl;
    
    cout << "VIP Branch: ";
    vipHuy->displayVipBenefits();
    
    vipHuy->accumulatePoints(5000.0);
    vipHuy->displayInfo();



    for (auto acc : accounts) delete acc;
    delete vipHuy;

    
    return 0;
}
