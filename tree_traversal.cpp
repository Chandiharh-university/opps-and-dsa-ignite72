#include <iostream>
using namespace std;

// Definition of a Node in the binary tree
struct Node {
    int data;          // Data stored in the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child

    // Constructor to create a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Preorder Traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return; // Base case
    cout << root->data << " ";   // Visit the root
    preorder(root->left);         // Traverse left subtree
    preorder(root->right);        // Traverse right subtree
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == nullptr) return; // Base case
    inorder(root->left);         // Traverse left subtree
    cout << root->data << " ";   // Visit the root
    inorder(root->right);        // Traverse right subtree
}

// Postorder Traversal: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return; // Base case
    postorder(root->left);       // Traverse left subtree
    postorder(root->right);      // Traverse right subtree
    cout << root->data << " ";   // Visit the root
}

int main() {
    // Creating a simple binary tree
    Node* root = new Node(1);          // Root node
    root->left = new Node(2);          // Left child of root
    root->right = new Node(3);         // Right child of root
    root->left->left = new Node(4);    // Left child of left child
    root->left->right = new Node(5);   // Right child of left child
    root->right->left = new Node(6);   // Left child of right child
    root->right->right = new Node(7);  // Right child of right child

    cout << "Preorder Traversal: ";
    preorder(root); // Call preorder traversal
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root); // Call inorder traversal
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root); // Call postorder traversal
    cout << endl;

    // Clean up memory (optional, but good practice)
    // In a real application, you would want to delete all nodes to avoid memory leaks.

    return 0; // Indicate successful completion
}
