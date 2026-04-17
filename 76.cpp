// Day 76 - Q1: Count Connected Components (Undirected Graph)
// Topic: Graph, DFS, Connected Components
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
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }

    cout << "Connected Components: " << count << endl;
    return 0;
}
