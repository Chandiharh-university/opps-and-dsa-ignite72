#include <iostream>
#include <algorithm> // For std::max
#include <queue>     // For level-order insertion
#include <functional> // For std::function
using namespace std;

// Definition of a Node in the Binary Tree/AVL Tree
struct Node {
    int data;          // Data stored in the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child
    int height;       // Height of the node (for AVL balancing)

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1; // Height is initially 1 (leaf node)
    }
};

// Class to represent a Binary Tree
class BinaryTree {
private:
    Node* root; // Root node of the tree

    // Helper function for in-order traversal
    void inOrder(Node* node) {
        if (node == nullptr)
            return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Function to insert a new node in the Binary Tree (level-order insertion)
    Node* insertBinary(Node* node, int value) {
        if (!node)
            return new Node(value);

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = new Node(value);
                break;
            } else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = new Node(value);
                break;
            } else {
                q.push(temp->right);
            }
        }
        return node;
    }

    // Helper function to get the height of a node
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    // Helper function to calculate balance factor
    int getBalanceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Right rotation for AVL balancing
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left rotation for AVL balancing
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        // Return new root
        return y;
    }

    // Helper function to insert a node in AVL tree
    Node* insertAVL(Node* node, int value) {
        if (!node)
            return new Node(value);

        // Perform normal BST insertion
        if (value < node->data)
            node->left = insertAVL(node->left, value);
        else if (value > node->data)
            node->right = insertAVL(node->right, value);
        else
            return node; // Duplicate values not allowed

        // Update height of the current node
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        // Check balance factor and perform rotations if unbalanced
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node; // Return the (unchanged) node pointer
    }

public:
    // Constructor to initialize the Binary Tree
    BinaryTree() {
        root = nullptr;
    }

    // Function to insert a new node into the Binary Tree
    void insertBinaryTree(int value) {
        root = insertBinary(root, value);
    }

    // Function to convert Binary Tree to AVL Tree
    void convertToAVL() {
        Node* newRoot = nullptr;
        queue<int> values;

        // Helper to collect all values from the binary tree
        auto collectValues = [&](Node* node, auto& collect) -> void {
            if (!node) return;
            collect(node->left, collect);
            values.push(node->data);
            collect(node->right, collect);
        };

        collectValues(root, collectValues);

        // Insert collected values into a new AVL tree
        while (!values.empty()) {
            newRoot = insertAVL(newRoot, values.front());
            values.pop();
        }

        root = newRoot;
    }

    // Function to perform in-order traversal
    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    // Function to print Binary Tree (pre-order traversal for simplicity)
    void printBinaryTree() {
        cout << "Binary Tree (Pre-order Traversal): ";
        inOrderTraversal();
    }

    // Function to print AVL Tree (in-order for sorted view)
    void printAVLTree() {
        cout << "AVL Tree (In-order Traversal): ";
        inOrderTraversal();
    }
};

// Main function to demonstrate the Binary Tree and AVL Tree
int main() {
    BinaryTree tree;

    // Inserting nodes into the Binary Tree
    tree.insertBinaryTree(10);
    tree.insertBinaryTree(20);
    tree.insertBinaryTree(30);
    tree.insertBinaryTree(40);
    tree.insertBinaryTree(50);
    tree.insertBinaryTree(25);

    // Print Binary Tree
    tree.printBinaryTree();

    // Convert to AVL Tree
    tree.convertToAVL();

    // Print AVL Tree
    tree.printAVLTree();

    return 0;
}
