// Day 4 - Q1: Reverse an Array In-Place
// Topic: Array Reversal, Two Pointers
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int left = 0, right = n-1;
    while (left < right) { swap(arr[left++], arr[right--]); }
    for (int i = 0; i < n; i++) { cout << arr[i]; if (i < n-1) cout << " "; }
    cout << endl;
    return 0;
}
