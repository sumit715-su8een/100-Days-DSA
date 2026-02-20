// Day 20 - Q1: Count Subarrays with Sum Zero
// Topic: Sorting, Two Pointers
// Time: O(n^2), Space: O(1)

#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) count++;
        }
    }
    cout << count << endl;
    return 0;
}
