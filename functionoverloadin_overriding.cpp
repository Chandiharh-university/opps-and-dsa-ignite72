#include <iostream>
using namespace std;

// Base class
class Base {
public:
    // Function to be overridden
    virtual void show() {
        cout << "Base class show function called." << endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Overriding the show function
    void show() override {
        cout << "Derived class show function called." << endl;
    }
};

// Function overloading example
void display(int a) {
    cout << "Display function with integer: " << a << endl;
}

void display(double b) {
    cout << "Display function with double: " << b << endl;
}

void display(int a, double b) {
    cout << "Display function with integer and double: " << a << ", " << b << endl;
}

int main() {
    // Function Overloading
    cout << "Function Overloading:" << endl;
    display(5);            // Calls display(int)
    display(3.14);        // Calls display(double)
    display(10, 20.5);    // Calls display(int, double)

    // Function Overriding
    cout << "\nFunction Overriding:" << endl;
    Base* basePtr;       
    Derived derivedObj;   
    basePtr = &derivedObj; 
    basePtr->show();     

    return 0;
}
