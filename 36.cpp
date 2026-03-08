// Day 36 - Q1: Circular Queue Using Array
// Topic: Circular Queue
// Time: O(n) for display, Space: O(n)

#include <iostream>
using namespace std;

struct CircularQueue {
    int *arr, front, rear, size, count;
};

CircularQueue* createQueue(int n) {
    CircularQueue* q = new CircularQueue();
    q->size = n; q->arr = new int[n];
    q->front = 0; q->rear = -1; q->count = 0;
    return q;
}

void enqueue(CircularQueue* q, int value) {
    if (q->count == q->size) return;
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = value;
    q->count++;
}

void dequeue(CircularQueue* q) {
    if (q->count == 0) return;
    q->front = (q->front + 1) % q->size;
    q->count--;
}

void display(CircularQueue* q) {
    for (int i = 0; i < q->count; i++)
        cout << q->arr[(q->front + i) % q->size] << " ";
    cout << endl;
}

int main() {
    int n, m, x;
    cin >> n;
    CircularQueue* q = createQueue(n);
    for (int i = 0; i < n; i++) { cin >> x; enqueue(q, x); }
    cin >> m;
    for (int i = 0; i < m; i++) dequeue(q);
    display(q);
    return 0;
}
