// Day 39 - Q1: Min Heap Implementation
// Topic: Heap, Priority Queue
// Time: Insert O(log n), ExtractMin O(log n), Peek O(1), Space: O(n)

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

int heap[MAX];
int heapSize = 0;

void swp(int &a, int &b) { int t = a; a = b; b = t; }

void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) { swp(heap[parent], heap[index]); index = parent; }
        else break;
    }
}

void heapifyDown(int index) {
    while (true) {
        int smallest = index, left = 2*index+1, right = 2*index+2;
        if (left < heapSize && heap[left] < heap[smallest]) smallest = left;
        if (right < heapSize && heap[right] < heap[smallest]) smallest = right;
        if (smallest != index) { swp(heap[index], heap[smallest]); index = smallest; }
        else break;
    }
}

void insert(int x) { heap[heapSize] = x; heapifyUp(heapSize); heapSize++; }

void extractMin() {
    if (heapSize == 0) { cout << -1 << endl; return; }
    cout << heap[0] << endl;
    heap[0] = heap[heapSize - 1]; heapSize--; heapifyDown(0);
}

void peek() {
    if (heapSize == 0) { cout << -1 << endl; return; }
    cout << heap[0] << endl;
}

int main() {
    int n; cin >> n;
    char op[20]; int x;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (strcmp(op, "insert") == 0) { cin >> x; insert(x); }
        else if (strcmp(op, "extractMin") == 0) extractMin();
        else if (strcmp(op, "peek") == 0) peek();
    }
    return 0;
}
