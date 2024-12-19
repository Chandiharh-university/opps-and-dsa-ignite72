#include <iostream>
#include <string>
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    int start = 0;                // Starting index
    int end = str.length() - 1;   // Ending index

    while (start < end) {
        if (str[start] != str[end]) {
            return false;         // Not a palindrome if mismatch
        }
        start++;
        end--;
    }
    return true;                  // It's a palindrome
}

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << "The string \"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "The string \"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
