#ifdef QUEUE_H 
using namespace std;

template <typename T>
Queue<T>::Queue(int size) {
    capacity = size;
    arr = new T[capacity];
    front_idx = 0;
    back_idx = -1;
    count = 0;
}

template <typename T>
Queue<T>::~Queue() {
    delete[] arr;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
bool Queue<T>::isFull() const {
    return count == capacity;
}

template <typename T>
int Queue<T>::size() const {
    return count;
}

template <typename T>
void Queue<T>::enqueue(T value) {
    if (isFull()) {
        
        cout << "Error: Queue is full, cannot Enqueue!\n";
        return;
    }
    back_idx = (back_idx + 1) % capacity;
    arr[back_idx] = value;
    count++;
}


template <typename T>
void Queue<T>::dequeue() {
    if (isEmpty()) {
        
        cout << "Error: Queue is empty, cannot Dequeue!\n";
        return;
    }
    front_idx = (front_idx + 1) % capacity;
    count--;
}


template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        
        cout << "Error: Queue is empty, cannot Front!\n";
        return T(); 
    }
    return arr[front_idx];
}

template <typename T>
T Queue<T>::back() const {
    if (isEmpty()) {
        
        cout << "Error: Queue is empty, cannot Back!\n";
        return T(); 
    }
    return arr[back_idx];
}

#endif 
