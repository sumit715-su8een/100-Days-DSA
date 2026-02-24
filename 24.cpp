// Day 24 - Q1: Delete First Occurrence of a Key
// Topic: Linked List Deletion
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* newNode(int d) { Node* n = new Node(); n->data = d; n->next = nullptr; return n; }

Node* deleteKey(Node* head, int key) {
    if (head && head->data == key) { Node* t = head; head = head->next; delete t; return head; }
    Node *prev = nullptr, *cur = head;
    while (cur && cur->data != key) { prev = cur; cur = cur->next; }
    if (cur) { prev->next = cur->next; delete cur; }
    return head;
}

int main() {
    int n, v, key;
    Node *head = nullptr, *tail = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> v; Node* nd = newNode(v); if (!head) head = tail = nd; else { tail->next = nd; tail = nd; } }
    cin >> key;
    head = deleteKey(head, key);
    Node* cur = head;
    while (cur) { cout << cur->data; if (cur->next) cout << " "; cur = cur->next; }
    cout << endl;
    return 0;
}
