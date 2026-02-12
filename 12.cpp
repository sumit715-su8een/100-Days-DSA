// Day 12 - Q1: Check Symmetric Matrix
// Topic: Matrix Diagonal
// Time: O(n^2), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int m, n, mat[100][100];
    cin >> m >> n;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> mat[i][j];
    bool sym = (m == n);
    if (sym) for (int i = 0; i < m && sym; i++)
        for (int j = 0; j < n; j++) if (mat[i][j] != mat[j][i]) { sym = false; break; }
    cout << (sym ? "Symmetric Matrix" : "Not a Symmetric Matrix") << endl;
    return 0;
}
