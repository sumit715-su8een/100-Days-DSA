// Day 11 - Q1: Matrix Addition
// Topic: Matrix
// Time: O(m*n), Space: O(m*n)

#include <iostream>
using namespace std;

int main() {
    int m, n, mat1[100][100], mat2[100][100];
    cin >> m >> n;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> mat1[i][j];
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> mat2[i][j];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat1[i][j] + mat2[i][j];
            if (j < n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
