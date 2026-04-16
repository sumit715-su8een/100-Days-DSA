// Day 75 - Q1: Largest Subarray with Zero Sum
// Topic: Hashing, Prefix Sum
// Time: O(n^2), Space: O(n)

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int prefix[2000], index[2000], sz = 0;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) maxLen = i + 1;

        bool found = false;
        for (int j = 0; j < sz; j++) {
            if (prefix[j] == sum) {
                int len = i - index[j];
                if (len > maxLen) maxLen = len;
                found = true;
                break;
            }
        }

        if (!found) {
            prefix[sz] = sum;
            index[sz] = i;
            sz++;
        }
    }

    cout << "Max length: " << maxLen << endl;
    return 0;
}
