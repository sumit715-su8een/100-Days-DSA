// Day 38 - Q1: Deque Operations
// Topic: Deque (Double-Ended Queue)
// Time: O(1) for all operations, Space: O(n)

#include <iostream>
using namespace std;

#define MAX 100

int deq[MAX];
int front = -1, rear = -1;

bool isFull() { return ((front == 0 && rear == MAX - 1) || (front == rear + 1)); }
bool isEmpty() { return (front == -1); }

void push_front(int x) {
    if (isFull()) { cout << "Deque Overflow" << endl; return; }
    if (isEmpty()) { front = rear = 0; }
    else if (front == 0) front = MAX - 1;
    else front--;
    deq[front] = x;
}

void push_back(int x) {
    if (isFull()) { cout << "Deque Overflow" << endl; return; }
    if (isEmpty()) { front = rear = 0; }
    else if (rear == MAX - 1) rear = 0;
    else rear++;
    deq[rear] = x;
}

void pop_front() {
    if (isEmpty()) { cout << "Deque Underflow" << endl; return; }
    if (front == rear) { front = rear = -1; }
    else if (front == MAX - 1) front = 0;
    else front++;
}

void pop_back() {
    if (isEmpty()) { cout << "Deque Underflow" << endl; return; }
    if (front == rear) { front = rear = -1; }
    else if (rear == 0) rear = MAX - 1;
    else rear--;
}

void display() {
    if (isEmpty()) { cout << "Deque is empty" << endl; return; }
    int i = front;
    while (true) {
        cout << deq[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    push_back(10); push_back(20); push_front(5); push_back(30);
    display();
    pop_front(); pop_back();
    display();
    cout << "Front: " << deq[front] << endl;
    cout << "Back: " << deq[rear] << endl;
    return 0;
}
