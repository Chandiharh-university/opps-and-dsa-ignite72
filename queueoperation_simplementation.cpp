#include <iostream>
using namespace std;

// Class representing a Queue
class Queue {
private:
    int* arr;          // Array to store queue elements
    int capacity;      // Maximum capacity of the queue
    int frontIndex;    // Index of the front element
    int rearIndex;     // Index of the rear element
    int currentSize;   // Current size of the queue

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Function to add an element to the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << element << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = element;
        currentSize++;
        cout << "Enqueued: " << element << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[frontIndex] << endl;
        frontIndex = (frontIndex + 1) % capacity;
        currentSize--;
    }

    // Function to get the front element of the queue
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return currentSize == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return currentSize == capacity;
    }

    // Function to get the current size of the queue
    int size() {
        return currentSize;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Queue size: " << q.size() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);  // Should display "Queue is full!"

    while (!q.isEmpty()) {
        cout << "Front element: " << q.front() << endl;
        q.dequeue();
    }

    return 0;
}
