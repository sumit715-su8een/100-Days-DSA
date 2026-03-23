// Day 51 - Q1: Lowest Common Ancestor in BST
// Topic: BST, LCA
// Time: O(h), Space: O(1)

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

Node* LCA(Node* root, int n1, int n2) {
    while (root != nullptr) {
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}

int main() {
    int n; cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        root = insert(root, x);
    }
    int n1, n2; cin >> n1 >> n2;
    Node* lca = LCA(root, n1, n2);
    if (lca) cout << "LCA: " << lca->data << endl;
    else cout << "LCA not found" << endl;
    return 0;
}
