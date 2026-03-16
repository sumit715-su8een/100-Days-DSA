// Day 44 - Q1: Binary Tree Traversals (Inorder, Preorder, Postorder)
// Topic: Tree Traversal
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
    if (n == 0 || arr[0] == -1) return nullptr;
    Node* root = createNode(arr[0]);
    Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        Node* current = queue[front++];
        if (i < n && arr[i] != -1) { current->left = createNode(arr[i]); queue[rear++] = current->left; }
        i++;
        if (i < n && arr[i] != -1) { current->right = createNode(arr[i]); queue[rear++] = current->right; }
        i++;
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left); cout << root->data << " "; inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " "; preorder(root->left); preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left); postorder(root->right); cout << root->data << " ";
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* root = buildTree(arr, n);
    cout << "Inorder: "; inorder(root); cout << endl;
    cout << "Preorder: "; preorder(root); cout << endl;
    cout << "Postorder: "; postorder(root); cout << endl;
    return 0;
}
