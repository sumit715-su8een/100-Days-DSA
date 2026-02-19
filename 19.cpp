// Day 19 - Q1: Pair Sum Closest to Zero
// Topic: Two Pointers, Sorting
// Time: O(n log n), Space: O(1)

#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int l = 0, r = n-1, minSum = INT_MAX, resL = 0, resR = 0;
    while (l < r) {
        int s = arr[l] + arr[r];
        if (abs(s) < abs(minSum)) { minSum = s; resL = arr[l]; resR = arr[r]; }
        if (s < 0) l++; else r--;
    }
    cout << resL << " " << resR << endl;
    return 0;
}
