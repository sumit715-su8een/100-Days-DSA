// Day 65 - Q1: Cycle Detection in Undirected Graph (DFS)
// Topic: Graph, Cycle Detection, DFS
// Time: O(V+E), Space: O(V)

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1;
    for (auto adjacentNode : adj[node]) {
        if (!vis[adjacentNode]) {
            if (dfs(adjacentNode, node, vis, adj)) return true;
        } else if (adjacentNode != parent) return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V + 1] = {0};
    for (int i = 1; i <= V; i++)
        if (!vis[i] && dfs(i, -1, vis, adj)) return true;
    return false;
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
    cout << (isCycle(V, adj) ? "Cycle Detected" : "No Cycle") << endl;
    return 0;
}
