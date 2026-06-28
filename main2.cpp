#include <iostream>
#include <vector>
#include <iomanip>
#include "LoginAccount.h"
#include "User.h"
#include "Banker.h"
#include "Partner.h"
#include "VIPUser.h"
#include "Queue.h"
using namespace std;

// Cách chạy file:
// - Bc1: Chuyển đúng cwd
// - Bc2: Paste "g++ main3.cpp LoginAccount.cpp User.cpp Banker.cpp Partner.cpp VIPUser.cpp VIP.cpp Queue.cpp Transaction.cpp -o main; .\main" vào terminal 

int main() {
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Size: " << q.size() << "\n";
    cout << "Front: " << q.front() << "\n";
    cout << "Back: " << q.back() << "\n";

    cout << "--- Pop 1 value ---\n";
    q.dequeue();
    cout << "Front moi: " << q.front() << "\n";
    
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 

    cout << "--- Try to enqueue when full ---\n";
    q.enqueue(70); 

    return 0;
}
