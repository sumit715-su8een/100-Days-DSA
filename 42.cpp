// Day 42 - Q1: Reverse a Queue Using Stack
// Topic: Queue, Stack, Reversal
// Time: O(n), Space: O(n)

#include <iostream>
using namespace std;

struct QNode { int data; QNode* next; };
struct SNode { int data; SNode* next; };

struct Queue { QNode* front; QNode* rear; };
struct Stack { SNode* top; };

Queue* createQueue() { Queue* q = new Queue(); q->front = q->rear = nullptr; return q; }
Stack* createStack() { Stack* s = new Stack(); s->top = nullptr; return s; }

void enqueue(Queue* q, int x) {
    QNode* node = new QNode(); node->data = x; node->next = nullptr;
    if (q->rear == nullptr) { q->front = q->rear = node; return; }
    q->rear->next = node; q->rear = node;
}

int dequeue(Queue* q) {
    if (q->front == nullptr) return -1;
    QNode* temp = q->front; int val = temp->data;
    q->front = q->front->next;
    if (q->front == nullptr) q->rear = nullptr;
    delete temp; return val;
}

void push(Stack* s, int x) {
    SNode* node = new SNode(); node->data = x; node->next = s->top; s->top = node;
}

int pop(Stack* s) {
    if (s->top == nullptr) return -1;
    SNode* temp = s->top; int val = temp->data; s->top = temp->next; delete temp; return val;
}

void reverseQueue(Queue* q) {
    Stack* s = createStack();
    while (q->front != nullptr) push(s, dequeue(q));
    while (s->top != nullptr) enqueue(q, pop(s));
}

int main() {
    Queue* q = createQueue();
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; enqueue(q, x); }
    reverseQueue(q);
    while (q->front != nullptr) cout << dequeue(q) << " ";
    cout << endl;
    return 0;
}
