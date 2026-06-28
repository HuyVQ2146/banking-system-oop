#include <iostream>
#include <vector>
#include <iomanip>
#include "LoginAccount.h"
#include "User.h"
#include "Banker.h"
#include "Partner.h"
#include "VIPUser.h"
#include "Queue.h"
#include "Transaction.h"
using namespace std;

// Cách chạy file:
// - Bc1: Chuyển đúng cwd
// - Bc2: Paste "g++ main3.cpp LoginAccount.cpp User.cpp Banker.cpp Partner.cpp VIPUser.cpp VIP.cpp Queue.cpp Transaction.cpp -o main; .\main" vào terminal 

int main() {
    Queue<Transaction> centralQueue(100); 

    User user1("Mike Johnson");
    User user2("Jane Smith");
    User user3("Bob Brown");

    Banker banker1("Employee Alice");

    user1.makeTransaction(centralQueue, 101, "Top up card", 500.0);
    user2.makeTransaction(centralQueue, 102, "Withdraw money", 200.0);
    user3.makeTransaction(centralQueue, 103, "Transfer money", 300.0);

    cout << "--- The Banker's session begins ---\n";

    banker1.processNextTransaction(centralQueue); 
    banker1.processNextTransaction(centralQueue); 
    banker1.processNextTransaction(centralQueue); 
    banker1.processNextTransaction(centralQueue); 

    if (centralQueue.isFull()) {
        cout << "[System] The queue is full. Please come back later.\n";
    } else if (centralQueue.isEmpty()) {
        cout << "[System] The queue is empty. No transactions to process.\n";
    } else {
        cout << "[System] There are " << centralQueue.size() << " transactions remaining in the queue.\n";
    }

    return 0;
}
