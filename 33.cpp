// Day 33 - Q1: Infix to Postfix Conversion
// Topic: Expression Conversion, Stack
// Time: O(n), Space: O(n)

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 100

char stk[MAX];
int top = -1;

void push(char c) { stk[++top] = c; }
char pop() { return stk[top--]; }
char peek() { return stk[top]; }
bool isEmpty() { return top == -1; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isEmpty() && peek() != '(') postfix[k++] = pop();
            if (!isEmpty()) pop();
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) postfix[k++] = pop();
            push(c);
        }
    }
    while (!isEmpty()) postfix[k++] = pop();
    postfix[k] = '\0';
    cout << postfix << endl;
}

int main() {
    char infix[MAX];
    cin >> infix;
    infixToPostfix(infix);
    return 0;
}
