// Day 16 - Q1: Frequency Counter in Array
// Topic: Array Count, HashMap Logic
// Time: O(n), Space: O(k)

#include <iostream>
using namespace std;

int main() {
    int n, arr[100], freq[1001] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> arr[i]; freq[arr[i]]++; }
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] > 0) {
            cout << arr[i] << ":" << freq[arr[i]] << " ";
            freq[arr[i]] = 0;
        }
    }
    cout << endl;
    return 0;
}
