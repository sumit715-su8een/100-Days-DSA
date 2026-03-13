// Day 41 - Q1: Queue Using Linked List
// Topic: Queue, Linked List
// Time: O(1) for enqueue/dequeue, Space: O(n)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
    int currSize;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}

Queue* createQueue() {
    Queue* q = new Queue();
    q->front = q->rear = nullptr;
    q->currSize = 0;
    return q;
}

bool isEmpty(Queue* q) { return q->front == nullptr; }

void enqueue(Queue* q, int data) {
    Node* node = newNode(data);
    if (isEmpty(q)) { q->front = q->rear = node; }
    else { q->rear->next = node; q->rear = node; }
    q->currSize++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == nullptr) q->rear = nullptr;
    delete temp;
    q->currSize--;
    return val;
}

int main() {
    Queue* q = createQueue();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; enqueue(q, x); }
    while (!isEmpty(q)) cout << dequeue(q) << " ";
    cout << endl;
    return 0;
}
