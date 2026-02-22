// Day 22 - Q1: Count Nodes in Linked List
// Topic: Linked List
// Time: O(n), Space: O(1)

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
    int count = 0;
    Node* cur = head;
    while (cur) { count++; cur = cur->next; }
    cout << count << endl;
    return 0;
}
