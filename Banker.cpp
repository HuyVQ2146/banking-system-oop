#include "Banker.h"
using namespace std;

Banker::Banker() : LoginAccount() {
    bankBranch = "Main Branch";
    employeeID = "EMP000";
    performanceScore = 0.0;
}

Banker::Banker(string name) : LoginAccount() {
    bankerName = name;
    bankBranch = "Main Branch";
    employeeID = "EMP000";
    performanceScore = 0.0;
}

Banker::Banker(int id, string user, string pass, string branch, string empID)
    : LoginAccount(id, user, pass) {
    this->bankBranch = branch;
    this->employeeID = empID;
    this->performanceScore = 5.0; 
}

void Banker::displayInfo() const {
    cout << "[Banker Profile]" << endl;
    LoginAccount::displayInfo();
    cout << "Employee ID: " << employeeID << " | Branch: " << bankBranch << endl;
    cout << "Performance Score: " << performanceScore << "/10" << endl;
}

void Banker::setBranch(string branch) {
    this->bankBranch = branch;
}

string Banker::getBranch() const {
    return this->bankBranch;
}

void Banker::approveTransaction(int transactionID) {
    cout << "Banker " << employeeID << " is verifying transaction #" << transactionID << "..." << endl;
}

void Banker::processNextTransaction(Queue<Transaction>& bankQueue) {
    if (!bankQueue.isEmpty()) {
        Transaction currentTrans = bankQueue.front(); 
        
        cout << "[Banker] " << bankerName << " is processing for " 
                  << currentTrans.getUsername() << " | Request: " << currentTrans.getType() 
                  << " | Amount: " << currentTrans.getAmount() << "$\n";
        
        bankQueue.dequeue(); 
        cout << "[System] Transaction " << currentTrans.getId() 
                  << " completed. " << bankQueue.size() << " people remaining in queue.\n";
        if (bankQueue.isEmpty()) {
            cout << "[Banker] " << bankerName << " has finished all transactions for now.\n";
        }
        else  {
            Transaction lastTrans = bankQueue.back();
            cout << "[Banker] " << bankerName << " is the last transaction: " 
                      << lastTrans.getUsername() << " | Request: " << lastTrans.getType() 
                      << " | Amount: " << lastTrans.getAmount() << "$\n";
        }
    } else {
        cout << "[Banker] " << bankerName << " is currently idle, no transactions to process!\n";
    }
}

