// Day 5 - Q1: Merge Two Sorted Arrays
// Topic: Array Merge, Two Pointers
// Time: O(n+m), Space: O(n+m)

#include <iostream>
using namespace std;

int main() {
    int n1, n2, arr1[100], arr2[100], result[200];
    cin >> n1;
    for (int i = 0; i < n1; i++) cin >> arr1[i];
    cin >> n2;
    for (int i = 0; i < n2; i++) cin >> arr2[i];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) result[k++] = arr1[i++];
        else result[k++] = arr2[j++];
    }
    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
    for (int x = 0; x < k; x++) { cout << result[x]; if (x < k-1) cout << " "; }
    cout << endl;
    return 0;
}
