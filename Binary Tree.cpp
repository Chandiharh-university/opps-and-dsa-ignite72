#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        vector<int> path;
        dfs(root, path, paths);
        return paths;
    }

private:
    void dfs(TreeNode* node, vector<int>& path, vector<string>& paths) {
        if (!node) return;

        // Add the current node's value to the path
        path.push_back(node->val);

        // If it's a leaf, construct the path and add it to paths
        if (!node->left && !node->right) {
            stringstream ss;
            for (size_t i = 0; i < path.size(); ++i) {
                ss << path[i];
                if (i < path.size() - 1) ss << "->";
            }
            paths.push_back(ss.str());
        } else {
            // Continue DFS on left and right children
            dfs(node->left, path, paths);
            dfs(node->right, path, paths);
        }

        // Backtrack
        path.pop_back();
    }
};

// Example usage:
// Construct the binary tree for the example input
// Input: root = [1,2,3,null,5]
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<string> result = solution.binaryTreePaths(root);

    for (const string& path : result) {
        cout << path << endl;
    }

    // Cleanup
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
