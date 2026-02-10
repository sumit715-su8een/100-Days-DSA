// Day 10 - Q1: Check Palindrome
// Topic: Palindrome Check, Two Pointers
// Time: O(n), Space: O(1)

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    int left = 0, right = s.size()-1;
    bool isPalin = true;
    while (left < right) {
        if (s[left] != s[right]) { isPalin = false; break; }
        left++; right--;
    }
    cout << (isPalin ? "YES" : "NO") << endl;
    return 0;
}
