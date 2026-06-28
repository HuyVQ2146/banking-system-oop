# BankingSystem

A C++ Object-Oriented Banking System that demonstrates core OOP principles — single inheritance, multiple inheritance, polymorphism, template classes, and composition — through a simulated bank with users, bankers, partners, VIP users, and a transaction queue.

**Course:** CS256

**Author:** Vu Quang Huy

---

## Key Concepts Demonstrated

| Concept | Implementation |
|---|---|
| **Single Inheritance** | `User`, `Banker`, `Partner` inherit from `LoginAccount` |
| **Multiple Inheritance** | `VIPUser` inherits from both `User` and `VIP` |
| **Polymorphism** | `displayInfo()` is virtual in `LoginAccount`, overridden in every derived class; called through base-class pointers |
| **Virtual Destructors** | `~LoginAccount()` is virtual for safe cleanup via base pointers |
| **Template Classes** | `Queue<T>` — a generic circular buffer |
| **Composition / Aggregation** | `User::makeTransaction()` and `Banker::processNextTransaction()` operate on a shared `Queue<Transaction>` |
| **Encapsulation** | Private members with public getters/setters throughout |
| **Constructor Delegation** | Derived classes call base constructors via initializer lists |
| **Forward Declaration** | `Queue<T>` is forward-declared in `User.h` and `Banker.h` to avoid circular includes |

---

## Class Hierarchy

```
LoginAccount  (abstract base — accountID, username, password, authenticate())
    |
    +-- User       (fullName, email, makeTransaction())
    |       |
    |       +-- VIPUser  ←── also inherits VIP (multiple inheritance)
    |                         (loyaltyPoints, accumulatePoints())
    |
    +-- Banker     (bankBranch, employeeID, performanceScore, processNextTransaction())
    |
    +-- Partner    (companyName, businessTaxID, commissionRate, verifyPartnership())

VIP  (standalone — vipLevel, cashbackRate, specialBenefit, calculateDiscount())
```

- **LoginAccount** — Base class holding authentication logic and account state.
- **User** — Bank customer who can create transactions and enqueue them.
- **Banker** — Bank employee who dequeues and processes transactions.
- **Partner** — Business partner with a fixed 5% commission rate.
- **VIP** — Standalone class providing discount/cashback benefits.
- **VIPUser** — Demonstrates multiple inheritance by combining `User` and `VIP`.
- **Transaction** — Simple data model (ID, username, type, amount).
- **Queue\<T\>** — Generic circular-buffer queue used as the central transaction pipeline.

---

## Project Structure

```
BankingSystem/
├── LoginAccount.h / .cpp   # Base account class
├── User.h / .cpp            # Regular bank user
├── Banker.h / .cpp          # Bank employee
├── Partner.h / .cpp         # Business partner
├── VIP.h / .cpp             # VIP benefits (standalone)
├── VIPUser.h / .cpp        # VIP user (multiple inheritance)
├── Transaction.h / .cpp     # Transaction data model
├── Queue.h / .cpp           # Generic circular queue template
├── main.cpp                 # Demo 1: Polymorphism & multiple inheritance
├── main2.cpp                # Demo 2: Queue template with integers
├── main3.cpp                # Demo 3: Full banking simulation
└── README.md
```

---

## Three Demo Programs

### 1. Polymorphism & Multiple Inheritance (`main.cpp`)

Creates a `vector<LoginAccount*>` containing a `User`, a `Banker`, and a `Partner`. Calls `displayInfo()` on each through the base pointer to demonstrate runtime polymorphism. Then creates a `VIPUser` to show multiple inheritance in action — calling methods from both the `User` and `VIP` branches.

```bash
g++ main.cpp LoginAccount.cpp User.cpp Banker.cpp Partner.cpp VIPUser.cpp VIP.cpp Transaction.cpp -o main
./main
```

### 2. Queue Template (`main2.cpp`)

Tests the `Queue<int>` template with enqueue, dequeue, front, and back operations, including boundary conditions (full queue, empty queue).

```bash
g++ main2.cpp Queue.cpp -o main2
./main2
```

### 3. Full Banking Simulation (`main3.cpp`)

The most complete demo. Three `User` objects create transactions (top-up, withdrawal, transfer) and enqueue them into a shared `Queue<Transaction>`. A `Banker` then processes them one by one from the queue, printing processing details and queue status after each transaction.

```bash
g++ main3.cpp LoginAccount.cpp User.cpp Banker.cpp Transaction.cpp Queue.cpp VIP.cpp VIPUser.cpp Partner.cpp -o main3
./main3
```

---

## Build Requirements

- **Compiler:** g++ (GCC) or any C++14-compatible compiler
- **No external dependencies** — standard library only

---

## Sample Output (Demo 3)

```
=== Banking System Simulation ===

--- Creating Transactions ---
Mike Johnson created transaction [T1]: Top up card - $500
Jane Smith created transaction [T2]: Withdraw money - $200
Bob Brown created transaction [T3]: Transfer money - $300

--- Processing Transactions ---
Processing transaction [T1] from Mike Johnson: Top up card - $500
Transaction processed successfully. Remaining in queue: 2
Processing transaction [T2] from Jane Smith: Withdraw money - $200
Transaction processed successfully. Remaining in queue: 1
Processing transaction [T3] from Bob Brown: Transfer money - $300
Transaction processed successfully. Remaining in queue: 0

No transactions to process. Banker is idle.

--- Final Queue Status ---
Queue is empty. All transactions processed.
```

---

## Design Notes

- **No diamond problem** — `VIP` and `LoginAccount` are independent branches, so `VIPUser` inherits cleanly from both `User` and `VIP` without ambiguity.
- **Template include pattern** — `Queue.cpp` is `#include`-d at the bottom of `Queue.h`, which is the standard pattern for separating template declaration and implementation into different files while keeping them in the same translation unit.
- **Convenience constructors** — `User(string)` and `Banker(string)` allow quick object creation without full login credentials, used in the simulation demo.
