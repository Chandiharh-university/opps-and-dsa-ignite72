#include <iostream>
using namespace std;

// Class representing a Stack
class Stack {
private:
    int* arr;          // Array to store stack elements
    int capacity;      // Maximum capacity of the stack
    int topIndex;      // Index of the top element

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Function to push an element onto the stack
    void push(int element) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << element << endl;
            return;
        }
        arr[++topIndex] = element;
        cout << "Pushed: " << element << endl;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << arr[topIndex--] << endl;
    }

    // Function to get the top element of the stack
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // Function to get the current size of the stack
    int size() {
        return topIndex + 1;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    Stack s(capacity);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.pop();

    cout << "Stack size: " << s.size() << endl;

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);  // Should display "Stack is full!"

    while (!s.isEmpty()) {
        cout << "Top element: " << s.top() << endl;
        s.pop();
    }

    return 0;
}
