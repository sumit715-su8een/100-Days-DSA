// Day 64 - Q1: Breadth First Search (BFS)
// Topic: Graph Traversal, BFS
// Time: O(V+E), Space: O(V)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V + 1] = {0};
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        bfs.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) { vis[it] = 1; q.push(it); }
        }
    }
    return bfs;
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
    vector<int> ans = bfsOfGraph(V, adj);
    cout << "BFS: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
