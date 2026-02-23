// Day 23 - Q1: Merge Two Sorted Linked Lists
// Topic: Linked List
// Time: O(n+m), Space: O(1)

#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* newNode(int d) { Node* n = new Node(); n->data = d; n->next = nullptr; return n; }

Node* merge(Node* l1, Node* l2) {
    Node dummy; Node* tail = &dummy; dummy.next = nullptr;
    while (l1 && l2) {
        if (l1->data <= l2->data) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

int main() {
    int n, m, v;
    Node *l1 = nullptr, *t1 = nullptr, *l2 = nullptr, *t2 = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> v; Node* nd = newNode(v); if (!l1) l1 = t1 = nd; else { t1->next = nd; t1 = nd; } }
    cin >> m;
    for (int i = 0; i < m; i++) { cin >> v; Node* nd = newNode(v); if (!l2) l2 = t2 = nd; else { t2->next = nd; t2 = nd; } }
    Node* res = merge(l1, l2);
    while (res) { cout << res->data; if (res->next) cout << " "; res = res->next; }
    cout << endl;
    return 0;
}
