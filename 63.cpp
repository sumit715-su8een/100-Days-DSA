// Day 63 - Q1: Depth First Search (DFS)
// Topic: Graph Traversal, DFS
// Time: O(V+E), Space: O(V)

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int>& ls) {
    vis[node] = 1;
    ls.push_back(node);
    for (auto it : adj[node])
        if (!vis[it]) dfs(it, adj, vis, ls);
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[V + 1] = {0};
    vector<int> result;
    for (int i = 1; i <= V; i++)
        if (!vis[i]) dfs(i, adj, vis, result);
    cout << "DFS: ";
    for (int x : result) cout << x << " ";
    cout << endl;
    return 0;
}
