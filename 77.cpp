// Day 77 - Q1: Check if Graph is Connected
// Topic: Graph, DFS, Connectivity
// Time: O(V+E), Space: O(V)

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], int visited[]) {
    visited[node] = 1;
    for (auto it : adj[node])
        if (!visited[it]) dfs(it, adj, visited);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int visited[n + 1] = {0};
    dfs(1, adj, visited);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NOT CONNECTED" << endl;
            return 0;
        }
    }

    cout << "CONNECTED" << endl;
    return 0;
}
