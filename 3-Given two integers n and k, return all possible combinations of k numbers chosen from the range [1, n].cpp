#include <iostream>
#include <vector>
using namespace std;

void combineHelper(int start, int n, int k, vector<int>& current, vector<vector<int>>& results) {
    // Base case: if the combination is of the required size
    if (current.size() == k) {
        results.push_back(current);
        return;
    }

    // Iterate through the range from 'start' to 'n'
    for (int i = start; i <= n; ++i) {
        current.push_back(i); // Include the current number
        combineHelper(i + 1, n, k, current, results); // Recurse to the next number
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> results;
    vector<int> current;
    combineHelper(1, n, k, current, results);
    return results;
}

int main() {
    int n = 4; // Upper range of numbers
    int k = 2; // Number of elements in each combination

    vector<vector<int>> combinations = combine(n, k);

    // Print the results
    for (const auto& combination : combinations) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
