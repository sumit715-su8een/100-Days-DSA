// Day 32 - Q1: Push and Pop in Stack
// Topic: Stack Operations
// Time: O(n+m), Space: O(n)

#include <iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) stack[++top] = value;
}

int pop() {
    if (top >= 0) return stack[top--];
    return -1;
}

int main() {
    int n, m, value;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> value; push(value); }
    cin >> m;
    for (int i = 0; i < m; i++) pop();
    for (int i = top; i >= 0; i--) {
        cout << stack[i];
        if (i > 0) cout << " ";
    }
    cout << endl;
    return 0;
}
