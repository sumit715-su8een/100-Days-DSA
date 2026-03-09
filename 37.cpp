// Day 37 - Q1: Priority Queue Using Array
// Topic: Priority Queue
// Time: Enqueue O(n), Dequeue O(n), Space: O(n)

#include <iostream>
using namespace std;

#define MAX 100

struct PQNode { int value, priority; };
PQNode pq[MAX];
int sz = 0;

void enqueue(int value, int priority) {
    int i;
    for (i = sz - 1; i >= 0 && pq[i].priority < priority; i--)
        pq[i + 1] = pq[i];
    pq[i + 1] = {value, priority};
    sz++;
}

void dequeue() {
    if (sz == 0) { cout << "Priority Queue is empty" << endl; return; }
    cout << "Dequeued: " << pq[0].value << endl;
    for (int i = 0; i < sz - 1; i++) pq[i] = pq[i + 1];
    sz--;
}

void display() {
    for (int i = 0; i < sz; i++)
        cout << "Value: " << pq[i].value << ", Priority: " << pq[i].priority << endl;
}

int main() {
    enqueue(10, 2); enqueue(30, 4); enqueue(20, 3); enqueue(40, 1);
    display();
    dequeue(); dequeue();
    display();
    return 0;
}
