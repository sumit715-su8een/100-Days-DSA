// Day 35 - Q1: Queue Using Array
// Topic: Queue
// Time: O(1) for enqueue/dequeue, Space: O(n)

#include <iostream>
using namespace std;

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() { return (front == -1 || front > rear); }
bool isFull() { return (rear == MAX - 1); }

void enqueue(int value) {
    if (isFull()) { cout << "Queue Overflow" << endl; return; }
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (isEmpty()) { cout << "Queue Underflow" << endl; return -1; }
    return queue[front++];
}

void display() {
    if (isEmpty()) { cout << "Queue is Empty" << endl; return; }
    for (int i = front; i <= rear; i++) cout << queue[i] << " ";
    cout << endl;
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
