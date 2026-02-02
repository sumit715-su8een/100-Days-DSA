// Day 2 - Q1: Delete an Element from an Array
// Topic: Array Operations
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, pos, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> pos;
    for (int i = pos-1; i < n-1; i++) arr[i] = arr[i+1];
    for (int i = 0; i < n-1; i++) { cout << arr[i]; if (i < n-2) cout << " "; }
    cout << endl;
    return 0;
}
