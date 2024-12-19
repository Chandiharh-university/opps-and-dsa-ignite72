
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=2;
    for(int i=0;i<=10;i++){
        cout<< n <<" * "<< i << " = "<< n * 1 <<endl;
    }
    string s = "(1) PALINDROME";

    // Using reverse() function to reverse s
    reverse(s.begin(), s.end());

    cout << s;
    return 0;
}
