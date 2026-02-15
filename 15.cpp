// Day 15 - Q1: Matrix Diagonal Sum
// Topic: Matrix
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int m, n, mat[100][100];
    cin >> m >> n;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> mat[i][j];
    int sum = 0, minDim = min(m, n);
    for (int i = 0; i < minDim; i++) sum += mat[i][i];
    cout << sum << endl;
    return 0;
}
