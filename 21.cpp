// Day 21 - Q1: Create and Traverse Singly Linked List
// Topic: Linked List
// Time: O(n), Space: O(n)

#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

Node* createNode(int d) { Node* n = new Node(); n->data = d; n->next = nullptr; return n; }

int main() {
    int n, v; cin >> n;
    Node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> v;
        Node* nd = createNode(v);
        if (!head) head = tail = nd;
        else { tail->next = nd; tail = nd; }
    }
    Node* cur = head;
    while (cur) { cout << cur->data; if (cur->next) cout << " "; cur = cur->next; }
    cout << endl;
    return 0;
}
