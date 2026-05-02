// Day 90 - Q1: Painter Partition Problem
// Topic: Binary Search on Answer
// Time: O(n log sum), Space: O(1)

#include <iostream>
using namespace std;

bool canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1, cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + boards[i] > maxTime) { painters++; cur = boards[i]; if (painters > k) return false; }
        else cur += boards[i];
    }
    return true;
}

int main() {
    int n, k; cin >> n >> k;
    int boards[n]; int low = 0, high = 0;
    for (int i = 0; i < n; i++) { cin >> boards[i]; if (boards[i] > low) low = boards[i]; high += boards[i]; }
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPaint(boards, n, k, mid)) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
