// Day 9 - Q1: Reverse a String (Mirror the Code Name)
// Topic: String, Two Pointers
// Time: O(n), Space: O(1)

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    int left = 0, right = s.size()-1;
    while (left < right) swap(s[left++], s[right--]);
    cout << s << endl;
    return 0;
}
