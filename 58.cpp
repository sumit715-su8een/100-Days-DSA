// Day 58 - Q1: Build Tree from Inorder & Preorder
// Topic: Tree Construction
// Time: O(n^2), Space: O(h)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int val) {
    Node* node = new Node();
    node->data = val; node->left = node->right = nullptr;
    return node;
}

int findIndex(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val) return i;
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return nullptr;
    int rootVal = preorder[*preIndex];
    (*preIndex)++;
    Node* root = createNode(rootVal);
    if (inStart == inEnd) return root;
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);
    return root;
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n; cin >> n;
    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    return 0;
}
