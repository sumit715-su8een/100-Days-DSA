// Day 30 - Q1: Polynomial Using Linked List
// Topic: Polynomial LL Representation
// Time: O(n), Space: O(n)

#include <iostream>
#include <cmath>
using namespace std;

struct Term { int coeff, exp; Term* next; };

int main() {
    int n; cin >> n;
    Term *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        int c, e; cin >> c >> e;
        Term* t = new Term(); t->coeff = c; t->exp = e; t->next = nullptr;
        if (!head) head = tail = t; else { tail->next = t; tail = t; }
    }
    Term* cur = head; bool first = true;
    while (cur) {
        if (!first && cur->coeff > 0) cout << " + ";
        else if (cur->coeff < 0) cout << " - ";
        int ac = abs(cur->coeff);
        if (cur->exp == 0) cout << ac;
        else if (cur->exp == 1) cout << ac << "x";
        else cout << ac << "x^" << cur->exp;
        first = false; cur = cur->next;
    }
    cout << endl;
    return 0;
}
