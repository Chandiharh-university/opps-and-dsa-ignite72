#include <iostream>
#include <vector>
using namespace std;

class NQueens {
public:
    int totalNQueens(int n) {
        vector<int> queens(n, -1); // Track queen positions: queens[row] = col
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        return backtrack(0, n, queens, cols, diag1, diag2);
    }

private:
    int backtrack(int row, int n, vector<int>& queens, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            return 1; // Found a valid solution
        }

        int count = 0;
        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue; // Skip invalid positions
            }

            // Place the queen
            queens[row] = col;
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;

            // Recurse to the next row
            count += backtrack(row + 1, n, queens, cols, diag1, diag2);

            // Backtrack
            queens[row] = -1;
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }

        return count;
    }
};

int main() {
    int n = 8; // Size of the chessboard

    NQueens solver;
    int solutions = solver.totalNQueens(n);

    cout << "The number of distinct solutions for " << n << "-Queens is: " << solutions << endl;

    return 0;
}
