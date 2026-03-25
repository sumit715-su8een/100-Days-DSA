// Day 53 - Q1: Print Binary Tree Vertical Order
// Topic: Tree Traversal, BFS
// Time: O(n*k), Space: O(n)

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

struct Pair { Node* node; int hd; };

void verticalOrder(Node* root) {
    if (!root) return;
    Pair q[1000];
    int front = 0, rear = 0;
    int hdArr[1000], valArr[1000], count = 0;
    q[rear++] = {root, 0};
    while (front < rear) {
        Pair cur = q[front++];
        hdArr[count] = cur.hd;
        valArr[count] = cur.node->data;
        count++;
        if (cur.node->left) q[rear++] = {cur.node->left, cur.hd - 1};
        if (cur.node->right) q[rear++] = {cur.node->right, cur.hd + 1};
    }
    for (int i = -100; i <= 100; i++) {
        bool printed = false;
        for (int j = 0; j < count; j++) {
            if (hdArr[j] == i) { cout << valArr[j] << " "; printed = true; }
        }
        if (printed) cout << endl;
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* root = buildTree(arr, n);
    verticalOrder(root);
    return 0;
}
