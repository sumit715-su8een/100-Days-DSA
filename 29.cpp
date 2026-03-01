// Day 29 - Q1: Rotate Linked List Right by K Places
// Topic: Linked List Rotation
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    int n, v, k;
    Node *head = nullptr, *tail = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        Node* nd = new Node(); nd->data = v; nd->next = nullptr;
        if (!head) head = tail = nd; else { tail->next = nd; tail = nd; }
    }
    cin >> k;
    k %= n;
    if (k == 0) { Node* c = head; while (c) { cout << c->data; if (c->next) cout << " "; c = c->next; } cout << endl; return 0; }
    int steps = n - k - 1;
    Node* newTail = head;
    for (int i = 0; i < steps; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    head = newHead;
    Node* cur = head;
    while (cur) { cout << cur->data; if (cur->next) cout << " "; cur = cur->next; }
    cout << endl;
    return 0;
}
