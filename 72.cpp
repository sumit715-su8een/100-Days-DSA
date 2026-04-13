// Day 72 - Q1: First Repeated Character
// Topic: Hashing, String
// Time: O(n), Space: O(1)

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[1000];
    int freq[26] = {0};
    bool found = false;

    cin >> s;

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';
        freq[idx]++;
        if (freq[idx] == 2) {
            cout << s[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << -1 << endl;

    return 0;
}
