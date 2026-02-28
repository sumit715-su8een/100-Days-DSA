// Day 28 - Q1: Circular Linked List Creation and Traversal
// Topic: Circular Linked List
// Time: O(n), Space: O(n)

#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    int n, v; cin >> n;
    Node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> v;
        Node* nd = new Node(); nd->data = v; nd->next = nullptr;
        if (!head) head = tail = nd;
        else { tail->next = nd; tail = nd; }
    }
    if (tail) tail->next = head;
    Node* cur = head;
    for (int i = 0; i < n; i++) { cout << cur->data; if (i < n-1) cout << " "; cur = cur->next; }
    cout << endl;
    return 0;
}
