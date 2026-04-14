// Day 73 - Q1: First Non-Repeating Character
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

    for (int i = 0; s[i] != '\0'; i++)
        freq[s[i] - 'a']++;

    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            cout << s[i] << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "$" << endl;

    return 0;
}
