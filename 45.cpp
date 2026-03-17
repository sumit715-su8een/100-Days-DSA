// Day 45 - Q1: Height of a Binary Tree
// Topic: Binary Tree, Recursion
// Time: O(n), Space: O(h)

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
        Node* cur = queue[front++];
        if (i < n) { cur->left = createNode(arr[i++]); queue[rear++] = cur->left; }
        if (i < n) { cur->right = createNode(arr[i++]); queue[rear++] = cur->right; }
    }
    return root;
}

int height(Node* root) {
    if (root == nullptr) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return 1 + (leftH > rightH ? leftH : rightH);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* root = buildTree(arr, n);
    cout << "Height: " << height(root) << endl;
    return 0;
}
