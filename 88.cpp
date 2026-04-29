// Day 88 - Q1: Aggressive Cows Problem
// Topic: Binary Search on Distance
// Time: O(n log n + n log D), Space: O(1)

#include <iostream>
#include <algorithm>
using namespace std;

bool canPlace(int stalls[], int n, int k, int minDist) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= minDist) { count++; last = stalls[i]; }
        if (count >= k) return true;
    }
    return false;
}

int main() {
    int n, k; cin >> n >> k;
    int stalls[n];
    for (int i = 0; i < n; i++) cin >> stalls[i];
    sort(stalls, stalls + n);
    int low = 1, high = stalls[n-1] - stalls[0], ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(stalls, n, k, mid)) { ans = mid; low = mid + 1; }
        else high = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
