// Day 80 - Q1: Floyd-Warshall Algorithm
// Topic: All-Pairs Shortest Path, DP
// Time: O(n^3), Space: O(n^2)

#include <iostream>
#define INF 1000000000
using namespace std;

int main() {
    int n;
    cin >> n;

    int dist[105][105];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j] == -1 && i != j) dist[i][j] = INF;
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
