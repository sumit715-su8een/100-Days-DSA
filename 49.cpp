// Day 49 - Q1: BST Insert
// Topic: Binary Search Tree
// Time: O(h) average, Space: O(h)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int data) {
    Node* node = new Node();
    node->data = data; node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n; cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = insert(root, x);
    }
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    return 0;
}
