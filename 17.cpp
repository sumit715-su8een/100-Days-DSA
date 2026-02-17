// Day 17 - Q1: Find Maximum and Minimum Element
// Topic: Kadane, DP Intro
// Time: O(n), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int mx = arr[0], mn = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) mx = arr[i];
        if (arr[i] < mn) mn = arr[i];
    }
    cout << "Max: " << mx << endl;
    cout << "Min: " << mn << endl;
    return 0;
}
