// Day 74 - Q1: Winner of an Election
// Topic: Hashing, Frequency Count
// Time: O(n*k), Space: O(k)

#include <iostream>
#include <cstring>
using namespace std;

struct Candidate {
    char name[100];
    int count;
};

int main() {
    int n;
    cin >> n;

    Candidate arr[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        char temp[100];
        cin >> temp;
        bool found = false;
        for (int j = 0; j < size; j++) {
            if (strcmp(arr[j].name, temp) == 0) {
                arr[j].count++;
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy(arr[size].name, temp);
            arr[size].count = 1;
            size++;
        }
    }

    char winner[100];
    int maxVotes = -1;

    for (int i = 0; i < size; i++) {
        if (arr[i].count > maxVotes) {
            maxVotes = arr[i].count;
            strcpy(winner, arr[i].name);
        } else if (arr[i].count == maxVotes) {
            if (strcmp(arr[i].name, winner) < 0)
                strcpy(winner, arr[i].name);
        }
    }

    cout << winner << " " << maxVotes << endl;
    return 0;
}
