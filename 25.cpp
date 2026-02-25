// Day 25 - Q1: Count Occurrences of Element in Linked List
// Topic: Cycle Detection, Linked List
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

int main() {
    int n, v, key;
    Node *head = nullptr, *tail = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        Node* nd = new Node(); nd->data = v; nd->next = nullptr;
        if (!head) head = tail = nd; else { tail->next = nd; tail = nd; }
    }
    cin >> key;
    int count = 0;
    Node* cur = head;
    while (cur) { if (cur->data == key) count++; cur = cur->next; }
    cout << count << endl;
    return 0;
}
