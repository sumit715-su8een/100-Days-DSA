// Day 60 - Q1: Validate Min-Heap
// Topic: Heap, Tree
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

bool isMinHeap(Node* root) {
    if (!root) return true;
    if (root->left && root->data > root->left->data) return false;
    if (root->right && root->data > root->right->data) return false;
    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* root = buildTree(arr, n);
    cout << (isMinHeap(root) ? "Valid Min-Heap" : "Not a Min-Heap") << endl;
    return 0;
}
