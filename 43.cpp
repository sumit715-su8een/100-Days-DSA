// Day 43 - Q1: Binary Tree Construction (Level Order)
// Topic: Binary Tree, BFS
// Time: O(n), Space: O(n)

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

Node* buildTree(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* root = createNode(arr[0]);
    Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        Node* current = queue[front++];
        if (i < n) { current->left = createNode(arr[i++]); queue[rear++] = current->left; }
        if (i < n) { current->right = createNode(arr[i++]); queue[rear++] = current->right; }
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* root = buildTree(arr, n);
    inorder(root);
    cout << endl;
    return 0;
}
