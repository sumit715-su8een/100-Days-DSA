// Day 3 - Q1: Linear Search with Comparison Count
// Topic: Array Searching
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, k, arr[100], comparisons = 0, found = -1;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) { found = i; break; }
    }
    if (found != -1) cout << "Found at index " << found << endl;
    else cout << "Not Found" << endl;
    cout << "Comparisons = " << comparisons << endl;
    return 0;
}
