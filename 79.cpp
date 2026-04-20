// Day 79 - Q1: Single Source Shortest Path using Dijkstra's Algorithm
// Topic: Dijkstra, Shortest Path
// Time: O(V^2), Space: O(V^2)

#include <iostream>
#define INF 1000000000
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int graph[105][105];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = INF;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source; cin >> source;

    int dist[105], visited[105] = {0};
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[source] = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1, minDist = INF;
        for (int i = 1; i <= n; i++)
            if (!visited[i] && dist[i] < minDist) { minDist = dist[i]; u = i; }
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 1; v <= n; v++)
            if (graph[u][v] != INF && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Shortest distances from " << source << ": ";
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << endl;
    return 0;
}
