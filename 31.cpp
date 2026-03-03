// Day 31 - Q1: Stack Implementation using Array
// Topic: Stack
// Time: O(1) per op, Space: O(n)

#include <iostream>
using namespace std;

#define MAX 100
int stk[MAX], top = -1;

void push(int v) { if (top < MAX-1) stk[++top] = v; }
int pop() { if (top >= 0) return stk[top--]; return -1; }
void display() { for (int i = top; i >= 0; i--) { cout << stk[i]; if (i > 0) cout << " "; } cout << endl; }

int main() {
    int n, op, v; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) { cin >> v; push(v); }
        else if (op == 2) { int p = pop(); if (p != -1) cout << p << endl; }
        else if (op == 3) display();
    }
    return 0;
}
