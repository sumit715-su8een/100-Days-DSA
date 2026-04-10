// Day 69 - Q1: Dijkstra's Algorithm (Shortest Path)
// Topic: Dijkstra, Shortest Path, Priority Queue
// Time: O(E log V), Space: O(V+E)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int S) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V + 1, INT_MAX);
    dist[S] = 0;
    pq.push({0, S});
    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node]) {
            int adjNode = it.first, edgeWeight = it.second;
            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main() {
    int V, E, S;
    cin >> V >> E >> S;
    vector<pair<int,int>> adj[V + 1];
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }
    vector<int> res = dijkstra(V, adj, S);
    cout << "Shortest distances from " << S << ": ";
    for (int i = 1; i <= V; i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}
