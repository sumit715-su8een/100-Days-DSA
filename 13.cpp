// Day 13 - Q1: Spiral Matrix Traversal
// Topic: Matrix Spiral
// Time: O(m*n), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int r, c, mat[100][100];
    cin >> r >> c;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> mat[i][j];
    int top = 0, bottom = r-1, left = 0, right = c-1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) cout << mat[top][j] << " ";
        top++;
        for (int i = top; i <= bottom; i++) cout << mat[i][right] << " ";
        right--;
        if (top <= bottom) { for (int j = right; j >= left; j--) cout << mat[bottom][j] << " "; bottom--; }
        if (left <= right) { for (int i = bottom; i >= top; i--) cout << mat[i][left] << " "; left++; }
    }
    cout << endl;
    return 0;
}
