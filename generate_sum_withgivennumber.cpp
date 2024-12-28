#include <iostream>
#include <vector>
using namespace std;

void generateNumbersWithSum(int n, int sum, vector<int>& current, vector<vector<int>>& results) {
    // Base case: if n is 0 and sum is 0, we have a valid combination
    if (n == 0 && sum == 0) {
        results.push_back(current);
        return;
    }

    // Base case: if n is 0 or sum becomes negative, stop recursion
    if (n == 0 || sum < 0) {
        return;
    }

    // Try all digits from 0 to 9
    for (int digit = 0; digit <= 9; ++digit) {
        current.push_back(digit);
        generateNumbersWithSum(n - 1, sum - digit, current, results);
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>> generateNumbers(int n, int sum) {
    vector<vector<int>> results;
    vector<int> current;
    generateNumbersWithSum(n, sum, current, results);
    return results;
}

int main() {
    int n = 3; // Number of digits
    int sum = 6; // Desired sum

    vector<vector<int>> numbers = generateNumbers(n, sum);

    // Print the results
    for (const auto& combination : numbers) {
        for (int num : combination) {
            cout << num;
        }
        cout << endl;
    }

    return 0;
}
