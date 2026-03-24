// Day 52 - Q1: LCA in Binary Tree
// Topic: Binary Tree, LCA
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

Node* LCA(Node* root, int n1, int n2) {
    if (!root) return nullptr;
    if (root->data == n1 || root->data == n2) return root;
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* root = buildTree(arr, n);
    int n1, n2; cin >> n1 >> n2;
    Node* lca = LCA(root, n1, n2);
    if (lca) cout << "LCA: " << lca->data << endl;
    else cout << "LCA not found" << endl;
    return 0;
}
