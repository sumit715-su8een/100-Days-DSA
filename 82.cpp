// Day 82 - Q1: Upper Bound & Lower Bound Implementation
// Topic: Binary Search, Bounds
// Time: O(log n), Space: O(1)

#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    return ans;
}

int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    return ans;
}

int main() {
    int n, x; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x;
    cout << "Lower Bound: " << lowerBound(arr, n, x) << endl;
    cout << "Upper Bound: " << upperBound(arr, n, x) << endl;
    return 0;
}
