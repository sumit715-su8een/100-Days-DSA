// Day 70 - Q1: Bellman-Ford Algorithm
// Topic: Bellman-Ford, Shortest Path, Negative Weights
// Time: O(V*E), Space: O(V)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V + 1, 1e8);
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (auto it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    // Check for negative cycle
    for (auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            cout << "Negative cycle detected!" << endl;
            return {-1};
        }
    }
    return dist;
}

int main() {
    int V, E, S;
    cin >> V >> E >> S;
    vector<vector<int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> res = bellmanFord(V, edges, S);
    if (res[0] != -1) {
        cout << "Shortest distances from " << S << ": ";
        for (int i = 1; i <= V; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
