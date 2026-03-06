// Day 34 - Q1: Evaluate Postfix Expression
// Topic: Stack
// Time: O(n), Space: O(n)

#include <iostream>
using namespace std;

int applyOperator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluatePostfix(char* exp) {
    int stack[1000];
    int top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch >= '0' && ch <= '9') {
            stack[++top] = ch - '0';
        } else {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = applyOperator(a, b, ch);
        }
    }
    return stack[top];
}

int main() {
    char exp[100];
    cin >> exp;
    cout << evaluatePostfix(exp) << endl;
    return 0;
}
