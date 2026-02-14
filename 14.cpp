// Day 14 - Q1: Check Identity Matrix
// Topic: Matrix Properties
// Time: O(n^2), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, mat[100][100];
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> mat[i][j];
    bool identity = true;
    for (int i = 0; i < n && identity; i++)
        for (int j = 0; j < n; j++) {
            if (i == j && mat[i][j] != 1) { identity = false; break; }
            if (i != j && mat[i][j] != 0) { identity = false; break; }
        }
    cout << (identity ? "Identity Matrix" : "Not an Identity Matrix") << endl;
    return 0;
}
