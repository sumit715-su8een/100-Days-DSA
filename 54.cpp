// Day 54 - Q1: Zigzag Traversal of Binary Tree
// Topic: Tree Traversal, BFS
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
        Node* cur = queue[front++];
        if (i < n) { cur->left = createNode(arr[i++]); queue[rear++] = cur->left; }
        if (i < n) { cur->right = createNode(arr[i++]); queue[rear++] = cur->right; }
    }
    return root;
}

void zigzagTraversal(Node* root) {
    if (!root) return;
    Node* q[1000];
    int front = 0, rear = 0;
    q[rear++] = root;
    bool leftToRight = true;
    while (front < rear) {
        int size = rear - front;
        int level[1000];
        for (int i = 0; i < size; i++) {
            Node* temp = q[front++];
            int index = leftToRight ? i : size - i - 1;
            level[index] = temp->data;
            if (temp->left) q[rear++] = temp->left;
            if (temp->right) q[rear++] = temp->right;
        }
        for (int i = 0; i < size; i++) cout << level[i] << " ";
        cout << endl;
        leftToRight = !leftToRight;
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* root = buildTree(arr, n);
    zigzagTraversal(root);
    return 0;
}
