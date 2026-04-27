// Day 86 - Q1: Square Root using Binary Search
// Topic: Binary Search, Math
// Time: O(log n), Space: O(1)

#include <iostream>
using namespace std;

int mySqrt(int n) {
    if (n == 0) return 0;
    long long low = 1, high = n, ans = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid == n) return (int)mid;
        else if (mid * mid < n) { ans = mid; low = mid + 1; }
        else high = mid - 1;
    }
    return (int)ans;
}

int main() {
    int n; cin >> n;
    cout << mySqrt(n) << endl;
    return 0;
}
