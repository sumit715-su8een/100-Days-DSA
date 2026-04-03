// Day 62 - Q1: Graph Representation Using Adjacency List
// Topic: Graph, Adjacency List
// Time: O(m), Space: O(n+m)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int x : adj[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}
