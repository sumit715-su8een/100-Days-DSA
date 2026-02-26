// Day 26 - Q1: Doubly Linked List Insertion and Traversal
// Topic: Doubly Linked List
// Time: O(n), Space: O(n)

#include <iostream>
using namespace std;

struct Node { int data; Node *next, *prev; };

int main() {
    int n, v; cin >> n;
    Node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> v;
        Node* nd = new Node(); nd->data = v; nd->next = nullptr; nd->prev = nullptr;
        if (!head) head = tail = nd;
        else { tail->next = nd; nd->prev = tail; tail = nd; }
    }
    Node* cur = head;
    while (cur) { cout << cur->data; if (cur->next) cout << " "; cur = cur->next; }
    cout << endl;
    return 0;
}
