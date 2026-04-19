// Day 78 - Q1: Minimum Spanning Tree using Prim's Algorithm
// Topic: MST, Prim's Algorithm
// Time: O(V^2), Space: O(V^2)

#include <iostream>
#define INF 1000000000
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int graph[105][105];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int selected[105] = {0};
    selected[1] = 1;
    int edges = 0, total = 0;

    while (edges < n - 1) {
        int minVal = INF, x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!selected[j] && graph[i][j] < minVal) {
                        minVal = graph[i][j]; x = i; y = j;
                    }
                }
            }
        }
        selected[y] = 1;
        total += graph[x][y];
        edges++;
    }

    cout << "MST Cost: " << total << endl;
    return 0;
}
