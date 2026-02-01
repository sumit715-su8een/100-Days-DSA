// Day 1 - Q1: Insert an Element in an Array
// Topic: Array Basics
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, pos, x, arr[101];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> pos >> x;
    for (int i = n; i >= pos; i--) arr[i] = arr[i-1];
    arr[pos-1] = x;
    for (int i = 0; i <= n; i++) { cout << arr[i]; if (i < n) cout << " "; }
    cout << endl;
    return 0;
}
