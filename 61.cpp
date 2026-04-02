// Day 61 - Q1: Graph Representation Using Adjacency Matrix
// Topic: Graph, Adjacency Matrix
// Time: O(m), Space: O(n^2)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    return 0;
}
