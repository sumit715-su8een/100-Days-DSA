// Day 27 - Q1: Find Intersection Point of Two Linked Lists
// Topic: Linked List
// Time: O(m+n), Space: O(1)

#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int getLen(Node* h) { int l = 0; while (h) { l++; h = h->next; } return l; }

int main() {
    int n, m, v;
    Node *l1 = nullptr, *t1 = nullptr, *l2 = nullptr, *t2 = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> v; Node* nd = new Node(); nd->data = v; nd->next = nullptr; if (!l1) l1 = t1 = nd; else { t1->next = nd; t1 = nd; } }
    cin >> m;
    for (int i = 0; i < m; i++) { cin >> v; Node* nd = new Node(); nd->data = v; nd->next = nullptr; if (!l2) l2 = t2 = nd; else { t2->next = nd; t2 = nd; } }
    int len1 = getLen(l1), len2 = getLen(l2);
    Node *p1 = l1, *p2 = l2;
    while (len1 > len2) { p1 = p1->next; len1--; }
    while (len2 > len1) { p2 = p2->next; len2--; }
    while (p1 && p2 && p1->data != p2->data) { p1 = p1->next; p2 = p2->next; }
    if (p1) cout << p1->data << endl;
    else cout << "No Intersection" << endl;
    return 0;
}
