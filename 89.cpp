// Day 89 - Q1: Allocate Minimum Pages
// Topic: Binary Search on Load
// Time: O(n log sum), Space: O(1)

#include <iostream>
using namespace std;

bool isFeasible(int pages[], int n, int m, int maxPages) {
    int students = 1, cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + pages[i] > maxPages) { students++; cur = pages[i]; if (students > m) return false; }
        else cur += pages[i];
    }
    return true;
}

int main() {
    int n, m; cin >> n >> m;
    int pages[n]; int low = 0, high = 0;
    for (int i = 0; i < n; i++) { cin >> pages[i]; if (pages[i] > low) low = pages[i]; high += pages[i]; }
    if (n < m) { cout << -1 << endl; return 0; }
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isFeasible(pages, n, m, mid)) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
