// Day 18 - Q1: Rotate Array by K Positions
// Topic: Prefix Suffix, Array
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

void rev(int arr[], int l, int r) { while (l < r) swap(arr[l++], arr[r--]); }

int main() {
    int n, k, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    k %= n;
    rev(arr, 0, n-1); rev(arr, 0, k-1); rev(arr, k, n-1);
    for (int i = 0; i < n; i++) { cout << arr[i]; if (i < n-1) cout << " "; }
    cout << endl;
    return 0;
}
