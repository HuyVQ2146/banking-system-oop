#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <typename T>
class Queue {
private:
    T* arr;         
    int capacity;  
    int front_idx;
    int back_idx;   
    int count;    

public:
    Queue(int size = 100);
    ~Queue();

    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void enqueue(T value);
    void dequeue();
    T front() const;
    T back() const;
};


#include "Queue.cpp" 

#endif 
