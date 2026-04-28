// Day 87 - Q1: Binary Search Iterative + Koko Eating Bananas
// Topic: Binary Search on Answer
// Time: O(n log max), Space: O(1)

#include <iostream>
#include <algorithm>
using namespace std;

long long hoursNeeded(int* piles, int n, int speed) {
    long long h = 0;
    for (int i = 0; i < n; i++) h += (piles[i] + speed - 1) / speed;
    return h;
}

int main() {
    int n, h; cin >> n;
    int piles[n];
    int maxPile = 0;
    for (int i = 0; i < n; i++) { cin >> piles[i]; maxPile = max(maxPile, piles[i]); }
    cin >> h;
    int low = 1, high = maxPile, ans = maxPile;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (hoursNeeded(piles, n, mid) <= h) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
