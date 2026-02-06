// Day 6 - Q1: Remove Duplicates from Sorted Array
// Topic: Array Cleanup, Two Pointers
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int slow = 0;
    for (int fast = 1; fast < n; fast++) {
        if (arr[fast] != arr[slow]) arr[++slow] = arr[fast];
    }
    for (int i = 0; i <= slow; i++) { cout << arr[i]; if (i < slow) cout << " "; }
    cout << endl;
    return 0;
}
