// Day 71 - Q1: Hash Table Using Quadratic Probing
// Topic: Hashing, Quadratic Probing
// Time: Average O(1), Space: O(m)

#include <iostream>
using namespace std;

#define SIZE 7

int table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) table[i] = -1;
}

void insert(int key) {
    int h = key % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;
        if (table[index] == -1) { table[index] = key; return; }
    }
    cout << "Table is full!" << endl;
}

int search(int key) {
    int h = key % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int index = (h + i * i) % SIZE;
        if (table[index] == key) return index;
        if (table[index] == -1) return -1;
    }
    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        cout << "table[" << i << "] = " << table[i] << endl;
}

int main() {
    init();
    int keys[] = {10, 22, 31, 4, 15, 28, 17};
    for (int k : keys) insert(k);
    display();
    int key = 15;
    int pos = search(key);
    cout << (pos != -1 ? "Found at index " + to_string(pos) : "Not found") << endl;
    return 0;
}
