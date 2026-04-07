// Day 66 - Q1: Cycle Detection in Directed Graph
// Topic: Graph, Cycle Detection, DFS
// Time: O(V+E), Space: O(V)

#include <iostream>
#include <vector>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis)) return true;
        } else if (pathVis[it]) return true;
    }
    pathVis[node] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    int vis[V + 1] = {0};
    int pathVis[V + 1] = {0};
    for (int i = 1; i <= V; i++)
        if (!vis[i] && dfsCheck(i, adj, vis, pathVis)) return true;
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); // directed
    }
    cout << (isCyclic(V, adj) ? "Cycle Detected" : "No Cycle") << endl;
    return 0;
}
